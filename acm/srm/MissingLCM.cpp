#include <cstdio>
#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#define INC(x,y) {x = (x+y);if(x>=mod) x-=mod;}
#define Min(x,y) {if(y<x) x=y;}
#define Max(x,y) {if(y>x) x=y;}
#define clr(x,y) memset(x,y,sizeof(x))
using namespace std ;
typedef long long ll ;

 
const int N = 1000005;
int co[N], pri[N], pn, temp[N];
bool is[N];


class MissingLCM
{
    void get_prime(int n)
    {
        clr(is, 0);
        pn = 0;
        is[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            if(!is[i])
            {
                pri[pn++] = i;
                for(int j = 2; i * j <= n; j++)
                {
                    is[i * j] = 1;
                }
            }
        } 
    }
public:
	int getMin(int n){
        clr(co, 0);
        clr(temp, 0);
        get_prime(n);
        for(int i = 0; i < pn; i++)
        {
            ll w = 1; 
            int cnt = 0;;
            while(w <= n)
            {
                co[pri[i]] = w;
                w *= pri[i];
                cnt++;
            }
        }
        int ans = n + 1;
        for(int i = 0; i < pn; i++)
        {
            if(co[pri[i]] > 0)
            {
                ans = max(ans, (n / co[pri[i]] + 1) * co[pri[i]]);
            }
        } 
		return ans;
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; verify_case(0, Arg1, getMin(Arg0)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 4; verify_case(1, Arg1, getMin(Arg0)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 6; verify_case(2, Arg1, getMin(Arg0)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 8; verify_case(3, Arg1, getMin(Arg0)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 10; verify_case(4, Arg1, getMin(Arg0)); }
	void test_case_5() { int Arg0 = 42; int Arg1 = 82; verify_case(5, Arg1, getMin(Arg0)); }
	void test_case_6() { int Arg0 = 999999; int Arg1 = 1999966; verify_case(6, Arg1, getMin(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
	MissingLCM ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
