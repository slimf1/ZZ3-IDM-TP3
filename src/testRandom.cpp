#include "CLHEP/Random/Randomize.h"
#include <iostream>
#include <cstdio>
#include <string_view>

int main() {
    CLHEP::MTwistEngine mtEngine;
    CLHEP::RandFlat aFlat(mtEngine);
    char filename[20];
    int i, j;

    for(i = 0; i < 10; ++i) {
        for(j = 0; j < 10; ++j) {
            std::cout <<  aFlat.fire() << std::endl;
        }
        snprintf(filename, sizeof(filename), "mtstatus%d.conf", i);
        mtEngine.saveStatus(filename);
    }

    for(i = 0; i < 10; i++) {
        for(j = 0; j < 2e9; ++j) {
            aFlat.fire();
        }
        snprintf(filename, sizeof(filename), "mtstatus_2_%d.conf", i);
        mtEngine.saveStatus(filename);
    }

    return 0;
}
