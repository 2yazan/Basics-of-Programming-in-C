// Given a matrix A, find the product of A and its transpose (A * A^T).

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

// Transposes the matrix
int** trm(int** mt, int rows, int cols) {
    int** At = (int**)calloc(cols, sizeof(int*)); // creates a new matrix
    for (int i = 0; i < cols; i++) {
        At[i] = (int*)calloc(rows, sizeof(int));
        for (int j = 0; j < rows; j++)
            At[i][j] = mt[j][i];
    }
    return At;
}

// Initializes a row of the matrix
void initRow(int** mx, int row, int col, ...) {
    va_list arg;
    va_start(arg, col);
    for (int i = 0; i < col; i++)
        mx[row][i] = va_arg(arg, int);
    va_end(arg);
}

// Multiplies matrices
int** mult(int** mt1, int rows1, int cols1, int** mt2, int rows2, int cols2) {
    int** Ar = (int**)calloc(rows1, sizeof(int*)); // new matrix
    for (int i = 0, k = 0; i < rows1; k++) {
        if (!k) Ar[i] = (int*)calloc(cols2, sizeof(int));
        Ar[i][k] = 0;
        for (int j = 0; j < cols1; j++)
            Ar[i][k] += mt1[i][j] * mt2[j][k]; // calculates values for the new matrix
        if (k + 1 == cols2) {
            i++;
            k = -1;
        }
    }
    return Ar;
}

// Prints the matrix
void print(int** mx, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", mx[i][j]);
        printf("\n");
    }
}

// Frees the matrix
void free_mx(int*** mx, int rows) {
    for (int i = 0; i < rows; i++)
        free((*mx)[i]);
    free(*mx);
    *mx = NULL;
}

int main() {

	const int row = 3;
	const int col = 4;
	int** A = (int**)calloc(row, sizeof(int*));
	for (int i = 0; i < row; i++)
		A[i] = (int*)calloc(col, sizeof(int));

	initRow(A, 0, col,/*matrix - */ 8, 4, 6, 5);
	initRow(A, 1, col,/*matrix - */ 2, 5, 4, 7);
	initRow(A, 2, col,/*matrix - */ 3, 6, 9, 9);
	int** At = trm(A, row, col); 
	int** Ar = mult(A, row, col, At, col, row);
	print(Ar, row, row);

	free_mx(&A, row);
	free_mx(&At, col);
	free_mx(&Ar, row);
	return 0;
}
