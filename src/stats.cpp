#include <numeric>
#include <cmath>
#include <algorithm>
#include "stats.hpp"

namespace idm {

stats_t resultsStats(const std::vector<double>& results) {
    
    stats_t stats;
    double sum = std::accumulate(results.begin(), results.end(), 0.0);
    stats.mean = sum / results.size();
    double acc = 0.0;
    std::for_each(results.begin(), results.end(), [&, stats](const double d) {
        acc += (d - stats.mean) * (d - stats.mean);
    });
    stats.stdDev = std::sqrt(acc / (results.size() - 1));

    return stats;
}

} // namespace idm
