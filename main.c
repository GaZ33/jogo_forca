#include <stdio.h>
#include <conio.h>
#include <windows.h>



void menu(void); // Menu de exibição
void gotoxy(int x, int y); // Função para movimentar os caracteres na tela

int main(void)
{
    menu();
}

void menu(void)
{
    system("cls");
    int posX, posY, tamHon, tamAlt;
    // Caso queira alturar a posição do menu, mude essas 2 variáveis
    posX = 0;       
    posY = 0;
    // Comprimento e altura do menu
    tamHon = 45;
    tamAlt = 20;
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