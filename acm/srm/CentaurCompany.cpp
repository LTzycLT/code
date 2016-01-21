// BEGIN CUT HERE

// END CUT HERE
#line 5 "CentaurCompany.cpp"
#include<stdio.h>
#include<string.h>
#include<sstream>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<string>
#define MP(x,y) make_pair(x,y)
#define clr(x,y) memset(x,y,sizeof(x))
#define ll long long
using namespace std;

vector<int> e[40];
int n;
ll dp[40][2][40][40];
ll back[2][40][40];

void update(int u, int v)
{
    memcpy(back, dp[u], sizeof(back));
    clr(dp[u], 0);
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            for(int k = 0; i + k <= n; k++)
            {
                for(int l = 0; j + l <= n; l++)
                {
                    dp[u][0][i + k][j + l] += dp[v][0][i][j] * back[0][k][l];
                    dp[u][0][i + k][j + l] += dp[v][1][i][j] * back[0][k][l];
                    dp[u][1][i + k][j + l] += dp[v][0][i][j] * back[1][k][l];
                    if(i + k - 1 >= 0) dp[u][1][i + k - 1][j + l] += dp[v][1][i][j] * back[1][k][l];
                }
            }
        }
    }
}
void dfs(int u, int fa)
{
    dp[u][0][0][1] = 1;
    dp[u][1][1][0] = 1;
    for(int i = 0; i < (int)e[u].size(); i++)
    {
        int v = e[u][i];
        if(v == fa) continue;
        dfs(v, u);
        update(u, v);
    }
}
class CentaurCompany
{
    public:
        double getvalue(vector <int> pa, vector <int> pb)
        {
            n = pa.size() + 1;
            clr(dp, 0);
            for(int i = 0; i < n; i++) e[i].clear();
            for(int i = 0; i < n - 1; i++)
            {
                int u = pa[i] - 1;
                int v = pb[i] - 1;
                e[u].push_back(v);
                e[v].push_back(u);
            }
            dfs(0, 0);
            double ans = 0;
            for(int i = 0; i <= n; i++)
                for(int j = 0; j <= n; j++)
                {
                    if(i == 0) continue;
                    ans += max(0, 2 * (i - 1) - (n - j)) * (dp[0][1][i][j] + dp[0][0][i][j]);
                }
            printf("%lf\n", ans);
            for(int i = 0; i < n - 1; i++)
            {
                ans /= 2; 
            }
            return ans;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(0, Arg2, getvalue(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.125; verify_case(1, Arg2, getvalue(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,2,3,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.375; verify_case(2, Arg2, getvalue(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,2,3,4,5,6,7,8,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5,6,7,8,9,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.41796875; verify_case(3, Arg2, getvalue(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 15.500000001076842; verify_case(4, Arg2, getvalue(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {10, 7, 2, 5, 6, 2, 4, 9, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8, 10, 10, 4, 1, 6, 2, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.646484375; verify_case(5, Arg2, getvalue(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    CentaurCompany ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE
