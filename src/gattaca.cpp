#include <iostream>
#include <set>
#include <mutex>
#include <vector>
#include <thread>
#include "CLHEP/Random/Randomize.h"
#include "monteCarloPi.hpp"

char randomCharFromString(std::string_view alphabet, CLHEP::HepRandomEngine& engine) {
    CLHEP::RandFlat aFlat(engine);
    return alphabet[aFlat.fireInt(0, alphabet.length())];
}

/* Retourne le nombre d'essais pour obtenir une phrase aléatoirement */
uint64_t randomStringTries(std::string_view target, std::string_view alphabet, int seed) {
    
    CLHEP::MTwistEngine engine(seed);
    std::stringstream ss;
    uint64_t count = 0u;
    const size_t targetSize = target.length(); 

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

    std::cout << "Target = '" << target << "'\n";

    for (i = 0; i < threadCount; ++i) {
        threads[i] = std::thread([](std::string_view target, std::string_view alphabet, uint32_t seed) {
            static std::mutex mutexPrint;
            auto tries = randomStringTries(target, alphabet, seed);
            std::lock_guard<std::mutex> guard(mutexPrint);
            std::cout << "[" << seed << "] " << tries << "\n";
            mutexPrint.unlock();
        }, target, alphabet, i);
    }

    for(auto& thread : threads) {
        thread.join();
    }

    std::cout << "\n\n";
}

int main() {
    std::stringstream asciiCharsetBuilder;

    for(char c = 'a'; c <= 'z'; ++c) {
        asciiCharsetBuilder << c;
    }
    asciiCharsetBuilder << "'" << " ";

    threadedExperiments("GATTACA", "AGCT", 100);
    threadedExperiments("le ha", asciiCharsetBuilder.str(), 10);

    return EXIT_SUCCESS;
}