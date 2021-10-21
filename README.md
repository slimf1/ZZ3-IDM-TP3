# ZZ3-IDM-TP

## Introduction
Troisième TP d'ingénierie des modèles et simulation, basé sur la bibliothèque CLHEP.


## Compilation
Le projet requiert CMake version 2.8.9 ou plus pour la compilation.
Dans le dossier racine du projet, on compilera le projet avec les commandes suivantes :
```bash
mkdir build
cd build
cmake ..
make
```

## TODO-List
* Rapport
* Le reste
* Etendre ce readme
* faire des schémas pour les dernières questions, cf. cours pour expliquer le séquence splitting
* rapport : une partie par question
* expliquer l'archi du projet (les headers sont dans include, génère un exe par question...)
* utiliser l'entrée standard pour les inputs ! état du générateur etc
* montrer qu'on a le même résultats pour 10 replications avec & sans restoreStatus
* On a testé avec les fichiers de conf séparés d'un tirage, les résultats étaient similaire car l'état du générateur restait quasiment le même... 
Cependant, avec les fichiers de confs séparés d'un milliard, les résultats sont différents.
utiliser les mots répétabilité, stochastique, 

slfakani@turing:/mnt/local.isima.fr/slfakani/ZZ3-IDM-TP3/build$ ./simPiThreads mtstatus_2_{0..9}.conf 3.14154 mtstatus_2_4.conf
3.14161 mtstatus_2_7.conf
3.14159 mtstatus_2_6.conf
3.14163 mtstatus_2_1.conf
3.1415 mtstatus_2_9.conf
3.14158 mtstatus_2_2.conf
3.14173 mtstatus_2_0.conf
3.14154 mtstatus_2_8.conf
3.14166 mtstatus_2_5.conf
3.14151 mtstatus_2_3.conf
slfakani@turing:/mnt/local.isima.fr/slfakani/ZZ3-IDM-TP3/build$ ./simPiThreads mtstatus_2_{0..9^Cconf 

lfakani@turing:/mnt/local.isima.fr/slfakani/ZZ3-IDM-TP3/build$ ./simPiThreads mtstatus{0..9}.conf 
3.14158 mtstatus1.conf
3.14158 mtstatus2.conf
3.14158 mtstatus7.conf
3.14158 mtstatus0.conf
3.14158 mtstatus3.conf
3.14158 mtstatus6.conf
3.14158 mtstatus9.conf
3.14158 mtstatus5.conf
3.14158 mtstatus4.conf
3.14158 mtstatus8.conf
slfakani@turing:/mnt/local.isima.fr/slfakani/ZZ3-IDM-TP3/build$ ^C

Expliquer les méthodes utilisées dans chaque fonction (eg. split q4,q5)
cf cours
