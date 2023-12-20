#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pendu.c"
#include "methode.c"
#include "propriete.c"


void run() {
    srand(time(NULL));
    char* mot = mot_aleatoire();
    char lettre_saisie[LONGUEUR_MAX_MOT] = "";
    int choix_incorrect = 0;

    while (choix_incorrect < ESSAI_MAX) {
        mot_cachee(mot, lettre_saisie);
        char choix = choix_utilisateur();
        int result = verifie_choix(mot, choix, lettre_saisie);

        if (result == 1) {
            strncat(lettre_saisie, &choix, 1);
        }
        else if (result == -1) {
            choix_incorrect++;
            pendu(choix_incorrect);
        }

        if (strspn(mot, lettre_saisie) == strlen(mot)) {
            printf("Félicitaion! vous avez découvert le mot secret !: %s\n", mot);
            break;
        }
    }

    if (choix_incorrect == ESSAI_MAX) {
        printf("Vous êtes mort!! (mot: %s)\n", mot);
    }
}

int main() {
    run();
    return 0;
}
