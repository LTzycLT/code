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

ll mod = 998244353;
const int N = 50005;
int n;
int l[N * 32], r[N * 32], idx;
ll c[N * 32];

void insert(int w)
{
    int node = 0;
    for(int i = 0; i < 31; i++)
    {
        int x = w % 2;
        w /= 2;
        if(x == 0)
        {
            if(l[node] == -1)
            {
                l[idx] = -1;
                r[idx] = -1;
                c[idx] = 0; 
                l[node] = idx++;
            }
            node = l[node];
        }
        else
        {
            if(r[node] == -1)
            {
                l[idx] = -1;
                r[idx] = -1;
                c[idx] = 0; 
                r[node] = idx++;
            }
            node = r[node];
        }
        c[node]++;
    } 
}
ll dfs(int node, int d)
{
    ll ans = 0;
    if(l[node] != -1 && r[node] != -1)
    {
        ans = (((ll)(c[l[node]] * c[r[node]] % mod)) << d) % mod * 2 % mod; 
    }
    if(l[node] != -1)
    {
        ans += dfs(l[node], d + 1);
        ans %= mod;
    }
    if(r[node] != -1)
    {
        ans += dfs(r[node], d + 1);
        ans %= mod;
    }
    return ans;
}
int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    int T;
    scanf("%d", &T);
    for(int cas = 0; cas < T; cas++)
    {
        idx = 1; 
        l[0] = -1;
        r[0] = -1;
        c[0] = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            int w;
            scanf("%d", &w);
            insert(w);
        }
        ll ans = dfs(0, 0);
        printf("Case #%d: %lld\n", cas + 1, ans);
    }
    return 0;
}
