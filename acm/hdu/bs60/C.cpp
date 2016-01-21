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

int n, l, p;
int d[305];

bool cmp(int a, int b)
{
    return __builtin_popcount(a) > __builtin_popcount(b);
}

bool dfs(int k, int depth, int w)
{
    p++;
    if(w == (1 << n) - 1) return true;
    if(depth == l) return false;
    for(int i = k + 1; i <= 300; i++)
    {
        int cnt = __builtin_popcount(w | d[i]);
        cnt += (l - depth - 1) * __builtin_popcount(d[i]);
        if(cnt < n) continue;
        if(dfs(i, depth + 1, w | d[i]))
        {
            return true;
        }
    }
    return false;
}
int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);

    int T;
    scanf("%d", &T);
    while(T--)
    {
        clr(d, 0);
        scanf("%d%d", &n, &l); 
        int w = 0;
        for(int i = 0; i < n; i++)
        {
            int k;
            scanf("%d", &k);
            for(int j = 0; j < k; j++)
            {
                int w;
                scanf("%d", &w);     
                d[w] |= (1 << i);
            }
        }
        sort(d + 1, d + 300); 
        for(int i = 1; i <= 300; i++)
        {
            w |= d[i]; 
        }
        if(__builtin_popcount(w) >= n && dfs(0, 0, 0)) puts("YES");
        else puts("NO");
    }
    printf("%d\n", p);
    return 0;
}

int main1()
{
    puts("1");
    puts("30 5");
    for(int i = 0; i < 5; i++)
    {
        for(int s = 0; s < 6; s++)
        {
            printf("10"); 
            for(int j = 0; j < 10; j++)
            {
                printf(" %d", i * 10 + j + 1);
            }
            puts("");
        }
    }
}
