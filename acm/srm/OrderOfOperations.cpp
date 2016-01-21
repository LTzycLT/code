// BEGIN CUT HERE

// END CUT HERE
#line 5 "OrderOfOperations.cpp"
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

int dp[1 << 20];
int bc[1 << 20];
class OrderOfOperations
{
    public:
        int minTime(vector <string> s)
        {
            int n = s.size(), m = s[0].size();
            int a[n], aim = 0;
            clr(a, 0);
            for(int i = 1; i < (1 << m); i++) bc[i] = bc[i & (i - 1)] + 1;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                    if(s[i][j] == '1')
                        a[i] |= (1 << j);
                aim |= a[i];
            }
            clr(dp, -1);
            dp[0] = 0;
            for(int i = 0; i < (1 << m); i++)
            {
                if(dp[i] == -1) continue;
                for(int j = 0; j < n; j++) 
                {
                    int c = bc[a[j] - (a[j] & i)];
                    int t = a[j] | i, w = dp[i] + c * c;
                    dp[t] = dp[t] == -1 ? w : min(dp[t], w);
                }
            }
            return dp[aim];
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
 "111",
 "001",
 "010"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, minTime(Arg0)); }
	void test_case_1() { string Arr0[] = {
 "11101",
 "00111",
 "10101",
 "00000",
 "11000"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(1, Arg1, minTime(Arg0)); }
	void test_case_2() { string Arr0[] = {
  "11111111111111111111"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 400; verify_case(2, Arg1, minTime(Arg0)); }
	void test_case_3() { string Arr0[] = {
  "1000",
  "1100",
  "1110"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, minTime(Arg0)); }
	void test_case_4() { string Arr0[] = {
  "111",
  "111",
  "110",
  "100"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(4, Arg1, minTime(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    OrderOfOperations ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE
