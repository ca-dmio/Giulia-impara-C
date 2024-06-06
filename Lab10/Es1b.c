#include <stdio.h>
#include <stdlib.h>

void Sort(double *arr, int size){
	for(int j = size-1; j > 0; j--){
		for(int i = 0; i < j; i++){
			if(arr[i] < arr[i+1]){
				double aux = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = aux;
			}
		}
		printf("%g\n", arr[j]);
		if(j == 1){
			printf("%g\n", arr[j-1]);
		}
	}
	return;
}

int main(){
	printf("How many double do you want to input? ");
	int n;
	scanf("%d", &n);
	double *arr = malloc(n * sizeof(double));
	if(arr == NULL){
		printf("Errore di allocazione della memoria\n");
		return 1;
	}
	for(int i = 0; i < n; i++){
		printf("Type the %dth double: ", i+1);
		scanf("%lf", arr + i);
	}
	Sort(arr, n);
	free(arr);
	return 0;
}		
