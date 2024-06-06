#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char** f;
	int n;
}testo;

void mostra(testo t){
	for(int i=0; i<t.n; i++){
		printf("%s", t.f[i]);
	}
}

int carica(char *nf, testo* txt){
	FILE *file = fopen(nf, "r");
	if(file == NULL){
		return -1;
	}
	int n;
	fscanf(file,"%d", &n);
	if(n <= 0){
		return -2;
	}
	txt->f = malloc((sizeof(char*))*n);
	if(txt->f == NULL){
		return -3;
	}
	char line[BUFSIZ];
	int a = 0;
	fgets(line, BUFSIZ, file);
	while(fgets(line, BUFSIZ, file)!= NULL){
		int i = 0;
		for(; line[i] != '\0'; i++);
		(txt->f)[a] = malloc(sizeof(char)*i);
		if((txt->f)[a] == NULL){
			return -4;
		}
		strcpy((txt->f)[a], line);
		a++;
	}
	txt->n = n;
	return 0;
}

int aggiungi(testo *txt, char *s){
	(txt->n)++;
	txt->f = realloc(txt->f, (sizeof(char*))*(txt->n));
	if(txt->f == NULL){
		return -1;
	}
	(txt->f)[(txt->n) - 1] = malloc(sizeof(s));
	if((txt->f)[(txt->n) - 1] == NULL){
			return -2;
	}
	strcpy((txt->f)[(txt->n) - 1], s);
	return 0;
}

int scrivisuf(char* nf, testo t){
	FILE *file = fopen(nf, "w");
	if(file == NULL){
		return -1;
	}
	for(int i=0; i<t.n; i++){
		fprintf(file, "%s", t.f[i]);
	}
	return 0;
}

int main(int argc, char* argv[]){
	if(argc < 1){
		printf("Numero sbagliato di argomenti\n");
		return -1;
	}
	testo t;
	int status;
	if(status = carica(argv[1], &t) != 0){
		printf("Errore in apertura del file o allocazione della memoria\n");
		return -1;
	}
	int option;
	while(1){
		printf("1. Mostra\n2. Aggiungi frase\n3. Scrivi su file\n4. Esci\n>");
		scanf("%d", &option);
		getchar();
		switch (option){
			case 1: 
				mostra(t);
				break;
			case 2:
				printf("Digita una frase: ");
				char line[BUFSIZ];
				fgets(line, BUFSIZ, stdin);
				aggiungi(&t, line);
				break;
			case 3:
				printf("Digita il nome di un file: ");
				char file[BUFSIZ];
				fgets(file, BUFSIZ, stdin);
				scrivisuf(file, t);
				break;
			case 4:
				return 0;
				break;
			default : 
				printf("Scelta inesistente\n");
				break;
		}
	}		 
}
		
 
	
