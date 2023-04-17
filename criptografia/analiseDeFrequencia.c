/*
Nesta tarefa de programação, você deverá implementar o método básico de análise de frequência para quebrar cifras de substituição monoalfabética.

Seu programa (ou conjunto de programas) deverá ser capaz de:

- criar uma tabela de frequência (histograma) a partir de um arquivo de texto puro, e armazenar esta tabela.

- mostrar os N (N dado pelo usuário) caracteres mais frequentes encontrados.
-OPCIONAL: contar também a frequência de pares de caracteres (digramas) encontrados
Exemplo: Use seu código na cifra de substituição monoalfabética simples abaixo
CIFRA: HQKQWTFLCGETRTEGROYOEGXQDTFLQUTDLTEKTZQ
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Função para calcular a frequência de cada letra na cifra
void calculateFrequency(char *cipher, int freq_table[]) {
    int i;
    for (i = 0; cipher[i] != '\0'; i++) {
        if (isalpha(cipher[i])) {
            freq_table[tolower(cipher[i]) - 'a']++;
        }
    }
}

int main() {
    char cipher[] = "HQKQWTFLCGETRTEGROYOEGXQDTFLQUTDLTEKTZQ";
    int freq_table[ALPHABET_SIZE] = {0};

    calculateFrequency(cipher, freq_table);

    // Abre o arquivo para escrita
    FILE *file = fopen("tabela.txt", "w");

    if (file == NULL) {
        printf("Erro ao criar o arquivo.");
        return 1;
    }

    // Escreve a tabela de frequência no arquivo
    int i;
    for (i = 0; i < ALPHABET_SIZE; i++) {
        fprintf(file, "%c: %d\n", i + 'a', freq_table[i]);
    }

    // Fecha o arquivo
    fclose(file);

    return 0;
}