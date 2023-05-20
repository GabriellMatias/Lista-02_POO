#include <stdio.h>
#include <string.h>

#define MAX_FABRICANTES 5
#define MAX_PRODUTOS 50
#define MAX_DESCRICAO 50
#define MAX_MARCA 50
#define MAX_SITE 50
#define MAX_TELEFONE 15

// Struct para armazenar informações de Fabricante
typedef struct {
    char marca[MAX_MARCA];
    char site[MAX_SITE];
    char telefone[MAX_TELEFONE];
    char UF[3];
} Fabricante;

// Struct para armazenar informações de Produto
typedef struct {
    char descricao[MAX_DESCRICAO];
    float peso;
    float valorCompra;
    float valorVenda;
    float valorLucro;
    float percentualLucro;
    Fabricante fabricante;
} Produto;

// Função para listar todas as marcas
void listarMarcas(Produto produtos[], int quantidadeProdutos) {
    int i;
    for (i = 0; i < quantidadeProdutos; i++) {
        printf("%s\n", produtos[i].fabricante.marca);
    }
}

// Função para listar todos os produtos
void listarProdutos(Produto produtos[], int quantidadeProdutos) {
    int i;
    for (i = 0; i < quantidadeProdutos; i++) {
        printf("Produto %d:\n", i + 1);
        printf("Descrição: %s\n", produtos[i].descricao);
        printf("Peso: %.2f\n", produtos[i].peso);
        printf("Valor de compra: %.2f\n", produtos[i].valorCompra);
        printf("Valor de venda: %.2f\n", produtos[i].valorVenda);
        printf("Valor do lucro: %.2f\n", produtos[i].valorLucro);
        printf("Percentual do lucro: %.2f%%\n", produtos[i].percentualLucro);
        printf("Fabricante: %s\n", produtos[i].fabricante.marca);
        printf("\n");
    }
}

// Função para listar os produtos de um determinado estado
void listarProdutosPorEstado(Produto produtos[], int quantidadeProdutos, char estado[3]) {
    int i;
    for (i = 0; i < quantidadeProdutos; i++) {
        if (strcmp(produtos[i].fabricante.UF, estado) == 0) {
            printf("Produto %d:\n", i + 1);
            printf("Descrição: %s\n", produtos[i].descricao);
            printf("Peso: %.2f\n", produtos[i].peso);
            printf("Valor de compra: %.2f\n", produtos[i].valorCompra);
            printf("Valor de venda: %.2f\n", produtos[i].valorVenda);
            printf("Valor do lucro: %.2f\n", produtos[i].valorLucro);
            printf("Percentual do lucro: %.2f%%\n", produtos[i].percentualLucro);
            printf("Fabricante: %s\n", produtos[i].fabricante.marca);
            printf("\n");
        }
    }
}

// Função para listar os produtos de uma determinada marca
void listarProdutosPorMarca(Produto produtos[], int quantidadeProdutos, char marca[MAX_MARCA]) {
    int i;
    for (i = 0; i < quantidadeProdutos; i++) {
        if (strcmp(produtos[i].fabricante.marca, marca) == 0) {
            printf("Produto %d:\n", i + 1);
            printf("Descrição: %s\n", produtos[i].descricao);
            printf("Peso: %.2f\n", produtos[i].peso);
            printf("Valor de compra: %.2f\n", produtos[i].valorCompra);
            printf("Valor de venda: %.2f\n", produtos[i].valorVenda);
            printf("Valor do lucro: %.2f\n", produtos[i].valorLucro);
            printf("Percentual do lucro: %.2f%%\n", produtos[i].percentualLucro);
            printf("Fabricante: %s\n", produtos[i].fabricante.marca);
            printf("\n");
        }
    }
}

// Função para apresentar o(s) estado(s) onde está registrado o produto mais caro
void listarEstadoProdutoMaisCaro(Produto produtos[], int quantidadeProdutos) {
    int i;
    float maiorValor = produtos[0].valorVenda;
    for (i = 1; i < quantidadeProdutos; i++) {
        if (produtos[i].valorVenda > maiorValor) {
            maiorValor = produtos[i].valorVenda;
        }
    }
    for (i = 0; i < quantidadeProdutos; i++) {
        if (produtos[i].valorVenda == maiorValor) {
            printf("Estado: %s\n", produtos[i].fabricante.UF);
        }
    }
}

// Função para apresentar o(s) fabricante(s) onde está registrado o produto mais barato
void listarFabricanteProdutoMaisBarato(Produto produtos[], int quantidadeProdutos) {
    int i;
    float menorValor = produtos[0].valorVenda;
    for (i = 1; i < quantidadeProdutos; i++) {
        if (produtos[i].valorVenda < menorValor) {
            menorValor = produtos[i].valorVenda;
        }
    }
    for (i = 0; i < quantidadeProdutos; i++) {
        if (produtos[i].valorVenda == menorValor) {
            printf("Fabricante: %s\n", produtos[i].fabricante.marca);
        }
    }
}

// Função de comparação para ordenação dos produtos por valor
int compararProdutosPorValor(const void* produto1, const void* produto2) {
    const Produto* p1 = (const Produto*)produto1;
    const Produto* p2 = (const Produto*)produto2;
    return (p1->valorVenda - p2->valorVenda);
}

// Função para listar todos os produtos em ordem crescente de valor
void listarProdutosPorValorCrescente(Produto produtos[], int quantidadeProdutos) {
    qsort(produtos, quantidadeProdutos, sizeof(Produto), compararProdutosPorValor);
    listarProdutos(produtos, quantidadeProdutos);
}

// Função de comparação para ordenação dos produtos por valor do lucro
int compararProdutosPorLucro(const void* produto1, const void* produto2) {
    const Produto* p1 = (const Produto*)produto1;
    const Produto* p2 = (const Produto*)produto2;
    return (p1->valorLucro - p2->valorLucro);
}

// Função para listar todos os produtos em ordem crescente de maior valor do lucro
void listarProdutosPorLucroCrescente(Produto produtos[], int quantidadeProdutos) {
    qsort(produtos, quantidadeProdutos, sizeof(Produto), compararProdutosPorLucro);
    listarProdutos(produtos, quantidadeProdutos);
}

int main() {
    Fabricante fabricantes[MAX_FABRICANTES];
    Produto produtos[MAX_PRODUTOS];
    int quantidadeFabricantes = 0;
    int quantidadeProdutos = 0;

    int opcao;
    do {
        printf("Menu:\n");
        printf("1. Cadastrar Fabricante\n");
        printf("2. Cadastrar Produto\n");
        printf("3. Listar todas as marcas\n");
        printf("4. Listar todos os produtos\n");
        printf("5. Listar os produtos de um determinado estado\n");
        printf("6. Listar os produtos de uma determinada marca\n");
        printf("7. Apresentar o(s) estado(s) onde está registrado o produto mais caro\n");
        printf("8. Apresentar o(s) fabricante(s) onde está registrado o produto mais barato\n");
        printf("9. Listar todos os produtos em ordem crescente de valor\n");
        printf("10. Listar todos os produtos em ordem crescente de maior valor do lucro\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                if (quantidadeFabricantes < MAX_FABRICANTES) {
                    Fabricante fabricante;
                    printf("Cadastro de Fabricante:\n");
                    printf("Marca: ");
                    scanf("%s", &fabricante.marca);
                    printf("Site: ");
                    scanf("%s", &fabricante.site);
                    printf("Telefone: ");
                    scanf("%s", &fabricante.telefone);
                    printf("UF: ");
                    scanf("%s", &fabricante.UF);
                    fabricantes[quantidadeFabricantes] = fabricante;
                    quantidadeFabricantes++;
                    printf("Fabricante cadastrado com sucesso!\n\n");
                } else {
                    printf("Limite máximo de fabricantes alcançado!\n\n");
                }
                break;
            }
            case 2: {
                if (quantidadeProdutos < MAX_PRODUTOS) {
                    Produto produto;
                    printf("Cadastro de Produto:\n");
                    printf("Descrição: ");
                    scanf("%s", &produto.descricao);
                    printf("Peso: ");
                    scanf("%f", &produto.peso);
                    printf("Valor de compra: ");
                    scanf("%f", &produto.valorCompra);
                    printf("Valor de venda: ");
                    scanf("%f", &produto.valorVenda);
                    produto.valorLucro = produto.valorVenda - produto.valorCompra;
                    produto.percentualLucro = (produto.valorLucro / produto.valorCompra) * 100;
                    printf("Fabricante (Marca): ");
                    scanf("%s", produto.fabricante.marca);
                    produtos[quantidadeProdutos] = produto;
                    quantidadeProdutos++;
                    printf("Produto cadastrado com sucesso!\n\n");
                } else {
                    printf("Limite máximo de produtos alcançado!\n\n");
                }
                break;
            }
            case 3: {
                printf("Marcas cadastradas:\n");
                listarMarcas(produtos, quantidadeProdutos);
                printf("\n");
                break;
            }
            case 4: {
                printf("Produtos cadastrados:\n");
                listarProdutos(produtos, quantidadeProdutos);
                printf("\n");
                break;
            }
            case 5: {
                char estado[3];
                printf("Digite o estado: ");
                scanf("%s", estado);
                printf("Produtos do estado %s:\n", estado);
                listarProdutosPorEstado(produtos, quantidadeProdutos, estado);
                printf("\n");
                break;
            }
            case 6: {
                char marca[MAX_MARCA];
                printf("Digite a marca: ");
                scanf("%s", marca);
                printf("Produtos da marca %s:\n", marca);
                listarProdutosPorMarca(produtos, quantidadeProdutos, marca);
                printf("\n");
                break;
            }
            case 7: {
                printf("Estado(s) onde está registrado o produto mais caro:\n");
                listarEstadoProdutoMaisCaro(produtos, quantidadeProdutos);
                printf("\n");
                break;
            }
            case 8: {
                printf("Fabricante(s) onde está registrado o produto mais barato:\n");
                listarFabricanteProdutoMaisBarato(produtos, quantidadeProdutos);
                printf("\n");
                break;
            }
            case 9: {
                printf("Produtos em ordem crescente de valor:\n");
                listarProdutosPorValorCrescente(produtos, quantidadeProdutos);
                printf("\n");
                break;
            }
            case 10: {
                printf("Produtos em ordem crescente de maior valor do lucro:\n");
                listarProdutosPorLucroCrescente(produtos, quantidadeProdutos);
                printf("\n");
                break;
            }
            case 0: {
                printf("Encerrando o programa...\n");
                break;
            }
            default: {
                printf("Opção inválida! Tente novamente.\n");
                break;
            }
        }
    } while (opcao != 0);

    return 0;
}
