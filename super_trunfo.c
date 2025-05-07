#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

typedef struct{
    char estado;
    char codigo[5];
    char cidade[30];
    int populacao;
    float area;
    float PIB;
    int pontos_turisticos;
} Carta;

/**
 * Inicializa a carta apontada por carta com base em informa es fornecidas pelo usu rio.
 * 
 * A função solicita ao usuario que forneça uma serie de informações sobre a carta e 
 * as armazena nas variaveis membro da estrutura apontada por carta.
 */
Carta inicializarCarta(int i) {
    Carta carta;

    printf("digite o nome da cidade da carta %d:", i);
    fgets(carta.cidade, 30, stdin);
    carta.cidade[strcspn(carta.cidade, "\n")] = 0;
    
    printf("digite o codigo da carta %d:", i);
    //pegando um carctere a mais por linha para remover quebra de linha
    fgets(carta.codigo, 5, stdin);
    carta.codigo[strcspn(carta.codigo, "\n")] = 0;

    printf("digite o estado da carta %d:", i);
    scanf("%c", &carta.estado);

    printf("digite a população da carta %d:", i);
    scanf("%d", &carta.populacao);

    printf("digite a area da carta %d:", i);
    scanf("%f", &carta.area);

    return carta;
    
}

/**
 * Imprime os dados de uma carta.
 * 
 * A função imprime na saida padrao os dados das  informações des armazenadas na estrutura
 * apontada por carta, formatadas de acordo com as especificações do enunciado.
 */
void imprimirCarta(Carta carta, int numeroCarta) {
    printf("\nCarta %d\n", numeroCarta);
    printf("Cidade: %s\n", carta.cidade);
    printf("Codigo: %s\n", carta.codigo);
    printf("Estado: %c\n", carta.estado);
    printf("Populacao: %d\n", carta.populacao);
    printf("Area: %.2f\n", carta.area);
    printf("PIB: %.2f\n", carta.PIB);
    printf("Número de Pontos turisticos: %d\n", carta.pontos_turisticos);
}

int main() {

    Carta primeiraCarta = inicializarCarta(1);
    Carta segundaCarta = inicializarCarta(2);

    imprimirCarta(primeiraCarta,1);
    imprimirCarta(segundaCarta,2);

    return 0;
}