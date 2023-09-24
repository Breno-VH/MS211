#include<stdio.h>
#include<math.h>

#define f(x) pow(x, 3) - 9*x + 3

long double abs(long double x) {
    if (x > 0) return x;
    return (long double) (-1)*x;
}

long double errRelativo(long double x, long double y) {
    return abs(abs(x - y)/x);
}

int main() {
    long double x0=2.0, x1=12.0, xi, f0, f1, fi, e1 = 0.0005, e2 = 0.0001;
    int itt = 2;
    f0 = f(x0);
    f1 = f(x1);
    int invalido = 0;
    if (f0 * f1 > 0.0) {
        printf("Ocorreu um erro e o intervalo entre f(x0) e f(x1) nao pode ser usado para o metodo da bisseccao \n");
        invalido = 1;
    }

    int podeProsseguir;
    do {
        if (invalido) break;
        podeProsseguir = 1;
        xi = (x0+x1)/2;
        fi = f(xi);

        printf("valor atual de x%i: %Lf\n", itt, xi);

        if (errRelativo(xi, x1) < e2 && abs(f(xi)) < e1) {
            podeProsseguir = 0;
            printf("condicao de parada 1 e 2 encontradas\n");
        } else if (abs(f(xi)) < e1) {
            podeProsseguir = 0;
            printf("condicao de parada 1 encontrada\n");
        } else if (errRelativo(xi, x1) < e2) {
            podeProsseguir = 0;
            printf("condicao de parada 2 encontrada\n");
        }
        printf("valor da condicao de parada 1: %Lf\n", abs(f(xi)));
        printf("valor da condicao de parada 2: %Lf\n\n", errRelativo(xi, x1));
        if (f0 * fi < 0) {
            x1 = xi;
            f1 = fi;
        } else {
            x0 = xi;
            f0 = fi;
        }
        itt++;
    } while(podeProsseguir);

    printf("valor final para as condicoes de parada: %Lf\n", xi);
    return 0;
}