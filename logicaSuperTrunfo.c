#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura que representa uma carta do jogo Super Trunfo
typedef struct {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

// Função para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para ler os dados de uma carta
void lerCarta(Carta *carta, int cartaNumero) {
    printf("Cadastro da Carta %d:\n", cartaNumero);

    do {
        printf("Informe o estado (letra de A a H): ");
        scanf(" %c", &carta->estado);
        limparBuffer();
    } while (carta->estado < 'A' || carta->estado > 'H');

    printf("Informe o código da carta (ex: A01): ");
    scanf("%3s", carta->codigo);
    limparBuffer();

    printf("Informe o nome da cidade: ");
    fgets(carta->nomeCidade, sizeof(carta->nomeCidade), stdin);
    size_t len = strlen(carta->nomeCidade);
    if (len > 0 && carta->nomeCidade[len - 1] == '\n') {
        carta->nomeCidade[len - 1] = '\0';
    }

    printf("Informe a população da cidade: ");
    scanf("%d", &carta->populacao);

    printf("Informe a área da cidade (em km²): ");
    scanf("%f", &carta->area);

    printf("Informe o PIB da cidade (em bilhões de reais): ");
    scanf("%f", &carta->pib);

    printf("Informe o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
    limparBuffer();

    // Cálculo dos atributos derivados
    if (carta->area > 0) {
        carta->densidadePopulacional = carta->populacao / carta->area;
    } else {
        carta->densidadePopulacional = 0;
    }

    if (carta->populacao > 0) {
        carta->pibPerCapita = (carta->pib * 1e9) / carta->populacao; // PIB em reais
    } else {
        carta->pibPerCapita = 0;
    }
}

// Função para exibir os dados da carta
void exibirCarta(const Carta *carta, int cartaNumero) {
    printf("\n=== CARTA %d ===\n", cartaNumero);
    printf("Estado: %c\n", carta->estado);
    printf("Código: %s\n", carta->codigo);
    printf("Nome da Cidade: %s\n", carta->nomeCidade);
    printf("População: %d\n", carta->populacao);
    printf("Área: %.2f km²\n", carta->area);
    printf("PIB: %.2f bilhões de reais\n", carta->pib);
    printf("Número de Pontos Turísticos: %d\n", carta->pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta->densidadePopulacional);
    printf("PIB per capita: R$ %.2f\n", carta->pibPerCapita);
}

// Função para comparar cartas com base no PIB per capita
void compararCartas(const Carta *c1, const Carta *c2) {
    printf("\n=== COMPARAÇÃO DE CARTAS (Atributo: PIB per capita) ===\n");
    printf("Carta 1 - %s (%c): R$ %.2f\n", c1->nomeCidade, c1->estado, c1->pibPerCapita);
    printf("Carta 2 - %s (%c): R$ %.2f\n", c2->nomeCidade, c2->estado, c2->pibPerCapita);

    if (c1->pibPerCapita > c2->pibPerCapita) {
        printf("Resultado: Carta 1 (%s) venceu!\n", c1->nomeCidade);
    } else if (c1->pibPerCapita < c2->pibPerCapita) {
        printf("Resultado: Carta 2 (%s) venceu!\n", c2->nomeCidade);
    } else {
        printf("Resultado: Empate!\n");
    }
}

int main() {
    Carta carta1, carta2;

    // Cadastro das cartas
    lerCarta(&carta1, 1);
    printf("\n");
    lerCarta(&carta2, 2);

    // Exibição das cartas
    exibirCarta(&carta1, 1);
    exibirCarta(&carta2, 2);

    // Comparação de cartas
    compararCartas(&carta1, &carta2);

    return 0;
}
