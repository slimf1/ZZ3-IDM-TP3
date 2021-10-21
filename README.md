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
