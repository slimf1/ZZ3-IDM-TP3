#include <numeric>
#include <cmath>
#include <algorithm>
#include "stats.hpp"

namespace idm {

/**
 * Calcul de la moyenne et de l'écart type pour un
 * vecteur numérique.
 * 
 * @param results Liste des résultats
 * @return Enregistrement contenant moyenne
 * et écart-type
 */
stats_t resultsStats(const std::vector<double>& results) {
    
    stats_t stats;
    double sum;
    double acc = 0.0;

    sum = std::accumulate(results.begin(), results.end(), 0.0);
    stats.mean = sum / results.size();
    acc = 0.0;
    std::for_each(results.begin(), results.end(), [&acc, &stats](double d) {
        acc += (d - stats.mean) * (d - stats.mean);
    });
    stats.stdDev = std::sqrt(acc / (results.size() - 1));

    return stats;
}

} // namespace idm
