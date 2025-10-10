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

    int opcao;


    // --- Entrada dos dados do jogador ---
    printf("=== CADASTRE SUA CARTA ===\n");
    printf("Nome do pais: ");
    scanf(" %s", paisJogador); 
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
    populacaoComp = (rand());  
    areaComp = (rand());         
    pibComp = (rand());                
    pontosTuristicosComp = rand();
    densidadeComp = populacaoComp / areaComp;

    printf("\n=== SUA CARTA ===\n");
    printf("Pais: %s\n", paisJogador);
    printf("Populacao: %d\n", populacaoJogador);
    printf("Area: %.2f km²\n", areaJogador);
    printf("PIB: %.2f bilhoes\n", pibJogador);
    printf("Pontos Turisticos: %d\n", pontosTuristicosJogador);
    printf("Densidade: %.2f hab/km²\n", densidadeJogador);

    printf("\n=== CARTA DO COMPUTADOR ===\n");
    printf("Pais: %s\n", paisComputador);
    printf("Populacao: %d\n", populacaoComp);
    printf("Area: %.2f km²\n", areaComp);
    printf("PIB: %.2f bilhoes\n", pibComp);
    printf("Pontos Turisticos: %d\n", pontosTuristicosComp);
    printf("Densidade: %.2f hab/km²\n\n", densidadeComp);

    // --- Menu interativo ---
    printf("=== ESCOLHA O ATRIBUTO PARA COMPARAR ===\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("Escolha: ");
    scanf("%d", &opcao);

    printf("=== RESULTADO ===\n");

    switch (opcao) {
        case 1:
            printf("Atributo: Populacao\n");
            printf("%s: %d\n", paisJogador, populacaoJogador);
            printf("%s: %d\n", paisComputador, populacaoComp);
            if (populacaoJogador > populacaoComp)
                printf("Vencedor: %s\n", paisJogador);
            else if (populacaoJogador < populacaoComp)
                printf("Vencedor: %s\n", paisComputador);
            else
                printf("Empate!\n");
            break;

        case 2:
            printf("Atributo: Area\n");
            printf("%s: %.2f km²\n", paisJogador, areaJogador);
            printf("%s: %.2f km²\n", paisComputador, areaComp);
            if (areaJogador > areaComp)
                printf("Vencedor: %s\n", paisJogador);
            else if (areaJogador < areaComp)
                printf("Vencedor: %s\n", paisComputador);
            else
                printf("Empate!\n");
            break;

        case 3:
            printf("Atributo: PIB\n");
            printf("%s: %.2f bilhoes\n", paisJogador, pibJogador);
            printf("%s: %.2f bilhoes\n", paisComputador, pibComp);
            if (pibJogador > pibComp)
                printf("Vencedor: %s\n", paisJogador);
            else if (pibJogador < pibComp)
                printf("Vencedor: %s\n", paisComputador);
            else
                printf("Empate!\n");
            break;

        case 4:
            printf("Atributo: Pontos Turisticos\n");
            printf("%s: %d\n", paisJogador, pontosTuristicosJogador);
            printf("%s: %d\n", paisComputador, pontosTuristicosComp);
            if (pontosTuristicosJogador > pontosTuristicosComp)
                printf("Vencedor: %s\n", paisJogador);
            else if (pontosTuristicosJogador < pontosTuristicosComp)
                printf("Vencedor: %s\n", paisComputador);
            else
                printf("Empate!\n");
            break;

        case 5:
            printf("Atributo: Densidade Demografica (menor vence)\n");
            printf("%s: %.2f hab/km²\n", paisJogador, densidadeJogador);
            printf("%s: %.2f hab/km²\n", paisComputador, densidadeComp);
            if (densidadeJogador < densidadeComp)
                printf("Vencedor: %s\n", paisJogador);
            else if (densidadeJogador > densidadeComp)
                printf("Vencedor: %s\n", paisComputador);
            else
                printf("Empate!\n");
            break;

        default:
            printf("Opcao invalida!\n");
    }

    return 0;
}
