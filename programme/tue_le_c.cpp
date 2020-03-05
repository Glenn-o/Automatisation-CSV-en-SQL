#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<windows.h> 
#include <string.h>
#define TAILLE_MAX 1000
#pragma warning(disable : 4996);
int replacechar(char* str, char orig, char rep);

int main(int argc, char argv[])
{
    int continuer = 0;
    do {
        FILE* fichier = NULL;
        FILE* script = NULL;
        FILE* erreur = NULL;
        fichier = fopen("tue_le_c.csv", "r");
        script = fopen("script.sql", "w");
        char chaine[TAILLE_MAX] = "";
        char virgule = ',';
        char point = '.';
        char point_virgule = ';';
        int choix = 0;
        printf("-------------Bienvenue sur l'algorithme qui converti vos fichier CSV en requètes SQL-------------\n\n");
        printf("Mettez le fichier .CSV dans le meme dossier que le fichier 'tue_le_c.cpp'\n");
        printf("1 - Convertir le fichier\n");
        printf("2 - Partir\n");
        int retour = scanf("%d", &choix);
        if (retour == 0) {
            erreur = fopen("erreur.txt", "a");
            fprintf(erreur, "ERREUR : Une touche autre que [1]ou [2] a été rentré;\n");
            fclose(erreur);
            printf("\n");
            printf("Une touche autre que [1] ou [2] a ete rentre");
            printf("\n");
            exit(0);
        };
        switch (choix) {
        case 1:
            if (fichier != NULL)
            {
                while (fgets(chaine, TAILLE_MAX, fichier) != NULL) {
                    replacechar(chaine, virgule, point);
                    replacechar(chaine, point_virgule, virgule);
                    fprintf(script, "INSERT INTO produit(pr_codebarre,pr_refour,pr_desi,pr_prix_achat,pr_prix_vente,pr_pack,FK_model_marque,FK_marque) VALUES (%s);\n", chaine);
                }
                fclose(fichier);
                fclose(script);
                printf("\n\n------------ Le script a ete cree avec succes !!! ------------\n\n");
                continuer = 1;
            }
            else
            {
                printf("\nLe fichier n'a pas ete trouve !\n\n");
                erreur = fopen("erreur.txt", "a");
                fprintf(erreur, "ERREUR : Le fichier n'a pas été retrouvé;\n");
                fclose(erreur);
            };
        break;
        case 2:
            continuer = 1;
        break;
        default:
            printf("\n");
            printf("veuillez rentrez soit [1] soit [2] comme valeur\n");
            printf("\n");
        break;
        }
    } while (continuer == 0);
    
};

int replacechar(char* str, char orig, char rep) {
    char* ix = str;
    int n = 0;
    while ((ix = strchr(ix, orig)) != NULL) {
        *ix++ = rep;
        n++;
    }
    return n;
}
 