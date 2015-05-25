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

int n, m, q;
int a[105][105];
int s[105];

int main() {
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    int T;
    scanf("%d", &T);
    for(int cas = 0; cas < T; cas++)
    {
        scanf("%d%d%d", &n, &m, &q);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &s[i]);          
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                a[i][j] = 0;
            }
        }
        for(int i = 0; i < m; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            a[v- 1][u - 1] = a[u - 1][v - 1] = w;
        }
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(s[i] != s[j])
                {
                    sum += a[i][j];
                }
            }
        }
        sum /= 2;
        printf("Case #%d:\n", cas + 1);
        while(q--)
        {
            int type, x, y, z;
            scanf("%d", &type);
            if(type == 1)
            {
                scanf("%d", &x);        
                x--;
                for(int i = 0; i < n; i++)
                {
                    if(s[i] == s[x])
                    {
                        sum += a[i][x];
                    }
                    else
                    {
                        sum -= a[i][x];
                    }
                }
                s[x] ^= 1;
            }
            else if(type == 2)
            {
                scanf("%d%d%d", &x, &y, &z); 
                x--;
                y--;
                if(s[x] == s[y])
                {
                    a[x][y] = a[y][x] = z;
                }
                else
                {
                    sum = sum - a[x][y] + z;  
                    a[x][y] = a[y][x] = z;
                }
            }else 
            {
                printf("%d\n", sum); 
            }
        }
    }
    return 0;
}
