    #include <iostream>
    #include <cctype>
    #include <cstdio>
    #include <cstring>
    #include <stack>

    #define BLOCKWORLD(i, n) for (int i; i < n; i++)
    #define maxN 27

    using namespace std;

    int n;
    stack<int> pile[maxN];
    int block[maxN];
    char s1[10], s2[10];

    void move_onto(int a, int b)
    {
        while (pile[block[a]].top() != a)
        {
            int top = pile[block[a]].top();
            block[top] = top;
            pile[top].push(top);
            pile[block[a]].pop();
        }
        while (pile[block[b]].top() != b)
        {
            int top = pile[block[b]].top();
            block[top] = top;
            pile[top].push(top);
            pile[block[b]].pop();
        }

        pile[block[a]].pop();
        block[a] = block[b];
        pile[block[b]].push(a);
    }
    void move_over(int a, int b)
    {
        while (pile[block[a]].top() != a)
        {
            int top = pile[block[a]].top();
            block[top] = top;
            pile[top].push(top);
            pile[block[a]].pop();
        }
        pile[block[a]].pop();
        block[a] =  block[b];
        pile[block[b]].push(a);
    }

    void pile_onto(int a, int b)
    {
    while (pile[block[b]].top() != b)
        {
            int top = pile[block[b]].top();
            block[top] = top;
            pile[top].push(top);
            pile[block[b]].pop();
        }

        stack<int> temp;
        while(pile[block[a]].top() != a){
            temp.push(pile[block[a]].top());
            pile[block[a]].pop();
        }
        temp.push(a);
        pile[block[a]].pop();

        while(!temp.empty()){
            pile[block[b]].push(temp.top());
            block[temp.top()] = block[b];
            temp.pop();
        }
    }

    void pile_over(int a, int b)
    {
        stack<int> temp;
        while(pile[block[a]].top() != a){
            temp.push(pile[block[a]].top());
            pile[block[a]].pop();
        }
        temp.push(a);
        pile[block[a]].pop();

        while(!temp.empty()){
            pile[block[b]].push(temp.top());
            block[temp.top()] = block[b];
            temp.pop();
        }
    }

    void result(){
        stack<int> temp;
        BLOCKWORLD(i, n){
            printf("%d:", i);
            while(!pile[i].empty()){
                temp.push(pile[i].top());
                pile[i].pop();
            }
            while(!temp.empty()){
                printf(" %d",temp.top());
                temp.pop();
            }
            putchar('\n');
        }
    }

    main()
    {
     while (scanf("%d", &n) != EOF) {
        BLOCKWORLD(i, n) {
            pile[i].push(i);
            block[i] = i;
        }
        int a, b;
        while (scanf("%s", &s1) != EOF) {
            if (s1[0] == 'q') break;
            scanf("%d %s %d ", &a, &s2, &b);
            
            if (a == b || block[a] == block[b]) continue;
            if (s1[0] == 'm') {
                if (s2[1] == 'n') move_onto(a, b);
                else move_over(a, b);
            }
            else {
                if (s2[1] == 'n') pile_onto(a, b);
                else pile_over(a, b);
            }
        }
        result();
    }
    }