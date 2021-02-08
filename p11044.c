#include<stdio.h>
#include<math.h>
int main(){
    int testCase;
    int row, column;
    while (scanf("%d", &testCase) != EOF)
    {
        int i;
        for(i=0;i<testCase;i++){
            scanf("%d %d",&row,&column);
            int solution = ceil((row) / 3) * ceil((column) / 3);
            printf("%d\n",solution);
        }
    }
    freopen("input.txt", "r", stdin);
    return 0;
}
