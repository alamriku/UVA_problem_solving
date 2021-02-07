#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>

#define BLOCKWORLD(i, n) for (int i = 0; i < n; i++)
#define maxN 27
using namespace std;

int n, block[maxN];
stack<int> pile[maxN];
char s1[10], s2[10];

void move_onto(int a, int b)
{
    // returning any blocks that are stacked on top of blocks a
    while (pile[block[a]].top() != a)
    {
        int top = pile[block[a]].top();
        block[top] = top;
        pile[top].push(top);
        pile[block[a]].pop();
    }
    // returning any blocks that are stacked on top of blocks b
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
    // returning any blocks that are stacked on top of block a to their initial positions.
    while (pile[block[a]].top() != a)
    {
        int top = pile[block[a]].top();
        block[top] = top;
        pile[top].push(top);
        pile[block[top]].pop();
    }
    pile[block[a]].pop();
    block[a] = block[b];
    pile[block[b]].push(a);
}

void pile_onto(int a, int b)
{
    // All blocks on top of block b are moved to their initial positions prior to the pile taking place.
    while (pile[block[b]].top() != b)
    {
        int top = pile[block[b]].top();
        block[top] = top;
        pile[top].push(top);
        pile[block[b]].pop();
    }

    //store the blocks consisting of block a, and any blocks that are stacked above block a on the temp stack,
    stack<int> temp;
    while (pile[block[a]].top() != a)
    {
        temp.push(pile[block[a]].top());
        pile[block[a]].pop();
    }
    temp.push(a);
    pile[block[a]].pop();
    // moves the pile of blocks consisting of block a, and any blocks that are stacked above block a, onto block b.
    while (!temp.empty())
    {
        pile[block[b]].push(temp.top());
        block[temp.top()] = block[b];
        temp.pop();
    }
}

void pile_over(int a, int b)
{
    //store the blocks consisting of block a, and any blocks that are stacked above block a on the temp stack,
    stack<int> temp;
    while (pile[block[a]].top() != a)
    {
        temp.push(pile[block[a]].top());
        pile[block[a]].pop();
    }
    temp.push(a);
    pile[block[a]].pop();

    while (!temp.empty())
    {
        pile[block[b]].push(temp.top());
        block[temp.top()] = block[b];
        temp.pop();
    }
}

void result()
{
    stack<int> temp;
    BLOCKWORLD(i, n)
    {
        printf("%d:", i);
        while (!pile[i].empty())
        {
            int top = pile[i].top();
            temp.push(top);
            pile[i].pop();
        }
        while (!temp.empty())
        {
            printf(" %d", temp.top());
            temp.pop();
        }
        putchar('\n');
    }
}

main()
{
    while (scanf("%d", &n) != EOF)
    {
        BLOCKWORLD(i, n)
        {
            pile[i].push(i);
            block[i] = i;
        }

        int a, b;
        while (scanf("%s", &s1) != EOF)
        {
            if (s1[0] == 'q')
            {
                break;
            }
            scanf("%d %s %d", &a, &s2, &b);
            // Any command in which a = b or in which a and b are in the same stack of blocks is an illegal
            // command. All illegal commands should be ignored and should have no affect on the configuration of
            // blocks.
            if (a == b || block[a] == block[b])
            {
                continue;
            }

            if (s1[0] == 'm')
            {
                if (s2[1] == 'n')
                {
                    move_onto(a, b);
                }
                else
                {
                    move_over(a, b);
                }
            }
            else
            {
                if (s2[1] == 'n')
                {
                    pile_onto(a, b);
                }
                else
                {
                    pile_over(a, b);
                }
            }
        }
        result();
    }
}