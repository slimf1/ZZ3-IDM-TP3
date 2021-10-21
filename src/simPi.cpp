#include <iostream>
#include <fstream>
#include "monteCarloPi.hpp"

int main(int argc, char** argv) {
    
    if (argc < 2) {
        std::cerr << "Ajouter l'état du générateur en argument.\n";
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file.good()) {
        std::cerr << "Le fichier spécifié n'a pas été trouvé.\n";
        return 1;
    }
    file.close();

    idm::loadPiExperimentFromFile(1e9, argv[1], std::cout);
    
    return EXIT_SUCCESS;
}
