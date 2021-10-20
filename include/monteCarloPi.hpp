#ifndef MONTECARLOPI_HPP
#define MONTECARLOPI_HPP

#include "CLHEP/Random/Randomize.h"
#include <string>

namespace idm {

struct pi_sim_result_t {
    double mean;
    double std_dev;
};

double pi_experiment(uint64_t points, CLHEP::HepRandomEngine& engine);
pi_sim_result_t pi_replications(uint64_t points, 
                                uint32_t replications);

} // namespace idm

#endif // MONTECARLOPI_HPP
