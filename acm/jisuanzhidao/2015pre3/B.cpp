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

int n, m;
int a[100005];

int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    scanf("%d%d", &n, &m); 
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    while(m--)
    {
        int l, r;
        int ans = 0;
        scanf("%d%d", &l, &r);
        l--;
        r--;
        for(int i = l; i <= r; i++)
        {
            int sum = 0;
            for(int j = 0; i - j >= l && i + j <= r; j++)
            {
                if(a[i - j] == a[i + j]) 
                {
                    if(j == 0)
                        sum += a[i];
                    else
                        sum += 2 * a[i - j];
                    ans += sum;

                }
                else
                {
                    break;
                }
            }
            sum = 0;
            for(int j = 0; i - j >= l && i + j + 1 <= r; j++)
            {
                if(a[i - j] == a[i + j + 1]) 
                {
                    sum += 2 * a[i - j];
                    ans += sum;
                }
                else
                {
                    break;
                }
            }

        }
        printf("%d\n", ans);
    }
    return 0;
}
