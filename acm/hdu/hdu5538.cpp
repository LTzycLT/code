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
int a[55][55];
int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++)
                scanf("%d", &a[i][j]);
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(a[i][j] != 0) ans += 1; 

                if(i == 0) ans += a[i][j];
                else ans += max(0, a[i][j] - a[i - 1][j]);

                if(i == n - 1) ans += a[i][j];
                else ans += max(0, a[i][j] - a[i + 1][j]);

                if(j == 0) ans += a[i][j];
                else ans += max(0, a[i][j] - a[i][j - 1]);

                if(j == m - 1) ans += a[i][j];
                else ans += max(0, a[i][j] - a[i][j + 1]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
