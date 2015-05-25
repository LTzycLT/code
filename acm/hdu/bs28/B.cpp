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

ll a[100000];
int n;
ll q[1000000];
int l, r;
set<ll> st;

int main() {
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    a[0] = 0;
    a[1] = 1;
    for(n = 2; ; n++)
    {
        a[n] = a[n - 1] + a[n - 2];
        if(a[n] > 1e9)
        {
            break;
        }
    }
    l = r = 0;
    for(int i = 0; i < n; i++)
    {
        st.insert(a[i]);
        if(i >= 2)
        {
            q[r++] = a[i];
        }
    }
    while(r != l)
    {
        ll x = q[l++]; 
        for(int i = 2; i < n; i++)
        {
            ll y = a[i] * x;
            if(y > 1e9)
            {
                break;
            }
            if(st.find(y) == st.end())
            {
                st.insert(y);
                q[r++] = y;
            }
        }
    }

    int T;
    scanf("%d", &T);
    while(T--)
    {
        int x; 
        scanf("%d", &x);
        if(st.find(x) != st.end())
        {
            puts("Yes");
        }
        else
        {
            puts("No");
        }
    }

    return 0;
}
