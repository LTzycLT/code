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

double eps = 1e-8;
int n;
int a[10000];

int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    while(scanf("%d", &n)!=EOF)
    {
        int sum = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        sort(a + 1, a + n + 1);
        double average = (double)sum / n;
        if(a[(n + 1) / 2] <= average + eps)
            puts("NO");
        else
            puts("YES");

    }
    return 0;
}
