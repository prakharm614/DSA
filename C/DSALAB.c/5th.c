#include <stdio.h>
void matrixAddition(int rows, int cols, int A[rows][cols], int B[rows][cols], int C[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j]; }}}
void matrixSubtraction(int rows, int cols, int A[rows][cols], int B[rows][cols], int C[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] - B[i][j];  }}}
void matrixMultiplication(int rowsA, int colsA, int rowsB, int colsB, int A[rowsA][colsA],
                              int B[rowsB][colsB], int C[rowsA][colsB]) {
    if (colsA != rowsB) {
        printf("Matrix multiplication is not possible\n");
        return;}
for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            C[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                C[i][j] += A[i][k] * B[k][j];}}}}
   void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);}
        printf("\n");}}
int main() {
    int rows, cols;
    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d %d", &rows, &cols);
    int matrixA[rows][cols], matrixB[rows][cols], result[rows][cols];
    printf("Enter elements for matrix A:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrixA[i][j]);}}
             printf("Enter elements for matrix B:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrixB[i][j]);}}
            printf("Matrix A:\n");
    printMatrix(rows, cols, matrixA);
    printf("Matrix B:\n");
    printMatrix(rows, cols, matrixB);

    matrixAddition(rows, cols, matrixA, matrixB, result);
    printf("Matrix A + B:\n");
    printMatrix(rows, cols, result);

    matrixSubtraction(rows, cols, matrixA, matrixB, result);
    printf("Matrix A - B:\n");
    printMatrix(rows, cols, result);

    int rowsA = rows, colsA = cols, rowsB = rows, colsB = cols;
    matrixMultiplication(rowsA, colsA, rowsB, colsB, matrixA, matrixB, result);
    printf("Matrix A * B:\n");
    printMatrix(rowsA, colsB, result);

    return 0;
}
