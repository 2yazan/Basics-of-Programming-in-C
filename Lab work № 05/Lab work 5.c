// Given an array of square matrices, determine the number of matrices 
// whose rows are ordered in non-increasing order of their elements.

#include <stdio.h>

int check(int(*mx)[3]) {
	for (int i = 0; i < 3; i++) {
		int p = mx[i][0];
		for (int j = 1; j < 3; j++)
			if (mx[i][j] > p)return 0;
			else
				p = mx[i][j];
	}
	return 1;
}

int count(int(*mx)[3][3], int cnt) {
	int c = 0;
	for (int i = 0; i < cnt; i++)
		c += check(mx[i]);
	return c;
}

int main() {
	int A[3][3][3] = {
		{
		{1,2,3},
		{3,4,2},
		{3,2,6}
		},
		{
		{3,2,1},
		{6,4,2},
		{8,6,6}
		},
		{
		{1,4,3},
		{3,7,2},
		{3,2,6}
		}
	};
	int cnt = count(A, 3);
	printf("%d", cnt);
	return 0;
}
