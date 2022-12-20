#include <stdio.h>

#define N 21
#define NCOL 35

// Função para encontrar o maior valor entre os dois vetores
float max(float v1[N], float v2[N]) {
float m = v1[0];
for (int i = 1; i < N; i++) {
if (v1[i] > m) m = v1[i];
if (v2[i] > m) m = v2[i];
}
return m;
}

// Função para desenhar uma linha da pirâmide
void desenha_linha(float v1, float v2, int idade) {
int n1 = v1 * NCOL / max(v1, v2);
int n2 = v2 * NCOL / max(v1, v2);
printf(" ");
for (int i = 0; i < NCOL - n1; i++) printf(" ");
for (int i = 0; i < n1; i++) printf("X");
printf(" ");
for (int i = 0; i < n2; i++) printf("X");
for (int i = 0; i < NCOL - n2; i++) printf(" ");
printf(" %2d\n", idade);
}

// Função principal para desenhar a pirâmide
void desenha_piramide(float ph[N], float pf[N]) {
printf("\n");
for (int i = 0; i < N; i++) {
desenha_linha(ph[i], pf[i], N - i - 1);
}
}

int main(void) {
float ph[N] = {200, 190, 180, 170, 160, 150, 140, 129, 120, 110, 100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 0};
float pf[N] = {200, 190, 220, 170, 160, 150, 140, 129, 120, 40, 100, 90, 80, 70, 70, 50, 40, 30, 20, 10, 0};
desenha_piramide(ph, pf);
return 0;
}
