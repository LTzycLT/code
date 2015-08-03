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

int n;
int a[1000005];

bool ok(int x)
{
    int pre = -10e7;
    for(int i = 0; i < n; i++)
    {
        int tmp = a[i];
        if(tmp > pre)
        {
            tmp = max(pre + 1, tmp - x); 
        }
        else
        {
            if(tmp + x > pre)
            {
                tmp = pre + 1;
            } 
            else
            {
                return false;
            }
        }
        pre = tmp;
    }
    return true;
}
int solve()
{
    int l = 0, r = 10e7;
    while(r - l > 1)
    {
        int mid = (l + r) / 2;
        if(ok(mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    if(ok(l))
    {
        return l;
    }
    else
    {
        return r;
    }
}
int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);

    int T;
    scanf("%d", &T);
    for(int cas = 0; cas < T; cas++)
    {
        scanf("%d", &n); 
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        printf("Case #%d:\n%d\n", cas + 1, solve());
    }
    return 0;
}
