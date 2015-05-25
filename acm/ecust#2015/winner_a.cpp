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

ll a[100];
int n, c;
int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
//    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    
    int T;
    scanf("%d", &T);
    for(int cas = 0; cas < T; cas++)
    {
        scanf("%d%d", &n, &c);
        for(int i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]); 
        }
        ll k;
        do{
            ll sum = 0;
            for(int i = 0; i < n; i++)
            {
                sum += a[i];
            }
            k = sum / c;
            bool exist = false;
            for(int i = 0; i < n; i++)
            {
                if(a[i] > k)
                {
                    exist = true;
                    a[i] = k;
                }
            }
            if(!exist)
            {
                break;
            }
        }while(true);
        printf("%lld\n", k);
    }
    return 0;
}
