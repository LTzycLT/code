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

int n, k;

int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    while(scanf("%d%d", &n, &k) != EOF)
    {
        if(k == 2 && n == 2)
        {
            puts("NO");
            continue;
        }
        bool flag = false;
        int x = (int)sqrt((double)n);
        for(; x >= 1 && !flag; x--){
            int x2 = x * x;
            int y = n - x2;
            int z = x2 - k * (k - 1) / 2;
            if(z < 0 || y <= 0)
                continue;
            if(y <= k - 1)
            {
                if(z + y >= k)
                    flag = true;
            }
            else
            {
                if(z == 1 && k - 1 + z == y)
                {
                }
                else
                {
                    flag = true;
                }
            }
        }
        if(flag)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
