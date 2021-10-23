#include "monteCarloPi.hpp"
#include <iostream>
#include "CLHEP/Random/Randomize.h"


char peptideGen(CLHEP::HepRandomEngine & engine){
    CLHEP::RandFlat aFlat(engine);
    
    double x = aFlat.fire();
    double distrib[] = {0.25, 0.5, 0.75, 1};
    char chars[] = {'A', 'G', 'T', 'C'};

    uint16_t i = 0;
    while(i < 4 && x > distrib[i]){
        i++;
    }
    return chars[i];
}

uint64_t Func1(const std::string & target, CLHEP::HepRandomEngine & engine){
    std::stringstream ss;
    uint64_t count = 0;
    do{
        ss.str(""); 
        for(uint16_t i=0; i<7; i++){
            ss << peptideGen(engine);
        }
        count++;
        // if(count%100==0){
        //     std::cout << "\t" << count << ss.str() << "\n";
        // }
    }while(ss.str() != target);

    return count;
}


char asciiGen(CLHEP::HepRandomEngine & engine){
    CLHEP::RandFlat aFlat(engine);
    double x = aFlat.fire();
    // [0,1] - > [65,122]
    char c = static_cast<int>(x * 57 + 65);
    // std::cout << x << " " << x * 61 + 65 << "\n";
    // std::cout << static_cast<int>(x * 61 + 65) << " "<< c << "\n"
    return c;
}





uint64_t Func2(const std::string & target, CLHEP::HepRandomEngine & engine, uint16_t targetSize){
    std::stringstream ss;
    uint64_t count = 0;
    do{
        ss.str(""); 
        for(uint64_t i=0; i<targetSize; i++){
            ss << asciiGen(engine);
        }
        count++;
        if(count%10000==0){
            std::cout << "\t" << count/10000 << "\n";
        }
    }while(ss.str() != target);
    std::cout << "\n\n\n" << ss.str() << "\n";
    return count;
}



int main() {
    CLHEP::MTwistEngine mtEngine;
    uint64_t N = 5e3+10;
    // uint64_t summ = 0;
    // uint64_t nb;

    // Gen of GATTACA
    // for(uint64_t i=0; i<N; i++){
    //     nb = Func1("GATTACA", mtEngine, 7);
    //     // std::cout << nb << "\n";
    //     summ+=nb;
    // }
    // std::cout << static_cast<double>(summ)/N << "\n";

    // Gen of ascii char
    std::string s = "Le hasard n’écrit pas de programmes ou de gènes";
    for(uint64_t i=0; i<1; i++){
        Func2(s, mtEngine, 47);
    }

    

}