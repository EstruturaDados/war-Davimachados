#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Incluído para a função system("cls") ou similar, se necessário, ou para size_t

typedef struct {
    char nome[50];
    char corExercito[20];
    int numTropas;
} Territorio;

#define NUM_TERRITORIOS 5

void cadastrarTerritorio(Territorio *t, int indice) {
    printf("\n--- Cadastro do Território %d ---\n", indice + 1);
    
    printf("Digite o Nome do Território: ");
    fflush(stdin); 
    if (fgets(t->nome, sizeof(t->nome), stdin) != NULL) {
        size_t len = strlen(t->nome);
        if (len > 0 && t->nome[len - 1] == '\n') {
            t->nome[len - 1] = '\0';
        }
    }

    printf("Digite a Cor do Exército Dominante (ex: Verde): ");
    fflush(stdin);
    if (fgets(t->corExercito, sizeof(t->corExercito), stdin) != NULL) {
        size_t len = strlen(t->corExercito);
        if (len > 0 && t->corExercito[len - 1] == '\n') {
            t->corExercito[len - 1] = '\0';
        }
    }

    do {
        printf("Digite o Número de Tropas (inteiro positivo): ");
        if (scanf("%d", &t->numTropas) != 1 || t->numTropas <= 0) {
            printf("Erro: Número de tropas inválido. Digite um valor positivo.\n");
            while (getchar() != '\n'); 
        }
    } while (t->numTropas <= 0);
}

void exibirMapa(const Territorio mapa[], int tamanho) {
    printf("\n==================================\n");
    printf("🗺️ ESTADO ATUAL DO MAPA WAR 🗺️\n");
    printf("==================================\n");
    
    printf("| %-2s | %-30s | %-15s | %-10s |\n", "ID", "Território", "Exército", "Tropas");
    printf("|----|--------------------------------|-----------------|------------|\n");
    
    for (int i = 0; i < tamanho; i++) {
        printf("| %-2d | %-30s | %-15s | %-10d |\n", 
               i + 1, 
               mapa[i].nome, 
               mapa[i].corExercito, 
               mapa[i].numTropas);
    }
    printf("|----|--------------------------------|-----------------|------------|\n");
}

int main() {
    Territorio mapa[NUM_TERRITORIOS];
    
    printf("🚀 Desafio WAR Estruturado - Nível Novato\n");
    printf("--- Cadastro Inicial de %d Territórios ---\n", NUM_TERRITORIOS);
    
    for (int i = 0; i < NUM_TERRITORIOS; i++) {
        cadastrarTerritorio(&mapa[i], i);
    }

    exibirMapa(mapa, NUM_TERRITORIOS);
    
    printf("\n✅ Cadastro concluído com sucesso. Fim do Nível Novato.\n");

    return 0;
}