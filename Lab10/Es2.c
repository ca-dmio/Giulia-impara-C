#include <stdio.h>
#include <stdlib.h>

void Sort(double *arr, int size){
	if(size == 1){
		printf("%g\n", arr[0]);
		return;
	}
	for(int j = size-1; j > 0; j--){
		for(int i = 0; i < j; i++){
			if(arr[i] < arr[i+1]){
				double aux = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = aux;
			}
		}
		printf("%g\t", arr[j]);
		if(j == 1){
			printf("%g\n", arr[j-1]);
		}
	}
	return;
}


int main(void){
	int size = 0;
	int arrctrl = 0;
	double *arr = malloc(sizeof(double));
	if(arr == NULL){
		printf("Allocation error\n");
		return 1;
	}
	while(1){
		int option;
		do{
			printf("Choose one of the following options: \n");
			printf("1. Type an array of double\n2. Sort the array\n3. View the array\n4. End\n");
			scanf("%d", &option); 
		} while(option != 1 && option != 2 && option != 3 && option != 4);
		switch (option){
			case 1:
				free(arr);
				double* TypeArr(int *);
				arr = TypeArr(&size);
				if(arr == NULL){
					printf("Allocation error\n");
					return 1;
				}
				arrctrl = 1;
				break;
			case 2:
				if(arrctrl == 1){
					Sort(arr, size);
				}
				else{
					printf("You have yet to type an array\n");
				}
				break;
			case 3:
				if(arrctrl == 1){
					for(int j = 0; j < size; j++){
						printf("%g\t", arr[j]);
					}
					printf("\n");
				}
				else{
					printf("You have yet to type an array\n");
				}
				break;
			case 4:
				free(arr);
				return 0;
				break;
		}
	}
}

double* TypeArr(int *size){
	int n;
	do{
		printf("How many doubles do you want to input? ");
		scanf("%d", &n);
	} while(n < 1);
	double *arr = malloc(n * sizeof(double));
	for(int i = 0; i < n; i++){
		printf("Type the %dth double: ", i+1);
		scanf("%lf", arr + i);
	}
	*size = n;
	return arr;
}
			
