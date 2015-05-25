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

int T, n, m, k, l;
int f[200000];
vector<int> e[200000];
int s[200000], t[200000];
bool ok[200000];

int find(int u)
{
    if(u == f[u]) return u;
    else return f[u] = find(f[u]);
}
void merge(int u, int v)
{
    int fu = find(u);
    int fv = find(v);
    if(fu != fv)
    {
        f[fu] = fv;
    }
}
bool together(int u, int v)
{
    int fu = find(u);
    int fv = find(v);
    return fu == fv;
}
int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 0; i < n; i++)
        {
            e[i].clear();
            f[i] = i;
            ok[i] = true;
        }
        bool ans = true;
        for(int i = 0; i < k; i++)
        {
            scanf("%d", &s[i]);
            s[i]--;
            ok[s[i]] = false;
        }
        for(int i = 0; i < m; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            u--;
            v--;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        scanf("%d", &l);
        for(int i = 0; i < l; i++)
        {
            scanf("%d", &t[i]);
            t[i]--;
        }
        if(l != k) ans = false;

        for(int i = 0; i < n; i++)
        {
            if(!ok[i]) continue;
            for(int j = 0; j < e[i].size(); j++)
                if(ok[e[i][j]]){
                    merge(i, e[i][j]);
                }
        }
        for(int i = 0; i < l - 1; i++)
        {
            ok[t[i]] = true;
            ok[t[i + 1]] = true;
            int u = t[i];
            for(int j = 0; j < e[u].size(); j++)
            {
                int v = e[u][j];
                if(ok[u] && ok[v])
                    merge(u, v);
            }
            u = t[i + 1];
            for(int j = 0; j < e[u].size(); j++)
            {
                int v = e[u][j];
                if(ok[u] && ok[v])
                    merge(u, v);
            }
            if(!together(t[i], t[i + 1]))
            {
                ans = false;
                break;
            }
        }
        int fa = find(0);
        for(int i = 0; i < n; i++)
            if(find(i) != fa)
                ans = false;

        if(ans) puts("Yes");
        else puts("No");
    } 
    return 0;
}
