#include <cstdio>
#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#define clr(x,y) memset(x,y,sizeof(x))
using namespace std ;
typedef long long ll ;
const int inf = 1000000000;
const double eps = 1e-6 ;
class YetAnotherBoardGame
{
public:
	int f[1<<16],c[1<<16];
	int g[16],a[16],n,m;
	void init(){
	    clr(f,0);
	    clr(c,0);
		for(int i=0;i<(1<<m);i++){
			for(int j=0;j<m;j++){
				if((i>>j)&1){
					c[i] ++;
					if(j>=1)
						f[i] ^= 1<<(j-1);
					if(j<m-1)
						f[i] ^= 1<<(j+1);
				}
			}
		}
	}
	int minimumMoves(vector <string> board){
		n = board.size();
		m = board[0].size();
		for(int i=0;i<n;i++){
            a[i] = 0;
            for(int j=0;j<m;j++)
                if(board[i][j]=='W') a[i]^=(1<<j);
        }

		init();
		int ans = inf;
		for(int i=0;i<(1<<m);i++){
			for(int j=0;j<(1<<m);j++){
				if((j&i)!=0 && (j&i)!=j) continue;

			    for(int k=0;k<n;k++) g[k] = a[k];
			    bool flag = true;
			    int tmp  = 0;

        		g[0] = g[0] ^ f[j] ^ (j & i);
				g[1] ^= j;
				tmp += c[j];

				for(int k=1;k<n;k++){
					int rt = g[k-1];
					if((rt&i)!=0 && (rt&i)!=rt){
                        flag = false;
                        break;
				}
					tmp += c[rt];
					g[k-1] = 0;
					g[k] ^= f[rt] ^ (rt&i);
					g[k+1] ^= rt;
				}
				if(g[n-1] == 0 && flag)
                    ans = min(ans,tmp);
			}
		}
		if(ans == inf) return -1;
		else return ans;
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"BBBBBBBBB",
 "BBWBBBBBB",
 "BWWWBBBBB",
 "BBWBBBWBB",
 "BBBBBWBWB",
 "BBBBBBWBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, minimumMoves(Arg0)); }
	void test_case_1() { string Arr0[] = {"BBW",
 "WWW",
 "BWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, minimumMoves(Arg0)); }
	void test_case_2() { string Arr0[] = {"WBW",
 "BBW",
 "WBW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, minimumMoves(Arg0)); }
	void test_case_3() { string Arr0[] = {"BBBB",
 "WBWB",
 "BBBB",
 "BBBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(3, Arg1, minimumMoves(Arg0)); }
	void test_case_4() { string Arr0[] = {"WWWWWBW",
 "WBWBWBW",
 "BBWBBWW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(4, Arg1, minimumMoves(Arg0)); }
	void test_case_5() { string Arr0[] = {"WWWWWWWWWW",
 "WWWWWWWWWW",
 "WWWWWWWWWW",
 "WWWWWWWWWW",
 "WWWWWWWWWW",
 "WWWWWWWWWW",
 "WWWWWWWWWW",
 "WWWWWWWWWW",
 "WWWWWWWWWW",
 "WWWWWWWWWW"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; verify_case(5, Arg1, minimumMoves(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
	YetAnotherBoardGame ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
