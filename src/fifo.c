#include <stdio.h>
#include <stdbool.h> //biblioteca que será usada na função estaNaMemoria();
#include<locale.h>


// Função para verificar se a página já está na memória
bool estaNaMemoria(int memoria[], int frames, int pagina) {
	int indice;
    for (indice = 0; indice < frames; indice++) {
        if (memoria[indice] == pagina) {  // Verifica se a página já está na memória
            return true;
        }
    }
    return false; 
}

// Função que irá imprimir para o suário o estado da memória
void imprimeMemoria(int memoria[], int frames) {
	int indice;
    for (indice = 0; indice < frames; indice++) {
        if (memoria[indice] == -1) {
            printf("");
        } else {
            printf("%d ", memoria[indice]);
        }
    }
    printf("\n");
}

// Procedimento para simular o algoritmo FIFO de substituição de páginas
void paginaFifo(int paginas[], int nPaginas, int frames) {
    int memoria[frames];  // array que vai armazenas as páginas que irão ser adcionadas a memória
    int indice = 0; 
    int falhasPagina = 0; 
    int i;

    
    for (i = 0; i < frames; i++) {
        memoria[i] = -1;//todas as molduras//frames da memória serão inicializadas com -1 para indicar que estão vazias
    }

    // Aqui se inicia o FIFO
    for (i = 0; i < nPaginas; i++) {
        int pagina = paginas[i];

        if (!estaNaMemoria(memoria, frames, pagina)) {
            memoria[indice] = pagina;
            indice = (indice + 1) % frames;
            falhasPagina++;
            printf("Falha. Estado da memória: ", pagina);
            imprimeMemoria(memoria, frames);
        }
    }

    printf("Total de falhas de página: %d\n", falhasPagina);
    printf("Estado final da memória: ");
    imprimeMemoria(memoria, frames);
    printf("\n");
}

void main() {
	
	setlocale(LC_ALL, "Portuguese");
    // Simulação do exemplo 2 disponível no documento
    int exemploPages2[] = {4, 1, 2, 4, 5, 1, 2, 3, 4};
    int exemploFrames2 = 2;
    int nPaginas2 = sizeof(exemploPages2) / sizeof(exemploPages2[0]);  
    printf("Exemplo 2:\n");
    paginaFifo(exemploPages2, nPaginas2, exemploFrames2);
    printf("\n");

    // Simulação do exemplo 3 disponível no documento
    int exemploPages3[] = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2};
    int exemploFrames3 = 4;
    int nPaginas3 = sizeof(exemploPages3) / sizeof(exemploPages3[0]);
    printf("Exemplo 3:\n");
    paginaFifo(exemploPages3, nPaginas3, exemploFrames3);
    printf("\n");

    // Simulação do desafio 1 disponível no documento
    int desafioPage1[] = {1, 3, 0, 3, 5, 6, 3, 1, 6, 1, 2};
    int desafioFrame1 = 3;
    int nPaginas1 = sizeof(desafioPage1) / sizeof(desafioPage1[0]);
    printf("Desafio 1:\n");
    paginaFifo(desafioPage1, nPaginas1, desafioFrame1);
    printf("\n");

    // Simulação do desafio 2 disponível no documento
    int desafioPage2[] = {5, 6, 7, 8, 5, 6, 8, 9, 7, 6};
    int desafioFrame2 = 4;
    int nPaginas2_2 = sizeof(desafioPage2) / sizeof(desafioPage2[0]);
    printf("Desafio 2:\n");
    paginaFifo(desafioPage2, nPaginas2_2, desafioFrame2);
    printf("\n");

    // Desafio 3
    int desafioPage3[] = {0, 2, 1, 6, 4, 0, 1, 0, 2, 1, 4};
    int desafioFrame3 = 3;
    int nPaginas3_2 = sizeof(desafioPage3) / sizeof(desafioPage3[0]);
    printf("Desafio 3:\n");
    paginaFifo(desafioPage3, nPaginas3_2, desafioFrame3);
    printf("\n");

    // Desafio 4
    int desafioPage4[] = {9, 3, 4, 2, 5, 6, 4, 9, 7, 1, 3};
    int desafioFrame4 = 4;
    int nPaginas4 = sizeof(desafioPage4) / sizeof(desafioPage4[0]);
    printf("Desafio 4:\n");
    paginaFifo(desafioPage4, nPaginas4, desafioFrame4);
    printf("\n");
    
    //Desafio 5
    int desafioPage5[] = {0, 2, 1, 6, 4, 0, 1, 0, 2, 1, 4};
    int desafioFrame5 = 3;
    int nPaginas5 = sizeof(desafioPage5) / sizeof(desafioPage5[0]);
    printf("Desafio 5:\n");
    paginaFifo(desafioPage5, nPaginas5, desafioFrame5);
    printf("\n");
    
    //Desafio 6
    int desafioPage6[] = {0, 2, 1, 6, 4, 0, 1, 0, 2, 1, 4};
    int desafioFrame6 = 3;
    int nPaginas6 = sizeof(desafioPage6) / sizeof(desafioPage6[0]);
    printf("Desafio 5:\n");
    paginaFifo(desafioPage6, nPaginas6, desafioFrame6);
    printf("\n");
    
    

 
}
