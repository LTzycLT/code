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

const ll mod = 1000000007;
int n;
ll K;
ll a[1005];
map<ll, ll> zyc[2];
int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);

    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%lld", &n, &K);
        for(int i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
        }
        zyc[0].clear();
        zyc[1].clear();
        zyc[0][K] = 1;
        for(int i = 0; i < n; i++)
        {
            int s = i & 1;
            int t = s ^ 1;
            zyc[t].clear();
            map<ll, ll>::iterator it = zyc[s].begin();
            for(; it != zyc[s].end(); it++) 
            {
                zyc[t][it->first] = (zyc[t][it->first] + it->second) % mod; 
                if(it->first % a[i] == 0)
                {
                    ll x = it->first / a[i];
                    zyc[t][x] = (zyc[t][x] + it->second) % mod;
                }
            }
        }
        printf("%lld\n", zyc[n & 1][1]);
    }
    return 0;
}
