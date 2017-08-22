#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	int **matrizA, **matrizB;

	int i = 0;
	int j = 0;
	int k = 0;

	matrizA = (int**)malloc(1000 * sizeof(int*));
	matrizB = (int**)malloc(1000 * sizeof(int*));

	for(i = 0; i < 1000; i++){
		*(matrizA + i) = (int*)malloc(1000 * sizeof(int)); 
		*(matrizB + i) = (int*)malloc(1000 * sizeof(int)); 
	}


	for(i = 0; i < 1000; i++){
		for(j = 0; j < 1000; j++){
			

		}
	}






	for(i = 0; i < 1000; i++){
		free(matrizA[i]);
		free(matrizB[i]);
	}

	free(matrizA);
	free(matrizB);


	return 0;
}