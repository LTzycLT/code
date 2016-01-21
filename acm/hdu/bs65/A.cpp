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

char a[105], b[105];
int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n; 
        scanf("%d", &n);
        scanf("%s%s", a, b);
        bool flag = true;
        for(int i = 0; i < n; i++)
        {
            if(a[i] == 'A' && b[i] != 'U') flag = false;
            if(a[i] == 'T' && b[i] != 'A') flag = false;
            if(a[i] == 'C' && b[i] != 'G') flag = false;
            if(a[i] == 'G' && b[i] != 'C') flag = false;
        }
        if(flag) puts("YES");
        else puts("NO");
    }

    return 0;
}
