#include <Geode/Geode.hpp>
#include <Geode/modify/LocalLevelManager.hpp>

using namespace geode::prelude;

class $modify(SuperWorldLocalLevelManager, LocalLevelManager) {
    gd::string getMainLevelString(int id) {
        auto file = CCString::createWithFormat("%i.txt"_spr, id);
        if(file == nullptr) return "";
        auto content = CCString::createWithContentsOfFile(file->getCString());
        if(content == nullptr) return "";

        return gd::string(content->getCString());
        return LocalLevelManager::getMainLevelString(id);
    }
};