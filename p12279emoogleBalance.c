#include <stdio.h>

int EventsNumber;
int i = 1;
int readCase()
{
    scanf("%d", &EventsNumber);
    if (EventsNumber == 0)
    {
        return 0;
    }
    return 1;
}

void solveCase(int CaseCount)
{
    int eventI,temp, balance;
    int givenTreat = 0;
    int expectedTreat = 0;
    for (eventI = 0; eventI < EventsNumber; eventI++)
    {
        scanf("%d", &temp);
        if (temp > 0)
        {
            expectedTreat++;
        }else{
            givenTreat++;
        }
    }

    balance = expectedTreat - givenTreat;
    printf("Case %d: %d\n",CaseCount,balance);
    
}

int main()
{

    while (readCase())
    {
        solveCase(i++);
    }
}