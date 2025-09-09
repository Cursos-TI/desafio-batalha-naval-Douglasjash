#include "stdio.h"
#include <stdlib.h> // Necessário para a função abs()

// Desafio Batalha Naval - Nível Mestre
// Implementação de habilidades especiais com padrões específicos
// Autor: MateCheck

// Constantes para o tamanho do tabuleiro
#define TAMANHO 10
#define TAMANHO_HABILIDADE 5

// Declaração das matrizes globais
int tabuleiro[TAMANHO][TAMANHO];           // Tabuleiro principal 10x10
int habilidade_cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];     // Matriz para habilidade cone
int habilidade_cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];     // Matriz para habilidade cruz
int habilidade_octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]; // Matriz para habilidade octaedro

// Protótipos das funções (serão implementadas nas próximas etapas)
void inicializar_tabuleiro();
void criar_habilidade_cone();
void criar_habilidade_cruz();
void criar_habilidade_octaedro();
void exibir_matriz(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int tamanho);

int main() {
    // NIVEL QUE DESENVOLVEREI
    
    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
