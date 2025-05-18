#include <Geode/modify/AchievementManager.hpp>

using namespace geode::prelude;

class $modify(AchievementManager)
{
    void addManualAchievements() {
    AchievementManager::addAchievement("geometry.ach.level01b", "The Challenger", "Completed \'Challenger\' In Normal Mode", "Complete \'Barracuda\' In Normal Mode", "cube_05", 1);
    
    AchievementManager::addAchievement("geometry.ach.level02b", "Danque?", "Completed \'Danque\' In Normal Mode", "Complete \'Danque\' In Normal Mode", "cube_06", 1);
    
    AchievementManager::addAchievement("geometry.ach.level03b", "Ignited", "Completed \'Lets Ignite\' In Normal Mode", "Complete \'Lets Ignite\' In Normal Mode", "cube_07", 1);

    AchievementManager::addAchievement("geometry.ach.level04b", "Damaged Brain", "Completed \'Brain Damage\' In Normal Mode", "Complete \'Brain Damage\' In Normal Mode", "cube_08", 1);
        
    AchievementManager::addAchievement("geometry.ach.level05b", "Insane", "Completed \'Crazy\' In Normal Mode", "Complete \'Crazy\' In Normal Mode", "cube_09", 1);

    AchievementManager::addAchievement("geometry.ach.level06b", "Airborne", "Completed \'Sky Fortress\' In Normal Mode", "Complete \'Sky Fortress\' In Normal Mode", "cube_10", 1);
        
    AchievementManager::addAchievement("geometry.ach.level07b", "The Osiris", "Completed \'Osiris\' In Normal Mode", "Complete \'Osiris\' In Normal Mode", "cube_11", 1);

    AchievementManager::addAchievement("geometry.ach.level08b", "Injury", "Completed \'Hit em Like This\' In Normal Mode", "Complete \'Hit em Like This\' In Normal Mode", "cube_12", 1);
        
    AchievementManager::addAchievement("geometry.ach.level09b", "Stomped On", "Completed \'Lets Stomp\' In Normal Mode", "Complete \'Lets Stomp\' In Normal Mode", "cube_13", 1);

    #ifdef GEODE_IS_WINDOWS
    AchievementManager::addAchievement("geometry.ach.steam01", "It's steaming over here!!", "Completed Levels 1-3 In Normal Mode (Steam Exclusive)", "Complete Levels 1-3 In Normal Mode (Steam Exclusive)", "spider_02", 0);
    #endif
    }
};
