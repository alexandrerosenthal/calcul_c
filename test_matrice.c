#include <stdio.h>
#include <stdlib.h>


double** create_matrice(int ligne , int colonne){
	double** matrice;
	int i;
	matrice = malloc(ligne*sizeof(double*));
	for(i=0 ; i<ligne ; i++){
		matrice[i] = malloc(colonne*sizeof(double));
	}
	return matrice;
}

void remove_matrice(double** matrice , int ligne){
	int i;
	for(i=0 ; i<ligne ; i++){
		free(matrice[i]);
	}
	free(matrice);
}

void print_matrice(double** matrice , int ligne , int colonne){
	int i;
	int j;
	for(i=0 ; i<ligne ; i++){
		for(j=0 ; j<colonne ; j++){
			printf("| %f ", matrice[i][j]);
		}
		printf("|");
		printf("\n");
	}
	printf("\n");
}

double** fill_matrice_graphique(double** matrice , int ligne , int colonne){
	int i;
	int j;
	for(i=0 ; i<ligne ; i++){
		for(j=0 ; j<colonne ; j++){
			printf("valeur pour case %d %d:", i , j);
			scanf("%lf",&matrice[i][j]);
		}
	}
	return matrice;
}

double** add_matrice(double** matrice1 , double** matrice2 , int ligne , int colonne , int ligne2 , int colonne2){
	int i;
	int j;
	double** matrice;
	matrice=create_matrice(ligne , colonne);
	if(ligne == ligne2){
		if(colonne == colonne2){
				for(i=0 ; i<ligne ; i++){
					for(j=0 ; j<colonne ; j++){
						matrice[i][j]=matrice1[i][j]+matrice2[i][j];
					}
				}
		} else {
			printf("opération non possible \n");
		}
	} else {
		printf("opération non possible \n");
	}

	return matrice;
}

double** mult_matrice(double** matrice1 , double** matrice2 , int ligne , int colonne , int ligne2 , int colonne2){
	int i;
	int j;
	int k;
	double** matrice;
	double nombre;
	matrice=create_matrice(ligne2 , colonne);
	if (colonne == ligne2) {
		for(i=0 ; i<ligne ; i++){
			for(j=0 ; j<colonne ; j++){
				for(k=0 ; k<colonne ; k++){
					nombre=matrice1[i][k]*matrice2[k][j];
					matrice[i][j]=matrice[i][j]+nombre;
				}
			}
		}
	} else {
		printf("opération non possible \n");
	}
	return matrice;
}

double** multr_matrice(int reel , double** matrice , int ligne , int colonne){
	int i;
	int j;
	for(i=0 ; i<ligne ; i++){
		for(j=0 ; j<colonne ; j++){
			matrice[i][j]=matrice[i][j]*reel;
		}
	}
	return matrice;
}

double** trace_matrice(double** matrice1 , double** matrice2 , int ligne , int colonne , int ligne2 , int colonne2){
	int i;
	double** matrice;
	matrice=create_matrice(ligne , colonne);
	if(ligne == colonne){
		if(ligne2 == colonne2){
			if(ligne == ligne2){
					for(i=0 ; i<ligne ; i++){
						matrice[i][i]=matrice1[i][i]+matrice2[i][i];
					}
			} else {
				printf("opération non possible \n");
			}
		} else {
			printf("opération non possible \n");
		}
	} else {
		printf("opération non possible \n");
	}
	return matrice;
}

double trace_matrice(double** matrice , int ligne , int colonne){
	int i;
	double k;
	if(ligne == colonne){
		for(i=0 ; i<mat->ligne ; i++){
			k=k+mat->tab[i][i];
		}
	} else {
		printf("opération non possible \n");
	}
	return k;
}

/*double** det_matrice(double** matrice , int ligne , int colonne){
	double det
	if(ligne == colonne){
		if(ligne == 2){
			det=matrice[0][0]*matrice[1][1]-matrice[1][0]*matrice[0][1]
		} else {
			
		}
	}
}*/

int main(){
	int ligne=0;
	int colonne=0;
	int ligne2=0;
	int colonne2=0;
	double** matrice1;
	double** matrice2;
	double** matrice;
	double** matrice_mult;
	
	printf("Entrez le nombre de ligne:");
	scanf("%d", &ligne);
	printf("\n");
	printf("Entrez le nombre de colonne:");
	scanf("%d", &colonne);
	printf("\n");
	
	matrice1=create_matrice(ligne , colonne);
	fill_matrice_graphique(matrice1 , ligne , colonne);
	print_matrice(matrice1 , ligne , colonne);
	
	printf("Entrez le nombre de ligne:");
	scanf("%d", &ligne2);
	printf("\n");
	printf("Entrez le nombre de colonne:");
	scanf("%d", &colonne2);
	printf("\n");
	
	matrice2=create_matrice(ligne2 , colonne2);
	fill_matrice_graphique(matrice2 , ligne2 , colonne2);
	print_matrice(matrice2 , ligne2 , colonne2);
	
	matrice=add_matrice(matrice1 , matrice2 , ligne , colonne , ligne2 , colonne2);
	print_matrice(matrice , ligne , colonne);
	
	matrice_mult=mult_matrice(matrice1 , matrice2 , ligne , colonne , ligne2 , colonne2);
	print_matrice(matrice_mult , ligne , colonne);
	
	matrice=trace_matrice(matrice1 , matrice2 , ligne , colonne , ligne2 , colonne2);
	print_matrice(matrice , ligne , colonne);
	
	remove_matrice(matrice , ligne);
	remove_matrice(matrice1 , ligne);
	remove_matrice(matrice2 , ligne);
	remove_matrice(matrice_mult , ligne);
	
	return 0;
}

