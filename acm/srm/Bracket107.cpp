// BEGIN CUT HERE

// END CUT HERE
#line 5 "Bracket107.cpp"
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
#define MP(x,y) make_pair(x,y)
#define clr(x,y) memset(x,y,sizeof(x))
#define ll long long
using namespace std;


set<string> zyc;

class Bracket107
{
    bool is_valid(string s)
    {
        ll sum = 0;
        for(int i = 0; i < (int)s.size(); i++)
        {
            if(s[i] == '(') sum += 1;
            else sum -= 1;
            if(sum < 0) return false;
        }
        if(sum == 0) return true;
        return false;
    }
    public:
        int yetanother(string s)
        {
            int n = s.size();
            zyc.clear();
            for(int i = 0; i < n; i++)
            {
                string t = s.substr(0, i) + s.substr(i + 1, n);
                for(int j = 0; j < n; j++)
                {
                    string p = t.substr(0, j) + s[i] + t.substr(j, t.size());
                    if(is_valid(p))
                    {
                        if(s != p)
                        {
                            zyc.insert(p);
                        }
                    }
                }
            }
            return zyc.size();
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "(())"; int Arg1 = 1; verify_case(0, Arg1, yetanother(Arg0)); }
	void test_case_1() { string Arg0 = "(())()"; int Arg1 = 3; verify_case(1, Arg1, yetanother(Arg0)); }
	void test_case_2() { string Arg0 = "()()()"; int Arg1 = 3; verify_case(2, Arg1, yetanother(Arg0)); }
	void test_case_3() { string Arg0 = "(((())))"; int Arg1 = 5; verify_case(3, Arg1, yetanother(Arg0)); }
	void test_case_4() { string Arg0 = "((())())"; int Arg1 = 9; verify_case(4, Arg1, yetanother(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    Bracket107 ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE
