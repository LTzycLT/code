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

int n[1000005], p[1000005], f[1000005];
vector<int> ans[2];
int m;

int main() {
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        n[u] = v;
        p[v] = u;
        f[u] = 1;
        f[v] = 1;
    }
    int s1 = 0, s2;
    for(int i = 1; i <= 1000000; i++)
    {
        if(p[i] == 0 && f[i] == 1 && n[0] != i)
            s2 = i;
    }
    int t = n[0];
    while(t)
    {
        ans[0].push_back(t);
        t = n[t];
    }
    t = s2;
    while(t)
    {
        ans[1].push_back(t);
        t = n[t];
    }
    for(int i = 0, j = 0; ; i++, j++)
    {
        if(i >= ans[0].size() && j >= ans[1].size())
            break;
        if(j < ans[1].size())
            printf("%d ", ans[1][j]);
        if(i < ans[0].size())
            printf("%d ",ans[0][i]);
    }
    
    return 0;
}
