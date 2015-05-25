#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>
#include<string>
#include<set>
#include<queue>
#define MP(x,y) make_pair(x,y)
#define clr(x,y) memset(x,y,sizeof(x))
#define forn(i,n) for(int i=0;i<n;i++)
#define sqr(x) ((x)*(x))
#define MAX(a,b) if(a<b) a=b;
#define ll long long
using namespace std;

const int N = 100000;
int n;
int in[1000006];

bool check_pop_seq(int n, int pop_seq[])
{
    int stack[N];
    int stack_top = 0, index = 1;
    for(int i = 0; i < n; i++)
    {
        if(stack_top > 0 && stack[stack_top - 1] == pop_seq[i])
        {
            stack_top--;
        }
        else
        {
            if(pop_seq[i] >= index)
            {
                for(int j = index; j < pop_seq[i]; j++)
                {
                    stack[stack_top++] = j;
                }
                index = pop_seq[i] + 1;
            }
            else 
            {
                return false;
            }
        }
    }
    return true;
}
int main() {
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    int cas = 0;
    while(scanf("%d", &n) != EOF && n != 0)
    {
        cas++;
        if(cas != 1)
        {
            puts("");
        }
        while(true)
        {
            scanf("%d", &in[0]); 
            if(in[0] == 0)
            {
                break;
            }
            for(int i = 1; i < n; i++)
            {
                scanf("%d", &in[i]);
            }
            if(!check_pop_seq(n, in))
            {
                puts("No");
            }
            else
            {
                puts("Yes");
            }
        }
    }
    return 0;
}
