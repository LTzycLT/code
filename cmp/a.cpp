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

struct item
{
    int l, r, w;
    double v;
}a[10005];
double dp[10005];

bool cmp(const item &a, const item &b)
{
    if(a.r != b.r)
    {
        return a.r < b.r;
    }
    else
    {
        return a.l > b.l;
    }
}
int main() {
//    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    
    int T;
    scanf("%d", &T);
    for(int cas = 0; cas < T; cas++)
    {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            int x, y, w;
            scanf("%d%d%d", &x, &y, &w);
            a[i].l = x - y;
            a[i].r = x + y;
            a[i].w = w;
            a[i].v = (double)y * y;
        }
        sort(a, a + n, cmp);
        for(int i = 0; i < n; i++)
        {
            double val = a[i].w - a[i].v;
            double add = 0;
            double maxx = 0;
            int s = i - 1;
            for(int j = i - 1; j >= 0; j--)
            {
                while(s >= 0 && a[s].r > a[j].r)
                {
                    if(a[s].l >= a[i].l)
                    {
                        add += a[s].w;
                    }
                    s--;
                }
                if(a[j].l < a[i].l)
                {
                    double temp = val;
                    temp += dp[j];
                    if(a[j].r > a[i].l)
                    {
                        double l = a[j].r - a[i].l;
                        temp += (l / 2) * (l / 2);
                    }
                    if(temp + add > maxx)
                    {
                        maxx = temp + add; 
                    }
                }
            }
            while(s >= 0)
            {
                if(a[s].l >= a[i].l)
                {
                    add += a[s].w;
                }
                s--;
            }

            dp[i] = max(maxx, val + add);
        }
        double ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans = max(ans, dp[i]);
        }
        printf("Case #%d: %.2lf\n", cas + 1, ans);
    }
    return 0;
}
