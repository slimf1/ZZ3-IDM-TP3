#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include "monteCarloPi.hpp"

void runExperiment(char* engineStateFilename) {
    idm::loadPiExperimentFromFile(1e9, engineStateFilename, std::cout);
}

int main(int argc, char** argv) {
    
    if (argc < 2) {
        std::cerr << "Ajouter au moins un fichier d'état du générateur.\n";
        return 1;
    }

    int i;
    std::vector<std::thread> threads(argc - 1);

    for(i = 0; i < argc - 1; ++i) {
        threads[i] = std::thread(runExperiment, argv[i + 1]);
    }
    
    for(i = 0; i < argc - 1; ++i) {
        threads[i].join();
    }
    
    return EXIT_SUCCESS;
}
