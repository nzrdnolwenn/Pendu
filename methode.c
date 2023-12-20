#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "propriete.c"

char* mot_aleatoire() {
    char* liste_mots[MOT_MAX] = {"acrobatique", "bouillonnement", "catastrophique", "delicatement", "efficacement", "fantastiquement", "genereusement", "harmonieusement", "illuminer", "jubilation", "kangourou", "luminescent", "merveilleusement", "nuageux", "oxygene", "precieusement", "quadrilatere", "rhapsodie", "sensationnel", "tenebreux"};
    int i = rand() % MOT_MAX;
    return liste_mots[i];
}

void mot_cache(char* mot, char* lettre_saisie) {
    for (int i = 0; i < strlen(mot); i++) {
        if (strchr(lettre_saisie, mot[i]) != NULL) {
            printf("%c ", mot[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

char choix_utilisateur() {
    char choix;
    printf("Entrez une lettre ->  ");
    scanf(" %c", &choix);
    return choix;
}

int verifie_choix(char* mot, char choix, char* lettre_saisie) {
    if (strchr(lettre_saisie, choix) != NULL) {
        printf("Lettre déjà trouver.\n");
        return 0;
    } else if (strchr(mot, choix) != NULL) {
        printf("Lettre correcte!\n");
        return 1;
    } else {
        printf("Lettre incorrecte!\n");
        return -1;
    }
}