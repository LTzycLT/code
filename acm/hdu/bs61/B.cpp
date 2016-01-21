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
#define ll unsigned long long
using namespace std;

set<ll> zyc;
ll p2[64];

void dfs(ll x)
{
    zyc.insert(x);
    for(int i = 0; i < 64; i++)
    {
        if(p2[i] - 1 == x) 
        { 
            for(int j = 0; j <= i; j++) zyc.insert(p2[j] - 1);
            return ;   
        }
    }

    int i;
    for(i = 0; i < 64; i++)
    {
        if(p2[i] - 1 > x) break;
    }
    i -= 1;

    ll l = p2[i - 1] - 1;
    ll r = p2[i - 1] - 1;
    ll y = x - (p2[i] - 1);
    if(y <= l + 1) l += y;
    else r += (y - l - 1), l = 2 * l + 1;
    //printf("%llu %llu %llu\n", x, l, r);
    dfs(l);
    dfs(r);
}

ll n;
int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);

    p2[0] = 1;
    for(int i = 1; i < 64; i++) p2[i] = p2[i - 1] * 2;
    while(scanf("%llu", &n) != EOF)
    {
        zyc.clear();
        dfs(n);
        printf("%d\n", (int)zyc.size() - 1);
    }
    return 0;
}
