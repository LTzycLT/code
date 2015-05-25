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

const int N = 105;
int a[N][N];

bool visited[N], color[N];
bool dfs(int u, int n, int edge[N][N])
{
    for(int v = 0; v < n; v++)
    {
        if(u == v)
        {
            continue;
        }
        if(edge[u][v])
        {
            if(visited[v])
            {
                if(color[v] == color[u])
                {
                    return false;
                }
            }
            else
            {
                visited[v] = true;
                color[v] = color[u] ^ 1;
                if(!dfs(v, n, edge))
                {
                    return false;
                }
            }
        }
    }
    return true;
}
bool is_bipartite(int n, int edge[N][N])
{
    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
        color[i] = 0;
    }
    visited[0] = true;
    color[0] = 0;
    if(dfs(0, n, edge))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main() {
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);    
    int n;
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
               a[i][j] = 1; 
            }
        }
        for(int i = 0; i < n; i++)
        {
            int id;
            while(scanf("%d", &id) && id != 0)
            {
                id--;
                a[i][id] = 0;
            } 
        } 
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(a[i][j])
                {
                    a[j][i] = 1;
                }
            }
        }
        if(is_bipartite(n, a))
        {
            puts("YES");
        }
        else
        {
            puts("NO");
        }
    }
    return 0;
}
