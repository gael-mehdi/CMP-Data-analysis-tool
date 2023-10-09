#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "FctProjAlgoProg.h"

int lireFichier(double tab_1[], double tab_2[], double tab_3[], double tab_4[], double tab_5[], double tab_6[], double tab_7[], double tab_8[], double tab_9[], double tab_10[], double tab_11[], double tab_12[], double tab_13[], double tab_14[], double tab_15[], double tab_16[], double tab_17[], double tab_18[], double tab_19[], double tab_time[]) ;
T_noeud *tete = NULL ;
 
int main(void){
	int Nblignes ;
  	int Nbl1 ;
  	int Nbl2 ;
  	int Nbl3 ;
  	int Nbl4 ;
  	int Nbl5 ;
  	int Nbl6 ;
  	int Nbl7 ;
  	int Nbl8 ;
  	int Nbl9 ;
  	int Nbl10 ;
  	int Nbl11 ;
  	int Nbl12 ;
  	int Nbl13 ;
  	int Nbl14 ;
  	int Nbl15 ;
  	int Nbl16 ;
  	int Nbl17 ;
  	int Nbl18 ;
  	int Nbl19 ;
  	double total_time ;
  	double tab_moyenne[19] ;
  	double tab_max[19] ;
  	double tab_min[19] ;
  	double tab_ecart_type[19] ;
  	double tab_mediane[19] ;
  	double tab_quartile1[19] ;
  	double tab_quartile3[19] ;
  	double *tab_wafer = malloc(sizeof(*tab_wafer)*250000) ;
  	double *tab_1 = malloc(sizeof(*tab_1)*250000) ;
  	double *tab_2 = malloc(sizeof(*tab_2)*250000) ;
  	double *tab_3 = malloc(sizeof(*tab_3)*250000) ;
  	double *tab_4 = malloc(sizeof(*tab_4)*250000) ;
  	double *tab_5 = malloc(sizeof(*tab_5)*250000) ;
  	double *tab_6 = malloc(sizeof(*tab_6)*250000) ;
  	double *tab_7 = malloc(sizeof(*tab_7)*250000) ;
  	double *tab_8 = malloc(sizeof(*tab_8)*250000) ;
  	double *tab_9 = malloc(sizeof(*tab_9)*250000) ;
  	double *tab_10 = malloc(sizeof(*tab_10)*250000) ;
  	double *tab_11 = malloc(sizeof(*tab_11)*250000) ;
  	double *tab_12 = malloc(sizeof(*tab_12)*250000) ;
  	double *tab_13 = malloc(sizeof(*tab_13)*250000) ;
  	double *tab_14 = malloc(sizeof(*tab_14)*250000) ;
  	double *tab_15 = malloc(sizeof(*tab_15)*250000) ;
  	double *tab_16 = malloc(sizeof(*tab_16)*250000) ;
  	double *tab_17 = malloc(sizeof(*tab_17)*250000) ;
  	double *tab_18 = malloc(sizeof(*tab_18)*250000) ;
  	double *tab_19 = malloc(sizeof(*tab_19)*250000) ;
  	double *tab_time = malloc(sizeof(*tab_time)*250000) ;
  	int rep ;

  	Nblignes = lireFichier(tab_1, tab_2, tab_3, tab_4, tab_5, tab_6, tab_7, tab_8, tab_9, tab_10, tab_11, tab_12, tab_13, tab_14, tab_15, tab_16, tab_17, tab_18, tab_19, tab_time) ;

  	printf(" => Pour la question 1, entrer 1\n => Pour la question 2, entrer 2\n => Pour la question 3, entrer 3\n => Pour la question 4, entrer 4\n: ") ;
  	scanf("%d", &rep) ;

  	if(rep == 1){
		
  		Nblignes = lireFichier(tab_1, tab_2, tab_3, tab_4, tab_5, tab_6, tab_7, tab_8, tab_9, tab_10, tab_11, tab_12, tab_13, tab_14, tab_15, tab_16, tab_17, tab_18, tab_19, tab_time) ;

  		/*--------------------------------------------------------*/// 1
  		
		tab_moyenne[0] = moyenne(tab_1, Nblignes) ;
  		tab_max[0] = maximum(tab_1, Nblignes) ;
  		tab_min[0] = minimum(tab_1, Nblignes) ;
  		tab_ecart_type[0] = ecart_type(tab_1, Nblignes) ;
  		tab_mediane[0] = mediane(tab_1, Nblignes) ;
  		tab_quartile1[0] = quartile1(tab_1, Nblignes) ;
  		tab_quartile3[0] = quartile3(tab_1, Nblignes) ;

  		/*--------------------------------------------------------*/// 2

  		tab_moyenne[1] = moyenne(tab_2,Nblignes) ;
  		tab_max[1] = maximum(tab_2,Nblignes) ;
  		tab_min[1] = minimum(tab_2,Nblignes) ;
  		tab_ecart_type[1] = ecart_type(tab_2,Nblignes) ;
  		tab_mediane[1] = mediane(tab_2,Nblignes) ;
  		tab_quartile1[1] = quartile1(tab_2,Nblignes) ;
  		tab_quartile3[1] = quartile3(tab_2,Nblignes) ;

  		/*--------------------------------------------------------*/// 3

  		tab_moyenne[2] = moyenne(tab_3, Nblignes) ;
  		tab_max[2] = maximum(tab_3, Nblignes) ;
  		tab_min[2] = minimum(tab_3, Nblignes) ;
  		tab_ecart_type[2] = ecart_type(tab_3, Nblignes) ;
  		tab_mediane[2] = mediane(tab_3, Nblignes) ;
  		tab_quartile1[2] = quartile1(tab_3, Nblignes) ;
  		tab_quartile3[2] = quartile3(tab_3, Nblignes) ;

  		/*--------------------------------------------------------*/// 4

  		tab_moyenne[3] = moyenne(tab_4, Nblignes) ;
  		tab_max[3] = maximum(tab_4, Nblignes) ;
  		tab_min[3] = minimum(tab_4, Nblignes) ;
  		tab_ecart_type[3] = ecart_type(tab_4, Nblignes) ;
  		tab_mediane[3] = mediane(tab_4, Nblignes) ;
  		tab_quartile1[3] = quartile1(tab_4, Nblignes) ;
  		tab_quartile3[3] = quartile3(tab_4, Nblignes) ;

  		/*--------------------------------------------------------*/// 5	

  		tab_moyenne[4] = moyenne(tab_5, Nblignes) ;
  		tab_max[4] = maximum(tab_5, Nblignes) ;
  		tab_min[4] = minimum(tab_5, Nblignes) ;
  		tab_ecart_type[4] = ecart_type(tab_5, Nblignes) ;
  		tab_mediane[4] = mediane(tab_5, Nblignes) ;
  		tab_quartile1[4] = quartile1(tab_5, Nblignes) ;
  		tab_quartile3[4] = quartile3(tab_5, Nblignes) ;

  		/*--------------------------------------------------------*/// 6

  		tab_moyenne[5] = moyenne(tab_6, Nblignes) ;
  		tab_max[5] = maximum(tab_6, Nblignes) ;
  		tab_min[5] = minimum(tab_6, Nblignes) ;
  		tab_ecart_type[5] = ecart_type(tab_6, Nblignes) ;
  		tab_mediane[5] = mediane(tab_6, Nblignes) ;
  		tab_quartile1[5] = quartile1(tab_6, Nblignes) ;
  		tab_quartile3[5] = quartile3(tab_6, Nblignes) ;

  		/*--------------------------------------------------------*/// 7

  		tab_moyenne[6] = moyenne(tab_7, Nblignes) ;
  		tab_max[6] = maximum(tab_7, Nblignes) ;
  		tab_min[6] = minimum(tab_7, Nblignes) ;
  		tab_ecart_type[6] = ecart_type(tab_7, Nblignes) ;
  		tab_mediane[6] = mediane(tab_7, Nblignes) ;
  		tab_quartile1[6] = quartile1(tab_7, Nblignes) ;
  		tab_quartile3[6] = quartile3(tab_7, Nblignes) ;

  		/*--------------------------------------------------------*/// 8

  		tab_moyenne[7] = moyenne(tab_8, Nblignes) ;
  		tab_max[7] = maximum(tab_8, Nblignes) ;
  		tab_min[7] = minimum(tab_8, Nblignes) ;
  		tab_ecart_type[7] = ecart_type(tab_8, Nblignes) ;
  		tab_mediane[7] = mediane(tab_8, Nblignes) ;
  		tab_quartile1[7] = quartile1(tab_8, Nblignes) ;
  		tab_quartile3[7] = quartile3(tab_8, Nblignes) ;

  		/*--------------------------------------------------------*/// 9

  		tab_moyenne[8] = moyenne(tab_9, Nblignes) ;
  		tab_max[8] = maximum(tab_9, Nblignes) ;
  		tab_min[8] = minimum(tab_9, Nblignes) ;
  		tab_ecart_type[8] = ecart_type(tab_9, Nblignes) ;
  		tab_mediane[8] = mediane(tab_9, Nblignes) ;
  		tab_quartile1[8] = quartile1(tab_9, Nblignes) ;
  		tab_quartile3[8] = quartile3(tab_9, Nblignes) ;

  		/*--------------------------------------------------------*/// 10

  		tab_moyenne[9] = moyenne(tab_10, Nblignes) ;
  		tab_max[9] = maximum(tab_10, Nblignes) ;
  		tab_min[9] = minimum(tab_10, Nblignes) ;
  		tab_ecart_type[9] = ecart_type(tab_10, Nblignes) ;
  		tab_mediane[9] = mediane(tab_10, Nblignes) ;
  		tab_quartile1[9] = quartile1(tab_10, Nblignes) ;
  		tab_quartile3[9] = quartile3(tab_10, Nblignes) ;

  		/*--------------------------------------------------------*/// 11

  		tab_moyenne[10] = moyenne(tab_11, Nblignes) ;
  		tab_max[10] = maximum(tab_11, Nblignes) ;
  		tab_min[10] = minimum(tab_11, Nblignes) ;
  		tab_ecart_type[10] = ecart_type(tab_11, Nblignes) ;
  		tab_mediane[10] = mediane(tab_11, Nblignes) ;
  		tab_quartile1[10] = quartile1(tab_11, Nblignes) ;
  		tab_quartile3[10] = quartile3(tab_11, Nblignes) ;
  		
		/*--------------------------------------------------------*/// 12

  		tab_moyenne[11] = moyenne(tab_12, Nblignes) ;
  		tab_max[11] = maximum(tab_12, Nblignes) ;
  		tab_min[11] = minimum(tab_12, Nblignes) ;
  		tab_ecart_type[11] = ecart_type(tab_12, Nblignes) ;
  		tab_mediane[11] = mediane(tab_12, Nblignes) ;
  		tab_quartile1[11] = quartile1(tab_12, Nblignes) ;
  		tab_quartile3[11] = quartile3(tab_12, Nblignes) ;

  		/*--------------------------------------------------------*/// 13

  		tab_moyenne[12] = moyenne(tab_13, Nblignes) ;
  		tab_max[12] = maximum(tab_13, Nblignes) ;
  		tab_min[12] = minimum(tab_13, Nblignes) ;
  		tab_ecart_type[12] = ecart_type(tab_13, Nblignes) ;
  		tab_mediane[12] = mediane(tab_13, Nblignes) ;
  		tab_quartile1[12] = quartile1(tab_13, Nblignes) ;
  		tab_quartile3[12] = quartile3(tab_13, Nblignes) ;
  		
		/*--------------------------------------------------------*/// 14	
  	
		tab_moyenne[13] = moyenne(tab_14, Nblignes) ;
  		tab_max[13] = maximum(tab_14, Nblignes) ;
  		tab_min[13] = minimum(tab_14, Nblignes) ;
  		tab_ecart_type[13] = ecart_type(tab_14, Nblignes) ;
  		tab_mediane[13] = mediane(tab_14, Nblignes) ;
  		tab_quartile1[13] = quartile1(tab_14, Nblignes) ;
  		tab_quartile3[13] = quartile3(tab_14, Nblignes) ;
  
  		/*--------------------------------------------------------*/// 15	
  	
		tab_moyenne[14] = moyenne(tab_15, Nblignes) ;
  		tab_max[14] = maximum(tab_15, Nblignes) ;
  		tab_min[14] = minimum(tab_15, Nblignes) ;
  		tab_ecart_type[14] = ecart_type(tab_15, Nblignes) ;
  		tab_mediane[14] = mediane(tab_15, Nblignes) ;
  		tab_quartile1[14] = quartile1(tab_15, Nblignes) ;
  		tab_quartile3[14] = quartile3(tab_15, Nblignes) ;
  
  		/*--------------------------------------------------------*/// 16	
  	
		tab_moyenne[15] = moyenne(tab_16, Nblignes) ;
  		tab_max[15] = maximum(tab_16, Nblignes) ;
  		tab_min[15] = minimum(tab_16, Nblignes) ;
  		tab_ecart_type[15] = ecart_type(tab_16, Nblignes) ;
  		tab_mediane[15] = mediane(tab_16, Nblignes) ;
  		tab_quartile1[15] = quartile1(tab_16, Nblignes) ;
  		tab_quartile3[15] = quartile3(tab_16, Nblignes) ;
  
  		/*--------------------------------------------------------*/// 17	
  	
		tab_moyenne[16] = moyenne(tab_17, Nblignes) ;
  		tab_max[16] = maximum(tab_17, Nblignes) ;
  		tab_min[16] = minimum(tab_17, Nblignes) ;
  		tab_ecart_type[16] = ecart_type(tab_17, Nblignes) ;
  		tab_mediane[16] = mediane(tab_17, Nblignes) ;
  		tab_quartile1[16] = quartile1(tab_17, Nblignes) ;
  		tab_quartile3[16] = quartile3(tab_17, Nblignes) ;
  
  		/*--------------------------------------------------------*/// 18
  		
		tab_moyenne[17] = moyenne(tab_18, Nblignes) ;
  		tab_max[17] = maximum(tab_18, Nblignes) ;
  		tab_min[17] = minimum(tab_18, Nblignes) ;
  		tab_ecart_type[17] = ecart_type(tab_18, Nblignes) ;
  		tab_mediane[17] = mediane(tab_18, Nblignes) ;
  		tab_quartile1[17] = quartile1(tab_18, Nblignes) ;
  		tab_quartile3[17] = quartile3(tab_18, Nblignes) ;
  
  		/*--------------------------------------------------------*/// 19
  	
		tab_moyenne[18] = moyenne(tab_19, Nblignes) ;
  		tab_max[18] = maximum(tab_19, Nblignes) ;
  		tab_min[18] = minimum(tab_19, Nblignes) ;
  		tab_ecart_type[18] = ecart_type(tab_19, Nblignes) ;
  		tab_mediane[18] = mediane(tab_19, Nblignes) ;
  		tab_quartile1[18] = quartile1(tab_19, Nblignes) ;
  		tab_quartile3[18] = quartile3(tab_19, Nblignes) ;
  	
		FILE *fichier ;	// déclaration d’un pointeur de type FILE
		fichier = fopen("Statistiques.txt", "w+") ;	

		fprintf(fichier, "Moyenne\n") ;
  		for(int i = 0 ; i<19 ; i++){	// ecriture du tableau
			fprintf(fichier, "%lf \t ", tab_moyenne[i]) ;
			}
		fprintf(fichier, "\n") ;

		fprintf(fichier, "Maximum\n") ;
  		for(int i = 0 ; i<19 ; i++){	// ecriture du tableau
			fprintf(fichier, "%lf \t", tab_max[i]) ;
			}
		fprintf(fichier, "\n") ;

		fprintf(fichier, "Minimum\n") ;
  		for(int i = 0 ; i<19 ; i++){	// ecriture du tableau
			fprintf(fichier, "%lf \t", tab_min[i]) ;
			}
		fprintf(fichier, "\n") ;

		fprintf(fichier, "Écart type\n") ;
  		for(int i = 0 ; i<19 ; i++){	// ecriture du tableau
			fprintf(fichier, "%lf \t", tab_ecart_type[i]) ;
			}
		fprintf(fichier, "\n") ;

		fprintf(fichier, "Médiane\n") ;
  		for(int i = 0 ; i<19 ; i++){	// ecriture du tableau
			fprintf(fichier, "%lf \t", tab_mediane[i]) ;
			}
		fprintf(fichier, "\n") ;

		fprintf(fichier, "Quartile 1\n") ;
  		for(int i = 0 ; i<19 ; i++){	// ecriture du tableau
			fprintf(fichier, "%lf \t", tab_quartile1[i]) ;
			}
		fprintf(fichier, "\n") ;

		fprintf(fichier, "Quartile 3\n") ;
  		for(int i = 0 ; i<19 ; i++){	// ecriture du tableau
			fprintf(fichier, "%lf \t", tab_quartile3[i]) ;
			}
		fprintf(fichier, "\n") ;

		printf("Les statistiques ont été enregistrées dans le fichier Statistiques.txt\n") ;
		}
 
	if(rep == 2){
		int k ;
		printf("Quelle valeur pour k ? ") ;
		scanf("%d", &k) ;
		Nbl1 = tri_liste2(tab_1, k, Nblignes) ;
		Nbl2 = tri_liste2(tab_2, k, Nblignes) ;
		Nbl3 = tri_liste2(tab_3, k, Nblignes) ;
		Nbl4 = tri_liste2(tab_4, k, Nblignes) ;
		Nbl5 = tri_liste2(tab_5, k, Nblignes) ;
		Nbl6 = tri_liste2(tab_6, k, Nblignes) ;
		Nbl7 = tri_liste2(tab_7, k, Nblignes) ;
		Nbl8 = tri_liste2(tab_8, k, Nblignes) ;
		Nbl9 = tri_liste2(tab_9, k, Nblignes) ;
		Nbl10 = tri_liste2(tab_10, k, Nblignes) ;
		Nbl11 = tri_liste2(tab_11, k, Nblignes) ;
		Nbl12 = tri_liste2(tab_12, k, Nblignes) ;
		Nbl13 = tri_liste2(tab_13, k, Nblignes) ;
		Nbl14 = tri_liste2(tab_14, k, Nblignes) ;
		Nbl15 = tri_liste2(tab_15, k, Nblignes) ;
		Nbl16 = tri_liste2(tab_16, k, Nblignes) ;
		Nbl17 = tri_liste2(tab_17, k, Nblignes) ;
		Nbl18 = tri_liste2(tab_18, k, Nblignes) ;
		Nbl19 = tri_liste2(tab_19, k, Nblignes) ;
		}

	if(rep == 3){
		printf("histogramme USAGE_OF_BACKING_FILM\n") ;
		histogramme(tab_1, Nblignes) ;
		printf("histogramme USAGE_OF_DRESSER\n") ;
		histogramme(tab_2, Nblignes) ;
		printf("histogramme USAGE_OF_POLISHING_TABLE\n") ;
		histogramme(tab_3, Nblignes) ;
		printf("histogramme USAGE_OF_DRESSER_TABLE\n") ;
		histogramme(tab_4, Nblignes) ;
		printf("histogramme PRESSURIZED_CHAMBER_PRESSURE\n") ;
		histogramme(tab_5, Nblignes) ;
		printf("histogramme MAIN_OUTER_AIR_BAG_PRESSURE\n") ;
		histogramme(tab_6, Nblignes) ;
		printf("histogramme CENTER_AIR_BAG_PRESSURE\n") ;
		histogramme(tab_7, Nblignes) ;
		printf("histogramme RETAINER_RING_PRESSURE\n") ;
		histogramme(tab_8, Nblignes) ;
		printf("histogramme RIPPLE_AIR_BAG_PRESSURE\n") ;
		histogramme(tab_9, Nblignes) ;
		printf("histogramme USAGE_OF_MEMBRANE\n") ;
		histogramme(tab_10, Nblignes) ;
		printf("histogramme USAGE_OF_PRESSURIZED_SHEET\n") ;
		histogramme(tab_11, Nblignes) ;
		printf("histogramme SLURRY_FLOW_LINE_A\n") ;
		histogramme(tab_12, Nblignes) ;
		printf("histogramme SLURRY_FLOW_LINE_B\n") ;
		histogramme(tab_13, Nblignes) ;
		printf("histogramme SLURRY_FLOW_LINE_C\n") ;
		histogramme(tab_14, Nblignes) ;
		printf("histogramme WAFER_ROTATION\n") ;
		histogramme(tab_15, Nblignes) ;
		printf("histogramme STAGE_ROTATION\n") ;
		histogramme(tab_16, Nblignes) ;
		printf("histogramme HEAD_ROTATION\n") ;
		histogramme(tab_17, Nblignes) ;
		printf("histogramme DRESSING_WATER_STATUS\n") ;
		histogramme(tab_18, Nblignes) ;
		printf("histogramme EDGE_AIR_BAG_PRESSURE\n") ;
		histogramme(tab_19, Nblignes) ;
		}

	if(rep == 4){
		lecture_fichierq4(tab_1, tab_2, tab_3, tab_4, tab_5, tab_6, tab_7, tab_8, tab_9, tab_10, tab_11, tab_12, tab_13, tab_14, tab_15, tab_16, tab_17, tab_18, tab_19, tab_wafer) ;
		printf("Les statistiques agrégées par wafer ont été enregistrées dans le fichier StatistiquesWafer.txt") ;
		}

	}
 
int lireFichier(double tab_1[], double tab_2[], double tab_3[], double tab_4[], double tab_5[], double tab_6[], double tab_7[], double tab_8[], double tab_9[], double tab_10[], double tab_11[], double tab_12[], double tab_13[], double tab_14[], double tab_15[], double tab_16[], double tab_17[], double tab_18[], double tab_19[], double tab_time[]){
	FILE *fp ;
	long i = 0 ;
	int k ;
 	char fichier[21] ;
	for(k = 0 ; k<59 ; k++){
		if(k<10) 
			sprintf(fichier, "CMP-training-00%d.csv", k) ;
		else(sprintf(fichier, "CMP-training-0%d.csv", k)) ;
		// printf("%s \n",fichier) ;
		fp = fopen(fichier, "r") ; 
		// printf("lecture du fichier numero %d \n", k) ;
		fscanf(fp, "%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s%*s") ;
		while((fscanf(fp, "%*d%*d%lf%*f%*s%*lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf", &tab_time[i], &tab_1[i], &tab_2[i], &tab_3[i], &tab_4[i], &tab_5[i], &tab_6[i], &tab_7[i], &tab_8[i], &tab_9[i], &tab_10[i], &tab_11[i], &tab_12[i], &tab_13[i], &tab_14[i], &tab_15[i], &tab_16[i], &tab_17[i], &tab_18[i], &tab_19[i])) == 20){
			i++ ;
			}
  		// printf("nombre de lignes %d \n", i) ;
  		fclose(fp) ; 
		}
  	return i ;
	}