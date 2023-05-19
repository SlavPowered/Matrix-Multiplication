#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void MatrixMultiplication(float* M, float* N, float* P, int height, int width, int depth) {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < depth; col++) {
            float pvalue = 0;
            for (int k = 0; k < width; k++) {
                pvalue += M[row * width + k] * N[k * depth + col];
            }
            P[row * depth + col] = pvalue;
        }
    }
}

int main() {
    clock_t start, end;

    int N = 1024; 
    int M = 512; 
    int K = 2048;

    float *h_M = (float*)malloc(N * M * sizeof(float));
    float *h_N = (float*)malloc(M * K * sizeof(float));
    float *h_P = (float*)malloc(N * K * sizeof(float));

    srand(time(NULL));
    for (int i = 0; i < N * M; i++) {
        h_M[i] = rand() / (float)RAND_MAX;
    }
    for (int i = 0; i < M * K; i++) {
        h_N[i] = rand() / (float)RAND_MAX;
    }
    start = clock();
    MatrixMultiplication(h_M, h_N, h_P, N, M, K);
    end = clock();

    double duration = ((double) end - start)/CLOCKS_PER_SEC;

    printf("Execution time: %f", duration);
    free(h_M);
    free(h_N);
    free(h_P);

    return 0;
}

