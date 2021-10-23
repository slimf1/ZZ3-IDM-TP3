#ifndef STATS_HPP
#define STATS_HPP

#include <vector>

namespace idm {

struct stats_t {
    double mean;
    double stdDev;
};

stats_t resultsStats(const std::vector<double>& results);

} // namespace idm

#endif // STATS_HPP
