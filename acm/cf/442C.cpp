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
int a[1000000];
set<int> st;
map<int,int> mp;

int main() {
//    freopen("/home/zyc/Downloads/in","r",stdin);
//    freopen("/home/zyc/Downloads/out","w",stdout);
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        st.insert(i);
    }
    for(int i=1;i<=n;i++){
        mp.insert(MP(min(a[i-1],a[i+1]),i));
    }
    ll ans=0;
    while(st.size()){
        map<int,int>::iterator rt = mp.end();
        rt--;
        int u = rt->second;
        int w = rt->first;
        int lw=0,rw=0;
        set<int>::iterator it = st.find(u);
        if(it!=st.begin()){
            it--;
            lw = a[*it];
            it++;
        }
        it++;
        if(it!=st.end()){
            rw = a[*it];
        }
        it--;
        if(w == min(lw,rw)){
            ans += w;
            mp.erase(rt);
            st.erase(it);
        }else{
            mp.erase(rt);
            mp.insert(MP(min(lw,rw),u));
        }
    }
    cout<<ans<<endl;
    return 0;
}
