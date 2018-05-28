#pragma once

class Map {
public:
    bool Load(const std::string& path);
    bool isValid() { return passable.size() == width * height; }
private:
    std::string path;
    unsigned width = -1u;
    unsigned height = -1u;
    std::vector<bool> passable;
};