#include <stdio.h>

int main() {
	float i;
	double n, sum;
	
	scanf("%d", &n);
	
	sum = 0;
	for(i = 1.0; i <= n; i++) {
		sum = sum + 1.0/i;
	}
	printf("n = %d,sum=%.7\n", n, sum);
	
	
	return 0;
} 