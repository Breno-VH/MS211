#include<stdio.h>

int main() {
    float xi = 0.5;
    double resultado = 0;

    for (int i = 1; i <= 30000; i++) {
        resultado += xi;
    }
    printf("%0.15f\n", resultado);

    resultado = 0;
    xi = 0.11;

    for (int i = 1; i <= 30000; i++) {
        resultado += xi;
    }
    printf("%0.15f\n", resultado);

    return 0;
}