// BEGIN CUT HERE

// END CUT HERE
#line 5 "RandomGCD.cpp"
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
ll mob[100005];

ll power(ll a, ll idx)
{
    ll ans = 1;
    while(idx)
    {
        if(idx & 1) ans = ans * a;
        a *= a;
        ans %= mod;
        a %= mod;
        idx >>= 1;
    }
    return ans;
}

class RandomGCD
{
    public:
        int countTuples(int N, int K, int low, int high)
        {
            clr(mob, 0);
            for(int i = 1; i <= 100000; i++)
            {
                if(i == 1) mob[i] = 1;
                else mob[i] *= -1;
                for(int j = i + i; j <= 100000; j += i)
                    mob[j] += mob[i];
            }

            low = (low % K) ? (low / K + 1) : (low / K);
            high = high / K;

            low = max(1, low);

            if(low > high) return 0;
  
            ll ans = 0; 
            for(int i = 1; i <= (high - low + 1); i++)
            {
                int c = (high / i) - ((low % i) ? (low / i + 1) : (low / i)) + 1;
                if(c > 1)
                {
                    ans += power(c, N) * mob[i];
                    ans -= c * mob[i];
                    ans = (ans % mod + mod) % mod;
                }
            }
            ans += (low == 1 ? 1 : 0);
            return (ans % mod + mod) % mod;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 4; int Arg4 = 3; verify_case(0, Arg4, countTuples(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 100; int Arg2 = 2; int Arg3 = 4; int Arg4 = 0; verify_case(1, Arg4, countTuples(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 5; int Arg2 = 5; int Arg3 = 5; int Arg4 = 1; verify_case(2, Arg4, countTuples(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 73824; int Arg1 = 17347; int Arg2 = 9293482; int Arg3 = 9313482; int Arg4 = 0; verify_case(3, Arg4, countTuples(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 222; int Arg1 = 222; int Arg2 = 222; int Arg3 = 22222; int Arg4 = 339886855; verify_case(4, Arg4, countTuples(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    RandomGCD ___test;
    ___test.run_test(-1);
    system("pause");
}
// END CUT HERE
