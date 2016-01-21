// BEGIN CUT HERE

// END CUT HERE
#line 5 "BearPermutations.cpp"
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

int s;
ll mod;
bool vis[105][105];
ll dp[105][105][105];
ll c[105][105];

void dfs(int n, int p)
{
    if(vis[n][p]) return;
    if(n <= 2) return;
    vis[n][p] = true;

    int x = p;
    int y = n - x - 1;

    for(int i = 0; i < x; i++) dfs(x, i);
    for(int i = 0; i < y; i++) dfs(y, i);

    if(p == 0)
    {
    
    }
    else if(p == n -1)
    {
    
    }
    else
    {
    
    }
}

class BearPermutations
{
    public:
        int countPermutations(int N, int S, int MOD)
        {
            clr(dp, 0);
            clr(c, 0);
            clr(vis, 0);

            int n = N;
            s = S;
            mod = MOD;
            for(int i = 0; i <= 100; i++)
            {
                c[i][0] = c[i][i] = 1;
                for(int j = 1; j <= i; j++)
                {
                    c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod; 
                }
            }

            for(int i = 0; i < n; i++)
            {
                dfs(n, i);
            }
            ll ans = 0;
            for(int i = 0; i < n; i++)
            {    
                for(int j = 0; j <= s; j++)
                {
                    ans = (ans + dp[n][i][j] * c[n - 1][i]) % mod;
                }
            }
            return ans;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 71876209; int Arg3 = 4; verify_case(0, Arg3, countPermutations(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 0; int Arg2 = 1000003; int Arg3 = 8; verify_case(1, Arg3, countPermutations(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 1; int Arg2 = 483128897; int Arg3 = 8; verify_case(2, Arg3, countPermutations(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 3; int Arg2 = 907283243; int Arg3 = 82; verify_case(3, Arg3, countPermutations(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 100; int Arg2 = 101; int Arg3 = 19; verify_case(4, Arg3, countPermutations(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 20; int Arg1 = 30; int Arg2 = 3; int Arg3 = 2; verify_case(5, Arg3, countPermutations(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    BearPermutations ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE
