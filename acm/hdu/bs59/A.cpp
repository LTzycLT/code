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
int a[100];
int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);        
        int ans = n;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        for(int i = n - 1; i >= 0; i--)
        {
            if(a[i] == ans) 
            {
                ans -= 1; 
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
