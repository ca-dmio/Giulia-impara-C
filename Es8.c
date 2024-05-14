#include <stdio.h>

int M(int n){
	if(n==0){ return 0;}
	int F(int);
	return n-F(M(n-1));
}
int F(int n){
	if(n==0){ return 1;}
	int M(int);
	return n-M(F(n-1));
}

int main(void){
	int n;
	do{
		printf("Type a positive integer: ");
		scanf("%d", &n);
	} while(n<0);
	printf("n\tF(n)\tM(n)\n");
	int F(int);
	int M(int);
	for(int i=0; i<=n; i++){
		printf("%d\t%d\t%d\n", i, F(i), M(i));
	}
	return 0;
}
