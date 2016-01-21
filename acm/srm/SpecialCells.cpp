// BEGIN CUT HERE

// END CUT HERE
#line 5 "SpecialCells.cpp"
#include<stdio.h>
#include<string.h>
#include<sstream>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<string>
#include<set>
#include<map>
#define MP(x,y) make_pair(x,y)
#define clr(x,y) memset(x,y,sizeof(x))
#define forn(i, n) for(int i = 0; i < n; i++)
#define ll long long
using namespace std;

typedef int typef;
typedef int typec;
const int N = 510, M = 40001;
const typef inff = 0x3f3f3f3f;
const typec infc = 0x3f3f3f3f;

struct MinCostMaxFlow {
    int e, ev[M], nxt[M], head[N];
    typec cost[M], dist[N];
    typef cap[M];
    int pnt[N], road[N], q[N], bg, ed;
    bool vis[N];
    void init() { e = 0; clr(head, -1); }
    void addedge(int u, int v, typef f, typec c) { //u->v flow=f, cost=c
        //printf("%d %d %d %d\n", u, v, f, c);
        ev[e]=v; cap[e]=f; cost[e]=c; nxt[e]=head[u]; head[u]=e++;
        ev[e]=u; cap[e]=0; cost[e]=-c; nxt[e]=head[v]; head[v]=e++;
    }
    bool spfa(int s, int t, int n) {
        forn (i, n) dist[i] = infc, vis[i] = 0;
        bg = ed = dist[s] = 0;
        pnt[s] = s; q[ed++] = s;
        while (bg != ed) {
            int u = q[bg++]; vis[u] = 0;
            if (bg == N) bg = 0;
            for (int i = head[u]; ~i; i = nxt[i]) {
                if (cap[i] <= 0)continue;
                int v = ev[i];
                if (dist[v] > dist[u] + cost[i]) {
                    dist[v] = dist[u] + cost[i];
                    pnt[v] = u; road[v] = i;
                    if (!vis[v]) {
                        q[ed++] = v; vis[v] = 1;
                        if(ed == N)ed = 0;
                    }
                }
            }
        }
        return dist[t] != infc;
    }
    void mincost(int s, int t, int n, typef &f, typec &c) {
        c = f = 0;
        while(spfa(s, t, n)){
            typef minf = inff;
            for(int u = t; u != s; u = pnt[u])
                minf = min(minf, cap[road[u]]);
            for(int u = t; u != s; u = pnt[u]){
                cap[road[u]] -= minf;
                cap[road[u] ^ 1] += minf;
            }
            f += minf;
            c += minf * dist[t];
        }
    }
}f;

class SpecialCells
{
    public:
        int guess(vector <int> x, vector <int> y)
        {
            f.init();
            set<pair<int, int> > zyc;
            map<int, int> tmp_a, tmp_b;
            int  n = x.size();
            for(int i = 0; i < n; i++)
                zyc.insert(make_pair(x[i], y[i]));

            for(int i = 0; i < n; i++)
            {
                if(tmp_a.find(x[i]) != tmp_a.end()) tmp_a[x[i]] += 1;
                else tmp_a[x[i]] = 1;
            }
            for(int i = 0; i < n; i++)
            {
                if(tmp_b.find(y[i]) != tmp_b.end()) tmp_b[y[i]] += 1;
                else tmp_b[y[i]] = 1;
            }
            
            map<int, int>::iterator it_a = tmp_a.begin(), it_b = tmp_b.begin();
            int a = tmp_a.size(), b = tmp_b.size(); 
            int s = 0, t = a + b + 1;
            for(int i = 0; i < a; i++, it_a++)
            {
                f.addedge(s, i + 1, it_a->second, 0); 
            }
            for(int i = 0; i < b; i++, it_b++)
            {
                f.addedge(a + i + 1, t, it_b->second, 0); 
            }
            it_a = tmp_a.begin();
            /*
            for(set<pair<int, int> >::iterator it = zyc.begin(); it != zyc.end(); it++)
            {
               printf("%d %d\n", it->first, it->second); 
            }
            */
            for(int i = 0; i < a; i++, it_a++)
            {
                it_b = tmp_b.begin();
                for(int j = 0; j < b; j++, it_b++)
                {
                    int w;
                    if(zyc.find(make_pair(it_a->first, it_b->first)) != zyc.end())
                    {
                        w = 1000;
                    }
                    else
                    {
                        w = 1;
                    }

                    f.addedge(i + 1, a + j + 1, 1, w);
                    //printf("%d %d %d\n", it_a->first, it_b->first, w);
                    //printf("%d %d %d\n", i + 1, a + j + 1, w);
                }
            }


            int flow, cost;
            f.mincost(s, t, t + 1, flow, cost);
            return n - cost % 1000;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(0, Arg2, guess(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(1, Arg2, guess(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,2,1,2,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(2, Arg2, guess(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; verify_case(3, Arg2, guess(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,100000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,100000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(4, Arg2, guess(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    SpecialCells ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE
