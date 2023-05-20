#include <stdio.h>

int le_valida_num() {
    int num;
    printf("Digite um número inteiro entre 1 e 99 (par e não múltiplo de 5): ");
    scanf("%d", &num);
    
    while (num < 1 || num > 99 || num % 2 != 0 || num % 5 == 0) {
        printf("Número inválido. Tente novamente.\n");
        printf("Digite um número inteiro entre 1 e 99 (par e não múltiplo de 5): ");
        scanf("%d", &num);
    }
    
    return num;
}

void selectionSort(int numeros[], int n) {
    int i, j, min_idx, max_idx, temp;
    
    // Ordenação crescente
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (numeros[j] < numeros[min_idx]) {
                min_idx = j;
            }
        }
        temp = numeros[min_idx];
        numeros[min_idx] = numeros[i];
        numeros[i] = temp;
    }
    
    // Ordenação decrescente
    for (i = 0; i < n - 1; i++) {
        max_idx = i;
        for (j = i + 1; j < n; j++) {
            if (numeros[j] > numeros[max_idx]) {
                max_idx = j;
            }
        }
        temp = numeros[max_idx];
        numeros[max_idx] = numeros[i];
        numeros[i] = temp;
    }
}

int main() {
    int numeros[10];
    int i, n;
    
    printf("Digite a quantidade de números que deseja informar (mínimo 2, máximo 10): ");
    scanf("%d", &n);
    
    while (n < 2 || n > 10) {
        printf("Quantidade inválida. Tente novamente.\n");
        printf("Digite a quantidade de números que deseja informar (mínimo 2, máximo 10): ");
        scanf("%d", &n);
    }
    
    for (i = 0; i < n; i++) {
        numeros[i] = le_valida_num();
    }
    
    selectionSort(numeros, n);
    
    printf("Valores ordenados em ordem crescente:\n");
    for (i = 0; i < n; i++) {
        printf("%d\n", numeros[i]);
    }
    
    printf("Valores ordenados em ordem decrescente:\n");
    for (i = n - 1; i >= 0; i--) {
        printf("%d\n", numeros[i]);
    }
    
    return 0;
}
