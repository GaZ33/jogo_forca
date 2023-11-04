#include <stdio.h>
#include <conio.h>
#include <windows.h>



void borda(int lin, int col); // Menu de exibição
void gotoxy(int x, int y); // Função para movimentar os caracteres na tela
void textcolor(int color, int background); // Função para trocar a cor da letra e do fundo
int menuopcao();


int main(void)
{



    menuopcao();
    
    //borda();
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

int menuopcao()
{
    int opcao;
    borda(15, 45);
    gotoxy(15, 1);
    printf("MENU PRINCIPAL");

    gotoxy(11, 4);
    printf("1 - CONFIGURACOES");
    gotoxy(11, 6);
    printf("2 - JOGO PADRAO");
    gotoxy(11, 8);
    printf("3 - JOGO MULTIPLAYER");
    gotoxy(19, 10);
    printf("OPCAO:");
    gotoxy(21, 11);
    scanf("%d", &opcao);



    gotoxy(0,25);
    return 1;
}