#include <iostream>
#include <set>
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
        // if (count % 1000 == 0) {
        //     std::cout << ss.str() << "\n";
        // }
    } while (ss.str() != target);

    return count;
}

int main() {
    const int threadCount = 10;
    std::stringstream asciiCharsetBuilder;
    std::string asciiCharset;
    std::vector<std::thread> threads(threadCount);

    for(char c = 'a'; c <= 'z'; ++c) {
        asciiCharsetBuilder << c;
    }
    asciiCharsetBuilder << "'" << " ";
    asciiCharset = asciiCharsetBuilder.str();

    for(int i = 0; i < 100; ++i) {
        // std::cout << randomStringTries("GATTACA", "AGCT") << "\n";
    }

    for(int i = 0; i < 1; ++i) {
        // std::cout << randomStringTries("le hasard n'ecrit pas de programme ou de genes", asciiCharset);
    }

    for(int i = 0; i < threadCount; ++i) {
        // Init avec un fichier différent
        // threads[i] = std::thread(randomStringTries, "le hasard n'ecrit pas de programme ou de genes", asciiCharset, i);
        threads[i] = std::thread([&](std::string_view s, std::string_view alphabet, int seed) {
            std::cout << randomStringTries(s, alphabet, seed) << "\n";
        }, "le ha", asciiCharset, i);
    }

    for(auto& thread : threads) {
        thread.join();
    }

    // std::cout << asciiCharset;
}