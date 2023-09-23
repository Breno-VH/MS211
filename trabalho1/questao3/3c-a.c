#include<stdio.h>
#define n 4


double max(double a, double b) {
    return (a > b) ? a: b;
}

double abs(double x) {
    if (x > 0) return x;
    return (double) (-1)*x;
}

double errRelativo(double x, double y) {
    return (abs(x - y) / abs(x));
}

double Fx1(double x2, double x3, double x4) {
    return (double) (7 -2*x2 - x3 - x4)/2;
}

double Fx2(double x1, double x3, double x4) {
    return (double) (-1)*(1 - x1 - 2*x3 + x4);
}

double Fx3(double x1, double x2, double x4) {
    return (double) (-1)*(4 - 3*x1 - 2*x2 + 2*x4)/3;
}

double Fx4(double x1, double x2, double x3) {
    return (double) (12 - 4*x1 - 3*x2 - 2*x3);
}

int main() {
    double x[] = {0.0, 0.0, 0.0, 0.0};
    double matriz[n][n+1] = {{2.0, 2.0, 1.0, 1.0, 7.0},
                    {1.0, -1.0, 2.0, -1.0, 1.0},
                    {3.0, 2.0, -3.0, -2.0, 4.0},
                    {4.0, 3.0, 2.0, 1.0, 12.0}};
    int itt = 1;
    double tol = 0.05;
    //criterio de parada dist relativa. tolerancia 0.05
    //nmr max de itt = 100
    do {
        double x1 = Fx1(x[1], x[2], x[3]);
        double x2 = Fx2(x[0], x[2], x[3]);
        double x3 = Fx3(x[0], x[1], x[3]);
        double x4 = Fx4(x[0], x[1], x[2]);
        
        double e1, e2, e3, e4;
        e1 = max(errRelativo(x1, x[0]), abs(x1 - x[0]));
        e2 = max(errRelativo(x2, x[1]), abs(x2 - x[1]));
        e3 = max(errRelativo(x3, x[2]), abs(x3 - x[2]));
        e4 = max(errRelativo(x4, x[3]), abs(x4 - x[3]));
        if (e1 < tol || e2 < tol || e3 < tol || e4 < tol) {
            printf("e1 = %lf\n", e1);
            printf("e2 = %lf\n", e2);
            printf("e3 = %lf\n", e3);
            printf("e4 = %lf\n", e4);
            printf("condicao de parada de tolerancia encontrada\n");
            break;
        }
        x[0] = x1;
        x[1] = x2;
        x[2] = x3;
        x[3] = x4;
        printf("valores de iteracao %i:\n", itt);
        for (int i = 0; i < n; i++) {
            printf("x%i: %lf\n", i, x[i]);
        }
        printf("\n");
        itt++;
    } while(itt < 100);
    printf("valores finais encontrados:\n");
    for (int i = 0; i < n; i++) {
        printf("x%i: %lf\n", i, x[i]);
    }

    return 0;
} 