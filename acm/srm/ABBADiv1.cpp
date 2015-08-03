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
const double eps = 1e-6 ;
const int inf = 1e8;

bool rev = 0;
string s, t;


bool check(int l, int r)
{
    for(int i = 0; i < r - l; i++)
    {
        if(!rev)
        {
            if(t[i + l] != s[i]) return false;
        }
        else
        {
            if(t[r - i - 1] != s[i]) return false;
        }
    }
    return true;
}
bool get(int l, int r)
{
    string x = t;
    for(int i = l; i < r; i++) x[i] = 'C';
    while(x.length() > s.length())
    {
        int len = x.length();
        while(x[x.size() - 1] == 'A') x = x.substr(0, x.size() - 1);
        if(x[0] == 'B')
        {
            std::reverse(x.begin(), x.end());
            x = x.substr(0, x.size() - 1);
        }
        if((int)x.length() == len)
        {
            return false;
        }
    }
    return true;
}

bool gao(string is, string it)
{
    s = is;
    t = it;
    rev = 0;
    int ls = s.length();
    int lt = t.length();
    int sa = 0, sb = 0, ta = 0, tb = 0;

    for(int i = 0; i < ls; i++)
    {
        if(s[i] == 'A') sa++;
        else sb++;
    }
    for(int i = 0; i < lt; i++)
    {
        if(t[i] == 'A') ta++;
        else tb++;
    }
    if(tb - sb < 0 || ta -sa < 0) return false;
    if((tb - sb) % 2 == 1) rev = true;
    for(int i = 0; i <= lt - ls; i++)
    {
        if(check(i, i + ls) && get(i, i + ls))
           return true; 
    }
    return false;
}
 
class ABBADiv1
{
public:
	string canObtain(string s, string t){
        if(gao(s, t)) return "Possible";
		else return "Impossible";
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "AA"; string Arg1 = "BBAAABAABBBABBBBAAABBBAABA"; string Arg2 = ""; verify_case(0, Arg2, canObtain(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "BAAAAABAA"; string Arg1 = "BAABAAAAAB"; string Arg2 = "Possible"; verify_case(1, Arg2, canObtain(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "A"; string Arg1 = "ABBA"; string Arg2 = "Impossible"; verify_case(2, Arg2, canObtain(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "AAABBAABB"; string Arg1 = "BAABAAABAABAABBBAAAAAABBAABBBBBBBABB"; string Arg2 = "Possible"; verify_case(3, Arg2, canObtain(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "AAABAAABB"; string Arg1 = "BAABAAABAABAABBBAAAAAABBAABBBBBBBABB"; string Arg2 = "Impossible"; verify_case(4, Arg2, canObtain(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
	ABBADiv1 ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
