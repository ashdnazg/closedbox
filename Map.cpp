#include <string>
#include <vector>
#include "Map.h"

#include <cstdio>
#include <cassert>
#include <cstdlib>

bool Map::Load(const std::string& mapPath)
{
    FILE* f = fopen(mapPath.c_str(), "rb");
    if (f == nullptr)
        return false;
    std::vector<char> buffer;
    buffer.resize(8192);
    
    // type
    fscanf(f, "%s ", buffer.data());
    assert(std::string(buffer.data()) == "type");
    fscanf(f, "%s\n", buffer.data());
    
    //sizes
    fscanf(f, "%s ", buffer.data());
    assert(std::string(buffer.data()) == "height");
    fscanf(f, "%u\n", &height);
    fscanf(f, "%s ", buffer.data());
    assert(std::string(buffer.data()) == "width");
    fscanf(f, "%u\n", &width);

    //map
    fscanf(f, "%s\n", buffer.data());
    assert(std::string(buffer.data()) == "map");
    
    for(unsigned row = 0; row < height; ++row) {
        fscanf(f, "%s\n", buffer.data());
        for(unsigned col = 0; col < width; ++col) {
            switch (buffer[col]) {
                case '.':
                case 'G':
                    passable.push_back(true);
                    break;
                case '$':
                case 'O':
                case 'T':
                    passable.push_back(false);
                    break;
                default:
                    passable.clear();
                    return false;
            }
        }
    }
    
    
    fclose(f);
    path = mapPath;
    return true;
}