#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomizarNumero() {
    // Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(0));
    
    // Gera um número aleatório entre 0 e 10
    int numeroAleatorio = rand() % 20;
    
    return numeroAleatorio;
}

int main() {
    int numeroGerado = randomizarNumero();
    printf("Número aleatório: %d\n", numeroGerado);
    
    return 0;
}
