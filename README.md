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
* faire comparaison sync / threadé
utiliser les mots répétabilité, stochastique, 
* nous avons défini plsieurs modules pour séparer la logique de l'appication. 
Memes résultats : async/sync => repro

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


[2] 4405
[0] 6794
[12] 1288
[13] 384
[9] 7753
[3] 12328
[4] 11526
[6] 12042
[17] 8836
[16] 12195
[11] 10427
[21] 1948
[10] 11673
[20] 13599
[25] 5942
[5] 30829
[14] 7955
[8] 31881
[32] 5432
[28] 7985
[33] 4583
[1] 35192
[29] 9002
[30] 140
[23] 13043
[18] 38068
[27] 21066
[26] 25806
[22] 33301
[34] 16171
[19] 42167
[35] 610
[41] 1359
[40] 3003
[44] 8913
[7] 15622
[45] 7453
[42] 353
[37] 22619
[48] 5222
[46] 773
[36] 27277
[38] 25700
[39] 13787
[24] 68840
[47] 11989
[50] 3496
[43] 20287
[60] 628
[51] 5343
[57] 3156
[62] 7044
[64] 11804
[54] 20858
[61] 17843
[63] 8611
[59] 24279
[67] 8269
[58] 34307
[73] 4889
[68] 27256
[76] 14643
[75] 2298
[65] 32568
[81] 285
[70] 23192
[77] 12373
[85] 413
[74] 24238
[82] 3831
[78] 14011
[31] 62784
[15] 12222
[53] 5193
[88] 4473
[86] 17781
[80] 39622
[90] 4795
[91] 174
[83] 28870
[98] 1345
[87] 17810
[92] 5151
[49] 45120
[52] 25785
[89] 13594
[56] 50738
[96] 1577
[69] 51137
[99] 13631
[84] 46435
[97] 10330
[71] 10289
[93] 18748
[66] 57703
[55] 34596
[72] 37852
[79] 64139
[95] 32627
[94] 91779


Target = le ha
[9] 58428
[3] 659567
[6] 2404300
[5] 3955219
[4] 7213363
[7] 8411666
[2] 9702491
[0] 13465014
[8] 13924796
[1] 39354640