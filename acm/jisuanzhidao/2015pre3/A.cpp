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

double PI = acos(-1.0);
int r[360];
int n;
struct item
{
    int s, t, r;
}a[100000];

bool cmp(item &a, item &b)
{
    return a.r > b.r;
}
int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    int T;
    scanf("%d", &T);
    for(int cas = 0; cas < T; cas++)
    {
        clr(r, 0);
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d%d%d", &a[i].r, &a[i].s, &a[i].t); 
            a[i].s += 90;
            a[i].t += 90;
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = a[i].s; j < a[i].t; j++)
            {
               r[j] = max(r[j], a[i].r);
            }
        }
        double ans  = 0;
        for(int i = 0; i < 360; i++)
        {
            ans += (double)r[i] * r[i] * PI / 180;
        }
        printf("%lf\n", ans / 2);

    }
    return 0;
}
