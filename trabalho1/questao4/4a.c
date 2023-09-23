#include<stdio.h>

double jacobMatriz[2][2];
double jacobInvertido[2][2];
double x1 = 1.0;
double x2 = 1.0;

double pow(double x, double pot) {
    if (pot == 0) return 1;
    return x * pow(x, pot-1);
}

void F(double *arr, double x1_i, double x2_i) {
    arr[0] = 4*x1_i - pow(x1_i, 3) + x2_i;
    arr[1] = -1.0*pow(x1_i, 2)/9.0 + (4.0*x2_i - pow(x2_i, 2))/4.0 + 1;
}

void calculaJacob(double x1, double x2) {
    jacobMatriz[0][0] = 4.0 - 3*pow(x1, 2);
    jacobMatriz[0][1] = 1.0;
    jacobMatriz[1][0] = (-2.0/9.0) * x1;
    jacobMatriz[1][1] = 1.0 - x2/2.0;
}

void inverteMatriz() {
    double determinante = jacobMatriz[0][0] * jacobMatriz[1][1] -
     jacobMatriz[0][1] * jacobMatriz[1][0];
    if (determinante == 0) {
        printf("impossivel inverter essa matriz\n");
        return;
    }
    jacobInvertido[0][0] = jacobMatriz[1][1];
    jacobInvertido[0][1] = -1.0 * jacobMatriz[0][1];
    jacobInvertido[1][0] = -1.0 * jacobMatriz[1][0];
    jacobInvertido[1][1] = jacobMatriz[0][0];
    return;
}

void multiplicaMatriz(double *sol) {
    double *fx = sol;


    double res1 = jacobInvertido[0][0] * fx[0] + jacobInvertido[0][1] * fx[1];
    double res2 = jacobInvertido[1][0] * fx[0] + jacobInvertido[1][1] * fx[1];

    fx[0] -= res1;
    fx[1] -= res2;
}

int main() {
    
    double tol = 0.0001;
    int itt = 1;

    do {


        itt++;
    } while (itt < 100);


    return 0;
}