#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct noeud {
	double info ;
	struct noeud * suiv ;
	} T_noeud ;

typedef struct{
	float* USAGE_OF_BACKING_FILM ;
	float* USAGE_OF_DRESSER ;
	float* USAGE_OF_POLISHING_TABLE ;
	float* USAGE_OF_DRESSER_TABLE ;
	float* PRESSURIZED_CHAMBER_PRESSURE ;
	float* MAIN_OUTER_AIR_BAG_PRESSURE ;
	float* CENTER_AIR_BAG_PRESSURE ;
	float* RETAINER_RING_PRESSURE ;
	float* RIPPLE_AIR_BAG_PRESSURE ;
	float* USAGE_OF_MEMBRANE ;
	float* USAGE_OF_PRESSURIZED_SHEET ;
	float* SLURRY_FLOW_LINE_A ;
	float* SLURRY_FLOW_LINE_B ;
	float* SLURRY_FLOW_LINE_C ;
	float* WAFER_ROTATION ;
	float* STAGE_ROTATION ;
	float* HEAD_ROTATION ;
	float* DRESSING_WATER_STATUS ;
	float* EDGE_AIR_BAG_PRESSURE ;
} dataset_st ;	// structure de pointeurs, afin d'en faire des listes avec malloc

typedef struct{
	double tab[250000] ;
	int taille ;
	} Colonne ;

typedef struct{
    double moy ;
    double min ;
    double max ;
    double e_type ;
    double med ;
    double quar1 ;
    double quar3 ;
	} Donnees ;

#define NB_ELEMENTS 10000
#define nbColonnes 25

double moyenne(double tab[], int taille) ;
double minimum(double tab[], int taille) ;
double maximum(double tab[], int taille) ;
double ecart_type(double tab[], int taille) ;
void fusionner( double T[], int d, int m, int f) ;
void Tri_fusion(double T[], int i, int j) ;
double mediane(double tab[], int taille) ;
double quartile1(double tab[], int taille) ;
double quartile3(double tab[], int taille) ;
Donnees donnees(double tab[], int taille) ;
char *Nom_Fichier(int i) ;
void insertion_liste(double info, T_noeud *tete) ;
void conv_tab_to_listech(Colonne col, T_noeud *tete) ;
void tri_liste(Colonne col, int k, T_noeud *tete) ;
Colonne conv_liste_to_tab(T_noeud *tete) ;
Colonne tri_tab(T_noeud * tete, Colonne col, int k) ;
int tri_liste2(double tabl[], int k, int Nblignes) ;
void copie_tab(double tab_deb[], double tab_fin[], int idebut, int ifin) ;
void lecture_fichierq4(double tab_1[], double tab_2[], double tab_3[], double tab_4[], double tab_5[], double tab_6[], double tab_7[], double tab_8[], double tab_9[], double tab_10[], double tab_11[], double tab_12[], double tab_13[], double tab_14[], double tab_15[], double tab_16[], double tab_17[], double tab_18[], double tab_19[], double wafer_id[]) ;
void histogramme(double tab[], int Nblignes) ;

/* Fonctions pour la Q1 */

double moyenne(double tab[], int taille){
	double moy = 0 ;
	for (int i = 0 ; i < taille ; i++){                            
		moy+ = tab[i] ;
		}
	return moy/taille ;
	}

/*----------------------------------------------------------------------*/

double minimum(double tab[], int taille){
	double min = tab[0] ;
	for (int i = 0 ; i < taille ; i++){
    	if (tab[i] <= min){
        	min = tab[i] ;
    		}
		}
	return min ;
	}

/*----------------------------------------------------------------------*/

double maximum(double tab[], int taille){
	double maxtab[0] ;
	for (int i = 0 ; i<taille ; i++){
    	if (tab[i]> = max){
        	max = tab[i] ;
			}
		}
	return max ;
	}

/*----------------------------------------------------------------------*/

double ecart_type(double tab[], int taille){
	double moy ;
	double moy2 ;
	double somme ;
	double ecart_type ;
	double tab1[taille] ;
	moy = moyenne(tab, taille) ;
	somme = 0 ;
	for(int i = 0 ; i<taille ; i++){
    	tab1[i] = tab[i]*tab[i] ;
    	somme+ = tab1[i] ;
		}
	moy2 = somme/taille ;
	ecart_type = sqrt(moy2-moy*moy) ;
	return ecart_type ;
	}
    
#define SIZE 250000

void fusionner(double T[], int d, int m, int f){
	double R[SIZE] ;	// de base c'est m-d, mais ça fonctionne pas de créer un tableau avec une taille étant les arguments, donc on met une grande taille de tableau
	for (int i = d ; i <= m ; i++){
		R[i] = T[i] ;
		}
	for (int j = m+1 ; j<= f ; j++){
		R[j] = T[f+m+1-j] ; 
		}
	int i = d ;
	int j = f ;
	for (int k = d ; k<= f ; k++){
		if (R[i]<R[j]){
			T[k] = R[i] ;
			i+ = 1 ;
			}
		else{
			T[k] = R[j] ;
			j- = 1 ;
			}
		}
	}

void Tri_fusion(double T[], int i, int j){
	int n = j-i+1 ;
	if (n>1){
		Tri_fusion(T, i, i+n/2-1) ;
		Tri_fusion(T, i+n/2, j) ;
		fusionner(T, i, i+n/2-1, j) ;
		}
	}

double mediane(double tab[], int taille){
	Tri_fusion(tab, 0, taille-1) ;
	if(taille%2 == 0){
    	return((tab[taille/2]+tab[taille/2-1])/2) ;
		}
	else{
    	return(tab[(taille)/2]) ;
		}
	}

double quartile1(double tab[], int taille){
	Tri_fusion(tab, 0, taille-1) ;
	double q ;
	int N ;
	if(taille%4 == 0){
    	N = taille/4 ;
    	q = tab[N-1] ;
		}
	else{
    	N = (taille/4)+1 ;
    	q = tab[N-1] ;
		}
	return q ;
	}
    
double quartile3(double tab[], int taille){
	Tri_fusion(tab, 0, taille-1) ;
	double q ;
	int N ;
	if(taille%4 == 0){
    	N = 3*taille/4 ;
    	q = tab[N-1] ;
		}
	else{
    	N = 3*taille/4+1 ;
    	q = tab[N-1] ;
		}
	return q ;
	}

/* Fonctions pour la Q2 */

int tri_liste2(double tabl[], int k, int Nblignes){
	Colonne col ;
	col.taille = Nblignes ;
	for (int t = 0 ; t<col.taille ; t++){
  		col.tab[t] = tabl[t] ;
		}
	double ecart = ecart_type(col.tab, col.taille) ;
	double moy = moyenne(col.tab, col.taille) ;
	int fin ;
	int i = 0 ;
	while(i<col.taille){
  		if (col.tab[i]< moy-k*ecart || col.tab[i]>moy+k*ecart){
  			fin = col.tab[i] ;
  			col.tab[i] = col.tab[col.taille-1] ;
  			col.tab[col.taille-1] = fin ;
  			col.taille-- ;
			i-- ;
			}
		i++ ;
		}
  	printf("Nous avons enlevée les elements %d \n",(Nblignes-col.taille)) ;
	for (int t = 0 ; t<col.taille ; t++){
  		tabl[t] = col.tab[t] ;
		}
	return col.taille ;
	}

/* Fonctions pour la Q3 */

void histogramme(double tab[], int Nblignes){
	double m = minimum(tab,Nblignes) ;
    double M = maximum(tab,Nblignes) ;
    double inter = (M-m)/5 ;
    Tri_fusion(tab,0,Nblignes) ;
    int tableau_inter[4] = {0,0,0,0} ;
    int j = 0 ;
    for(int i = 0 ; i<4 ; i++){
		if(i<4){
			tableau_inter[i] = tableau_inter[i-1] ;
			}
        while(tab[j]<= m+i*inter){
            tableau_inter[i] = j ;
            j = j+1 ;
        	}
    	}
    double f0 ;
    f0 = (double)tableau_inter[0]/Nblignes ;
    double f1 ;
    f1 = (double)tableau_inter[1]/Nblignes -f0 ;
    double f2 ;
    f2 = (double)tableau_inter[2]/Nblignes-f0-f1 ;
    double f3 ;
    f3 = (double)tableau_inter[3]/Nblignes-f0-f1-f2 ;
    double f4 = 1-f0-f1-f2-f3 ;
    f0 = round(f0*100) ;
    f1 = round(f1*100) ;
    f2 = round(f2*100) ;
    f3 = round(f3*100) ;
    f4 = round(f4*100) ;
    for(int i = 0 ; i<f0 ; i++){
    	printf("*") ;
		}
	printf(" %lf ", f0) ;
    printf("\n") ;
    for(int i = 0 ; i<f1 ; i++){
    	printf("*") ;
		}
	printf(" %lf ", f1) ;
    printf("\n") ;
    for(int i = 0 ; i<f2 ; i++){
    	printf("*") ;
		}
	printf(" %lf ", f2) ;
    printf("\n") ;
    for(int i = 0 ; i<f3 ; i++){
    	printf("*") ;
		}
	printf(" %lf ", f3) ;
    printf("\n") ;
    for(int i = 0 ; i<f4 ; i++){
    	printf("*") ;
		}
	printf(" %lf ", f4) ;
    printf("\n\n") ;
	}

/* Fonctions pour la Q4 */

void copie_tab(double tab_deb[], double tab_fin[], int idebut, int ifin){
	for(int i = idebut ; i<ifin+1 ; i++){
		tab_fin[i-idebut] = tab_deb[i] ;
		}
	}

void lecture_fichierq4(double tab_1[], double tab_2[], double tab_3[], double tab_4[], double tab_5[], double tab_6[], double tab_7[], double tab_8[], double tab_9[], double tab_10[], double tab_11[], double tab_12[], double tab_13[], double tab_14[], double tab_15[], double tab_16[], double tab_17[], double tab_18[], double tab_19[], double wafer_id[]){
	int idebut = 0 ;
	int ifin = 0 ;
	double tab_temp[5000] ;
	double tab_moyenne[19] ;
	FILE *fp ;
	long i = 0 ;
	int k ;
	char fichier[21] ;
	for(k = 0 ; k<59 ; k++){
		if(k<10){
			sprintf(fichier, "CMP-training-00%d.csv", k) ;
			}
		else(sprintf(fichier, "CMP-training-0%d.csv", k)) ;
		// printf("%s \n", fichier) ;
		fp = fopen(fichier, "r") ; 
		// printf("lecture du fichier numero %d \n", k) ;
		fscanf(fp, "%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s") ;
		while((fscanf(fp, "%*d%*d%*lf%lf%*s%*lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf", &wafer_id[i], &tab_1[i], &tab_2[i], &tab_3[i], &tab_4[i], &tab_5[i], &tab_6[i], &tab_7[i], &tab_8[i], &tab_9[i], &tab_10[i], &tab_11[i], &tab_12[i], &tab_13[i], &tab_14[i], &tab_15[i], &tab_16[i], &tab_17[i], &tab_18[i], &tab_19[i])) == 20){
			if(wafer_id[i] !=  wafer_id[idebut]){
				ifini-1 ;
				copie_tab(tab_1, tab_temp, idebut, ifin) ;
				tab_moyenne[0] = moyenne(tab_temp, ifin-idebut) ;
				copie_tab(tab_2, tab_temp, idebut, ifin) ;
				tab_moyenne[1] = moyenne(tab_temp, ifin-idebut) ;
				copie_tab(tab_3, tab_temp, idebut, ifin) ;
				tab_moyenne[2] = moyenne(tab_temp, ifin-idebut) ;
				copie_tab(tab_4, tab_temp, idebut, ifin) ;
				tab_moyenne[3] = moyenne(tab_temp, ifin-idebut) ;
				copie_tab(tab_5, tab_temp, idebut, ifin) ;
				tab_moyenne[4] = moyenne(tab_temp, ifin-idebut) ;
				copie_tab(tab_6, tab_temp, idebut, ifin) ;
				tab_moyenne[5] = moyenne(tab_temp, ifin-idebut) ;
				copie_tab(tab_7, tab_temp, idebut, ifin) ;
				tab_moyenne[6] = moyenne(tab_temp, ifin-idebut) ;
				copie_tab(tab_8, tab_temp, idebut, ifin) ;
				tab_moyenne[7] = moyenne(tab_temp, ifin-idebut) ;
				copie_tab(tab_9, tab_temp, idebut, ifin) ;
				tab_moyenne[8] = moyenne(tab_temp, ifin-idebut) ;
				copie_tab(tab_10, tab_temp ,idebut, ifin) ;
				tab_moyenne[9] = moyenne(tab_temp, ifin-idebut) ;
				copie_tab(tab_11, tab_temp, idebut, ifin) ;
				tab_moyenne[10] = moyenne(tab_temp, ifin-idebut) ;
				copie_tab(tab_12, tab_temp, idebut, ifin) ;
				tab_moyenne[11] = moyenne(tab_temp, ifin-idebut) ;
				copie_tab(tab_13, tab_temp, idebut, ifin) ;
				tab_moyenne[12] = moyenne(tab_temp, ifin-idebut) ;
				copie_tab(tab_14, tab_temp, idebut, ifin) ;
				tab_moyenne[13] = moyenne(tab_temp, ifin-idebut) ;
				copie_tab(tab_15, tab_temp, idebut, ifin) ;
				tab_moyenne[14] = moyenne(tab_temp, ifin-idebut) ;
				copie_tab(tab_16, tab_temp, idebut, ifin) ;
				tab_moyenne[15] = moyenne(tab_temp, ifin-idebut) ;
				copie_tab(tab_17, tab_temp, idebut, ifin) ;
				tab_moyenne[16] = moyenne(tab_temp, ifin-idebut) ;
				copie_tab(tab_18, tab_temp, idebut, ifin) ;
				tab_moyenne[17] = moyenne(tab_temp, ifin-idebut) ;
				copie_tab(tab_19, tab_temp, idebut, ifin) ;
				tab_moyenne[18] = moyenne(tab_temp, ifin-idebut) ;
				FILE *new_fich ;
				new_fich = fopen("StatistiquesWafer.txt", "a") ;
				fprintf(new_fich, "Wafer ID :\t%lf\n ", wafer_id[idebut]) ;
				fprintf (new_fich, "Moyenne \n") ;
  				for (int i0 ; i < 19 ; i ++){ // ecriture du tableau
					fprintf(new_fich , "%lf \t " , tab_moyenne[i]) ;
					}
				fprintf(new_fich,"\n") ;
				idebut = i ;
				}
			i++ ;
			}
		// printf("nombre de lignes %d \n", i) ;
		fclose(fp) ;
		}
	}

/* Fonctions non utilisées */

Donnees donnees(double tab[], int taille){
    Donnees p ;
    p.moy = moyenne(tab, taille) ;
    p.min = minimum(tab, taille) ;
    p.max = maximum(tab, taille) ;
    p.e_type = ecart_type(tab, taille) ;
    p.med = mediane(tab, taille) ;
    p.quar1 = quartile1(tab, taille) ;
    p.quar3 = quartile3(tab, taille) ;
    return p ;
	}

char *Nom_Fichier(int i){      	// fonction qui permat de choisir le nom du fichier celon son numéros 
	char num[100] = "" ;			// chaine de caractere qui contiendra le numéros i
	char Nom[50] = "" ;			// chaine dde caractere qui contiendra le nom du fichier
	sprintf(num, "%d", i) ;		// sprintf permet de convertir le int i en str puis le met dans num
	if(i<10){					// il faut dissocier le cas ou il y a un seul chiffre et celui où il y en a deux
		strcat(Nom, "CMP-training-00") ;	// strcat rajoute au char Nom la chaine de caracteres "CMP-training-00" 
		}						
	else{
		strcat(Nom, "CMP-training-0") ;
		}
	strcat(strcat(Nom, num), ".csv") ;	
	printf("%s\n",Nom) ;	// concatenation avec num puis ".csv"
	char* Nomf = Nom ;
	return Nomf ;
	}

void conv_tab_to_listech(Colonne col, T_noeud *tete){
	int i = 0 ;
	for(i = 0 ; i<col.taille ; i++){
		insertion_liste(col.tab[i], tete) ;
		}
	}

void insertion_liste(double info, T_noeud *tete){
	T_noeud *nouveau ;
	nouveau = (T_noeud *)malloc(sizeof(T_noeud)) ;
	nouveau->info = info ;
	nouveau->suiv = tete ;
	tete = nouveau ;
	}

void tri_liste(Colonne col, int k, T_noeud *tete){
	double ecarttype = ecart_type(col.tab, col.taille) ;
	T_noeud *prec ;
	prec = (T_noeud *)malloc(sizeof(T_noeud)) ;
	prec = NULL ;
	T_noeud *courant ;
	courant = (T_noeud *)malloc(sizeof(T_noeud)) ;
	courant = tete ;
	while(courant !=  NULL){
		if(courant->info < -k*ecarttype || courant->info>k*ecarttype){
			if (prec !=  NULL){
     			prec->suiv = courant->suiv ;
				}
    		else{	// prec vaut NULL> le compte a supprimer est le premier
      			tete = courant->suiv ;
				}
			}
		prec = courant ;
		courant = courant->suiv ;
		}
	}

Colonne conv_liste_to_tab(T_noeud *tete){
	Colonne col ;
	col.taille = 0 ;
	T_noeud *courant ;
	courant = tete ;
	while (courant != NULL){
		col.tab[col.taille] = courant->info ;
		col.taille++ ;
		courant = courant->suiv ;
		}
	return col ;
	}

Colonne tri_tab(T_noeud * tete, Colonne col, int k){
	conv_tab_to_listech(col,tete) ;
	tri_liste(col,k,tete) ;
	return conv_liste_to_tab(tete) ;
	}