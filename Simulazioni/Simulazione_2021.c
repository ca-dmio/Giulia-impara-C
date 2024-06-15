#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n, r, c;
int **G;

void show(){
	for(int i = 0; i < r; i++){
		printf("|");
		for(int j = 0; j < c; j++){
			switch(G[i][j]){
				case 0:
					printf(" ");
					break;
				case 1:
					printf("+");
					break;
				case 2:
					printf("*");
					break;
				}
			printf("|");
		}
		printf("\n");
	}
	return;
}

int leggi_mossa(){
	int j;
	do{
		printf("Utente, qual é la tua mossa? ");
		char mossa[BUFSIZ];
		fgets(mossa, BUFSIZ, stdin);
		j = atoi(mossa);
	} while(j <= 0 || j > c);
	return j;
}

int scrivi(int gioc, int j){
	if(G[0][j] != 0){
		printf("Colonna piena\n");
		return 0;
	}
	int i = r-1;
	while(G[i][j] != 0){
		i--;
	}
	G[i][j] = gioc;
	return 1;
}

int mossa(){
	srand(time(NULL));
	int x;
	do{
		x = (rand()%c);	
	}while(G[0][x] != 0);
	return x+1;
}

int check_r(int gioc){
	for(int i = 0; i < r; i++){
		for(int j = 0; j <= c-n; j++){
			if(G[i][j] == gioc){
				int InRow = 1;
				for(int k=1; k<n; k++){
					if(G[i][j+k] == gioc){
						InRow++;
					}
				}
				if(InRow == n){
					return 1;
				}
			}
		}
	}
	return 0;
}

int check_c(int gioc){
	for(int i = 0; i <= r-n; i++){
		for(int j = 0; j < c; j++){
			if(G[i][j] == gioc){
				int InCol = 1;
				for(int k=1; k<n; k++){
					if(G[i+k][j] == gioc){
						InCol++;
					}
				}
				if(InCol == n){
					return 1;
				}
			}
		}
	}
	return 0;
}

int game_over(){
	int IsEnd = 1;
	for(int i = 0; i < c; i++){
		IsEnd *= G[0][i];
	} 
	if(IsEnd != 0){
		return 0;	
	}
	if(check_r(1) == 1 || check_c(1) == 1){
		return 1;
	}
	if(check_r(2) == 1 || check_c(2) == 1){
		return 2;
	}	
	return -1;
}
	
	

int main(int argc, char *argv[]){
	if(argc < 3){
		printf("Errore nel numero di argomenti\n");
		return 1;
	}
	n = atoi(argv[1]);
	r = atoi(argv[2]);
	c = atoi(argv[3]);
	G = malloc(r * sizeof(int*));
	if(G == NULL){
		printf("Errore di allocazione della memoria\n");
		return 1;
	}
	for(int i = 0; i < r; i++){
		G[i] = malloc(c * sizeof(int));
		if(G[i] == NULL){
			printf("Errore di allocazione della memoria\n");
		return 1;
		}
		for(int j = 0; j < c; j++){
			G[i][j] = 0;
		}
	}
	int play = -1;
	while(play==-1){
		show();
		int ctrl;
		do{
			ctrl = scrivi(1, leggi_mossa()-1);
		} while(ctrl == 0);
		play = game_over();
		show();
		if(play == -1){
			scrivi(2, (mossa()-1));
			printf("\n");
			play = game_over();
		}
	}
	switch(play){
		case 0:
			printf("La partita è terminata con un pareggio\n");
			break;
		case 1:
			printf("Complimenti, mi hai battuto\n");
			break;
		case 2:
			show();
			printf("Mi spiace, hai perso\n");
			break;
	}
	for(int i = 0; i < r; i++){
		free(G[i]);
	}
	free(G);
	return 0;
}


