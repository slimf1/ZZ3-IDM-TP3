#include "monteCarloPi.hpp"
#include <vector>
#include <sstream>
#include <numeric>
#include <iostream>
#include <string>

namespace idm {

/**
 * Expérience de Monte Carlo pour le calcul de Pi.
 *
 * @param points Le nombre de points à utiliser
 * @param engine PRNG
 * @return Une estimation de Pi
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

/**
 * Réalise une expérience de Monte Carlo pour calculer Pi
 * à partir d'un état pré-défini.
 * 
 * @param points Le nombre de points à utiliser 
 *               dans une simulation
 * @param engineStatusFile Le fichier contenant l'état 
 *                         du générateur
 * @param outputStream Le flux de sortie pour le résultat
 *                     de l'expérience
 */
void loadPiExperimentFromFile(uint64_t points, const std::string& engineStatusFile, std::ostream& outputStream) {
    
    CLHEP::MTwistEngine engine;

    engine.restoreStatus(engineStatusFile.c_str());
    outputStream << piExperiment(points, engine) << " " << engineStatusFile << "\n";
}

/**
 * Réalise plusieurs réplications d'une expérience de
 * Monte Carlo pour estimer Pi.
 * 
 * @param points Le nombre de points à utiliser dans 
 *               une expérience
 * @param replications Le nombre de réplications à réaliser
 * @return Un enregistrement contenant moyenne et écart-type
 *         des expériences réalisées
 */
stats_t piReplications(uint64_t points, uint32_t replications) {

    std::vector<double> results(replications); // Résultats des expériences
    CLHEP::MTwistEngine engine;                // PRNG
    std::stringstream ss;                      // Flux pour le nom de fichier
    uint32_t i;                                // Indice de la réplication courante

    for(i = 0u; i < replications; ++i) {

        // Chargement de l'état
        ss.str("");
        ss << "mtstatus_2_" << i << ".conf";
        std::cout << "Restoring status of " << ss.str() << "\n";
        engine.restoreStatus(ss.str().c_str());

        // Résultat de l'expérience
        std::cout << "Exp:" << "\n";
        results[i] = piExperiment(points, engine);

        std::cout << "Exp[" << i << "]: " << results[i] << "\n";
    }

    return resultsStats(results);
}

} // namespace idm
