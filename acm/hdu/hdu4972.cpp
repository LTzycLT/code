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

int n, a[100005];

int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
//    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    int T, cas = 0;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        int s = 1;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        bool flag = true;
        for(int i = 0; i < n - 1; i++)
        {
            if(a[i] == 1 && a[i + 1] == 2)
                s++;
            if(a[i] == 2 && a[i + 1] == 1)
                s++;
            if(abs(a[i + 1] - a[i]) > 3 || (a[i + 1] == a[i] && a[i] != 1))
                flag = false;
        }
        if(n == 1 && a[0] > 3)
            flag = false;
        int ans = s * (2 - (a[n -1] == 0 ? 1 : 0));
        if(!flag)
            ans = 0;
        printf("Case #%d: %d\n", ++cas, ans);
    }

    return 0;
}
