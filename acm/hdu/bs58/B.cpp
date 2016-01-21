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

ll mod = 1e9 + 7;
int n;
ll a[100005], p[100005], tmp[100005];
int pre[100005];

map<ll, int> zyc;


int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    int T;
    scanf("%d", &T);
    p[0] = 1;
    for(int i = 1; i <= 100000; i++)
    {
        p[i] = p[i - 1] * 2 % mod;
    }
    while(T--)
    {
        zyc.clear();
        scanf("%d", &n);
        ll sum = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%I64d", &a[i]);
            sum += a[i];
            if(zyc.find(a[i]) != zyc.end())
            {
                pre[i] = zyc[a[i]]; 
            }
            else
            {
                pre[i] = -1;
            }
            zyc[a[i]] = i;
        }
        sum %= mod;
        ll ans = sum * p[n - 1] % mod;
        for(int i = 0; i < n; i++)
        {
            if(pre[i] != -1)
            {
                ans -= a[i] * tmp[pre[i]] % mod * p[n - i -1] % mod;
                ans = (ans % mod + mod) % mod;
            }
            tmp[i] = p[i];
            if(pre[i] != -1) tmp[i] = (tmp[i] + tmp[pre[i]]) % mod;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
