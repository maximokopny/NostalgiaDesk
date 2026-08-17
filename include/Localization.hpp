// include/Localization.hpp
#pragma once
#include <string>
#include <unordered_map>

class Localization {
public:
    void load(const std::string& lang);
    std::string t(const std::string& key) const;
private:
    std::unordered_map<std::string, std::string> dict_;
};
