#include <Geode/modify/AchievementManager.hpp>

using namespace geode::prelude;

class $modify(AchievementManager)
{
    void addManualAchievements() {
    AchievementManager::addAchievement("geometry.ach.level01b", "The challenger", "Completed \'Challenger\' In Normal Mode", "Complete \'Barracuda\' In Normal Mode", "cube_05", 1);
    
    AchievementManager::addAchievement("geometry.ach.level02b", "Ignited", "Completed \'Lets Ignite\' In Normal Mode", "Complete \'Lets Ignite\' In Normal Mode", "cube_06", 1);
    
    AchievementManager::addAchievement("geometry.ach.level03b", "Damaged Brain", "Completed \'Brain Damage\' In Normal Mode", "Complete \'Brain Damage\' In Normal Mode", "cube_07", 1);

    #ifdef GEODE_IS_WINDOWS
    AchievementManager::addAchievement("geometry.ach.steam01", "It's steaming over here!!", "Completed Levels 1-3 In Normal Mode (Steam Exclusive)", "Complete Levels 1-3 In Normal Mode (Steam Exclusive)", "spider_02", 0);
    #endif
    }
};