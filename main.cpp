#include <vector>
#include <string>
#include "Map.h"
#include "Scenario.h"

#include <cstdio>


int main(int argc, char** argv) 
{
    Scenario scenario("scens/arena.map.scen");
    
    printf("valid: %d\n", scenario.isValid());
    return 0;
}