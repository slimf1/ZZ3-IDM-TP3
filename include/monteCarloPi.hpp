#ifndef MONTECARLOPI_HPP
#define MONTECARLOPI_HPP

#include "CLHEP/Random/Randomize.h"
#include <string>

namespace idm {

struct pi_sim_result_t {
    double mean;
    double std_dev;
};

double piExperiment(uint64_t points, CLHEP::HepRandomEngine& engine);
void loadPiExperimentFromFile(uint64_t points, const std::string& engineStatusFile, std::ostream& outputStream);
pi_sim_result_t piReplications(uint64_t points, uint32_t replications);

} // namespace idm

#endif // MONTECARLOPI_HPP
