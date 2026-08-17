// src/Localization.cpp
#include "Localization.hpp"
#include <fstream>

void Localization::load(const std::string& lang) {
    dict_.clear();
    std::ifstream f("lang/" + lang + ".lang");
    std::string line;
    while (std::getline(f, line)) {
        auto pos = line.find('=');
        if (pos == std::string::npos) continue;
        auto key = line.substr(0, pos);
        auto val = line.substr(pos + 1);
        dict_[key] = val;
    }
}

std::string Localization::t(const std::string& key) const {
    auto it = dict_.find(key);
    if (it != dict_.end()) return it->second;
    return key;
}
