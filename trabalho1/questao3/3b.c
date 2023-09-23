#include<stdio.h>
#define n 4


double abs(double x) {
    if (x > 0) return x;
    return (double) (-1)*x;
}


int main() {
    double matrizH[n][n];
    double vetorB[n];
    double x[n];
    double matrizJustaposta[n][n+1];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrizH[i][j] = (double)1/((i+1)+(j+1)-1);
        }
    }

    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < n; j++) {
            sum += (double) 1/((double)(i+1) + (j+1) -1);
        }
        vetorB[i] = sum;
    }

    int i, j;
    for (i=0; i < n; i++) {
        for (j=0; j < n; j++) {
            matrizJustaposta[i][j] = matrizH[i][j];
        }
        matrizJustaposta[i][n] = vetorB[i];
    }

    //aqui comecamos a resolver
    
    for (int k = 0; k < n; k++) {
        // encontrando o melhor pivo e mudar as linhas
        // para deixar a matriz triangular
        int linhaPivo = k;
        int maxPivo = 0.0;

        for (int i = k; i < n; i++) {
            if (abs(matrizJustaposta[i][k]) > maxPivo) {
                linhaPivo = i;
            }
        }

        //trocando os elementos das culunas
        if (linhaPivo != k) {
            for (int i = k; i < n+1; i++) {
                double temp;
                temp = matrizJustaposta[linhaPivo][i];
                matrizJustaposta[linhaPivo][i] = matrizJustaposta[k][i];
                matrizJustaposta[k][i] = temp;
            }
        }

        //eliminando as variaveis
        for (int i = k+1; i < n; i++) {
            double m = matrizJustaposta[i][k] / matrizJustaposta[k][k];
            for (int j = k; j < n+1; j++) {
                matrizJustaposta[i][j] -= m*matrizJustaposta[k][j];
            }
        }
    }

    for (int k = n-1; k >= 0; k--) {
        double soma = matrizJustaposta[k][n];
        for (int j = k+1; j < n; j++) {
            soma -= matrizJustaposta[k][j] * x[j];
        }
        x[k] = soma / matrizJustaposta[k][k];
    }


    for (int i = 0; i < n; i++) {
        printf("%lf\n", x[i]);
    }

    return 0;
}