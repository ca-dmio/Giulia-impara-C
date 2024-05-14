#include <stdio.h>

int fatt(int n){
	if(n==0){ return 1;}
	return n*fatt(n-1);
}
int bin(int n, int k){
	int fatt(int);
	return fatt(n)/(fatt(k)*fatt(n-k));
}
int Bell(int n){
	if(n<2){ return 1;}
	int bin(int,int);
	int cnt=0;
	for(int i=0; i<n; i++){
		cnt += (bin(n-1,i)*Bell(i)) ;
	}
	return cnt;
}

int main(void){
	int n;
	do{
		printf("Type a positive integer: ");
		scanf("%d", &n);
	} while(n<0);
	int Bell(int);
	printf("B(%d)=%d\n", n, Bell(n));
	return 0;
}
