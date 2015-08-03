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

int c[4] = {1000, 1500, 2000, 2500};
int a[4], b[4]; 


int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++)
    {
        for(int i = 0; i < 4; i++)
        {
            scanf("%d%d", &a[i], &b[i]);
        }
        int ans = 0;
        for(int i = 0; i < 4; i++)
        {
            int temp = c[i] * (250 - a[i]) / 250;
            temp -= b[i] * 50;
            if(temp < c[i] * 4 / 10)
            {
                temp = c[i] * 4 / 10;
            }
            ans += temp;
        }

        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
