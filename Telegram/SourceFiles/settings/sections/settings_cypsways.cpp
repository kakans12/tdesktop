/*
This file is part of Telegram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/telegramdesktop/tdesktop/blob/master/LEGAL
*/
#include "settings/sections/settings_cypsways.h"

#include "settings/settings_common_session.h"

#include "settings/settings_builder.h"
#include "settings/sections/settings_main.h"
#include "lang/lang_keys.h"
#include "main/main_session.h"
#include "main/main_session_settings.h"
#include "ui/vertical_list.h"
#include "ui/wrap/vertical_layout.h"
#include "window/window_session_controller.h"
#include "styles/style_settings.h"
#include "styles/style_menu_icons.h"

namespace Settings {
namespace {

using namespace Builder;

void BuildGhostSection(SectionBuilder &builder) {
	const auto session = builder.session();
	const auto controller = builder.controller();

	builder.addSkip();
	builder.addSubsectionTitle({
		.id = u"cw/ghost"_q,
		.title = tr::lng_settings_cw_ghost_title(),
		.keywords = { u"ghost"_q, u"invisible"_q },
	});
	builder.addSkip(st::settingsSendTypeSkip);

	const auto ghostToggle = builder.addCheckbox({
		.id = u"cw/ghost-toggle"_q,
		.title = tr::lng_settings_cw_ghost_toggle(),
		.checked = session->settings().ghostMode(),
		.keywords = { u"ghost"_q, u"mode"_q },
	});
	if (ghostToggle) {
		ghostToggle->checkedChanges(
		) | rpl::on_next([=](bool checked) {
			controller->session().settings().setGhostMode(checked);
			controller->session().saveSettingsDelayed();
		}, ghostToggle->lifetime());
	}

	builder.addDividerText(tr::lng_settings_cw_ghost_about());

	builder.addSkip(st::settingsSendTypeSkip);

	const auto noRead = builder.addCheckbox({
		.id = u"cw/ghost-no-read"_q,
		.title = tr::lng_settings_cw_ghost_no_read(),
		.checked = session->settings().ghostNoReadRaw(),
		.keywords = { u"read"_q, u"blue"_q, u"tick"_q },
	});
	if (noRead) {
		noRead->checkedChanges(
		) | rpl::on_next([=](bool checked) {
			controller->session().settings().setGhostNoRead(checked);
			controller->session().saveSettingsDelayed();
		}, noRead->lifetime());
	}

	const auto noOnline = builder.addCheckbox({
		.id = u"cw/ghost-no-online"_q,
		.title = tr::lng_settings_cw_ghost_no_online(),
		.checked = session->settings().ghostNoOnlineRaw(),
		.keywords = { u"online"_q, u"status"_q },
	});
	if (noOnline) {
		noOnline->checkedChanges(
		) | rpl::on_next([=](bool checked) {
			controller->session().settings().setGhostNoOnline(checked);
			controller->session().saveSettingsDelayed();
		}, noOnline->lifetime());
	}

	const auto noTyping = builder.addCheckbox({
		.id = u"cw/ghost-no-typing"_q,
		.title = tr::lng_settings_cw_ghost_no_typing(),
		.checked = session->settings().ghostNoTypingRaw(),
		.keywords = { u"typing"_q },
	});
	if (noTyping) {
		noTyping->checkedChanges(
		) | rpl::on_next([=](bool checked) {
			controller->session().settings().setGhostNoTyping(checked);
			controller->session().saveSettingsDelayed();
		}, noTyping->lifetime());
	}

	const auto noStories = builder.addCheckbox({
		.id = u"cw/ghost-no-stories"_q,
		.title = tr::lng_settings_cw_ghost_no_stories(),
		.checked = session->settings().ghostNoStoriesRaw(),
		.keywords = { u"stories"_q },
	});
	if (noStories) {
		noStories->checkedChanges(
		) | rpl::on_next([=](bool checked) {
			controller->session().settings().setGhostNoStories(checked);
			controller->session().saveSettingsDelayed();
		}, noStories->lifetime());
	}

	const auto autoOffline = builder.addCheckbox({
		.id = u"cw/ghost-auto-offline"_q,
		.title = tr::lng_settings_cw_ghost_auto_offline(),
		.checked = session->settings().ghostAutoOfflineRaw(),
		.keywords = { u"offline"_q, u"automatic"_q },
	});
	if (autoOffline) {
		autoOffline->checkedChanges(
		) | rpl::on_next([=](bool checked) {
			controller->session().settings().setGhostAutoOffline(checked);
			controller->session().saveSettingsDelayed();
		}, autoOffline->lifetime());
	}

	builder.addSkip(st::settingsCheckboxesSkip);

	const auto readOnAction = builder.addCheckbox({
		.id = u"cw/ghost-read-on-action"_q,
		.title = tr::lng_settings_cw_ghost_read_on_action(),
		.checked = session->settings().ghostReadOnActionRaw(),
		.keywords = { u"read"_q, u"action"_q, u"send"_q },
	});
	if (readOnAction) {
		readOnAction->checkedChanges(
		) | rpl::on_next([=](bool checked) {
			controller->session().settings().setGhostReadOnAction(checked);
			controller->session().saveSettingsDelayed();
		}, readOnAction->lifetime());
	}

	builder.addDividerText(tr::lng_settings_cw_ghost_read_on_action_about());
}

void BuildSpySection(SectionBuilder &builder) {
	const auto session = builder.session();
	const auto controller = builder.controller();

	builder.addSkip();
	builder.addSubsectionTitle({
		.id = u"cw/spy"_q,
		.title = tr::lng_settings_cw_spy_title(),
		.keywords = { u"spy"_q },
	});
	builder.addSkip(st::settingsSendTypeSkip);

	const auto saveDeleted = builder.addCheckbox({
		.id = u"cw/spy-save-deleted"_q,
		.title = tr::lng_settings_cw_spy_save_deleted(),
		.checked = session->settings().spySaveDeleted(),
		.keywords = { u"deleted"_q, u"save"_q },
	});
	if (saveDeleted) {
		saveDeleted->checkedChanges(
		) | rpl::on_next([=](bool checked) {
			controller->session().settings().setSpySaveDeleted(checked);
			controller->session().saveSettingsDelayed();
		}, saveDeleted->lifetime());
	}

	const auto saveEdits = builder.addCheckbox({
		.id = u"cw/spy-save-edits"_q,
		.title = tr::lng_settings_cw_spy_save_edits(),
		.checked = session->settings().spySaveEdits(),
		.keywords = { u"edit"_q, u"history"_q },
	});
	if (saveEdits) {
		saveEdits->checkedChanges(
		) | rpl::on_next([=](bool checked) {
			controller->session().settings().setSpySaveEdits(checked);
			controller->session().saveSettingsDelayed();
		}, saveEdits->lifetime());
	}

	const auto saveOnetime = builder.addCheckbox({
		.id = u"cw/spy-save-onetime"_q,
		.title = tr::lng_settings_cw_spy_save_onetime(),
		.checked = session->settings().spySaveOnetime(),
		.keywords = { u"onetime"_q, u"self-destruct"_q },
	});
	if (saveOnetime) {
		saveOnetime->checkedChanges(
		) | rpl::on_next([=](bool checked) {
			controller->session().settings().setSpySaveOnetime(checked);
			controller->session().saveSettingsDelayed();
		}, saveOnetime->lifetime());
	}

	const auto saveInBots = builder.addCheckbox({
		.id = u"cw/spy-save-in-bots"_q,
		.title = tr::lng_settings_cw_spy_save_in_bots(),
		.checked = session->settings().spySaveInBotChats(),
		.keywords = { u"bot"_q },
	});
	if (saveInBots) {
		saveInBots->checkedChanges(
		) | rpl::on_next([=](bool checked) {
			controller->session().settings().setSpySaveInBotChats(checked);
			controller->session().saveSettingsDelayed();
		}, saveInBots->lifetime());
	}

	builder.addSkip(st::settingsCheckboxesSkip);
}

void BuildUISection(SectionBuilder &builder) {
	const auto session = builder.session();
	const auto controller = builder.controller();

	builder.addSkip();
	builder.addSubsectionTitle({
		.id = u"cw/ui"_q,
		.title = tr::lng_settings_cw_ui_title(),
		.keywords = { u"interface"_q },
	});
	builder.addSkip(st::settingsSendTypeSkip);

	const auto silent = builder.addCheckbox({
		.id = u"cw/send-silent"_q,
		.title = tr::lng_settings_cw_send_silent(),
		.checked = session->settings().allSilent(),
		.keywords = { u"silent"_q, u"sound"_q, u"mute"_q },
	});
	if (silent) {
		silent->checkedChanges(
		) | rpl::on_next([=](bool checked) {
			controller->session().settings().setAllSilent(checked);
			controller->session().saveSettingsDelayed();
		}, silent->lifetime());
	}

	builder.addDividerText(tr::lng_settings_cw_send_silent_about());
	builder.addSkip(st::settingsSendTypeSkip);

	const auto showSeconds = builder.addCheckbox({
		.id = u"cw/show-seconds"_q,
		.title = tr::lng_settings_cw_show_seconds(),
		.checked = session->settings().showSeconds(),
		.keywords = { u"seconds"_q, u"time"_q },
	});
	if (showSeconds) {
		showSeconds->checkedChanges(
		) | rpl::on_next([=](bool checked) {
			controller->session().settings().setShowSeconds(checked);
			controller->session().saveSettingsDelayed();
		}, showSeconds->lifetime());
	}

	const auto showDialogId = builder.addCheckbox({
		.id = u"cw/show-dialog-id"_q,
		.title = tr::lng_settings_cw_show_dialog_id(),
		.checked = session->settings().showDialogId(),
		.keywords = { u"dialog"_q, u"id"_q },
	});
	if (showDialogId) {
		showDialogId->checkedChanges(
		) | rpl::on_next([=](bool checked) {
			controller->session().settings().setShowDialogId(checked);
			controller->session().saveSettingsDelayed();
		}, showDialogId->lifetime());
	}

	builder.addSkip(st::settingsCheckboxesSkip);
}

void BuildCypsWaysContent(SectionBuilder &builder) {
	BuildGhostSection(builder);
	BuildSpySection(builder);
	BuildUISection(builder);
}

class CypsWays : public Section<CypsWays> {
public:
	CypsWays(
		QWidget *parent,
		not_null<Window::SessionController*> controller);

	[[nodiscard]] rpl::producer<QString> title() override;

private:
	void setupContent();

};

const auto kMeta = BuildHelper({
	.id = CypsWays::Id(),
	.parentId = MainId(),
	.title = &tr::lng_settings_cypsways,
	.icon = &st::menuIconExperimental,
}, [](SectionBuilder &builder) {
	BuildCypsWaysContent(builder);
});

const SectionBuildMethod kCypsWaysSection = kMeta.build;

CypsWays::CypsWays(
	QWidget *parent,
	not_null<Window::SessionController*> controller)
: Section(parent, controller) {
	setupContent();
}

rpl::producer<QString> CypsWays::title() {
	return tr::lng_settings_cypsways();
}

void CypsWays::setupContent() {
	const auto content = Ui::CreateChild<Ui::VerticalLayout>(this);

	build(content, kCypsWaysSection);

	Ui::ResizeFitChild(this, content);
}

} // namespace

Type CypsWaysId() {
	return CypsWays::Id();
}

} // namespace Settings
