#include <string>
#include <vector>
#include "Map.h"
#include "Scenario.h"

#include <cstdio>
#include <cassert>
#include <cstdlib>

Scenario::Scenario(const std::string& path)
 : path(path)
{
    FILE* f = fopen(path.c_str(), "rb");
    if (f == nullptr)
        return;
    std::vector<char> buffer;
    buffer.resize(8192);
    int version;

    // version
    fscanf(f, "%s %d\n", buffer.data(), &version);
    assert(std::string(buffer.data()) == "version");
    assert(version == 1);

    unsigned bucket, width, height, startX, startY, goalX, goalY;
    float dist;

    while(fscanf(f, "%u\t%s\t%u\t%u\t%u\t%u\t%u\t%u\t%f\n", &bucket,
          buffer.data(), &width, &height, &startX, &startY, &goalX, &goalY, &dist) != EOF) {
        if (!map.isValid() && !map.Load(std::string(buffer.data())))
            return;

        searches.push_back({startX, startY, goalX, goalY});
    }
    fclose(f);
}
