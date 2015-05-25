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

bool l[1000005], r[1000005];
char s[1000005];
int a, b, len;

int main() {
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    scanf("%s", s);
    len = strlen(s);
    scanf("%d%d", &a, &b); 
    ll num = 0;
    for(int i = 0; i < len; i++)
    {
        num = (num * 10 + s[i] - '0') % a; 
        if(num == 0) l[i]  = 1;
    }
    ll ten = 1;
    num = 0;
    for(int i = len - 2; i >= 0; i--)
    {
        num = (num + ten * (s[i + 1] - '0')) % b; 
        ten = ten * 10 % b;
        if(num == 0) r[i] = 1;
    }
    int k = -1;
    for(int i = 0; i < len - 1; i++)
        if(s[i + 1] != '0' && l[i] && r[i])
        {
            k = i;
            break;    
        }
    if(k != -1)
    {
        puts("YES");
        for(int i = 0; i <= k; i++)
           printf("%c", s[i]);
        puts("");
        for(int i = k + 1; i < len ; i++)
           printf("%c", s[i]); 
        puts("");
    }
    else
    {
        puts("NO");
    }
    return 0;
}
