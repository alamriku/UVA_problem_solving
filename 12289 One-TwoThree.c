#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char writtenNumber[10];
int smAnswer;

void readCase(){
    gets(writtenNumber);
}

void processCase(){

    if(strlen(writtenNumber) == 5){
        smAnswer = 3;
    }else if( ((writtenNumber[0] == 'o') && (writtenNumber[1] == 'n'))
        || ((writtenNumber[1] == 'n') && (writtenNumber[2] == 'e'))
        || ((writtenNumber[0] == 'o') && (writtenNumber[2] == 'e'))){
        smAnswer = 1;
    }else if( ((writtenNumber[0] == 't') && (writtenNumber[1] == 'w'))
       || ((writtenNumber[1] == 'w') && (writtenNumber[2] == 'o'))
       || ((writtenNumber[0] == 't') && (writtenNumber[2] == 'o'))){
         smAnswer = 2;
    }
}

void printAnswer(){
    printf("%d\n",smAnswer);
}

int main()
{

    int caseCount,i;
    scanf("%d\n",&caseCount);
    for(i=0;i<caseCount;i++){
        readCase();
        processCase();
        printAnswer();
    }
    return 0;
}
