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

int sum = 0;
int n;
ll a[100], b[100];
vector<int> e[100];

int val(int x)
{
    int ans = 0;
    while(x)
    {
        ans += (x & 1);
        x >>= 1;
    }
    return ans;
}


bool check(int u, int f, int mask)
{
    vector<ll> temp;
    b[u] = (mask >> u) & 1;
    for(int i = 0; i < (int)e[u].size(); i++)
    {
        int v = e[u][i];
        if(v == f) continue;
        if(!check(v, u, mask))
        {
            return false;
        }
        temp.push_back(b[v]);
    }
    ll ans = 0;
    temp.push_back(b[u]);
    for(int i = 0; i < (int)temp.size(); i++)
    {
        for(int j = i + 1; j < (int)temp.size(); j++)
        {
            ans += temp[i] * temp[j];
        }
    }
    b[u] = 0;
    for(int i = 0; i < (int)temp.size(); i++)
        b[u] += temp[i];
    if(ans >= a[u])
        return true;
    else
        return false;
}
int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]); 
            e[i].clear();
        }
        for(int i = 0; i < n - 1; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v); 
            u--;
            v--;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        sum = (1 << n);
        int min = n + 1, ans = 0;
        for(int i = 0; i < sum; i++)
        {
            if(val(i) < min && check(0, 0, i))
            {
                min = val(i);
                ans = i;
            }
        }
        if(min != n + 1)
        {
            printf("%d\n", min);
            if(min != 0)
            {
                bool first = false;
                for(int i = 0; i < n; i++)
                {
                    if((ans >> i) & 1)
                    {
                        if(first != false) printf(" ");
                        first =  true; 
                        printf("%d", i + 1);
                    }
                }
                puts("");
            }
        }
        else
        {
            puts("-1");
        }
    }
    return 0;
}
