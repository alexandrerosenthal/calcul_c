#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct polynome {
	int* tab;
	int ordre;
};


struct polynome* create_poly(int ordre) {
	struct polynome* poly ;
	poly = malloc ( sizeof(struct polynome) ) ;
	poly->tab = malloc(ordre*sizeof(int));
	poly->ordre=ordre;
	return poly;
}

void print_poly(struct polynome* poly){
	int i;
	for(i=0 ; i<poly->ordre ; i++){
		printf(" %dX^%d ", poly->tab[i], i);
	}
	printf("\n");
}

void free_poly(struct polynome* poly){
	free(poly->tab);
	free(poly);
}

void val_poly(struct polynome* poly, int y){
	int i;
	int val;
	for(i=0 ; i<poly->ordre ; i++){
		val=val+poly->tab[i]*pow(y,i);
	}
	printf("%d \n", val);
}

int main(){
	struct polynome* poly1;
	poly1=create_poly(4);
	poly1->tab[0]=2;
	poly1->tab[1]=3;
	poly1->tab[2]=1;
	poly1->tab[3]=0;
	print_poly(poly1);
	val_poly(poly1 , 6);
	free_poly(poly1);
}
