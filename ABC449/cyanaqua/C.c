#include <stdio.h>

int main(void)
{
    int stringLength, leftBound, rightBound;
    char string[500100];

    int numberOfPairs = 0;

    scanf("%d %d %d", &stringLength, &leftBound, &rightBound);
    scanf("%s", string);

    for(int i = 0; i < stringLength - leftBound; i++)
    {
        for(int j = leftBound; j <= rightBound; j++)
        {
            if(i + j >= stringLength) break;

            if(string[i] == string[i + j])
            {
                numberOfPairs++;
            }
        }
    }
    printf("%d", numberOfPairs);
    return 0;
}
