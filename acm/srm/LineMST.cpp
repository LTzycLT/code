// BEGIN CUT HERE

// END CUT HERE
#line 5 "LineMST.cpp"
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

const ll mod = 1e9 + 7;

ll dp[205][205];

ll power(ll a, ll idx)
{
    ll ans = 1;
    while(idx)
    {
        if(idx & 1) ans *= a;
        a *= a;
        a %= mod;
        ans %= mod;
        idx >>= 1;
    }
    return ans;
}
class LineMST
{
    public:
        int count(int n, int l)
        {
            ll p = 1;
            for(int i = 3; i <= n; i++) 
            {
                p = (p * i) % mod;
            }

            clr(dp, 0);
            for(int i = 0; i <= l; i++) dp[0][i] = 1;
            for(int i = 1; i <= n - 1; i++)
            {
                for(int j = 1; j <= l; j++)
                {
                    for(int k = 1; k <= i; k++)
                    {
                        dp[i][j] += dp[k - 1][j - 1] * dp[i - k][j] % mod * power(l - j + 1, k * (i + 1 - k) - 1);
                        dp[i][j] %= mod;
                    }
                    dp[i][j] += dp[i][j - 1];
                    dp[i][j] %= mod;
                }
            }
            return p * dp[n - 1][l] % mod;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 15; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 10; int Arg2 = 10; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 3; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 8; int Arg1 = 41; int Arg2 = 655468587; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 200; int Arg1 = 200; int Arg2 = 152699064; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    LineMST ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE
