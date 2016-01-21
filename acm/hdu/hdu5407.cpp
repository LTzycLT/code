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

#define N 1000005
int is_not[N], c[N];
void preprecess_prime(int is_not[], int n)
{
    is_not[0] = is_not[1] = 0;
    for(int i = 2; i <= n; i++)
    {
        if(is_not[i] == 0)
        {
            for(int j = 2; j * i <= n; j++)
            {
                is_not[i * j] = i;
            }
        }
    }
}

/* factorize x, and update c with the greater number
 */
void factor_to_prime(int x, int c[])
{
    int prime = is_not[x], count = 0;
    while(is_not[x])
    {
        if(is_not[x] != prime)
        {
            c[prime] = max(c[prime], count);
            prime = is_not[x];
            count = 0;
        }
        x /= is_not[x]; 
        count++;
    }
    if(x == prime) c[x] = max(c[x], count + 1);
    else c[prime] = max(c[prime], count), c[x] = max(c[x], 1);
}

int main() {
    freopen("/home/zyc/Documents/code/acm/in","r",stdin);
    return 0;
}
