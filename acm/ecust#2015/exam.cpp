//http://code.google.com/codejam/contest/dashboard?c=32002#s=p2
//
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

int n, m;
int nx, ny;
char g[100][100];
vector<int> e[10000];
int p[10000];
int match[10000], vis[10000];

int get_p0(int i, int j)
{
    return i * ((m + 1) / 2) + j / 2;
}
int get_p1(int i, int j)
{
    return i * (m / 2) + j / 2;
}
void add(int x, int y, int x1, int y1)
{
    if(x1 < 0 || x1 >= n || y1 < 0 || y1>= m)
    {
        return;
    }
    if(g[x][y] == 'x' || g[x1][y1] == 'x')
    {
        return; 
    }
    int u, v;
    if(y % 2 == 0)
    {
        u = get_p0(x, y);
        v = get_p1(x1, y1);
    }
    else
    {
        u = get_p0(x1, y1); 
        v = get_p1(x, y);
    }
    e[u].push_back(v);
}
bool dfs(int u)
{
    for(int i = 0; i < (int)e[u].size(); i++)
    {
        int v = e[u][i];
        if(!vis[v])
        {
            vis[v] = true;
            if(match[v] == -1 || dfs(match[v]))
            {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}
int hungary()
{
    int res = 0;
    for(int i = 0; i < ny; i++)
    {
        match[i] = -1;
    }
    for(int i = 0 ; i <nx;  i++)
    {
        for(int j = 0; j < ny; j++) 
        {
            vis[j] = false;
        }
        if(dfs(i)) res++;
    }
    return res;
}
int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
//    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    
    int T;
    scanf("%d", &T);
    for(int cas = 0; cas < T; cas++)
    {
        scanf("%d%d", &n, &m);     
        for(int i = 0; i < n; i++)
        {
            scanf("%s", g[i]);
        }
        nx = n * ((m  +  1) / 2);
        ny = n * m - nx;
        for(int i = 0; i < nx; i++)
        {
            e[i].clear();
        }

        int broken = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0;  j < m; j++)
            {
                if(g[i][j] == 'x')
                {
                    broken++;
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                add(i, j, i - 1, j - 1);
                add(i, j, i, j - 1);
                add(i, j, i - 1, j + 1);
                add(i, j, i, j + 1);
            }
        }
        int ans = n * m - broken - hungary();
        printf("Case #%d: %d\n", cas + 1, ans);
    }
    return 0;
}
