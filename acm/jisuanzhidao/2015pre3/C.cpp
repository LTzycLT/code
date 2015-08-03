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

int n, m;
int a[100005];
int p[100005];
int q[100005];
ll s[100005], t[100005];

ll cal(int l, int r)
{
    ll temp = s[r];
    ll temp1 = t[r];
    if(l != 0)
    {
        temp -= s[l - 1];
        temp1 -= t[l - 1];
    }
    temp -= temp1 * (l - 1);
    return temp;
}
int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    scanf("%d%d", &n, &m); 
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++)
    {
        p[i] = -1;
        for(int j = 0; i - j >= 0 && i + j < n; j++)
        {
            if(a[i - j] != a[i + j])
                break;
            p[i] = j;
        }

        q[i] = -1;
        for(int j = 0; i - j >= 0 && i + j + 1 < n; j++)
        {
            if(a[i - j] != a[i + j + 1])
                break;
            q[i] = j;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(i > 0){
            s[i] = s[i - 1];
            t[i] = t[i - 1];
        }
        s[i] += i * a[i];
        t[i] += a[i]; 
    }
    while(m--)
    {
        int l, r;
        ll ans = 0;
        scanf("%d%d", &l, &r);
        l--;
        r--;
        for(int i = l; i <= r; i++)
        { 
            int x = p[i];
            x = min(x, i - l);
            x = min(x, r - i);
            ans += 2 * cal(i - x, i - 1) + (x + 1) * a[i];

            if(q[i] == -1)
            {
                continue; 
            }
            x = q[i];
            x = min(x, i -l);
            x = min(x, r - i - 1);
            if(x < 0)
            {
                continue;
            }
            ans += 2 * cal(i - x, i);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
