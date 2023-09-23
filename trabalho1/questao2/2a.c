#include<stdio.h>

double pow(double x, int power) {
    if (!power) return 1;
    return x * pow(x, power-1);
}

double F(double x) {
    return pow(x, 3) - (double)9.0*x + 3.0;
}

double dF(double x) {
    return (double)3*pow(x, 2) - 9.0;
}

double abs(double x) {
    if (x > 0) return x;
    return (double) (-1)*x;
}

double errRelativo(double x, double y) {
    return (abs(x - y) / abs(x));
}

int main() {
    int itt = 1;
    double xi = 0.5, e1 = 0.0001, e2 = 0.0001;
    double x;
    int podeProsseguir;
    do {
        podeProsseguir = 1;
        
        x = xi;
        xi = x - F(x)/dF(x);

        if (errRelativo(xi, x) < e2 && abs(F(xi)) < e1) {
            podeProsseguir = 0;
            printf("condicao de parada 1 e 2 encontradas\n");
        } else if (abs(F(xi)) < e1) {
            podeProsseguir = 0;
            printf("condicao de parada 1 encontrada\n");
        } else if (errRelativo(xi, x) < e2) {
            podeProsseguir = 0;
            printf("condicao de parada 2 encontrada\n");
        }

        printf("valor atual de x%i: %f\n", itt, xi);
        printf("valor da condicao de parada 1: %Lf\n", abs(F(xi)));
        printf("valor da condicao de parada 2: %Lf\n\n", errRelativo(xi, x));
        itt++;
    } while(podeProsseguir);

    printf("valor final para as condicoes de parada: %f\n", xi);

    return 0;
}