#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define ROW 1000

int main(void){

	time_t start_time;
	time_t end_time;

	clock_t begin = clock();


	int **matrizA, **matrizB, **matrizC;

	int i = 0;
	int j = 0;
	int k = 0;

	matrizA = (int**)malloc(ROW * sizeof(int*));
	matrizB = (int**)malloc(ROW * sizeof(int*));
	matrizC = (int**)malloc(ROW * sizeof(int*));

	for(i = 0; i < ROW; i++){
		*(matrizA + i) = (int*)malloc(ROW * sizeof(int)); 
		*(matrizB + i) = (int*)malloc(ROW * sizeof(int)); 
		*(matrizC + i) = (int*)malloc(ROW * sizeof(int)); 
	}

	for(i = 0; i < ROW; i++){
		for(j = 0; j < ROW; j++){
			matrizA[i][j] = 1;
			matrizB[i][j] = 1;
		}
	}

	start_time = time(NULL);

	#pragma omp parallel for
	for(i = 0; i < ROW; i++){
		#pragma omp parallel for
		for(j = 0; j < ROW; j++){

			int sum = 0;

			#pragma omp parallel for
			for(k = 0; k < ROW; k++){
				sum += matrizA[i][k] * matrizB[k][j];
			}
			matrizC[i][j] = sum;
		}
	}

	end_time = time(NULL);

	clock_t end = clock();

	printf("time %lf\n", ((double)(end - begin) / CLOCKS_PER_SEC) / 4);


	/*for(i = 0; i < ROW; i++){
		for(j = 0; j < ROW; j++){
			printf("%i ", matrizC[i][j]);
		}
		printf("\n");
	}*/



	for(i = 0; i < ROW; i++){
		free(matrizA[i]);
		free(matrizB[i]);
		free(matrizC[i]);
	}

	free(matrizA);
	free(matrizB);
	free(matrizC);


	return 0;
}