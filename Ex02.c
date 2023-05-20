#include <stdio.h>

// Função para validar se um número está entre 1 e 99, é ímpar e não é múltiplo de 3
int le_valida_num() {
    int num;
    do {
        printf("Digite um número ímpar não múltiplo de 3 entre 1 e 99: ");
        scanf("%d", &num);
    } while (num < 1 || num > 99 || num % 2 == 0 || num % 3 == 0);
    return num;
}

// Função para ordenar o array usando o método de inserção (Insertion Sort)
void insertionSort(int array[], int tamanho) {
    int i, j, chave;
    for (i = 1; i < tamanho; i++) {
        chave = array[i];
        j = i - 1;
        while (j >= 0 && array[j] < chave) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = chave;
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

    // Ordenação dos números usando o método de inserção (Insertion Sort)
    insertionSort(numeros, qtd_numeros);

    // Exibição dos números ordenados em ordem decrescente
    printf("\nValores ordenados de forma decrescente:\n");
    for (i = 0; i < qtd_numeros; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}
