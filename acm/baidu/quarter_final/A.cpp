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

struct stick{
    int x1, x2, y1, y2;
}s[30],h[30];
int n, sn, hn;

int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++)
    {
        scanf("%d", &n);
        sn = hn = 0;
        for(int i = 0; i < n; i++)
        {
            struct stick temp;
            scanf("%d%d%d%d", &temp.x1, &temp.y1, &temp.x2, &temp.y2);
            if(temp.x1 > temp.x2)
            {
                swap(temp.x1, temp.x2);
            }
            if(temp.y1 > temp.y2)
            {
                swap(temp.y1, temp.y2);
            }
            if(temp.x1 == temp.x2)
            {
                s[sn++] = temp;    
            }
            else
            {
                h[hn++] = temp; 
            }
        }
        int ans = 0;
        for(int i1 = 0; i1 < sn; i1++)
        {
            for(int i2 = i1 + 1; i2 < sn; i2++)
            {
                for(int j1 = 0; j1 < hn ; j1++)
                {
                    for(int j2 = j1 + 1; j2 < hn; j2++)
                    {
                        if((    s[i1].y1 < h[j1].y1 && s[i1].y2 > h[j1].y1)
                            && (s[i1].y1 < h[j2].y1 && s[i1].y2 > h[j2].y1)

                            && (s[i2].y1 < h[j1].y1 && s[i2].y2 > h[j1].y1)
                            && (s[i2].y1 < h[j2].y1 && s[i2].y2 > h[j2].y1)

                            && (h[j1].x1 < s[i1].x1 && h[j1].x2 > s[i1].x1)
                            && (h[j1].x1 < s[i2].x1 && h[j1].x2 > s[i2].x1)

                            && (h[j2].x1 < s[i1].x1 && h[j2].x2 > s[i1].x1)
                            && (h[j2].x1 < s[i2].x1 && h[j2].x2 > s[i2].x1)
                          )
                            ans++;
                    }
                }
            }
        }
        printf("Case #%d:\n%d\n", cas, ans);
    }
    return 0;
}
