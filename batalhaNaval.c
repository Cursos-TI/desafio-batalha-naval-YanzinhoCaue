#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define COLUNAS 10
#define LINHAS 10

void tabuleiro(int matriz[LINHAS][COLUNAS]) {
    char letras[COLUNAS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    // Imprime o cabeçalho com as letras
    printf("   "); 
    for (int j = 0; j < COLUNAS; j++) {
        printf("%c ", letras[j]);
    }
    printf("\n");

    // Imprime a matriz com os números da linha
    for (int i = 0; i < LINHAS; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matriz[LINHAS][COLUNAS] = {0}; // Inicializa o tabuleiro com 0

    int y;
    char x;
    int menu;

    printf("\n===== BATALHA NAVAL =====\n");
    printf("\n1. Iniciar jogo...\n");
    printf("2. Regras do jogo...\n");
    printf("3. Sair do jogo...\n");

    printf("\nEscolha uma opção:\n");
    scanf("%d", &menu);

    switch (menu) {
        case 1:
            printf("\nIniciando jogo...\n\n");
            tabuleiro(matriz); // Exibe o tabuleiro inicial

            printf("\nEscolha uma posição de 'A' a 'J' para mover o navio no eixo X:\n");
            scanf(" %c", &x);
            printf("Agora escolha uma posição de '1' a '10' para mover o navio no eixo Y:\n");
            scanf("%d", &y);

            // Verifica se a entrada é válida
            if (strchr("abcdefghijABCDEFGHIJ", x) == NULL) {
                printf("Opção de eixo X inválida...\n");
            } else if (y < 1 || y > 10) {
                printf("Opção de eixo Y inválida...\n");
            } else {
                // Converte a letra X para um índice numérico (0 a 9)
                int coluna = (x >= 'a') ? x - 'a' : x - 'A';
                int linha = y - 1; // Ajusta para índice da matriz (0 a 9)

                // Posiciona o navio (3) na matriz
                matriz[linha][coluna] = 3;
                if (coluna + 1 < COLUNAS) matriz[linha][coluna + 1] = 3; // Direita 1
                if (coluna + 2 < COLUNAS) matriz[linha][coluna + 2] = 3; // Direita 2

                printf("Posicionando navio...\n\n");
                tabuleiro(matriz); // Atualiza o tabuleiro
            }
            break;

        case 2:
            printf("Regras do Jogo - Batalha Naval:\n");
            printf("1. O tabuleiro é 10x10, com colunas A-J e linhas 1-10.\n");
            printf("2. O jogador posiciona um navio de 3 blocos horizontalmente, escolhendo uma coordenada (ex: C5).\n");
            printf("3. O navio é colocado nas 3 células consecutivas da coordenada escolhida.\n");
            printf("4. O jogador escolhe coordenadas (letra + número) para tentar acertar um navio adversário.\n");
            printf("5. Se o jogador acertar todas as partes de um navio, ele é afundado.\n");
            printf("6. O jogo termina quando todos os navios de um jogador são afundados.\n");
            printf("7. O jogador que afundar todos os navios do oponente primeiro, vence o jogo.\n");
            break;

        case 3:
            printf("Saindo do jogo...\n");
            exit(0);

        default:
            printf("Opção inválida...\n");
            break;
    }

    return 0;
}