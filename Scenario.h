#pragma once

struct Search {
    unsigned startX;
    unsigned startY;
    unsigned goalX;
    unsigned goalY;
    //unsigned dist;
};

class Map;

class Scenario {
public:
    Scenario(const std::string& path);
    bool isValid() { return searches.size() > 0; }
private:
    std::vector<Search> searches;
    std::string path;
    Map map;
};