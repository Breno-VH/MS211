#include<stdio.h>
#define n 4


double abs(double x) {
    if (x > 0) return x;
    return (double) (-1)*x;
}


int main() {
    double x[] = {0.0, 0.0, 0.0, 0.0};
    double matriz[n][n+1] = {{2.0, 2.0, 1.0, 1.0, 7.0},
                    {1.0, -1.0, 2.0, -1.0, 1.0},
                    {3.0, 2.0, -3.0, -2.0, 4.0},
                    {4.0, 3.0, 2.0, 1.0, 12.0}};

    
    for (int k = 0; k < n; k++) {
        // encontrando o melhor pivo e mudar as linhas
        // para deixar a matriz triangular
        int linhaPivo = k;
        int maxPivo = 0.0;

        for (int i = k; i < n; i++) {
            if (abs(matriz[i][k]) > maxPivo) {
                linhaPivo = i;
            }
        }

        //trocando os elementos das culunas
        if (linhaPivo != k) {
            for (int i = k; i < n+1; i++) {
                double temp;
                temp = matriz[linhaPivo][i];
                matriz[linhaPivo][i] = matriz[k][i];
                matriz[k][i] = temp;
            }
        }

        //eliminando as variaveis
        for (int i = k+1; i < n; i++) {
            double m = matriz[i][k] / matriz[k][k];
            for (int j = k; j < n+1; j++) {
                matriz[i][j] -= m*matriz[k][j];
            }
        }
    }

    for (int k = n-1; k >= 0; k--) {
        double soma = matriz[k][n];
        for (int j = k+1; j < n; j++) {
            soma -= matriz[k][j] * x[j];
        }
        x[k] = soma / matriz[k][k];
    }

    for (int i = 0; i < n; i++) {
        printf("%lf\n", x[i]);
    }

    return 0;
}