#include <Geode/Geode.hpp>
#include <Geode/modify/LevelTools.hpp>

using namespace geode::prelude;

class $modify(SuperWorldLevelTools, LevelTools) {
	static bool verifyLevelIntegrity(std::string verifyString, int levelID) {
		return true;
	}

	$override static gd::string getAudioTitle(int levelID) {
		switch (levelID)
		{
		case 1:
			return "Challenger";
		case 2:
			return "Danque";
		default:
			return LevelTools::getAudioTitle(levelID);
		}
	}

	$override static gd::string getAudioFileName(int levelID) {
		switch (levelID)
		{
		case 101:
			return "Challenger.mp3"_spr;
		case 102:
			return "Danque.mp3"_spr;
		default:
			return "-";
		}
	}

	$override static int artistForAudio(int p0)	{
		switch (p0) {
		case 1:
			return 12;
		default:
			return LevelTools::artistForAudio(p0);
		}
	}

	static gd::string nameForArtist(int p0) {
		switch (p0)
		{
		case 12:
			return "Creo";
		default:
			return LevelTools::nameForArtist(p0);
		}
	}

	$override static gd::string urlForAudio(int p0) {

		switch (p0)
		{
		case 50:
			return ""; // not yet
		default:
			return LevelTools::urlForAudio(p0);
		}
	}

	$override static GJGameLevel *getLevel(int levelID, bool loaded) {
		GJGameLevel *level = GJGameLevel::create();
		switch (levelID) {
            case 1:
                level->m_levelName = getAudioTitle(1);
                level->m_audioTrack = 101;
                level->m_difficulty = GJDifficulty::Easy;
                level->m_requiredCoins = 0;
                level->m_timestamp = 0;
                level->m_coins = 3;
                level->m_levelLength = 5;
                level->m_stars = 2;
                break;
			case 2:
				level->m_levelName = getAudioTitle(2);
				level->m_audioTrack = 102;
				level->m_difficulty = GJDifficulty::Normal;
				level->m_requiredCoins = 0;
				level->m_timestamp = 0;
				level->m_coins = 3;
				level->m_levelLength = 5;
				level->m_stars = 3;
				break;
		}

		if (!loaded)
			level->m_levelString = LocalLevelManager::sharedState()->getMainLevelString(levelID);

		level->m_levelID = levelID;
		level->m_levelType = GJLevelType::Local;

		return level;
	};
};