#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char hello[100];
int i = 1;

int readCase()
{
    scanf("%s", hello);
    if (strcmp(hello, "#") == 0)
    {
        return 0;
    }
    return 1;
}
void solveCase(int i)
{
    if (strcmp(hello, "HELLO") == 0)
    {
        printf("Case %d: ENGLISH\n", i);
    }
    else if (strcmp(hello, "HOLA") == 0)
    {
        printf("Case %d: SPANISH\n", i);
    }
    else if (strcmp(hello, "HALLO") == 0)
    {
        printf("Case %d: GERMAN\n", i);
    }
    else if (strcmp(hello, "BONJOUR") == 0)
    {
        printf("Case %d: FRENCH\n", i);
    }
    else if (strcmp(hello, "CIAO") == 0)
    {
        printf("Case %d: ITALIAN\n", i);
    }
    else if (strcmp(hello, "ZDRAVSTVUJTE") == 0)
    {
        printf("Case %d: RUSSIAN\n", i);
    }else{
        printf("Case %d: UNKNOWN\n", i);
    }
}
int main()
{
    while (readCase())
    {

        solveCase(i++);
    }
    return 0;
}
