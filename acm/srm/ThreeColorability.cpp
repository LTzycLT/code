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

int n,m;
int bad;
int g[55][55];
vector<pair<int,int> > vc;

class ThreeColorability
{
public:
    void check(int x,int y){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==x||j==y) continue;
                if(g[x][j]!=2&&g[i][y]!=2&&g[i][j]!=2){
                    if(g[i][j]^g[x][j]^g[i][y]^g[x][y]){;
                        bad = 1;
                    }
                }else if(g[x][j]!=2&&g[i][y]!=2){
                    g[i][j] = g[x][y] ^ g[x][j] ^g[i][y];
                    vc.push_back(make_pair(i,j));
                }else if(g[x][j]!=2&&g[i][j]!=2){
                    g[i][y] = g[x][y] ^ g[x][j] ^ g[i][j];
                    vc.push_back(make_pair(i,y));
                }else if(g[i][y]!=2&&g[i][j]!=2){
                    g[x][j] = g[x][y] ^ g[i][y] ^ g[i][j];
                    vc.push_back(make_pair(x,j));
                }
            }
        }
    }
	vector <string> lexSmallest(vector <string> c){
        n = c.size();
        m = c[0].size();
        bad = 0;
        vc.clear();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(c[i][j]=='?') g[i][j] = 2;
                else{
                    if(c[i][j]=='N') g[i][j] = 0;
                    else g[i][j] = 1;
                    vc.push_back(make_pair(i,j));
                }
        for(int i=0;i<(int)vc.size();i++){
            check(vc[i].first,vc[i].second);
        }
        if(bad){
            c.clear();
            return c;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==2){
                    g[i][j] = 0;
                    vc.clear();
                    vc.push_back(make_pair(i,j));
                    for(int k=0;k<(int)vc.size();k++)
                        check(vc[k].first,vc[k].second);
                }
            }
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(g[i][j]==0) c[i][j] = 'N';
                else c[i][j] = 'Z';
		return c;
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"Z"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Z" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, lexSmallest(Arg0)); }
	void test_case_1() { string Arr0[] = {"??", "?N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NN", "NN" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, lexSmallest(Arg0)); }
	void test_case_2() { string Arr0[] = {"ZZZ", "ZNZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, lexSmallest(Arg0)); }
	void test_case_3() { string Arr0[] = {"N?N??NN","??ZN??Z","NN???Z?","ZZZ?Z??","Z???NN?","N?????N","ZZ?N?NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, lexSmallest(Arg0)); }
	void test_case_4() { string Arr0[] = {"ZZZZ","ZZZZ","ZZZZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ZZZZ", "ZZZZ", "ZZZZ" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, lexSmallest(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
	ThreeColorability ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
