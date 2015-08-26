#include<stdio.h>
#include<stdlib.h>
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
#define ll unsigned long long
using namespace std;


#define N 3000005
ll  mod = 3221225473;

int a[N], n;
bool vis[N];

int is_not[N], c[N];
void preprecess_prime(int is_not[], int n)
{
    is_not[0] = is_not[1] = 0;
    for(int i = 2; i <= n; i++)
    {
        if(is_not[i] == 0)
        {
            for(int j = 2; j * i <= n; j++)
            {
                is_not[i * j] = i;
            }
        }
    }
}
void factor_to_prime(int x, int c[])
{
    int prime = is_not[x], count = 0;
    while(is_not[x])
    {
        if(is_not[x] != prime)
        {
            c[prime] = max(c[prime], count);
            prime = is_not[x];
            count = 0;
        }
        x /= is_not[x]; 
        count++;
    }
    if(x == prime) c[x] = max(c[x], count + 1);
    else c[prime] = max(c[prime], count), c[x] = max(c[x], 1);
}

ll power(ll a, int idx)
{
    ll ans = 1;
    while(idx)
    {
        if(idx & 1) ans *= a;
        if(ans >= mod) ans %= mod;
        a *= a;
        if(a >= mod) a %= mod;
        idx >>= 1;
    }
    return ans;
}

int main() {
//    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    int T;
    scanf("%d", &T);
    preprecess_prime(is_not, 3000000);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i <=n ; i++) c[i] = 0;
        for(int i = 0; i < n; i++)
        {
            vis[i] = 0;
            scanf("%d", &a[i]);
            a[i]--;
        }
        ll ans = 1;
        for(int i = 0; i < n; i++)
        {
            if(vis[i]) continue;
            int u = i, size = 0;
            while(!vis[u])
            {
                size++;
                vis[u] = 1;
                u = a[u];
            }
            factor_to_prime(size, c);
        }
        for(int i = 2; i <= n; i++)
        {
            ans = ans * power(i, c[i]) % mod;
        }
        printf("%lld\n", ans);
    }

    return 0;
}
