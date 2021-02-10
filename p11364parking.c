#include<stdio.h>
#include<stdlib.h>

int storeQuantity, storePosition[100];
int cmpfunc(const void *a, const void *b){
    return (*(int*)b - *(int*)a);
}
void readCase(){
    scanf("%d", &storeQuantity);
    int j;
    for(j=0; j < storeQuantity; j++){
        scanf("%d", &storePosition[j]);
    }

}

int solveCase(){
 qsort(storePosition,storeQuantity,sizeof(int),cmpfunc);
    int k, distance;
    distance = 0;
    for(k = 0; k < storeQuantity-1;k++){
        distance = distance + storePosition[k] - storePosition[k+1];
    }
    distance = distance + storePosition[0] - storePosition[storeQuantity -1];
    return distance;
}
void printAnswer(int ans){
    printf("%d\n",ans);
}
int main(){
    int testCase, i, result;
     scanf("%d", &testCase);
    for(i = 0; i < testCase; i++){
        readCase();
       result = solveCase();
      printAnswer(solveCase());
    }
    return 0;
}
