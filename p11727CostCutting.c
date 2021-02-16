#include <stdio.h>

int main()
{
    int i, testCase;
    while (scanf("%d", &testCase) != EOF)
    {
        int first, second, third;
        for (i = 1; i <= testCase; i++)
        {
            scanf("%d%d%d", &first, &second, &third);

            if (first > second && first < third)
            {
                printf("Case %d: %d\n", i, first);
            }
            if (first < second && first > third)
            {
                printf("Case %d: %d\n", i, first);
            }
            if (second > first && second < third)
            {
                printf("Case %d: %d\n", i, second);
            }
            if (second < first && second > third)
            {
                printf("Case %d: %d\n", i, second);
            }
            if (third > first && third < second)
            {
                printf("Case %d: %d\n", i, third);
            }
            if (third < first && third > second)
            {
                printf("Case %d: %d\n", i, third);
            }
        }
        return 0;
    }
}
