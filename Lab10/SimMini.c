#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char mat[3][3];

void shift(char arr[3][3]){
	for(int i=0; i<3; i++){
		char aux;
		aux = arr[i][0];
		arr[i][0] = arr[i][2];
		arr[i][2] = arr[i][1];
		arr[i][1] = aux;
	}
	return;
}

void rifletti(char arr[3][3]){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j <= i; j++){
			char aux = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = aux;
		}
	}
	return;
}

void nega(char arr[3][3]){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(arr[i][j] == '-'){
				arr[i][j] = '+';
			}
			else{
				arr[i][j] = '-';
			}
		}
	}
}

int speculare(char arr[3][3]){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j <= i; j++){
			if(arr[i][j] != arr[j][i]){return 0;}
		}
	}
	return 1;
}

int main(){
	srand(time(NULL));
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			int c = rand();
			mat[i][j] = (c%2 == 0)? '+' : '-';
		}
	}
	while(1){
		int option;
		do{
			printf("1. Mostra matrice\n2. Shift\n3. Riflessione\n4. Negazione\n5. Controlla se speculare\n6. Esci\n");
			printf("Scegli un'opzione:\t");
			scanf("%d", &option);
		}while(option != 1 && option != 2 && option != 3 && option != 4 && option != 5 && option != 6);
		switch(option){
			case 1:
				for(int i = 0; i < 3; i++){
					for(int j = 0; j < 3; j++){
						printf("%c\t", mat[i][j]);
					}
					printf("\n");
				}
				break;
			case 2:
				shift(mat);
				break;
			case 3:
				rifletti(mat);
				break;
			case 4:
				nega(mat);
				break;
			case 5:
				printf("La matrice ");
				if(speculare(mat) == 0){
					printf("non ");
				}
				printf("è speculare\n");
				break;
			case 6:
				return 0;
				break;
		}
	}
}
	

