// 2 9223372036854775808
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


ll n, m;
ll p[1000005];
int pn = 0, an = 0, bn = 0;
pair<ll, int> a[1000005];
int b[1000005];
bool vis[1000005];

int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);

    for(int i = 2; i <= 1000000; i++)
    {
        if(!vis[i])
        {
            p[pn++] = i;
            for(int j = i; j <= 1000000; j += i)
            {
                vis[j] = 1;  
            }
        }
    }

    int T;
    scanf("%d", &T);
    while(T--)
    {
        an = 0;
        scanf("%llu%llu", &n, &m);
        for(int i = 0; i < pn && p[i] * p[i] <= n; i++)
        {
            if(n % p[i] == 0)
            {
                int cnt = 0;
                while(n % p[i] == 0) cnt += 1, n /= p[i];
                a[an++] = MP(p[i], cnt);
            }
        }
        if(n > 1) a[an++] = MP(n, 1);

        for(int i = 0; i < an; i++)
        {
            b[i] = 0;
            while(m % a[i].first == 0) b[i] += 1, m /= a[i].first;
        }
        if(m != 1)
        {
            puts("-1");
        }
        else
        {
            bool flag = true;
            int ans = 0;
            for(int i = 0; i < an; i++)
            {
                if(a[i].second > b[i]) flag = false;
                int tmp = 0;
                while(a[i].second < b[i]) a[i].second *= 2, tmp++;
                //printf("%d %d\n", a[i].second, b[i]);
                ans = max(ans, tmp); 
            }
            if(flag) printf("%d\n", ans);
            else puts("-1");
        }
    }
    return 0;
}
