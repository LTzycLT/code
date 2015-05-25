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

int T, len;
char s[100];

bool same(int l, int r, int len)
{
    for(int i = 0; i < len; i++)
        if(s[l + i] != s[r + i])
            return false;
    return true;
}
int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", s);
        len = strlen(s);
        int j = 0;
        for(int i = 0; i < len; i++)
        {
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
                s[j++] = s[i];
        }
        len = j;

        bool ans = false;
        for(int a = 1; a < len; a++)
        {
            for(int b = 1; b < len; b++)
            {
                if(3 * a + 2 * b == len)
                {
                    if(same(0, a + b, a) && 
                        same(0, 2 * a + 2 * b, a) &&
                        same(a, 2 * a + b, b))
                    {
                        bool temp = true;
                        if(a == b && same(0, a, a))
                            temp = false;
                        if(temp)
                            ans = true;
                    }
                }
                int c = len - 3 * a - 3 * b;
                if(c > 0 && same(0, a + b, a) &&
                    same(0, 2 * a + 2 * b + c, a) &&
                    same(a, 2 * a + b, b) &&
                    same(a, 3 * a + 2 * b + c, b))
                {
                    bool temp = true;
                    if(a == b && same(0, a, a))
                        temp = false;
                    if(a == c && same(0, 2 * a + 2 * b, a))
                        temp = false;
                    if(b == c && same(a, 2 * a + 2 * b, b))
                        temp = false;
                    if(temp)
                        ans = true;
                }
            }
        }
        if(ans) puts("Yes");
        else puts("No");
    } 
    return 0;
}
