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
		case 3:
			return "Lets Ignite";
		case 4:
			return "Brain Damage";
		case 5:
			return "Crazy";
		case 6:
			return "Sky Fortress";
		case 7:
			return "Osiris";
		case 8:
			return "Hit em Like This";
		case 9:
			return "Lets Stomp!";
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
		case 103:
			return "LetsIgnite.mp3"_spr;
		case 104:
			return "BrainDamage.mp3"_spr;
		case 105:
			return "Crazy.mp3"_spr;
		case 106:
			return "SkyFortress.mp3"_spr;
		case 107:
			return "Osiris.mp3"_spr;
		case 108:
			return "HitEmLikeThis.mp3"_spr;
		case 109:
			return "LetsStomp.mp3"_spr;
		default:
			return "-";
		}
	}

	$override static int artistForAudio(int p0)	{
		switch (p0) {
		case 1:
			return 12;
		case 2:
			return 13;
		case 3:
			return 14;
		case 4:
			return 12;
		case 5:
			return 14;
		case 6:
			return 15;
		case 7:
			return 16;
		case 8:
			return 16;
		default:
			return LevelTools::artistForAudio(p0);
		}
	}

	static gd::string nameForArtist(int p0) {
		switch (p0)
		{
		case 12:
			return "Creo";
		case 13:
			return "BoomKitty";
		case 14:
			return "Waterflame";
		case 15:
			return "EnV";
		case 16:
			return "F-777";
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
			case 3:
				level->m_levelName = getAudioTitle(3);
				level->m_audioTrack = 103;
				level->m_difficulty = GJDifficulty::Hard;
				level->m_requiredCoins = 0;
				level->m_timestamp = 0;
				level->m_coins = 3;
				level->m_levelLength = 5;
				level->m_stars = 4;
				break;
			case 4:
				level->m_levelName = getAudioTitle(4);
				level->m_audioTrack = 104;
				level->m_difficulty = GJDifficulty::Harder;
				level->m_requiredCoins = 0;
				level->m_timestamp = 0;
				level->m_coins = 3;
				level->m_levelLength = 5;
				level->m_stars = 6;
				break;
			case 5:
				level->m_levelName = getAudioTitle(5);
				level->m_audioTrack = 105;
				level->m_difficulty = GJDifficulty::Harder;
				level->m_requiredCoins = 0;
				level->m_timestamp = 0;
				level->m_coins = 3;
				level->m_levelLength = 5;
				level->m_stars = 7;
				break;
			case 6:
				level->m_levelName = getAudioTitle(6);
				level->m_audioTrack = 106;
				level->m_difficulty = GJDifficulty::Harder;
				level->m_requiredCoins = 0;
				level->m_timestamp = 0;
				level->m_coins = 3;
				level->m_levelLength = 5;
				level->m_stars = 6;
				break;
			case 7:
				level->m_levelName = getAudioTitle(7);
				level->m_audioTrack = 107;
				level->m_difficulty = GJDifficulty::Insane;
				level->m_requiredCoins = 0;
				level->m_timestamp = 0;
				level->m_coins = 3;
				level->m_levelLength = 5;
				level->m_stars = 8;
				break;
			case 8:
				level->m_levelName = getAudioTitle(8);
				level->m_audioTrack = 108;
				level->m_difficulty = GJDifficulty::Insane;
				level->m_requiredCoins = 0;
				level->m_timestamp = 0;
				level->m_coins = 3;
				level->m_levelLength = 5;
				level->m_stars = 9;
				break;
			case 9:
				level->m_levelName = getAudioTitle(9);
				level->m_audioTrack = 109;
				level->m_difficulty = GJDifficulty::Insane;
				level->m_requiredCoins = 0;
				level->m_timestamp = 0;
				level->m_coins = 3;
				level->m_levelLength = 5;
				level->m_stars = 9;
				break;
		}

		if (!loaded)
			level->m_levelString = LocalLevelManager::sharedState()->getMainLevelString(levelID);

		level->m_levelID = levelID;
		level->m_levelType = GJLevelType::Local;

		return level;
	};
};