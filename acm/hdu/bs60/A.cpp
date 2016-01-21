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

ll a[100];
int n;
int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        int b = 0, c = 0, d = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%I64d", &a[i]);
            if(a[i] < 0) b += 1;
            if(a[i] == 0) c += 1;
            if(a[i] > 0) d += 1;
        }
        ll ans;
        if(d == 0 && b <= 1)
        {
            if(c > 0)
            {
                ans = 0; 
            }
            else
            {
                ans = a[0];
            }
        }
        else
        {
            ans = 1;
            ll x = 1;
            for(int i = 0; i < n; i++)
            {
                if(a[i] != 0)
                {
                    ans *= a[i];
                    if(a[i] < 0 && b % 2 == 1 && (x == 1 || a[i] > x))
                    {
                        x = a[i];
                    }
                }
            }
            ans /= x;
        }
        printf("%I64d\n", ans);
    }

    return 0;
}
