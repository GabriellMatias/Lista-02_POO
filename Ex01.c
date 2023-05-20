#include <stdio.h>

// Função para validar se um número está entre 1 e 99
int le_valida_num() {
    int num;
    do {
        printf("Digite um número entre 1 e 99: ");
        scanf("%d", &num);
    } while (num < 1 || num > 99);
    return num;
}

// Função para ordenar o array usando o Bubble Sort
void bubbleSort(int array[], int tamanho) {
    int i, j, temp;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Troca os elementos
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main() {
    int numeros[20];
    int i, qtd_numeros;

    printf("Informe entre 10 e 20 números inteiros.\n");
    printf("Digite -1 para finalizar após informar os 10 primeiros números.\n\n");

    // Leitura dos números e validação
    for (i = 0; i < 20; i++) {
        if (i == 10) {
            printf("\nVocê informou 10 números. Deseja sair? (Digite -1 para sair, ou continue informando): ");
            scanf("%d", &qtd_numeros);
            if (qtd_numeros == -1)
                break;
        }

        numeros[i] = le_valida_num();
    }

    qtd_numeros = i; // Atualiza a quantidade real de números informados

    // Ordenação dos números usando o Bubble Sort
    bubbleSort(numeros, qtd_numeros);

    // Exibição dos números ordenados
    printf("\nNúmeros ordenados de forma crescente:\n");
    for (i = 0; i < qtd_numeros; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}
