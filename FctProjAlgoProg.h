#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    double moy ;
    double min ;
    double max ;
    double e_type ;
    double med ;
    double quar1 ;
    double quar3 ;
    } Donnees ;

typedef struct noeud {
    double info ;
    struct noeud *suiv ;
    } T_noeud ;

typedef struct{
    double tab[250000] ;
    int taille ;
    } Colonne ;

double moyenne(double tab[], int taille) ;
double minimum(double tab[], int taille) ;
double maximum(double tab[], int taille) ;
double ecart_type(double tab[], int taille) ;
void fusionner( double T[], int d, int m, int f) ;
void Tri_fusion(double T[], int i, int j) ;
double mediane(double tab[], int taille) ;
double quartile1(double tab[], int taille) ;


Donnees donnees(double tab[], int taille) ;
double quartile3(double tab[], int taille) ;
char *Nom_Fichier(int i) ;
void insertion_liste(double info, T_noeud *tete) ;
void conv_tab_to_listech(Colonne col, T_noeud *tete) ;
void tri_liste(Colonne col,int k, T_noeud *tete) ;
Colonne conv_liste_to_tab(T_noeud *tete) ;
Colonne tri_tab(T_noeud * tete, Colonne col, int k) ;
int tri_liste2(double tabl[], int k, int Nblignes) ;
void copie_tab(double tab_deb[], double tab_fin[], int idebut, int ifin) ;
void lecture_fichierq4(double tab_1[], double tab_2[], double tab_3[], double tab_4[], double tab_5[], double tab_6[], double tab_7[], double tab_8[], double tab_9[], double tab_10[], double tab_11[], double tab_12[], double tab_13[], double tab_14[], double tab_15[], double tab_16[], double tab_17[], double tab_18[], double tab_19[], double wafer_id[]) ;
void histogramme(double tab[], int Nblignes) ;