#include <stdio.h>
#include <conio.h>
#include <windows.h>



void borda(int lin, int col); // Menu de exibição
void personagem(void); // Criação do personagem da forca
void gotoxy(int x, int y); // Função para movimentar os caracteres na tela
void textcolor(int color, int background); // Função para trocar a cor da letra e do fundo
int menuopcao();  // Função de exibição das opções e escolha de uma opção


int main(void)
{



    menuopcao();
    
}

void borda(int lin, int col)
{
    system("cls");
    int posX, posY, tamHon, tamAlt;
    // Caso queira alturar a posição do menu, mude essas 2 variáveis
    posX = 0;       
    posY = 0;
    // Comprimento e altura do menu
    tamHon = col;
    tamAlt = lin;
    gotoxy(posX, posY);
    printf("%c", 201);
    for (int i = 0; i < tamHon; i++)
    {
        printf("%c", 205);
    }
    printf("%c", 187);
    for (int i = posY+1, alt = tamAlt+posY; i < alt; i++)
    {
        gotoxy(posX, i);
        printf("%c", 186);
    }
    for (int i = posY+1, alt = tamAlt+posY, final = posX+tamHon+1; i < alt; i++)
    {
        gotoxy(final, i);
        printf("%c", 186);
    }
    gotoxy(posX, posY+tamAlt);
    printf("%c", 200);
    for (int i = 0; i < tamHon; i++)
    {
        printf("%c", 205);
    }
    printf("%c", 188);
    
}

void gotoxy(int x, int y)
{
    HANDLE hcon;
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hcon, dwPos);
}

void textcolor(int color, int background)
{
    int soma = color + (background * 16);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), soma); // Recomendo pesquisar sobre
}

void personagem(void)
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
    for (int i = 5; i < 12; i++)
    {
        gotoxy(22, i);
        printf("%c", 179); 
    }
    // Cabeça
    gotoxy(22, 8);
    printf("%c", 153);
    // Tronco
    gotoxy(22, 9);
    printf("%c", 186); 
    gotoxy(22, 10);
    printf("%c", 186);
    gotoxy(22, 11);
    printf("%c", 186);

    // Braço direito
    gotoxy(23, 9);
    printf("%c", 92);
    gotoxy(24, 10);
    printf("%c", 92);

    // Braço esquerdo
    gotoxy(21, 9);
    printf("/");
    gotoxy(20, 10);
    printf("/");

    // perna direito
    gotoxy(23, 12);
    printf("%c", 92);
    gotoxy(24, 13);
    printf("%c", 92);

    // Perna esquerdo
    gotoxy(21, 12);
    printf("/");
    gotoxy(20, 13);
    printf("/");
}

int menuopcao()
{
    int opcao;
    borda(20, 85);
    personagem();
    gotoxy(55, 3);
    textcolor(9, 0);
    printf("MENU PRINCIPAL");

    gotoxy(53, 6);
    textcolor(7, 0);
    printf("1 - CONFIGURACOES");
    gotoxy(53, 9);
    printf("2 - JOGO PADRAO");
    gotoxy(53, 12);
    printf("3 - JOGO MULTIPLAYER");
    gotoxy(58, 16);
    printf("OPCAO:");
    gotoxy(61, 17);
    textcolor(3,0);
    scanf("%d", &opcao);
    textcolor(7,0);
    
    gotoxy(0,25);
    return 1;
}