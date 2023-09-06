//github: sudipde3

#include <stdio.h>
#include <math.h>

// 1. Function to print the value and address of a variable
void printValueAndAddress(int *ptr) {
    printf("Value: %d\n", *ptr);
    printf("Address: %p\n", ptr);
}

// 2. 
void printArrayAddress(int *ptr) {
    printf("Array Address: %p\n", ptr);
    printf("Arr[0] Address: %p\n", &ptr[0]);
}

// 3.
void minMaxFun(int *arr, int size, int *min, int *max) {
    *min = *max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        }
        if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}

// 4. 
void funNorArr(int *arr, int n, float *arrN) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    float meanOfArr = sum / n;
    float sdOfArr = 0;
    for (int i = 0; i < n; i++) {
        sdOfArr += pow(arr[i] - meanOfArr, 2);
    }
    sdOfArr = sqrt(sdOfArr / n);
    for (int i = 0; i < n; i++) {
        arrN[i] = (arr[i] - meanOfArr) / sdOfArr;
    }
}

void normalizeArray(int *arr, int size, int *arrN) {
    int min, max;
    minMaxFun(arr, size, &min, &max);
    
    for (int i = 0; i < size; i++) {
        arrN[i] = (arr[i] - min) / (max - min);
    }
}

// 6.
void diagonalEntries(int **matrix, int rows, int cols, int *diagonal) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == j) {
                diagonal[i] = matrix[i][j];
            }
        }
    }
}

int main() {
    int num = 10;
    int Arr[] = {1, 5, 3, 7, 2};
    int ArrN[5];
    int min, max;
    
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int diagonal[3];
    
    printValueAndAddress(&num);
    printArrayAddress(Arr);
    
    minMaxFun(Arr, 5, &min, &max);
    printf("Min: %d, MAx: %d\n", min, max);
    
    normalizeArray(Arr, 5, ArrN);
    printf("Normalized Array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", ArrN[i]);
    }
    printf("\n");
    
    int *matrixPtr[3];
    for (int i = 0; i < 3; i++) {
        matrixPtr[i] = matrix[i];
    }
    
    diagonalEntries(matrixPtr, 3, 3, diagonal);
    printf("Diagonal Entries: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", diagonal[i]);
    }
    printf("\n");
    
    return 0;
}