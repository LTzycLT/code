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

char s[100][5];
int a[100];
int n;

int main() {
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    
    int T;
    scanf("%d", &T);
    for(int cas = 0; cas < T; cas++)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%s", s[i]);
        }
        for(int i = 0; i < n; i++)
        {
            a[i] = i;
        }
        int ans = 0;
        do
        {
            bool flag = true;
            for(int i = 1; i < n; i++)
            {
                if(s[a[i - 1]][0] == s[a[i]][0])
                {
                    flag = false;
                } 
            }
            if(flag)
            {
                ans++;
            }
        }while(next_permutation(a, a + n));
        printf("Case #%d: %d\n", cas + 1, ans);
    }
    return 0;
}
