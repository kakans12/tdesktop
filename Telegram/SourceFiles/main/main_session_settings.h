/*
This file is part of Telegram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/telegramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

#include "data/data_auto_download.h"
#include "data/notify/data_peer_notify_settings.h"
#include "data/data_authorization.h"
#include "ui/rect_part.h"

namespace Support {
enum class SwitchSettings;
} // namespace Support

namespace ChatHelpers {
enum class SelectorTab;
} // namespace ChatHelpers

namespace Data {
enum class SetupEmailState;
} // namespace Data

namespace Main {

class SessionSettings final {
public:
	SessionSettings();

	[[nodiscard]] QByteArray serialize() const;
	void addFromSerialized(const QByteArray &serialized);

	void setSupportSwitch(Support::SwitchSettings value) {
		_supportSwitch = value;
	}
	[[nodiscard]] Support::SwitchSettings supportSwitch() const {
		return _supportSwitch;
	}
	void setSupportFixChatsOrder(bool fix) {
		_supportFixChatsOrder = fix;
	}
	[[nodiscard]] bool supportFixChatsOrder() const {
		return _supportFixChatsOrder;
	}
	void setSupportTemplatesAutocomplete(bool enabled) {
		_supportTemplatesAutocomplete = enabled;
	}
	[[nodiscard]] bool supportTemplatesAutocomplete() const {
		return _supportTemplatesAutocomplete;
	}
	void setSupportChatsTimeSlice(int slice);
	[[nodiscard]] int supportChatsTimeSlice() const;
	[[nodiscard]] rpl::producer<int> supportChatsTimeSliceValue() const;
	void setSupportAllSearchResults(bool all);
	[[nodiscard]] bool supportAllSearchResults() const;
	[[nodiscard]] rpl::producer<bool> supportAllSearchResultsValue() const;
	void setSupportAllSilent(bool enabled) {
		_supportAllSilent = enabled;
	}
	[[nodiscard]] bool supportAllSilent() const {
		return _supportAllSilent;
	}

	void setAllSilent(bool enabled) {
		_allSilent = enabled;
	}
	[[nodiscard]] bool allSilent() const {
		return _allSilent;
	}
	void setSpySaveDeleted(bool enabled) {
		_spySaveDeleted = enabled;
	}
	[[nodiscard]] bool spySaveDeleted() const {
		return _spySaveDeleted;
	}
	void setSpySaveEdits(bool enabled) {
		_spySaveEdits = enabled;
	}
	[[nodiscard]] bool spySaveEdits() const {
		return _spySaveEdits;
	}
	void setSpySaveInBotChats(bool enabled) {
		_spySaveInBotChats = enabled;
	}
	[[nodiscard]] bool spySaveInBotChats() const {
		return _spySaveInBotChats;
	}
	void setSpySaveOnetime(bool enabled) {
		_spySaveOnetime = enabled;
	}
	[[nodiscard]] bool spySaveOnetime() const {
		return _spySaveOnetime;
	}

	void setGhostMode(bool enabled) {
		_ghostMode = enabled;
	}
	[[nodiscard]] bool ghostMode() const {
		return _ghostMode;
	}
	void setGhostNoRead(bool enabled) {
		_ghostNoRead = enabled;
	}
	[[nodiscard]] bool ghostNoRead() const {
		return _ghostMode && _ghostNoRead;
	}
	void setGhostNoOnline(bool enabled) {
		_ghostNoOnline = enabled;
	}
	[[nodiscard]] bool ghostNoOnline() const {
		return _ghostMode && _ghostNoOnline;
	}
	void setGhostNoTyping(bool enabled) {
		_ghostNoTyping = enabled;
	}
	[[nodiscard]] bool ghostNoTyping() const {
		return _ghostMode && _ghostNoTyping;
	}
	void setGhostNoStories(bool enabled) {
		_ghostNoStories = enabled;
	}
	[[nodiscard]] bool ghostNoStories() const {
		return _ghostMode && _ghostNoStories;
	}
	void setGhostAutoOffline(bool enabled) {
		_ghostAutoOffline = enabled;
	}
	[[nodiscard]] bool ghostAutoOffline() const {
		return _ghostMode && _ghostAutoOffline;
	}
	void setGhostReadOnAction(bool enabled) {
		_ghostReadOnAction = enabled;
	}
	[[nodiscard]] bool ghostReadOnAction() const {
		return _ghostMode && _ghostReadOnAction;
	}
	[[nodiscard]] bool ghostNoReadRaw() const {
		return _ghostNoRead;
	}
	[[nodiscard]] bool ghostNoOnlineRaw() const {
		return _ghostNoOnline;
	}
	[[nodiscard]] bool ghostNoTypingRaw() const {
		return _ghostNoTyping;
	}
	[[nodiscard]] bool ghostNoStoriesRaw() const {
		return _ghostNoStories;
	}
	[[nodiscard]] bool ghostAutoOfflineRaw() const {
		return _ghostAutoOffline;
	}
	[[nodiscard]] bool ghostReadOnActionRaw() const {
		return _ghostReadOnAction;
	}

	void setShowSeconds(bool enabled) {
		_showSeconds = enabled;
	}
	[[nodiscard]] bool showSeconds() const {
		return _showSeconds;
	}
	void setShowDialogId(bool enabled) {
		_showDialogId = enabled;
	}
	[[nodiscard]] bool showDialogId() const {
		return _showDialogId;
	}

	[[nodiscard]] ChatHelpers::SelectorTab selectorTab() const {
		return _selectorTab;
	}
	void setSelectorTab(ChatHelpers::SelectorTab tab) {
		_selectorTab = tab;
	}

	void setGroupStickersSectionHidden(PeerId peerId) {
		_groupStickersSectionHidden.insert(peerId);
	}
	[[nodiscard]] bool isGroupStickersSectionHidden(PeerId peerId) const {
		return _groupStickersSectionHidden.contains(peerId);
	}
	void removeGroupStickersSectionHidden(PeerId peerId) {
		_groupStickersSectionHidden.remove(peerId);
	}

	void setGroupEmojiSectionHidden(PeerId peerId) {
		_groupEmojiSectionHidden.insert(peerId);
	}
	[[nodiscard]] bool isGroupEmojiSectionHidden(PeerId peerId) const {
		return _groupEmojiSectionHidden.contains(peerId);
	}
	void removeGroupEmojiSectionHidden(PeerId peerId) {
		_groupEmojiSectionHidden.remove(peerId);
	}

	[[nodiscard]] Data::AutoDownload::Full &autoDownload() {
		return _autoDownload;
	}
	[[nodiscard]] const Data::AutoDownload::Full &autoDownload() const {
		return _autoDownload;
	}

	void setArchiveCollapsed(bool collapsed);
	[[nodiscard]] bool archiveCollapsed() const;
	[[nodiscard]] rpl::producer<bool> archiveCollapsedChanges() const;

	void setArchiveInMainMenu(bool inMainMenu);
	[[nodiscard]] bool archiveInMainMenu() const;
	[[nodiscard]] rpl::producer<bool> archiveInMainMenuChanges() const;

	void setSkipArchiveInSearch(bool skip);
	[[nodiscard]] bool skipArchiveInSearch() const;
	[[nodiscard]] rpl::producer<bool> skipArchiveInSearchChanges() const;

	[[nodiscard]] bool hadLegacyCallsPeerToPeerNobody() const {
		return _hadLegacyCallsPeerToPeerNobody;
	}

	[[nodiscard]] MsgId hiddenPinnedMessageId(
		PeerId peerId,
		MsgId topicRootId = 0,
		PeerId monoforumPeerId = 0) const;
	void setHiddenPinnedMessageId(
		PeerId peerId,
		MsgId topicRootId,
		PeerId monoforumPeerId,
		MsgId msgId);

	[[nodiscard]] bool verticalSubsectionTabs(PeerId peerId) const;
	void setVerticalSubsectionTabs(PeerId peerId, bool vertical);

	[[nodiscard]] bool dialogsFiltersEnabled() const {
		return _dialogsFiltersEnabled;
	}
	void setDialogsFiltersEnabled(bool value) {
		_dialogsFiltersEnabled = value;
	}

	[[nodiscard]] bool photoEditorHintShown() const;
	void incrementPhotoEditorHintShown();

	[[nodiscard]] std::vector<TimeId> mutePeriods() const;
	void addMutePeriod(TimeId period);

	[[nodiscard]] TimeId lastNonPremiumLimitDownload() const {
		return _lastNonPremiumLimitDownload;
	}
	[[nodiscard]] TimeId lastNonPremiumLimitUpload() const {
		return _lastNonPremiumLimitUpload;
	}
	void setLastNonPremiumLimitDownload(TimeId when) {
		_lastNonPremiumLimitDownload = when;
	}
	void setLastNonPremiumLimitUpload(TimeId when) {
		_lastNonPremiumLimitUpload = when;
	}
	void setRingtoneVolume(
		Data::DefaultNotify defaultNotify,
		ushort volume);
	[[nodiscard]] ushort ringtoneVolume(
		Data::DefaultNotify defaultNotify) const;
	void setRingtoneVolume(
		PeerId peerId,
		MsgId topicRootId,
		PeerId monoforumPeerId,
		ushort volume);
	[[nodiscard]] ushort ringtoneVolume(
		PeerId peerId,
		MsgId topicRootId,
		PeerId monoforumPeerId) const;

	void markTranscriptionAsRated(uint64 transcriptionId);
	[[nodiscard]] bool isTranscriptionRated(uint64 transcriptionId) const;

	void setUnreviewed(std::vector<Data::UnreviewedAuth> auths);
	[[nodiscard]] const std::vector<Data::UnreviewedAuth> &unreviewed() const;

	void setSetupEmailState(Data::SetupEmailState state);
	[[nodiscard]] Data::SetupEmailState setupEmailState() const;

	void setModerateCommonGroups(std::vector<int32> groups) {
		_moderateCommonGroups = std::move(groups);
	}
	[[nodiscard]] const std::vector<int32> &moderateCommonGroups() const {
		return _moderateCommonGroups;
	}

private:
	static constexpr auto kDefaultSupportChatsLimitSlice = 7 * 24 * 60 * 60;
	static constexpr auto kPhotoEditorHintMaxShowsCount = 5;

	struct ThreadId {
		PeerId peerId;
		MsgId topicRootId;
		PeerId monoforumPeerId;

		friend inline constexpr auto operator<=>(
			ThreadId,
			ThreadId) = default;
	};

	ChatHelpers::SelectorTab _selectorTab; // per-window
	base::flat_set<PeerId> _groupStickersSectionHidden;
	base::flat_set<PeerId> _groupEmojiSectionHidden;
	bool _hadLegacyCallsPeerToPeerNobody = false;
	Data::AutoDownload::Full _autoDownload;
	rpl::variable<bool> _archiveCollapsed = false;
	rpl::variable<bool> _archiveInMainMenu = false;
	rpl::variable<bool> _skipArchiveInSearch = false;
	base::flat_map<ThreadId, MsgId> _hiddenPinnedMessages;
	base::flat_set<PeerId> _verticalSubsectionTabs;
	base::flat_map<Data::DefaultNotify, ushort> _ringtoneDefaultVolumes;
	base::flat_map<ThreadId, ushort> _ringtoneVolumes;
	bool _dialogsFiltersEnabled = false;
	int _photoEditorHintShowsCount = 0;
	std::vector<TimeId> _mutePeriods;
	TimeId _lastNonPremiumLimitDownload = 0;
	TimeId _lastNonPremiumLimitUpload = 0;

	Support::SwitchSettings _supportSwitch;
	bool _supportFixChatsOrder = true;
	bool _supportTemplatesAutocomplete = true;
	bool _supportAllSilent = false;

	bool _allSilent = false;
	bool _spySaveDeleted = false;
	bool _spySaveEdits = false;
	bool _spySaveInBotChats = false;
	bool _spySaveOnetime = false;

	bool _ghostMode = false;
	bool _ghostNoRead = false;
	bool _ghostNoOnline = false;
	bool _ghostNoTyping = false;
	bool _ghostNoStories = false;
	bool _ghostAutoOffline = false;
	bool _ghostReadOnAction = false;

	bool _showSeconds = false;
	bool _showDialogId = false;
	rpl::variable<int> _supportChatsTimeSlice
		= kDefaultSupportChatsLimitSlice;
	rpl::variable<bool> _supportAllSearchResults = false;

	base::flat_set<uint64> _ratedTranscriptions;

	std::vector<Data::UnreviewedAuth> _unreviewed;

	Data::SetupEmailState _setupEmailState;

	std::vector<int32> _moderateCommonGroups;

};

} // namespace Main
