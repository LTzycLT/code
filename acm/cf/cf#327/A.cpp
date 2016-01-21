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
int a[500005];
int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int ans = 0;
    int s = 0;
    while(s < n - 1)
    {
        while(s < n - 1 && a[s] == a[s + 1]) s += 1;

        int t = s;
        while(t < n - 1 && a[t] != a[t + 1]) t += 1;
        if(t - s > 1)
        {
            if(a[s] == a[t])
            {
                ans = max(ans, (t - s) / 2);
                for(int i = s + 1; i < t; i++)
                {
                    a[i] = a[s]; 
                }
            }
            else
            {
                int g = (t - s - 1) / 2;
                ans = max(ans, g);
                for(int i = s + 1; i <= s + g; i++) a[i] = a[s];
                for(int i = s + g + 1; i < t; i++) a[i] = a[t];
            }
        }
        s = t;
    }
    printf("%d\n", ans);
    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
