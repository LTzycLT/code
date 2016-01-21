// BEGIN CUT HERE

// END CUT HERE
#line 5 "Treestrat.cpp"
#include<stdio.h>
#include<string.h>
#include<sstream>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<string>
#include<queue>
#include<set>
#define MP(x,y) make_pair(x,y)
#define clr(x,y) memset(x,y,sizeof(x))
#define ll long long
using namespace std;

vector<int> e[100];
set<int> blue;
int n, d[100];

class Treestrat
{
    public:
        int roundcnt(vector <int> tree, vector <int> A, vector <int> B)
        {
            n = tree.size() + 1; 
            blue.clear();
            for(int i = 0; i < n; i++) e[i].clear();
            for(int i = 1; i < n; i++)
            {
                e[i].push_back(tree[i - 1]);
                e[tree[i - 1]].push_back(i);
            }
            for(int i = 0; i < (int)B.size(); i++) blue.insert(B[i]);

            for(int i = 0; i < n; i++)
            {
                bool vis[100]; 
                queue<pair<int, int> > q;
                clr(vis, 0);
                vis[i] = 1;
                q.push(MP(i, 0));
                while(!q.empty())
                {
                    pair<int, int> tmp = q.front(); 
                    //if(i == 0) printf("%d\n", tmp.first);
                    q.pop();
                    if(blue.find(tmp.first) != blue.end())
                    {
                        d[i] = tmp.second;
                        break;
                    }
                    int u = tmp.first;
                    for(int j = 0; j < (int)e[u].size(); j++)
                    {
                        int v = e[u][j];
                        if(vis[v]) continue;
                        vis[v] = true;
                        q.push(MP(v, tmp.second + 1));
                    }
                }
            }
            //for(int i = 0; i < n; i++) printf("%d\n", d[i]);
            int ans = 1e8;
            for(int i = 0; i < (int)A.size(); i++)
            {
                bool vis[100]; 
                int val = 0;
                queue<pair<int, int> > q;
                clr(vis, 0);
                vis[A[i]] = 1;
                q.push(MP(A[i], 0));
                while(!q.empty())
                {
                    pair<int, int> tmp = q.front(); 
                    q.pop();
                    int u = tmp.first;
                    val = max(val, d[u]);
                    if(d[u] <= tmp.second)
                    {
                        continue;
                    }
                    for(int j = 0; j < (int)e[u].size(); j++)
                    {
                        int v = e[u][j];
                        if(vis[v]) continue;
                        vis[v] = true;
                        q.push(MP(v, tmp.second + 1));
                    }
                }
                ans = min(ans, val);
            }
            return ans;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, roundcnt(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(1, Arg3, roundcnt(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0,0,0,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(2, Arg3, roundcnt(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0,0,0,3,4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; verify_case(3, Arg3, roundcnt(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {0,0,0,3,4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(4, Arg3, roundcnt(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {0,0,0,3,4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(5, Arg3, roundcnt(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    Treestrat ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE
