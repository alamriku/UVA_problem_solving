#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{

    int testCase, i, donate;
    char s1[10];
    int total = 0;
    while (scanf("%d", &testCase) != EOF)
    {
        for (i = 0; i < testCase; i++)
        {

            if (i == 0)
            {

                scanf("%s", &s1);

                if (s1[0] == 'd')
                {
                    scanf("%d", &donate);
                    total = total + donate;
                }else{
                    printf("%d\n", total);
                }
            }
        }
    }

    return 0;
}
