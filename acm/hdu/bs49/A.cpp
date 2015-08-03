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

int n, a;
int b[100];

int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    int T;
    scanf("%d", &T);
    for(int cas = 0; cas < T; cas++)
    {
        scanf("%d%d", &n, &a);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &b[i]);
        }
        sort(b, b + n);
        int ans = n + 1;
        for(int i = 0; i < (1 << n); i++)
        {
            int temp = a;
            int cnt = 0;
            for(int j = n - 1; j >= 0; j--) 
            {
                if((i >> j) & 1)
                {
                    cnt++;
                    temp %= b[j];
                }
            }
            if(temp == 0 && cnt < ans)
            { 
                ans = cnt;
            }
        }
        if(ans == n + 1) puts("-1");
        else printf("%d\n", ans);
    }
    return 0;
}
