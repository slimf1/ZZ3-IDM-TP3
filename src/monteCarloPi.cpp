#include "monteCarloPi.hpp"
#include <vector>
#include <sstream>
#include <numeric>
#include <iostream>
#include <string>

namespace idm {

/**
 * 
 * 
 */
double piExperiment(uint64_t points, CLHEP::HepRandomEngine& engine) {
    
    uint64_t inCircle = 0;                    // Nombre de points dans le cercle
    CLHEP::RandFlat flatDistribution(engine); // Distribution uniforme
    uint64_t i;                               // Indice du point courant
    double x, y;                              // Coordonnées du point tiré

    for(i = 0u; i < points; ++i) {
        x = flatDistribution.fire();
        y = flatDistribution.fire();

        if (x * x + y * y <= 1) {
            ++inCircle;
        }
    }

    return 4 * inCircle / static_cast<double>(points);
}

void loadPiExperimentFromFile(uint64_t points, const std::string& engineStatusFile, std::ostream& outputStream) {
    
    CLHEP::MTwistEngine engine;

    engine.restoreStatus(engineStatusFile.c_str());
    outputStream << piExperiment(points, engine) << "\n";
}

pi_sim_result_t piReplications(uint64_t points, uint32_t replications) {

    std::vector<double> results(replications);
    CLHEP::MTwistEngine engine;
    pi_sim_result_t stats;
    std::stringstream ss;
    uint32_t i;

    for(i = 0u; i < replications; ++i) {

        // Chargement de l'état
        ss.str("");
        ss << "mtstatus_2_" << i << ".conf";
        std::cout << "Restoring status of " << ss.str() << "\n";
        engine.restoreStatus(ss.str().c_str());

        std::cout << "Exp:" << "\n";
        // Résultat de l'expérience
        results[i] = piExperiment(points, engine);

        // If verbose... ? 
        std::cout << "Exp[" << i << "]: " << results[i] << "\n";
    }

    stats.mean = std::accumulate(results.begin(), results.end(), 0.0) / 
                    static_cast<double>(results.size());

    return stats;
}

} // namespace idm
