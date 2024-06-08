#include <stdio.h>
#include <stdlib.h>

char *testo = NULL;

int leggiTesto(){
	testo = realloc(testo, 0);
	if(testo == NULL){
		return -1;
	}
	int lung_testo = 0;
	printf("Inserisci il testo da cifrare:\n");
	int cond = 1;
	do{
		char str[BUFSIZ];
		fgets(str, BUFSIZ, stdin);
		int lenght = 0;
		for(; str[lenght] != '\0'; lenght++);
		testo = realloc(testo, (lenght * sizeof(char)) + sizeof(testo));
		if(testo == NULL){
			return -1;
		}
		for(int i = 0; i < lenght; i++){
			testo[lung_testo + i] = str[i];
		}
		lung_testo += lenght;
		if(testo[lung_testo - 2] == '.'){
			cond = 0;
		}
	} while(cond);
	return 0;
}

char* cifra(char *testo){
	int k;
	printf("Inserisci un intero: ");
	scanf("%d", &k);
	k %= 26;
	if(k == 0){
		return testo;
	}
	for(int i = 0; testo[i] != '\0'; i++){
		if(testo[i] > 64 && testo[i] <= 90-k){
			testo[i] += k;
		}
		else if(testo[i] > 90-k && testo[i] < 91){
			testo[i] = (testo[i] + k - 26);
		}
		else if(testo[i] > 96 && testo[i] <= 122-k){
			testo[i] += k;
		}
		else if(testo[i] > 122-k && testo[i] < 123){
			testo[i] = (testo[i] + k - 26);
		}
	}
	return testo;
}

char* decifra(char *testo){
	int k;
	printf("Inserisci un intero: ");
	scanf("%d", &k);
	k = 26 - (k % 26);
	if(k == 0){
		return testo;
	}
	for(int i = 0; testo[i] != '\0'; i++){
		if(testo[i] > 64 && testo[i] <= 90-k){
			testo[i] += k;
		}
		else if(testo[i] > 90-k && testo[i] < 91){
			testo[i] = (testo[i] + k - 26);
		}
		else if(testo[i] > 96 && testo[i] <= 122-k){
			testo[i] += k;
		}
		else if(testo[i] > 122-k && testo[i] < 123){
			testo[i] = (testo[i] + k - 26);
		}
	}
	return testo;
}

int esporta(char* testo){
	printf("Inserisci il nome di un file: ");
	char fn[BUFSIZ];
	fgets(fn, BUFSIZ, stdin);
	FILE *pfile = fopen(fn, "w");
	if(pfile == NULL){
		return -1;
	}
	fprintf(pfile, "%s", testo);
	fclose(pfile);	
	return 0;
}

int main(){
	int exit=1, isIn = 0, isCif = 0, isDec = 0, option;
	char *testocif, *testodecif;
	do{
		printf("1. Inserire testo\n2. Visualizzare testo\n3. Cifrare il testo\n4. Visualizzare testo cifrato\n5. Decifrare il testo\n6. Visualizzare il testo decifrato\n7. Esporta\n8. Esci\n>");
		char input[BUFSIZ];
		fgets(input, BUFSIZ, stdin);
		option = atoi(input);
		switch(option){
			case 1:
					leggiTesto();
					isIn = 1;
					isCif = 0;
					isDec = 0;
					break;
			case 2:
				if(isIn == 0){
					printf("Devi ancora inserire il testo\n");
				}
				else{
					printf("%s", testo);
				}
				break;
			case 3:
				if(isIn == 0){
					printf("Devi ancora inserire il testo\n");
				}
				else{
					testocif = cifra(testo);
					printf("\nIl testo è stato cifrato\n");
					isCif = 1;
					isDec = 0;
				}
				break;
			case 4:
				if(isIn == 0){
					printf("Devi ancora inserire il testo\n");
				}
				else if(isCif == 0){
					printf("Devi ancora cifrare il testo\n");
				}
				else{
					printf("%s", testocif);
				}
				break;
			case 5:
				if(isIn == 0){
					printf("Devi ancora inserire il testo\n");
				}
				else if(isCif == 0){
					printf("Devi ancora cifrare il testo\n");
				}
				else{
					testodecif = decifra(testocif);
					isDec = 1;
				}
				break;
			case 6:
				if(isIn == 0){
					printf("Devi ancora inserire il testo\n");
				}
				else if(isCif == 0){
					printf("Devi ancora cifrare il testo\n");
				}
				else if(isDec == 0){
					printf("Devi ancora decifrare il testo\n");
				}
				else{
					printf("%s", testodecif);
				}
				break;
			case 7:
				if(isIn == 0){
					printf("Devi ancora inserire il testo\n");
				}
				else if(isCif == 0){
					printf("Devi ancora cifrare il testo\n");
				}
				else{
					esporta(testocif);
				}
				break;
			case 8:
				free(testo);
				exit = 0;
				break;
			default:
				printf("Non è un'opzione\n");
				break;
			}			
		}while(exit);
	return 0;
}
		
			
