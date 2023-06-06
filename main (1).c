#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char titulo[50];
    char autor[50];
    bool disponivel;
} Livro;

typedef struct {
    Livro livros[100];
    int totalLivros;
} Biblioteca;

void adicionarLivro(Biblioteca *biblioteca, Livro livro) {
    biblioteca->livros[biblioteca->totalLivros++] = livro;
}

void removerLivro(Biblioteca *biblioteca, Livro livro) {
    int i;
    for (i = 0; i < biblioteca->totalLivros; i++) {
        if (strcmp(biblioteca->livros[i].titulo, livro.titulo) == 0) {
            for (; i < biblioteca->totalLivros - 1; i++) {
                biblioteca->livros[i] = biblioteca->livros[i + 1];
            }
            biblioteca->totalLivros--;
            break;
        }
    }
}

void listarLivrosDisponiveis(Biblioteca biblioteca) {
    int i;
    for (i = 0; i < biblioteca.totalLivros; i++) {
        if (biblioteca.livros[i].disponivel) {
            printf("Título: %s\nAutor: %s\n\n", biblioteca.livros[i].titulo, biblioteca.livros[i].autor);
        }
    }
    if (i == 0) {
        printf("Não há livros disponíveis.\n");
    }
}

void reservarLivro(Biblioteca *biblioteca, char *titulo) {
    int i;
    for (i = 0; i < biblioteca->totalLivros; i++) {
        if (strcmp(biblioteca->livros[i].titulo, titulo) == 0 && biblioteca->livros[i].disponivel) {
            biblioteca->livros[i].disponivel = false;
            printf("O livro \"%s\" foi reservado com sucesso.\n", titulo);
            return;
        }
    }
    printf("O livro \"%s\" não está disponível para reserva.\n", titulo);
}

void mostrarLivrosReservados(Biblioteca biblioteca) {
    int i;
    bool encontrouLivro = false;
    printf("----- Livros Reservados -----\n");
    for (i = 0; i < biblioteca.totalLivros; i++) {
        if (!biblioteca.livros[i].disponivel) {
            printf("Título: %s\nAutor: %s\n\n", biblioteca.livros[i].titulo, biblioteca.livros[i].autor);
            encontrouLivro = true;
        }
    }
    if (!encontrouLivro) {
        printf("Você não reservou nenhum livro.\n");
    }
}

void exibirMenu() {
    printf("----- Menu -----\n");
    printf("1. Listar Livros Disponíveis\n");
    printf("2. Reservar Livro\n");
    printf("3. Registrar Novo Livro\n");
    printf("4. Excluir Livro\n");
    printf("5. Mostrar Livros Reservados\n");
    printf("6. Sair\n");
}

int main() {
    Biblioteca biblioteca;
    biblioteca.totalLivros = 0;

    Livro livro1 = {"Frankenstein", "Mary Shelley", true};
    Livro livro2 = {"1984", "George Orwell", true};
    Livro livro3 = {"Dom Quixote", "Miguel de Cervantes", true};
    Livro livro4 = {"Hamlet", "William Shakespeare", true};
    Livro livro5 = {"Ilíada", "Homero", true};

    adicionarLivro(&biblioteca, livro1);
    adicionarLivro(&biblioteca, livro2);
    adicionarLivro(&biblioteca, livro3);

    char opcao[2];
    char titulo[50];

    while (true) {
        exibirMenu();
        printf("Digite o número da opção desejada: ");
        scanf("%s", opcao);

        if (strcmp(opcao, "1") == 0) {
            printf("----- Lista de Livros Disponíveis -----\n");
            listarLivrosDisponiveis(biblioteca);
        } else if (strcmp(opcao, "2") == 0) {
            printf("Digite o título do livro que deseja reservar: ");
            scanf(" %[^\n]", titulo);
            reservarLivro(&biblioteca, titulo);
        } else if (strcmp(opcao, "3") == 0) {
            Livro novoLivro;
            printf("Digite o título do livro: ");
            scanf(" %[^\n]", novoLivro.titulo);
            printf("Digite o nome do autor do livro: ");
            scanf(" %[^\n]", novoLivro.autor);
            novoLivro.disponivel = true;
            adicionarLivro(&biblioteca, novoLivro);
            printf("O livro \"%s\" foi registrado com sucesso.\n", novoLivro.titulo);
        } else if (strcmp(opcao, "4") == 0) {
            printf("Digite o título do livro que deseja excluir: ");
            scanf(" %[^\n]", titulo);
            Livro livroExcluir = {"", "", false};
            strcpy(livroExcluir.titulo, titulo);
            removerLivro(&biblioteca, livroExcluir);
            printf("O livro \"%s\" foi removido da biblioteca.\n", titulo);
        } else if (strcmp(opcao, "5") == 0) {
            mostrarLivrosReservados(biblioteca);
        } else if (strcmp(opcao, "6") == 0) {
            printf("Encerrando o programa...\n");
            break;
        } else {
            printf("Opção inválida. Por favor, tente novamente.\n");
        }
    }

    return 0;
}
