#include <stdio.h>
#include <stdlib.h>

double* Sort(double *arr, int size){
	if(size == 1){
		return arr;
	}
	for(int j = size-1; j > 0; j--){
		for(int i = 0; i < j; i++){
			if(arr[i] > arr[i+1]){
				double aux = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = aux;
			}
		}
	}
	return arr;
}

int main(int argc, char *argv[]){
	if(argc < 2){
		printf("Not enough arguments\n");
		return 1;
	}
	FILE *file = fopen(argv[1], "r");
	if(file == NULL){
		printf("The first document couldn't be opened\n");
		return 1;
	}
	int size = 0;
	double *arr = malloc(sizeof(double));
	if(arr == NULL){
		printf("Allocation issue\n");
		return 1;
	}
	double* Add(double*, double, int*);
	double a;
	while(fscanf(file, "%lf", &a) == 1){
		arr = Add(arr, a, &size);
	}
	fclose(file);
	file = fopen(argv[2], "w");
	if(file == NULL){
		printf("The second document couldn't be opened\n");
		return 1;
	}
	arr = Sort(arr, size);
	for(int i = 0; i < size; i++){
		fprintf(file, "%g\n", arr[i]);
	}
	fclose(file);
	file = fopen(argv[2], "r");
	if(file == NULL){
		printf("The second document couldn't be opened\n");
		return 1;
	}
	while(fscanf(file, "%lf", &a) == 1){
		printf("%g\t", a);
	}
	printf("\n");
	fclose(file);
	free(arr);
	return 0;
}

double* Add(double* arr, double a, int *size){
	(*size)++;
	arr = realloc(arr, (*size)*sizeof(double));
	if(arr == NULL){
		printf("Alllocation issue\n");
		return arr;
	}
	arr[(*size)-1] = a;
	return arr;
} 
