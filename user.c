#include <stdio.h>
#include <string.h>

struct user
{
    char letra;
    int flag;
};


int main()
{
    int a;
    char tentativa[10];
    struct user word[10];
    char palavra[10] = {'a', 'b', 'c', 'd'};
    for (int i = 0; i < strlen(palavra); i++)
    {
        word[i].letra = palavra[i];
    }
    
    for (int i = 0; i < 3; i++)
    {
        printf("\nLeta:");
        fgets(tentativa, sizeof(tentativa), stdin);
        a = strlen(tentativa);
        for (int i = 0; i < strlen(palavra); i++)
        {
            if (tentativa[0] == palavra[i])
            {
                printf("Tem essa letra");
                word[i].flag = 1;
            }
            
        }
    }
    printf("\nLetras acertadas: ");
    for (int i = 0; i < strlen(palavra); i++)
    {
        if (word[i].flag == 1)
        {
            printf("%c", word[i].letra);
        }
        
    }
    
    

    
    

}