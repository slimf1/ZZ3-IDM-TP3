#ifndef MONTECARLOPI_HPP
#define MONTECARLOPI_HPP

#include "CLHEP/Random/Randomize.h"
#include "stats.hpp"
#include <string_view>

namespace idm {

double piExperiment(uint64_t points, CLHEP::HepRandomEngine& engine);
void loadPiExperimentFromFile(uint64_t points, const std::string& engineStatusFile, std::ostream& outputStream);
stats_t piReplications(uint64_t points, uint32_t replications);

} // namespace idm

#endif // MONTECARLOPI_HPP
