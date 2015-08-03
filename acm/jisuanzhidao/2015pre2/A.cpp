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

int c[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
struct date
{
    int y, m, d;
};

bool is_bissextile(int year)
{
    if(year % 4 == 0)
    {
        if(year % 100 == 0)
        {
            if(year % 400 == 0)
            {
                return true;
            }
            else 
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}
int cal(int x, int l)
{
    int ans = 0;
    for(int i = 0; i < l; i++)
    {
       ans += c[x % 10]; 
       x /= 10;
    }
    return ans;
}
int val(int y, int m, int d)
{
    return cal(y, 4) + cal(m, 2) + cal(d, 2);
}

bool end(date now)
{
    if(now.y >= 3000) return true;
    else return false;
}
date next(date now)
{
    int td = month[now.m - 1]; 
    if(is_bissextile(now.y) && now.m == 2)
    {
        td++;
    }
    now.d++; 
    if(now.d > td)
    {
        now.d = 1;
        now.m++;
    }
    if(now.m > 12)
    {
        now.m = 1;
        now.y++;
    }
    return now;
}

int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int need = 0, num = 0;
        scanf("%d%d", &num, &need);       
        date now;
        now.y = num / 10000;
        now.m = (num % 10000) / 100;
        now.d = num % 100;

        bool flag = false;
        int index = 0;
        while(!end(now))
        {
            int ret = val(now.y, now.m, now.d);
            if(need == ret)
            {
                flag = true;
                break;
            }
            now = next(now);
            index++;
        }
        if(!flag) puts("-1");
        else printf("%d\n", index);
    }
    return 0;
}
