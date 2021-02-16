#include<stdio.h>
#include<stdlib.h>

int main(){
    int i, testCase;
    while(scanf("%d",&testCase) != EOF){
        int n;
        int answer;
        for(i=0; i < testCase; i++){
            scanf("%d", &n);
            n = n * 567;
            n  = n / 9;
            n +=7492;
            n *=235;
            n /=47;
            n  = n - 498;
            n/=10;
            n%=10;
             n=abs(n);

            printf("%d\n",n);
        }
    }
    return 0;
}
