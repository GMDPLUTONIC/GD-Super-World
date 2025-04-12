#include <Geode/modify/AchievementManager.hpp>

using namespace geode::prelude;

class $modify(AchievementManager)
{
    void addManualAchievements()
    {

    AchievementManager::addAchievement("geometry.ach.level01b", "Fish Killer", "Completed \'Barracuda\' In Normal Mode", "Complete \'Barracuda\' In Normal Mode", "cube_05", 1);

    #ifdef GEODE_IS_WINDOWS
    AchievementManager::addAchievement("geometry.ach.steam01", "Crazy Steamer", "Completed Levels 1-3 In Normal Mode (Steam Exclusive)", "Complete Levels 1-3 In Normal Mode (Steam Exclusive)", "spider_02", 0);
    #endif

    }
};