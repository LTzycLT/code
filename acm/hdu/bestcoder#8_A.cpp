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

ll a[1000];
int n;
set<ll> st;

int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    while(scanf("%d", &n) != EOF)
    {
        st.clear();
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                st.insert(a[i] + a[j]);
        ll ans = 0;
        for(set<ll>::iterator it = st.begin(); it != st.end(); it++)
            ans += *it;
        cout << ans << endl;

    }
    return 0;
}
