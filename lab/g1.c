#include <stdio.h>

float tribonacci(int n){
	if(n==-1||n==0)
		return 0;
	if(n==1)
		return 1;
	else
		return tribonacci(n-3)+tribonacci(n-2)+tribonacci(n-1);
}	

int main() {
	int n,i;
	printf("Inserisci numero di ricorsioni: ");
	scanf("%d",&n);
	printf("\nSerie di tribonacci:\n");
	printf("%.0f ",tribonacci(n));
	printf("\n\n--FINE--\n");
	return 0;
}
	
	