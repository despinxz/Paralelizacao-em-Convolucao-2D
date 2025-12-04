#include <stdio.h>
#include <stdlib.h>

#define KERNEL_SIZE 3
#define NORM_FACTOR 9.0 

const float kernel[KERNEL_SIZE * KERNEL_SIZE] = {
    1.0/NORM_FACTOR, 1.0/NORM_FACTOR, 1.0/NORM_FACTOR,
    1.0/NORM_FACTOR, 1.0/NORM_FACTOR, 1.0/NORM_FACTOR,
    1.0/NORM_FACTOR, 1.0/NORM_FACTOR, 1.0/NORM_FACTOR
};

// Função auxiliar para inicializar imagem com valores aleatórios
void init_image(float *image, int n) {
    srand(0); // Para garantir que a sequência seja a mesma em todos os testes
    for (int i = 0; i < n * n; i++) {
        image[i] = (float) (rand() % 256);
    }
}

// Função sequencial de convolução 2D
void convolution_2d_sequential(float *input, float *output, int n) {
    int i, j, k_i, k_j;
    int offset = KERNEL_SIZE / 2; // offset para controle das bordas

    // Loop para percorrer cada pixel da imagem de saída
    for (i = offset; i < n - offset; i++) {
        for (j = offset; j < n - offset; j++) {
            float sum = 0.0;

            // Loop para aplicar o kernel
            for (k_i = 0; k_i < KERNEL_SIZE; k_i++) {
                for (k_j = 0; k_j < KERNEL_SIZE; k_j++){
                    
                    // Coordenadas do pixel de entrada
                    int r = i + k_i - offset;
                    int c = j + k_j - offset;

                    int input_index = r * n + c;
                    int kernel_index = k_i * KERNEL_SIZE + k_j;

                    sum += input[input_index] * kernel[kernel_index];
                }
            }

            output[i * n + j] = sum;
        }
    }
}

int main() {
    
}