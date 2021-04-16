#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct matrice {
	int** tab;
	int ligne;
	int colonne;
};

struct matrice* create_matrice(int l, int c){
	int i;
	struct matrice* mat ;
	mat = malloc ( sizeof(struct matrice) ) ;
	mat->tab = malloc(l*sizeof(int*));
	for(i=0 ; i<l ; i++){
		mat->tab[i] = malloc(c*sizeof(int));
	}
	mat->ligne = l ;
	mat->colonne = c ;
	return mat;
}

void remove_matrice(struct matrice* mat){
	int i;
	for(i=0 ; i<mat->ligne ; i++){
		free(mat->tab[i]);
	}
	free(mat);
}

void print_matrice(struct matrice* mat){
	int i;
	int j;
	for(i=0 ; i<mat->ligne ; i++){
		for(j=0 ; j<mat->colonne ; j++){
			printf("| %d ", mat->tab[i][j]);
		}
		printf("|");
		printf("\n");
	}
	printf("\n");
}

struct matrice* add_matrice(struct matrice* mat1 , struct matrice* mat2){
	int i;
	int j;
	struct matrice* mat3;
	if(mat1 -> ligne == mat2 -> ligne){
		if(mat1 -> colonne == mat2 -> colonne){
			mat3=create_matrice(mat1 -> ligne , mat1 -> colonne);
			for(i=0 ; i<mat1 -> ligne ; i++){
				for(j=0 ; j<mat1 -> colonne ; j++){
					mat3->tab[i][j]=mat1->tab[i][j]+mat2->tab[i][j];
				}
			}
		} else {
			printf("opération non possible \n");
		}
	} else {
		printf("opération non possible \n");
	}

	return mat3;
}

struct matrice* fill_matrice_graphique(struct matrice* mat){
	int i;
	int j;
	for(i=0 ; i<mat -> ligne ; i++){
		for(j=0 ; j<mat -> colonne ; j++){
			printf("Valeur pour case %d %d : ", i , j);
			scanf("%d" , &mat -> tab[i][j]);
		}
	}
	return mat;
}

struct matrice* mult_matrice(struct matrice* mat1 , struct matrice* mat2){
	int i;
	int j;
	int k;
	struct matrice* mat3;
	if (mat1 -> colonne == mat2 -> ligne) {
		mat3=create_matrice(mat1 -> ligne , mat1 -> colonne);
		for(i=0 ; i<mat1 ->ligne ; i++){
			for(j=0 ; j<mat1 -> colonne ; j++){
				for(k=0 ; k<mat1 -> colonne ; k++){
					mat3->tab[i][j]=mat3->tab[i][j]+mat1->tab[i][k]*mat2->tab[k][j];
				}
			}
		}
	} else {
		printf("opération non possible \n");
	}
	return mat3;
}

struct matrice* multr_matrice(int reel , struct matrice* mat){
	int i;
	int j;
	for(i=0 ; i<mat -> ligne ; i++){
		for(j=0 ; j<mat -> colonne ; j++){
			mat->tab[i][j]=mat->tab[i][j]*reel;
		}
	}
	return mat;
}

int trace_matrice(struct matrice* mat){
	int i;
	int k;
	k=0;
	if(mat->ligne == mat->colonne){
		for(i=0 ; i<mat->ligne ; i++){
			k=k+mat->tab[i][i];
		}
	} else {
		printf("opération non possible \n");
	}
	return k;
}

struct matrice* red_mat(struct matrice* mat , int l, int c){
	int i;
	int j;
	struct matrice* mat3;
	mat3=create_matrice(mat->ligne-1, mat->colonne-1);
	for(i=0 ; i<mat->ligne ; i++){
		for(j=0 ; j<mat->ligne ; j++){
			if(i < l){
				if(j < c){
						mat3->tab[i][j]=mat->tab[i][j];
				} 
			}
			if(i >= l){
				if(j < c){
					if(i < mat->ligne-1 ){
						mat3->tab[i][j]=mat->tab[i+1][j];
					}
				}
			}
			if(i < l){
				if(j >= c){
					if(j < mat->colonne-1 ){
						mat3->tab[i][j]=mat->tab[i][j+1];
					}
				}
			}
			if(i >= l){
				if(j >= c){
					if(i < mat->ligne-1 ){
						if(j < mat->colonne-1 ){
							mat3->tab[i][j]=mat->tab[i+1][j+1];
						} 
					}
				}
			}
		}
	}
	return mat3;
}

int det(struct matrice* mat , int i){
	int k;
	int n;
	struct matrice* mat2;
	if(mat->ligne == 2){
		n=mat->tab[0][0]*mat->tab[1][1]-mat->tab[0][1]*mat->tab[1][0];
		return n;
	}
	if(i<mat->ligne){
		if(mat->ligne > 2){
			for(k=0 ; k < mat->ligne-2 ; k++){
					mat2=create_matrice(mat->ligne-k, mat->colonne-k);
					mat2=red_mat(mat , i , 0);
						return det(mat , i+1)+pow(-1,i)*mat->tab[i][0]*det(mat2 , 0);
			remove_matrice(mat2);
			}		
		}
	}
}

int main(){
	struct matrice* tab;
	struct matrice* tab2;
	struct matrice* tab3;
	struct matrice* tab4;
	
	
	tab = create_matrice(3,3);
	fill_matrice_graphique(tab);
	print_matrice(tab);
	
	
	tab2 = create_matrice(3,3);
	fill_matrice_graphique(tab2);
	print_matrice(tab2);
	
	
	tab3=add_matrice(tab , tab2);
	print_matrice(tab3);
	
	tab3=mult_matrice(tab , tab2);
	print_matrice(tab3);
	
	int trace;
	trace=trace_matrice(tab);
	printf("%d\n", trace);
	
	
	tab4=red_mat(tab , 1 , 2);
	print_matrice(tab4);
	
	int determinant;
	determinant=det(tab , 0);
	printf("%d\n", determinant);
	
	remove_matrice(tab);
	remove_matrice(tab2);
	remove_matrice(tab3);
	remove_matrice(tab4);
	return 0;
}
