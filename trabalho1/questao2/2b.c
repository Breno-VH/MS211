#include<stdio.h>

long double pow(long double x, int power) {
    if (!power) return 1;
    return x * pow(x, power-1);
}

long double F(long double x) {
    return pow(x, 3) - (long double)9.0*x + 3.0;
}


long double abs(long double x) {
    if (x > 0) return x;
    return (long double) (-1)*x;
}

long double errRelativo(long double x, long double y) {
    return abs(abs(x - y)/x);
}

int main() {
    int itt = 2;
    long double x1 = 0.0, x2 = 1.0 , e1 = 0.0005, e2 = 0.0001;
    long double x3;
    int podeProsseguir;
    do {
        podeProsseguir = 1;
        //tamo checando as condicoes de parada depois de ja atualizar os valores
        long double f1 = F(x1);
        long double f2 = F(x2);
        
        x3 = x2 - f2*(x2-x1)/(f2-f1);
        printf("valor atual de x%i: %Lf\n", itt, x3);

        if (errRelativo(x3, x2) < e2 && abs(F(x3)) < e1) {
            podeProsseguir = 0;
            printf("condicao de parada 1 e 2 encontradas\n");
        } else if (abs(F(x3)) < e1) {
            podeProsseguir = 0;
            printf("condicao de parada 1 encontrada\n");
        } else if (errRelativo(x3, x2) < e2) {
            podeProsseguir = 0;
            printf("condicao de parada 2 encontrada\n");
        }
        printf("valor da condicao de parada 1: %Lf\n", abs(F(x3)));
        printf("valor da condicao de parada 2: %Lf\n\n", errRelativo(x3, x2));

        x1 = x2;
        x2 = x3;
        itt++;
    } while(podeProsseguir);

    printf("valor final para as condicoes de parada: %Lf\n", x3);

    return 0;
}