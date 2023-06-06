class Livro:
    def __init__(self, titulo, autor, disponivel=True):
        self.titulo = titulo
        self.autor = autor
        self.disponivel = disponivel

class Biblioteca:
    def __init__(self):
        self.livros = []

    def adicionar_livro(self, livro):
        self.livros.append(livro)

    def remover_livro(self, livro):
        self.livros.remove(livro)

    def listar_livros_disponiveis(self):
        livros_disponiveis = [livro for livro in self.livros if livro.disponivel]
        if livros_disponiveis:
            for livro in livros_disponiveis:
                print(f'Título: {livro.titulo}\nAutor: {livro.autor}\n')
        else:
            print('Não há livros disponíveis.')

    def reservar_livro(self, titulo):
        for livro in self.livros:
            if livro.titulo == titulo and livro.disponivel:
                livro.disponivel = False
                print(f'O livro "{titulo}" foi reservado com sucesso.')
                return
        print(f'O livro "{titulo}" não está disponível para reserva.')

    def mostrar_livros_reservados(self):
        livros_reservados = [livro for livro in self.livros if not livro.disponivel]
        if livros_reservados:
            print('----- Livros Reservados -----')
            for livro in livros_reservados:
                print(f'Título: {livro.titulo}\nAutor: {livro.autor}\n')
        else:
            print('Você não reservou nenhum livro.')


def exibir_menu():
    print('----- Menu -----')
    print('1. Listar Livros Disponíveis')
    print('2. Reservar Livro')
    print('3. Registrar Novo Livro')
    print('4. Excluir Livro')
    print('5. Mostrar Livros Reservados')
    print('6. Sair')


biblioteca = Biblioteca()

livro1 = Livro('Frankenstein', 'Mary Shelley')
livro2 = Livro('1984', 'George Orwell')
livro3 = Livro('Dom Quixote', 'Miguel de Cervantes')
livro4 = Livro('Hamlet', 'William Shakespeare')
livro5 = Livro('Ilíada', 'Homero')

biblioteca.adicionar_livro(livro1)
biblioteca.adicionar_livro(livro2)
biblioteca.adicionar_livro(livro3)
biblioteca.adicionar_livro(livro4)
biblioteca.adicionar_livro(livro5)

while True:
    exibir_menu()
    opcao = input('Digite o número da opção desejada: ')

    if opcao == '1':
        print('----- Lista de Livros Disponíveis -----')
        biblioteca.listar_livros_disponiveis()

    elif opcao == '2':
        titulo_livro = input('Digite o título do livro que deseja reservar: ')
        biblioteca.reservar_livro(titulo_livro)

    elif opcao == '3':
        titulo_livro = input('Digite o título do livro: ')
        autor_livro = input('Digite o nome do autor do livro: ')
        novo_livro = Livro(titulo_livro, autor_livro)
        biblioteca.adicionar_livro(novo_livro)
        print(f'O livro "{titulo_livro}" foi registrado com sucesso.')

    elif opcao == '4':
        titulo_livro = input('Digite o título do livro que deseja excluir: ')
        for livro in biblioteca.livros:
            if livro.titulo == titulo_livro:
                biblioteca.remover_livro(livro)
                print(f'O livro "{titulo_livro}" foi removido da biblioteca.')
                break
        else:
            print(f'O livro "{titulo_livro}" não foi encontrado na biblioteca.')

    elif opcao == '5':
        biblioteca.mostrar_livros_reservados()

    elif opcao == '6':
        print('Encerrando o programa...')
        break

    else:
        print('Opção inválida. Por favor, tente novamente.')
