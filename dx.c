#include <stdio.h>
#include <conio.h>
#include <windows.h>



void borda(int lin, int col); // Menu de exibição
void gotoxy(int x, int y); // Função para movimentar os caracteres na tela
void textcolor(int color, int background); // Função para trocar a cor da letra e do fundo
int menuopcao(int lin, int col, int qtd, char lista[3][10]);


int main(void)
{
    int opc;
    char lista[3][10];
    fgets(lista[0], sizeof(lista), stdin);
    fgets(lista[1], sizeof(lista), stdin);
    fgets(lista[2], sizeof(lista), stdin);

    while (1 == 1)
    {
        opc = menuopcao(10,10,3,lista);
    }
    
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

int menuopcao(int lin, int col, int qtd, char lista[3][10])
{
    int opc=1;
    int lin2, col2, linha, tamMaxitem;

    // Bloco de código para procurar qual linha de texto é maior dentro das opções
    tamMaxitem = strlen(lista[0]);
    for(int i= 1; i < qtd; i++)
    {
        if (tamMaxitem <= strlen(lista[i]))
        {
            tamMaxitem = strlen(lista[i]);
        }
        
    }
    // Ajeitando a altura
    lin2 = lin+(qtd*2+4);
    col2 = col+tamMaxitem+4;
    // Criando as bordas com os resultados obtidos
    borda(lin2, col2);

    // Criando as opções
    while (1 == 1)
    {
        linha=lin+2;
        for(int i=0; i<qtd; i++)
        {
            if(i+1 == opc)
            {
                textcolor(3, 5);
            }
            else
            {
                textcolor(2, 5);
            }
            gotoxy(linha, col+2);
            printf("%s", lista[i]);
            linha += 2;
        }
        
        


    }
    return 0;
    

}