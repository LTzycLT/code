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
int a[100005], p[100005], q[100005];
bool vis[100005];

int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n); 
        for(int i = 1; i <= n; i++) vis[i] = 0;
        for(int i = 1; i <= n; i++) scanf("%d", &p[i]);
        for(int i = 1; i <= n; i++) scanf("%d", &q[i]);
        for(int i = 1; i <= n; i++) a[p[i]] = q[i];
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            if(vis[i]) continue; 
            int cnt = 1;
            vis[i] = 1;
            for(int j = a[i]; j != i; j = a[j])
            {
                vis[j] = 1;
                cnt += 1;
            }
            if(cnt > 1)
            {
                ans += cnt - 1; 
            }
            else
            {
                ans += 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
