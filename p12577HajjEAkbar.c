#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char hajj[15];


int main()
{

    int counter = 1;
    while (scanf("%s", &hajj) != EOF)
    {

        if (hajj[0] != '*')
        {
            if(hajj[0] == 'H'){
                printf("Case %d: Hajj-e-Akbar\n", counter);
            }else{
                printf("Case %d: Hajj-e-Asghar\n", counter);
            }
            
            counter++;
        }
        
    }

    return 0;
}
