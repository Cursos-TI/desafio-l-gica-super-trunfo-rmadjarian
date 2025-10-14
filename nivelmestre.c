#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Variáveis do jogador
    char paisJogador[50];
    int populacaoJogador, pontosTuristicosJogador;
    float areaJogador, pibJogador, densidadeJogador;

    // Variáveis do computador
    char paisComputador[50] = "Computador";
    int populacaoComp, pontosTuristicosComp;
    float areaComp, pibComp, densidadeComp;

    int opcao1, opcao2;
    float somaJogador = 0, somaComp = 0;

    // Inicializa números aleatórios
    srand(time(0));

    // --- Entrada dos dados do jogador ---
    printf("=== CADASTRE SUA CARTA ===\n");
    printf("Nome do pais: ");
    scanf("%s", paisJogador);
    printf("Populacao: ");
    scanf("%d", &populacaoJogador);
    printf("Area (em km²): ");
    scanf("%f", &areaJogador);
    printf("PIB (em bilhoes): ");
    scanf("%f", &pibJogador);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicosJogador);

    densidadeJogador = populacaoJogador / areaJogador;

    // --- Geração aleatória dos dados do computador ---
    populacaoComp = rand() % 100000000 + 1000000;
    areaComp = (rand() % 8000) + 1000;
    pibComp = (rand() % 9000) + 500;
    pontosTuristicosComp = rand() % 50 + 1;
    densidadeComp = populacaoComp / areaComp;

    // --- Menu para escolha dos atributos ---
    printf("\n=== ESCOLHA O PRIMEIRO ATRIBUTO ===\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("Escolha: ");
    scanf("%d", &opcao1);

    printf("\n=== ESCOLHA O SEGUNDO ATRIBUTO (diferente do primeiro) ===\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("Escolha: ");
    scanf("%d", &opcao2);

    if (opcao2 == opcao1) {
        printf("Os dois atributos devem ser diferentes! Encerrando jogo.\n");
        return 0;
    }

    // Função auxiliar: comparar e somar
    for (int i = 1; i <= 2; i++) {
        int atributo = (i == 1) ? opcao1 : opcao2;
        printf("\n=== COMPARACAO %d ===\n", i);
        switch (atributo) {
            case 1: // População
                printf("Populacao: %d (Você) vs %d (Computador)\n", populacaoJogador, populacaoComp);
                somaJogador += (populacaoJogador > populacaoComp) ? 1 : 0;
                somaComp += (populacaoComp > populacaoJogador) ? 1 : 0;
                break;
            case 2: // Área
                printf("Area: %.2f vs %.2f\n", areaJogador, areaComp);
                somaJogador += (areaJogador > areaComp) ? 1 : 0;
                somaComp += (areaComp > areaJogador) ? 1 : 0;
                break;
            case 3: // PIB
                printf("PIB: %.2f vs %.2f\n", pibJogador, pibComp);
                somaJogador += (pibJogador > pibComp) ? 1 : 0;
                somaComp += (pibComp > pibJogador) ? 1 : 0;
                break;
            case 4: // Pontos turísticos
                printf("Pontos Turisticos: %d vs %d\n", pontosTuristicosJogador, pontosTuristicosComp);
                somaJogador += (pontosTuristicosJogador > pontosTuristicosComp) ? 1 : 0;
                somaComp += (pontosTuristicosComp > pontosTuristicosJogador) ? 1 : 0;
                break;
            case 5: // Densidade (menor vence)
                printf("Densidade: %.2f vs %.2f\n", densidadeJogador, densidadeComp);
                somaJogador += (densidadeJogador < densidadeComp) ? 1 : 0;
                somaComp += (densidadeComp < densidadeJogador) ? 1 : 0;
                break;
            default:
                printf("Atributo inválido!\n");
                return 0;
        }
    }

    // --- Resultado final ---
    printf("\n=== RESULTADO FINAL ===\n");
    printf("%s: %.0f pontos\n", paisJogador, somaJogador);
    printf("%s: %.0f pontos\n", paisComputador, somaComp);

    if (somaJogador > somaComp)
        printf("Você venceu o jogo!\n");
    else if (somaJogador < somaComp)
        printf("O computador venceu!\n");
    else
        printf("Empate!\n");

    return 0;
}