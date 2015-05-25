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

#define INF 1e18
int n, m, k;
ll w[1000005];
vector<int> e[1000005];
bool vis[1000005];
bool got[1000005];
ll minn = INF;
int this_u;
multimap<ll, int> zyc;

void dfs(int u)
{
    vis[u] = 1;
    if(w[u] < minn)
    {
        this_u = u;
        minn = w[u];
    }
    for(int i = 0; i < (int)e[u].size(); i++)
    {
        int v = e[u][i]; 
        if(!vis[v])
        {
            dfs(v);
        }
    }
}
int main() {
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    int T;
    scanf("%d", &T);
    for(int cas = 0; cas < T; cas++)
    {
        scanf("%d%d%d", &n, &m, &k);
        zyc.clear();
        for(int i = 0; i < n; i++)
        {
            scanf("%lld", &w[i]); 
            e[i].clear();
            vis[i] = 0;
            got[i] = 0;
            zyc.insert(MP(w[i], i));
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
        int count = 0;
        ll ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                minn = INF;
                dfs(i);
                got[this_u] = true;
                ans += minn;
                count++;
            }
        }
        k -= (m - (n - count));
        multimap<ll, int>::iterator it = zyc.begin();
        while(k > 0)
        {
            while(got[it->second])
            {
               it++; 
            }
            ans += it->first;
            k--; 
            it++;
        } 
        printf("Case #%d: %lld\n", cas + 1, ans);
    }
    return 0;
}
