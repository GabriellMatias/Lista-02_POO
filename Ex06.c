#include <stdio.h>

// Função que recebe um parâmetro por valor
void passagemPorValor(int valor) {
    valor = valor + 10;
    printf("Dentro da função (por valor): %d\n", valor);
}

// Função que recebe um parâmetro por referência
void passagemPorReferencia(int* valor) {
    *valor = *valor + 10;
    printf("Dentro da função (por referência): %d\n", *valor);
}

int main() {
    int num = 5;

    printf("Antes da chamada da função:\n");
    printf("Valor: %d\n", num);

    // Chamada da função com passagem por valor
    passagemPorValor(num);

    printf("Depois da chamada da função (por valor):\n");
    printf("Valor: %d\n", num);

    printf("\n");

    printf("Antes da chamada da função:\n");
    printf("Valor: %d\n", num);

    // Chamada da função com passagem por referência
    passagemPorReferencia(&num);

    printf("Depois da chamada da função (por referência):\n");
    printf("Valor: %d\n", num);

    return 0;
}