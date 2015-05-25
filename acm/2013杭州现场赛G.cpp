#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<string>
#include<list>
#include<set>
#include<map>
#include<queue>
#include <math.h>
#define clr(x,y) memset(x,y,sizeof(x))
#define forn(i,n) for(int i=0;i<n;i++)
#define MP(x,y) make_pair(x,y)
#define ll long long
const int inf=1<<20;
using namespace std;

const int N = 200000;
vector<pair<int,ll> > e[N];
int n,Q;
vector<ll> ans;
ll w[N];
const int bit=62;
const int ch=2;
int trie[N*30][ch+1],top;

void merge_v(vector<ll> a,vector<ll> b){
    for(int i=0;i<a.size();i++)
        for(int j=0;j<b.size();j++)
            ans.push_back(a[i]^b[j]);
}
void get(int rt,vector<ll> &a){
    if(trie[rt][0]==trie[rt][1] && trie[rt][1]==0){
        a.push_back(w[rt]);
        return ;
    }
    if(trie[rt][0])
        get(trie[rt][0],a);
    if(trie[rt][1])
        get(trie[rt][1],a);
}
int num(int rt){
    return trie[rt][ch];
}
void calc(){
    int sum=n*n-n;
    vector<pair<int,int> > p,q;
    p.push_back(MP(0,0));
    for(int i=bit;i>=0;i--){
        ll temp=0;
        for(int j=0;j<p.size();j++){
            int x=p[j].first,y=p[j].second;
            if(trie[x][0] && trie[y][1])
                temp += num(trie[x][0])*num(trie[y][1]) ;
            if(trie[x][1] && trie[y][0])
                temp += num(trie[x][1])*num(trie[y][0]);
        }
        if(temp>sum){
            q.clear();
            for(int j=0;j<p.size();j++){
                int x=p[j].first,y=p[j].second;
                if(trie[x][0] && trie[y][1])
                    q.push_back(MP(trie[x][0],trie[y][1]));
                if(trie[x][1] && trie[y][0])
                    q.push_back(MP(trie[x][1],trie[y][0]));
            }
            p=q;
        }else{
            q.clear();
            sum-=temp;
            for(int j=0;j<p.size();j++){
                int x=p[j].first,y=p[j].second;
                if(trie[x][0] && trie[y][1]){
                    vector<ll> a,b;
                    get(trie[x][0],a);
                    get(trie[y][1],b);
                    merge_v(a,b);
                }
                if(trie[x][1] && trie[y][0]){
                    vector<ll> a,b;
                    get(trie[x][1],a);
                    get(trie[y][0],b);
                    merge_v(a,b);
                }
            }
            for(int j=0;j<p.size();j++){
                int x=p[j].first,y=p[j].second;
                if(trie[x][0] && trie[y][0])
                    q.push_back(MP(trie[x][0],trie[y][0]));
                if(trie[x][1] && trie[y][1])
                    q.push_back(MP(trie[x][1],trie[y][1]));
            }
            p=q;
        }
    }
}
void insert(ll val){
    int rt=0;
    trie[rt][ch]++;
    for(int i=bit;i>=0;i--){
        int dig=(val>>i)&1;
        if(trie[rt][dig]==0){
            top++;
            clr(trie[top],0);
            trie[rt][dig]=top;
        }
        rt=trie[rt][dig];
        trie[rt][ch]++;
    }
    w[rt]=val;
}
void dfs(int u,int f,ll val){
    insert(val);
    for(int i=0;i<e[u].size();i++){
        int v=e[u][i].first;
        if(v==f) continue;
        dfs(v,u,val^e[u][i].second);
    }
}
bool cmp(ll a,ll b){
    return a>b;
}
int main(){
    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    while(1){
        ans.clear();
        scanf("%d",&n);
        if(n==0) break;
        for(int i=1;i<=n;i++) e[i].clear();
        for(int i=1;i<n;i++){
            int u,v;
            ll w;
            scanf("%d%d%lld",&u,&v,&w);
            e[u].push_back(MP(v,w));
            e[v].push_back(MP(u,w));
        }
        clr(trie[0],0);
        top=0;
        dfs(1,1,0);
        ans.clear();
        calc();
        scanf("%d",&Q);
        sort(ans.begin(),ans.end(),cmp);
        while(Q--){
            int k;
            scanf("%d",&k);
            if(k<=ans.size())
                printf("%lld\n",ans[k-1]);
            else
                printf("-1\n");
        }
    }
    return 0;
}

