#include <stdio.h> 

/*求矩阵的局部最大值*/

int fun(int m, int n) {
	int martix[m][n];
	int val;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &val);
			martix[i][j] = val;
		}
	}
	int value;
	int flag = 0;
	for (int i = 1; i < m - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			value = martix[i][j];
			if (value > martix[i - 1][j] &&
				value > martix[i + 1][j] &&
				value > martix[i][j - 1] &&
				value > martix[i][j + 1]) {
					printf("%d %d %d\n", value, i + 1, j + 1);
					flag = 1;
				}
		}
	}
	if (flag == 0) {
		printf("None %d %d", m, n);
	}
	return 0;
} 

int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	fun(m, n);
	return 0;
}
