#include <iostream>
#include <set>
#include <mutex>
#include <vector>
#include <thread>
#include "CLHEP/Random/Randomize.h"
#include "monteCarloPi.hpp"

/**
 * Caractère aléatoire d'une chaîne de caractères.
 * 
 * @param alphabet Chaîne d'entrée
 * @param engine PRNG pour l'aléatoire
 * @return Caractère aléatoire tiré dans la chaîne 
 */
char randomCharFromString(std::string_view alphabet, CLHEP::HepRandomEngine& engine) {
    CLHEP::RandFlat aFlat(engine);
    return alphabet[aFlat.fireInt(0, alphabet.length())];
}

/* Retourne le nombre d'essais pour obtenir une phrase aléatoirement */
/**
 * Nombre d'essais pour obtenir une chaîne aléatoirement
 * 
 * @param target La chaîne cible à obtenir
 * @param alphabet La liste des caractères disponible
 * @param seed La graine du générateur pseudo-aléatoire
 * @return Le nombre d'essais pour obtenir la chaîne
 */
uint64_t randomStringTries(std::string_view target, std::string_view alphabet, int seed) {
    
    const size_t targetSize = target.length(); // Longueur de la chaîne cible
    CLHEP::MTwistEngine engine(seed);          // PRNG
    std::stringstream ss;                      // Builder de la chaîne
    uint64_t count = 0u;                       // Nombre d'essais courants

    do {
        ss.str(""); // Réinit. du stream
        for(uint32_t i = 0u; i < targetSize; ++i) {
            ss << randomCharFromString(alphabet, engine);
        }
        ++count;
    } while (ss.str() != target);

    return count;
}

void threadedExperiments(std::string_view target, std::string_view alphabet, uint32_t threadCount) {
    
    std::vector<std::thread> threads(threadCount);
    uint32_t i;
    std::vector<double> results(threadCount);
    idm::stats_t experimentResults;

    std::cout << "Target = '" << target << "'\n";

    for (i = 0; i < threadCount; ++i) {
        threads[i] = std::thread([&](std::string_view target, std::string_view alphabet, uint32_t seed) {
            static std::mutex mutexPrint;
            auto tries = randomStringTries(target, alphabet, seed);
            std::lock_guard<std::mutex> guard(mutexPrint);
            std::cout << "[" << seed << "] " << tries << "\n";
            results[seed] = tries;
            mutexPrint.unlock();
        }, target, alphabet, i);
    }

    for(auto& thread : threads) {
        thread.join();
    }

    experimentResults = idm::resultsStats(results);
    std::cout << "Mean = " << experimentResults.mean << ", "
              << "Stdev = " << experimentResults.stdDev << "\n\n"; 
}

int main() {
    std::stringstream asciiCharsetBuilder;

    for(char c = 'a'; c <= 'z'; ++c) {
        asciiCharsetBuilder << c;
    }
    asciiCharsetBuilder << "'" << " ";

    threadedExperiments("GATTACA", "AGCT", 300);
    threadedExperiments("le ha", asciiCharsetBuilder.str(), 10);

    return EXIT_SUCCESS;
}