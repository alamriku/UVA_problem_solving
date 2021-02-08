#include <stdio.h>
#include <stdlib.h>

int initialPosition, firstCombination, secondCombination, thirdCombination, totalRotatedDegree;
int readCase()
{
    scanf("%d%d%d%d", &initialPosition, &firstCombination, &secondCombination, &thirdCombination);

    if (firstCombination == 0 && secondCombination == 0 && thirdCombination == 0)
    {

        return 0;
    }
    return 1;
}

void solveCase()
{
    int rotationOfFirstCombination, rotationOfSecondCombination, rotationOfThirdCombination;
    if (initialPosition < firstCombination)
    {
        rotationOfFirstCombination = 40 + initialPosition - firstCombination;
    }
    else
    {
        rotationOfFirstCombination = initialPosition - firstCombination;
    }
    if (secondCombination < firstCombination)
    {
        rotationOfSecondCombination = 40 + secondCombination - firstCombination;
    }
    else
    {
        rotationOfSecondCombination = firstCombination - secondCombination;
    }
    if (secondCombination < thirdCombination)
    {
        rotationOfThirdCombination = 40 + secondCombination - thirdCombination;
    }
    else
    {
        rotationOfThirdCombination = secondCombination - thirdCombination;
    }
    // 1080 for two full clockwise rotation and one counter-clockwise rotation
    // 9 beacouse 360/40 = 9. to get the degrees we have to multiplie the number by 9;
    totalRotatedDegree = 1080 + 9 * (rotationOfFirstCombination + rotationOfSecondCombination + rotationOfThirdCombination);
    printf("%d\n", totalRotatedDegree);
}
int main()
{

    while (readCase())
    {
        solveCase();
    }
    freopen("input.txt", "r", stdin);
    return 0;
}
