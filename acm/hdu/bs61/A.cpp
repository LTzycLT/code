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

int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    int s, t, n;
    while(scanf("%d%d%d", &n, &s, &t) != EOF)
    {
        if(s == t)
        {
            if(n != 1) puts("-1");
            else puts("0");
        }
        else if((s == 1 && t == n) || (s == n && t == 1))
        {
            puts("0");
        }
        else
        {
            if(s < t)
            {
                if(t - s > 1 && s > 1)
                {
                    puts("2");
                    continue;
                }
            }
            else
            {
                if(s - t > 1 && s < n)
                {
                    puts("2");
                    continue;
                }
            }
            puts("1");
        }
        
    }
    return 0;
}
