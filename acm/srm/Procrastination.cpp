// BEGIN CUT HERE

// END CUT HERE
#line 5 "Procrastination.cpp"
#include<stdio.h>
#include<string.h>
#include<sstream>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<string>
#include<map>
#define MP(x,y) make_pair(x,y)
#define clr(x,y) memset(x,y,sizeof(x))
#define ll long long
using namespace std;

class Procrastination
{
    public:
        long long findFinalAssignee(long long n)
        {
            for(ll i = 2; i <= 100000; i++)
            {
                if(n % i == 0 && n / i != 1) n += 1;  
                else if((n - 1) % i == 0 && (n - 1) / i != 1) n -= 1;
            }

            for(ll i = n / 100001; i > 1; i--)
            {
                if(n % i == 0 && n / i != 1) n += 1;  
                else if((n - 1) % i == 0 && (n - 1) / i != 1) n -= 1;
            }
            return n;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 3LL; long long Arg1 = 3LL; verify_case(0, Arg1, findFinalAssignee(Arg0)); }
	void test_case_1() { long long Arg0 = 8LL; long long Arg1 = 11LL; verify_case(1, Arg1, findFinalAssignee(Arg0)); }
	void test_case_2() { long long Arg0 = 20LL; long long Arg1 = 20LL; verify_case(2, Arg1, findFinalAssignee(Arg0)); }
	void test_case_3() { long long Arg0 = 196248LL; long long Arg1 = 196259LL; verify_case(3, Arg1, findFinalAssignee(Arg0)); }
	void test_case_4() { long long Arg0 = 5587021440LL; long long Arg1 = 5587021440LL; verify_case(4, Arg1, findFinalAssignee(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    Procrastination ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE
