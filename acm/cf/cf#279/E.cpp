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

int n;
char s[100005][10];

void any(char a[])
{    
    for(int i = 0; a[i]; i++)
    {
        if(a[i] == '?')
        {
            if(i == 0) a[i] = '1';
            else a[i] = '0';
        }
    }
}
bool gao(char a[], char b[])
{
    int la = strlen(a), lb = strlen(b);
    if(la < lb) return false;
    else if(la == lb)
    {
        for(int i = 0; i < la; i++)
        {
            if(a[i] == '?')
            {
                bool lag = false;
                for(int j = i + 1; j < la; j++)
                {
                    if(a[j] == '?')
                    {
                        if(b[j] != '9')
                        {
                            lag = true;
                            break;
                        }
                    }
                    else if(a[j] > b[j])
                    {
                        lag = true;
                        break;
                    }
                    else if(a[j] < b[j])
                    {
                        lag = false;
                        break;
                    }
                    else continue;
                }
                if(lag) a[i] = b[i];
                else if(b[i] == '9')
                {
                    return false;
                }
                else
                {
                    a[i] = b[i] + 1;
                    any(a);
                    return true;
                }
            }
            else if(a[i] > b[i])
            {
                any(a);
                return true;
            }
            else if(a[i] < b[i])
            {
                return false;
            }
            else continue;
        }
    }
    else
    {
        any(a);
        return true;
    }
    return false;
}

int main() {
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%s", s[i]); 
    }
    any(s[0]);
    int i;
    for(i = 1; i < n; i++)
    {
        if(!gao(s[i], s[i - 1]))
            break;
    }
    if(i < n) puts("NO");
    else
    {
        puts("YES");
        for(int i = 0; i < n; i++)
            printf("%s\n", s[i]);
    }
    return 0;
}
