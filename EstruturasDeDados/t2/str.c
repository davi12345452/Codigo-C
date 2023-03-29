#include "str.h"
#include <stdlib.h>
#include <string.h>

typedef struct _str {
    char *texto;
    int tamanho;
} str;

Str str_cria(char *s) {
    Str nova_str = (Str)malloc(sizeof(str));
    if (nova_str == NULL) {
        return NULL;
    }

    nova_str->tamanho = strlen(s);
    nova_str->texto = (char *)malloc((nova_str->tamanho + 1) * sizeof(char));
    strcpy(nova_str->texto, s);

    return nova_str;
}

Str str_cria_linha(FILE *arq) {
    Str nova_str = NULL;
    char *linha = NULL;
    size_t tamanho = 0;
    ssize_t caracteres_lidos;

    caracteres_lidos = getline(&linha, &tamanho, arq);
    if (caracteres_lidos > 0) {
        if (linha[caracteres_lidos - 1] == '\n') {
            linha[caracteres_lidos - 1] = '\0';
            caracteres_lidos--;
        }
        nova_str = str_cria(linha);
    }

    free(linha);
    return nova_str;
}

void str_destroi(Str s) {
    if (s != NULL) {
        free(s->texto);
        free(s);
    }
}

int str_tam(Str s) {
    return s->tamanho;
}

int str_char(Str s, int i) {
    if (i < 0) {
        i += s->tamanho;
    }

        if (i < 0 || i >= s->tamanho) {
        return -1;
    }

    return s->texto[i];
}

Str str_substr(Str s, int p, int n) {
    if (p < 0) {
        p += s->tamanho;
    }

    if (p < 0 || p >= s->tamanho || n < 1) {
        return str_cria("");
    }

    int tamanho_substring = n;
    if (p + n > s->tamanho) {
        tamanho_substring = s->tamanho - p;
    }

    char *substring = (char *)malloc((tamanho_substring + 1) * sizeof(char));
    strncpy(substring, s->texto + p, tamanho_substring);
    substring[tamanho_substring] = '\0';

    Str nova_str = str_cria(substring);
    free(substring);

    return nova_str;
}

int str_poschar(Str s, int c) {
    for (int i = 0; i < s->tamanho; i++) {
        if (s->texto[i] == c) {
            return i;
        }
    }

    return -1;
}

bool str_igual(Str s, Str o) {
    if (s->tamanho != o->tamanho) {
        return false;
    }

    return strcmp(s->texto, o->texto) == 0;
}

Str str_altera(Str s, int p, int n, Str o) {
    if (p < 0) {
        p += s->tamanho;
    }

    if (p < 0) {
        p = 0;
    }

    if (p >= s->tamanho) {
        p = s->tamanho;
    }

    if (n < 0) {
        n = 0;
    }

    int tamanho_novo = s->tamanho - n + o->tamanho;
    char *novo_texto = (char *)malloc((tamanho_novo + 1) * sizeof(char));

    strncpy(novo_texto, s->texto, p);
    strncpy(novo_texto + p, o->texto, o->tamanho);
    strcpy(novo_texto + p + o->tamanho, s->texto + p + n);

    free(s->texto);
    s->texto = novo_texto;
    s->tamanho = tamanho_novo;

    return s;
}

#ifdef TESTE
void str_teste(void) {
    // Implemente os testes para o TAD Str
}
#endif

