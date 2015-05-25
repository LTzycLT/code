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

bool a[10000];

int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n + 2; i++)
            a[i] = 0;
        for(int i = 1; i <= n; i++)
        {
            int w;scanf("%d", &w);
            a[w] = 1;
        }
        n+=2;
        int s1 = -1, s2 = -1;
        for(int i = 1; i <= n; i++)
        {
           if(a[i] == 0)
           {
               if(s1 == -1)
               {
                    s1 = i;
               }
               else
               {
                    s2 = i;
               }
           } 
        }
        printf("%d %d\n", s1, s2);
    
    }
    return 0;
}
