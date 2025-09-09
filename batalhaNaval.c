#include <stdio.h>
#include <stdlib.h> // Necessário para a função abs()

// Desafio Batalha Naval - Nível Mestre
// Implementação robusta com habilidades especiais e estrutura modular
// Versão melhorada

// Constantes para o tamanho do tabuleiro
#define TAMANHO 10
#define TAMANHO_HABILIDADE 5
#define TAMANHO_NAVIO 3
#define NUMERO_NAVIOS 4

// Declaração das matrizes globais
int tabuleiro[TAMANHO][TAMANHO];           // Tabuleiro principal 10x10
int habilidade_cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];     // Matriz para habilidade cone
int habilidade_cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];     // Matriz para habilidade cruz
int habilidade_octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]; // Matriz para habilidade octaedro

// Protótipos das funções
void inicializar_tabuleiro();
void posicionar_navios();
void criar_habilidade_cone();
void criar_habilidade_cruz();
void criar_habilidade_octaedro();
void exibir_matriz(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], const char* nome_habilidade);
void exibir_tabuleiro();
void exibir_coordenadas_navios();
void exibir_habilidades_especiais();

int main() {
    printf("=== BATALHA NAVAL - NIVEL MESTRE MELHORADA ===\n\n");
    
    // Inicialização do sistema
    inicializar_tabuleiro();
    posicionar_navios();
    
    // Criação das habilidades especiais
    criar_habilidade_cone();
    criar_habilidade_cruz();
    criar_habilidade_octaedro();
    
    // Exibição dos resultados
    exibir_coordenadas_navios();
    exibir_tabuleiro();
    exibir_habilidades_especiais();
    
    return 0;
}

// Função para inicializar o tabuleiro com zeros
void inicializar_tabuleiro() {
    for(int i = 0; i < TAMANHO; i++) {
        for(int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para posicionar todos os navios no tabuleiro
void posicionar_navios() {
    // Posicionamento do primeiro navio horizontalmente
    // Navio horizontal na linha 1, colunas 1, 2 e 3
    int navio1_linha = 1;
    int navio1_coluna = 1;
    
    for(int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navio1_linha][navio1_coluna + i] = 3;
    }
    
    // Posicionamento do segundo navio verticalmente
    // Navio vertical na coluna 5, linhas 3, 4 e 5
    int navio2_coluna = 5;
    int navio2_linha = 3;
    
    for(int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navio2_linha + i][navio2_coluna] = 3;
    }
    
    // Posicionamento do terceiro navio na diagonal principal
    // Navio diagonal na posição [7][1], [8][2], [9][3]
    int navio3_linha = 7;
    int navio3_coluna = 1;
    
    for(int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navio3_linha + i][navio3_coluna + i] = 3;
    }
    
    // Posicionamento do quarto navio na diagonal secundária
    // Navio diagonal na posição [2][8], [3][7], [4][6]
    int navio4_linha = 2;
    int navio4_coluna = 8;
    
    for(int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navio4_linha + i][navio4_coluna - i] = 3;
    }
}

// Função para criar a habilidade em cone
void criar_habilidade_cone() {
    // Inicialização da matriz cone com zeros
    for(int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for(int j = 0; j < TAMANHO_HABILIDADE; j++) {
            habilidade_cone[i][j] = 0;
        }
    }
    
    // Preenchimento do padrão cone usando loops aninhados
    for(int i = 0; i < 3; i++) { // Apenas as primeiras 3 linhas do cone
        int inicio = 2 - i;  // Posição inicial da linha
        int fim = 2 + i;     // Posição final da linha
        
        for(int j = inicio; j <= fim; j++) {
            if(j >= 0 && j < TAMANHO_HABILIDADE) {
                habilidade_cone[i][j] = 1;
            }
        }
    }
}

// Função para criar a habilidade em cruz
void criar_habilidade_cruz() {
    // Inicialização da matriz cruz com zeros
    for(int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for(int j = 0; j < TAMANHO_HABILIDADE; j++) {
            habilidade_cruz[i][j] = 0;
        }
    }
    
    // Preenchimento do padrão cruz usando loops aninhados
    int centro = TAMANHO_HABILIDADE / 2; // Posição central (2)
    
    for(int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for(int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Linha vertical central ou linha horizontal central
            if(i == centro || j == centro) {
                habilidade_cruz[i][j] = 1;
            }
        }
    }
}

// Função para criar a habilidade em octaedro (losango)
void criar_habilidade_octaedro() {
    // Inicialização da matriz octaedro com zeros
    for(int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for(int j = 0; j < TAMANHO_HABILIDADE; j++) {
            habilidade_octaedro[i][j] = 0;
        }
    }
    
    // Preenchimento do padrão octaedro usando loops aninhados
    int centro = TAMANHO_HABILIDADE / 2; // Posição central (2)
    
    for(int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for(int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Distância Manhattan do centro
            int distancia = abs(i - centro) + abs(j - centro);
            
            // Se a distância for menor ou igual a 1, faz parte do octaedro
            if(distancia <= 1) {
                habilidade_octaedro[i][j] = 1;
            }
        }
    }
}

// Função genérica para exibir uma matriz de habilidade
void exibir_matriz(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], const char* nome_habilidade) {
    printf("%s:\n", nome_habilidade);
    for(int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for(int j = 0; j < TAMANHO_HABILIDADE; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função para exibir o tabuleiro completo
void exibir_tabuleiro() {
    printf("=== TABULEIRO COMPLETO %dx%d ===\n", TAMANHO, TAMANHO);
    printf("(0 = vazio, 3 = navio)\n\n");
    
    for(int i = 0; i < TAMANHO; i++) {
        for(int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função para exibir as coordenadas de todos os navios
void exibir_coordenadas_navios() {
    printf("Coordenadas do Navio Horizontal:\n");
    for(int i = 0; i < TAMANHO_NAVIO; i++) {
        printf("Posicao [%d][%d]\n", 1, 1 + i);
    }
    
    printf("\nCoordenadas do Navio Vertical:\n");
    for(int i = 0; i < TAMANHO_NAVIO; i++) {
        printf("Posicao [%d][%d]\n", 3 + i, 5);
    }
    
    printf("\nCoordenadas do Navio Diagonal Principal:\n");
    for(int i = 0; i < TAMANHO_NAVIO; i++) {
        printf("Posicao [%d][%d]\n", 7 + i, 1 + i);
    }
    
    printf("\nCoordenadas do Navio Diagonal Secundaria:\n");
    for(int i = 0; i < TAMANHO_NAVIO; i++) {
        printf("Posicao [%d][%d]\n", 2 + i, 8 - i);
    }
    printf("\n");
}

// Função para exibir todas as habilidades especiais
void exibir_habilidades_especiais() {
    printf("=== HABILIDADES ESPECIAIS ===\n");
    printf("(0 = Area nao afetada, 1 = area afetada)\n\n");
    
    exibir_matriz(habilidade_cone, "Habilidade em CONE");
    exibir_matriz(habilidade_cruz, "Habilidade em CRUZ");
    exibir_matriz(habilidade_octaedro, "Habilidade em OCTAEDRO");
}