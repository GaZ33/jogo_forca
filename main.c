#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>



void borda(int lin, int col); // Cria a borda da interface
void personagem(int num); // Criação do personagem da forca
void gotoxy(int x, int y); // Função para movimentar os caracteres na tela
void textcolor(int color, int background); // Função para trocar a cor da letra e do fundo
int menuopcao();  // Função de exibição das opções e escolha de uma opção
int randomizarNumero(int max); // Função para randomizar um número
void jogo(int vidas); // Função para inciar o jogo padrão
void lacuna(int qntletras); // Cria as lacunas  da forca
void escolhapalavra(char palavra[30]); // Escolhe a palavra entre os arquivos
int bancodeletras(int qnt, char letrasescolhidas[15], char letra[15]); //  Verifica se a letra já foi escolhida
int contemnapalavra(char palavra[15], char linha[30], int *index); // Verifica se a letra está na palavra
void won(int lifes); // Tela de vitória
void lose(); // Tela d ederrota


int main(void)
{
    int opcao;
    while (opcao != 3)
    {
        opcao = menuopcao();
        if (opcao == 1)
        {
            jogo(1);
        }
        if (opcao == 2)
        {
            jogo(2);
        }
    }
    
}

void borda(int lin, int col) 
{
    system("cls");
    int posX, posY, tamHon, tamAlt;
    // Caso queira alturar a posição do menu, mude essas 2 variáveis
    posX = 0; // Define o inicio da posição X
    posY = 0;
    // Comprimento e altura do menu
    tamHon = col; // Tamanho do Comprimento da borda
    tamAlt = lin; // Tamanho da altura da borda
    gotoxy(posX, posY);
    printf("%c", 201); // Canto superior esquerdo
    for (int i = 0; i < tamHon; i++) // Comprimento superior
    {
        printf("%c", 205);
    }
    printf("%c", 187); // Canto superior direuto
    for (int i = posY+1, alt = tamAlt+posY; i < alt; i++) // Altura da borda esquerda
    {
        gotoxy(posX, i);
        printf("%c", 186);
    }
    for (int i = posY+1, alt = tamAlt+posY, final = posX+tamHon+1; i < alt; i++) // Altura da borda direita
    {
        gotoxy(final, i);
        printf("%c", 186);
    }
    gotoxy(posX, posY+tamAlt);
    printf("%c", 200); // Canto inferior direito
    for (int i = 0; i < tamHon; i++) // Comprimento inferior
    {
        printf("%c", 205);
    }
    printf("%c", 188);  // Canto inferior esquerdo
    
}

void gotoxy(int x, int y)
{
    HANDLE hcon;
    COORD dwPos;  // Estrutura que pega 2 cordendas da tela
    dwPos.X = x;
    dwPos.Y = y;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hcon, dwPos);
}

void textcolor(int color, int background)
{
    int soma = color + (background * 16); //Calculo para definir a cor no cmd
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), soma); // Função que realiza a mudança de cor
}

void personagem(int num)
{
    //Titulo
    gotoxy(9, 2);
    textcolor(4, 0);
    printf("JOGO DA FORCA");
    textcolor(7, 0);
    // Suporte da forca
    for (int i = 5; i < 14; i++)
    {
        gotoxy(i, 17);
        printf("%c", 242); 
    }
    // Poste da forca
    for (int i = 5; i < 18; i++)
    {   
        gotoxy(9, i);
        printf("%c", 179); 
    }
    // Curva da forca
    gotoxy(9, 4);
    printf("%c", 218);
    // Parte superior da forca
    for (int i = 10; i < 22; i++)
    {
        gotoxy(i, 4);
        printf("%c", 196); 
    }
    // Curva para conectar com a corda
    gotoxy(22, 4);
    printf("%c", 191);
    // Corda
    for (int i = 5; i < 8; i++)
    {
        gotoxy(22, i);
        printf("%c", 179); 
    }
    if (num < 6)
    {
        // Cabeça
        gotoxy(22, 8);
        printf("%c", 153);
    }
    if (num < 5)
    {
        // Tronco
        gotoxy(22, 9);
        printf("%c", 186); 
        gotoxy(22, 10);
        printf("%c", 186);
        gotoxy(22, 11);
        printf("%c", 186);
    }
    if (num < 4)
    {
        
    // Braço direito
    gotoxy(23, 9);
    printf("%c", 92);
    gotoxy(24, 10);
    printf("%c", 92);
    }
    if (num < 3)
    {
        
    // Braço esquerdo
    gotoxy(21, 9);
    printf("/");
    gotoxy(20, 10);
    printf("/");
    }
    if (num < 2)
    {
    
    // perna direito
    gotoxy(23, 12);
    printf("%c", 92);
    gotoxy(24, 13);
    printf("%c", 92);
    }
    if (num < 1)
    {
        // Perna esquerdo
    gotoxy(21, 12);
    printf("/");
    gotoxy(20, 13);
    printf("/");
    }
    
    textcolor(7, 0);
}

int menuopcao()
{
    int opcao; // opcao do user
    borda(20, 85);
    personagem(0);
    gotoxy(55, 3);
    textcolor(9, 0);
    printf("MENU PRINCIPAL");

    textcolor(7, 0);
    gotoxy(53, 6);
    printf("1 - JOGO PADRAO");
    gotoxy(53, 9);
    printf("2 - HARD MODE");
    gotoxy(53, 12);
    printf("3 - SAIR");
    gotoxy(58, 14);
    printf("OPCAO:");
    gotoxy(61, 15);
    textcolor(3,0);
    scanf("%d", &opcao);
    textcolor(7,0);
    
    gotoxy(0,25);
    return opcao;
}
int randomizarNumero(int max)
{
    // Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(0));
    
    // Gera um número aleatório entre 0 e max
    int numeroAleatorio = rand() % max;
    
    return numeroAleatorio;
}

void escolhapalavra(char palavra[30])
{
    FILE *file;
    int tema = randomizarNumero(3); // Escolha de um dos 3 temas
    int numerolinha; // Escolha da linha do arquivo
    char Linha[30]; // Palavra escolhida do arquivo
    int i; // Variável para achar a linha correspondente no arquivo

    if (tema == 0)
    {
        numerolinha = randomizarNumero(100);
        // Abre o arquivo de TEXTO para LEITURA
        file = fopen("nome.txt", "r");
        if (file == NULL)  // Se houve erro na abertura
        {
            printf("Problemas na abertura do arquivo\n");
            return;
        }
        i = 0;
        while (!feof(file))
        {
            // Lê uma linha (inclusive com o '\n')
            fgets(Linha, 30, file);  // o 'fgets' lê até 29 caracteres ou até o '\n'
            if (i == numerolinha)
            {
                break;
            }
            
            i++;
        }
        gotoxy(40, 5);
        printf("Tema: nomes");
        
    }
    if (tema == 1)
    {
        numerolinha = randomizarNumero(100);
        // Abre o arquivo de TEXTO para LEITURA
        file = fopen("objetos.txt", "r");
        if (file == NULL)  // Se houve erro na abertura
        {
            printf("Problemas na abertura do arquivo\n");
            return;
        }
        i = 0;
        while (!feof(file))
        {
            // Lê uma linha (inclusive com o '\n')
            fgets(Linha, 30, file);  // o 'fgets' lê até 29 caracteres ou até o '\n'
            if (i == numerolinha)
            {
                break;
            }
            
            i++;
        }
        gotoxy(40, 5);
        printf("Tema: objetos");
    }
    if (tema == 2)
    {
        numerolinha = randomizarNumero(100);
        // Abre o arquivo de TEXTO para LEITURA
        file = fopen("comida.txt", "r");
        if (file == NULL)  // Se houve erro na abertura
        {
            printf("Problemas na abertura do arquivo\n");
            return;
        }
        i = 0;
        while (!feof(file))
        {
            // Lê uma linha (inclusive com o '\n')
            fgets(Linha, 30, file);  // o 'fgets' lê até 29 caracteres ou até o '\n'
            if (i == numerolinha)
            {
                break;
            }
            
            i++;
        }
        gotoxy(40, 5);
        printf("Tema: comidas");
    }
    fclose(file);
    strcpy(palavra, Linha); // Copia a palavra escolhida do arquivo para a palavra a ser adivinhada
}  


void jogo(int vidas)
{
    char tentativa[15], palavra[15], palavraescolhida[30]; // tentativa = entrada para o user tentar adivinhar
    // palavra = banco de letras e palavraescolhida é a palavra a ser adivinhada
    int verifica; // variável para verificar as ocasiões durante o jogo
    int lifes = 6; // qnt de vidas
     //randomizarNumero(5);
    system("cls");
    
    borda(20, 85);
    escolhapalavra(palavraescolhida);
    if(vidas == 2) //  Se estiver na dificuldade hard, o tema será ocultado
    {
        gotoxy(40, 5);
        printf("Tema: #########");
    }
    int qnt = strlen(palavraescolhida); // contar a quantidade de letras para desenhar as lacunas
    lacuna(qnt);
    for (int i = 0; i < 15; i++)
    {
        palavra[i] = NULL; // Limpando o lixo da array
    }
    gotoxy(40,40);
    printf("%s", palavraescolhida);
    fflush(stdin); // Necessário, pois o último input foi um número
    int index = 0; // Auxilia o index da array palavra
    while (lifes != 0)
    {
        personagem(lifes);
        gotoxy(55,2);
        printf("Vidas restantes: %d", lifes);
        for (int i = 0; i < 15; i++)
        {
            tentativa[i] = NULL; // Limpando o lixo da array para toda tentativa
        }
        gotoxy(35, 10);
        printf("Letras ja escolhidas: %s", palavra); 
        gotoxy(35, 13);
        printf("Letra ou palavra: ");
        
        fgets(tentativa, sizeof(tentativa), stdin);
        
        int letras = strlen(tentativa);
        if (letras == 2) // Se o user digitar só uma letra execut ao if
        {
            int check = bancodeletras(strlen(palavra), palavra, tentativa); // Verifica se a letra ja foi
            if (check == 1) // Se a letra já foi, então ele pula esse loop
            {
                continue;
            }
            verifica = contemnapalavra(tentativa, palavraescolhida, &index); // verifica se a letra está ou não na palavra
            if (0 == verifica) // Se não está, desconta a vida
            {
                lifes -= vidas;
            }
        }        
        else if (letras > 2) // Se ele tentar adivinhar a palavra
        {
            for (int i = 0; i < 15; i++)
            {
                tentativa[i] = tolower(tentativa[i]);
            }
            
            if (strcmp(tentativa, palavraescolhida) == 0) // Se as palavras forem iguais ele ganha
            {
                won(lifes);
                break;
            }
            lose();
            break;
        }
        
        else // Se ele só apertar espaço
        {
            continue;
        }
        if (verifica == 3) // Se o user ganhar por acertar todas as letras um a um
            {
                won(lifes);
                break;
            }
    }
    if (lifes == 0)
    {
        lose();
    }
    
}

void lacuna(int qntletras)
{
    for (int i = 25; i <=  qntletras*6 + 18; i+=6) // Cria o espaço entre as lacunas
    {
        gotoxy(i, 17);
        printf("___");
    }
}
int bancodeletras(int qnt, char letrasescolhidas[15], char letra[15])
{
   for (int i = 0; i < qnt; i++)
   {
        if (letra[0] == letrasescolhidas[i]) // Verifica se a letra já foi
        {
            return 1;
        }
        
   }
   letrasescolhidas[qnt] = letra[0]; // Se não foi, adiciona ela na posição final
   return 0;
   
}
int contemnapalavra(char palavra[15], char linha[30], int *index)
{
    int esta = 0; // Verifica se está ou não na palavra (quantidade de vezes)
    
    int j = strlen(linha); // Tamanho da palavra a ser adivinhada
    for (int i = 0; i < j; i++)
    {
        if (tolower(palavra[0]) == linha[i])
        {
            int f = 26 + i*6; // Lógica para preencher no lugar correto da lacuna
            gotoxy(f, 16);
            printf("%c", palavra[0]);
            *index = *index + 1; // Auxilia no banco de palavras
            esta++;
        }
    }
    if (esta == 0) //  Se não tiver na palavra
    {
        return 0;
        
    }
    if (*index == j - 1) // Se o user acerta todas as palavras uma por uma
    {
        return 3;
    }
    
    return 1;
}

void won(int lifes)
{
    borda(20, 85);
    personagem(6);

    // Cabeça
    gotoxy(27, 13);
    printf("%c", 153);

    // Tronco
    gotoxy(27, 14);
    printf("%c", 186); 
    gotoxy(27, 15);
    printf("%c", 186);
    gotoxy(27, 16);
    printf("%c", 186);

    // Braço direito
    gotoxy(28, 14);
    printf("%c", 92);
    gotoxy(29, 15);
    printf("%c", 92);

    // Braço esquerdo
    gotoxy(26, 14);
    printf("/");
    gotoxy(25, 15);
    printf("/");

    // perna direito
    gotoxy(28, 17);
    printf("%c", 92);
    gotoxy(29, 18);
    printf("%c", 92);

    // Perna esquerdo
    gotoxy(26, 17);
    printf("/");
    gotoxy(25, 18);
    printf("/");

    gotoxy(55, 10);
    textcolor(2,0);
    printf("YOU WON");
    gotoxy(55, 11);
    printf("Pontuacao: %d", lifes *25);
    getch();
    textcolor(7,0);
}
void lose()
{
    borda(20, 85);
    personagem(0);

    gotoxy(55, 10);
    textcolor(4,0);
    printf("GAME OVER");



    getch();
    textcolor(7,0);
}