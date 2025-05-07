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
    float densidade_populacional;
    float PIB_per_capita;
    float super_poder;
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

    printf("digite o PIB em bilhões de reais da carta %d:", i);
    scanf("%f", &carta.PIB);

    printf("digite os pontos turisticos da carta %d:", i);
    scanf("%d%*c", &carta.pontos_turisticos);

    carta.densidade_populacional = carta.populacao / carta.area;
    carta.PIB_per_capita = (carta.PIB /carta.populacao) * 1000000000;

    carta.super_poder = carta.populacao + carta.area + carta.PIB + carta.pontos_turisticos + 1 / carta.densidade_populacional + carta.PIB_per_capita;

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
    printf("Area: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.PIB);
    printf("Número de Pontos turisticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n",carta.densidade_populacional);
    printf("PIB per Capita: %.2f reais\n", carta.PIB_per_capita);
    printf("Super Poder: %.2f\n", carta.super_poder);
}


/**
 * Compara as informações de duas cartas e imprime na saída padrão as comparações
 * realizadas.
 * 
 * A função compara as informações de duas cartas e imprime na saída padrão as
 * comparações realizadas. A comparação é realizada em sete critérios:
 * - População
 * - Area
 * - PIB
 * - Pontos Turisticos
 * - Densidade Populacional
 * - PIB per Capita
 * - Super Poder
 * 
 * Para cada critério, a função imprime na saída padrão qual carta venceu e qual foi
 * o valor que determinou a vitória.
 */
void calcularCartaVencedora(Carta primeiraCarta, Carta segundaCarta) {
    printf("\nComparação de Cartas:\n");
    
    int populacao = primeiraCarta.populacao > segundaCarta.populacao;
    printf("População: Carta %d venceu (%d)\n", populacao ? 1 : 2, populacao);

    int area = primeiraCarta.area > segundaCarta.area;
    printf("Area: Carta %d venceu (%d)\n", area ? 1 : 2, area);

    int PIB = primeiraCarta.PIB > segundaCarta.PIB;
    printf("PIB: Carta %d venceu (%d)\n", PIB ? 1 : 2, PIB);

    int pontos_turisticos = primeiraCarta.pontos_turisticos > segundaCarta.pontos_turisticos;
    printf("Pontos Turisticos: Carta %d venceu (%d)\n", pontos_turisticos ? 1 : 2, pontos_turisticos);

    int densidade_populacional = primeiraCarta.densidade_populacional < segundaCarta.densidade_populacional;
    printf("Densidade Populacional: Carta %d venceu (%d)\n", densidade_populacional ? 1 : 2, densidade_populacional);

    int PIB_per_capita = primeiraCarta.PIB_per_capita > segundaCarta.PIB_per_capita;
    printf("PIB per Capita: Carta %d venceu (%d)\n", PIB_per_capita ? 1 : 2, PIB_per_capita);

    int super_poder = primeiraCarta.super_poder > segundaCarta.super_poder;
    printf("Super Poder: Carta %d venceu (%d)\n", super_poder ? 1 : 2, super_poder);
}

int main() {

    Carta primeiraCarta = inicializarCarta(1);
    Carta segundaCarta = inicializarCarta(2);

    imprimirCarta(primeiraCarta,1);
    imprimirCarta(segundaCarta,2);

    calcularCartaVencedora(primeiraCarta, segundaCarta);

    return 0;
}

