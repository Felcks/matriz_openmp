#include <stdio.h>

int main(void){

	int i = 0;
 	#pragma omp parallel for 
 	for(i = 0; i < 10; i++){
 		printf("%i %i\n",i, omp_get_thread_num());
 	}


 	printf("Hello, world.\n");
 	return 0;
}