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

int a[100005];
int r[10][10];
int n, l, x, y;

int find(int need, int &s, int &t)
{
    int j = 0;
    for(int i = 0; i < n; i++)
    {
        while(a[j] - a[i] < need && j < n) j++;
        if(j < n && a[j] - a[i] == need)
        {
            if(need == y - x)
                if(a[i] + y > l && a[j] - y < 0)
                    continue;
            s = a[i];
            t = a[j];
            return 1;
        }
    }
    return 0;
}
int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    scanf("%d%d%d%d", &n, &l, &x, &y);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    r[0][2] = find(x, r[0][0], r[0][1]);

    r[1][2] = find(y, r[1][0], r[1][1]);

    r[2][2] = find(x + y, r[2][0], r[2][1]);

    r[3][2] = find(y - x, r[3][0], r[3][1]);

    if(r[0][2] + r[1][2] >= 1)
    {
        printf("%d\n", 2 - r[0][2] - r[1][2]);
        if(!r[0][2]) printf("%d\n", x);
        if(!r[1][2]) printf("%d\n", y);
    }else
    {
        if(r[2][2])
        {
            printf("1\n%d\n", r[2][0] + x);
        }
        else if(r[3][2] && (r[3][0] + y <= l || r[3][1] - y >=0 ))
        {
            if(r[3][0] + y <= l)
                printf("1\n%d\n", r[3][0] + y);
            else
                printf("1\n%d\n", r[3][1] - y);
        }
        else
        {
            printf("2\n%d %d\n", x, y);
        }
    }
    return 0;
}
