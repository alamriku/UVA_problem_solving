#include <stdio.h>

int main()
{

    int testCase, i;

    while (scanf("%d", &testCase) != EOF)
    {
        for (i = 0; i < testCase; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            if (a == b)
            {
                printf("=\n");
            }
            if (a > b)
            {
                printf(">\n");
            }
            else if(a < b)
            {
                printf("<\n");
            }
        }
    }
    freopen("input.txt", "r", stdin);
    return 0;
}
