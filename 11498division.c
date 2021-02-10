#include <stdio.h>
#include <stdlib.h>

int divisionPointX, divisionPointY, testCase;
void readCase()
{
   
}

void solveCase()
{
}
int main()
{
    int i;

    while (scanf("%d", &testCase) != EOF)
    {
        scanf("%d%d", &divisionPointX, &divisionPointY);
        int residencePointA, residencePointB, j;
        if (testCase != 0)
        {
            for (j=0;j<testCase;j++)
            {
                
                scanf("%d%d", &residencePointA, &residencePointB);
                if (divisionPointX == residencePointA || divisionPointY == residencePointB)
                {
                    printf("divisa\n");
                }
                if (residencePointA > divisionPointX && residencePointB > divisionPointY)
                {
                    printf("NE\n");
                }
                if (residencePointA < divisionPointX && residencePointB > divisionPointY)
                {
                    printf("NO\n");
                }
                if (residencePointA < divisionPointX && residencePointB < divisionPointY)
                {
                    printf("SO\n");
                }
                if (residencePointA > divisionPointX && residencePointB < divisionPointY)
                {
                    printf("SE\n");
                }
            }
        }
    }
    return 0;
}
