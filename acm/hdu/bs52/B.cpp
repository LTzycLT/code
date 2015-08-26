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

#define N 50005
int n, m;
ll w[N], a[N];

ll gcd(ll a, ll b)
{
    if(b == 0) return a;
    else return gcd(b, a % b);
}
int main() {
    //freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    freopen("case","r",stdin);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++)
            scanf("%I64u", &w[i]);
        for(int i = 0; i < n; i++) a[i] = 0;
        for(int i = 0; i < m; i++)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            l--;r--;
            a[l] += 1;
            a[r + 1] -= 1;
        }
        if(m < 3){
            printf("0\n");
            continue;
        }
        for(int i = 1; i < n; i++) a[i] += a[i - 1];

        ll sum = 0, div = (ll)m * (m - 1) * (m - 2);
        for(int i = 0; i < n; i++)
        {
            if(a[i] >= 3)
                sum += w[i] * a[i] * (a[i] - 1) * (a[i] - 2) / 6; 
        }
        ll g = gcd(sum ,div);
        sum /= g;
        div /= g;
        if(div == 1) printf("%I64u\n", sum);
        else printf("%I64u/%I64u\n", sum, div);
    }
    return 0;
}
