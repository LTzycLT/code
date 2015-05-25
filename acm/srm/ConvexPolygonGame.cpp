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
const double eps = 1e-10 ;

const ll inf = 1e18;

class ConvexPolygonGame
{
public:
    vector<int> x,y;
    void gao(ll x,ll x1,ll y1,ll x2,ll y2,ll &l,ll &r){
        if(x1==x2){
            if(x==x1){
                l=min(y1,y2)+1;
                r=max(y1,y2)-1;
            }else{
                if((x-x1)*(y2-y1)>0) l=inf,r=-inf;
                else l=-inf,r=inf;
            }
            return ;
        }
        else if(x2>x1){
            r=inf;
            l=(y2-y1)*(x-x1)/(x2-x1)+y1;
            if((x2-x1)*(l-y1)-(x-x1)*(y2-y1)<0)
                l++;

            if(x1==x&&y1==l) l++;
            if(x2==x&&y2==l) l++;
        }else{
            l=-inf;
            r=(y2-y1)*(x-x1)/(x2-x1)+y1;

            if((x2-x1)*(r-y1)-(x-x1)*(y2-y1)<0)
                r--;
            if(x1==x&&y1==r) r--;
            if(x2==x&&y2==r) r--;
        }

    }
    void border(ll sx,ll &l,ll &r,int n){
        l=-inf,r=inf;
        for(int j=0;j<n;j++){
            ll tl,tr;
            gao(sx,x[j],y[j],x[(j+1)%n],y[(j+1)%n],tl,tr);
            l=max(tl,l);
            r=min(tr,r);
        }
    }

	string winner(vector <int> ix, vector <int> iy){
	    x=ix;
	    y=iy;
	    int n=x.size();
        ll s=inf,t=-inf;
        for(int i=0;i<n;i++){
            s=min(s,(ll)x[i]);
            t=max(t,(ll)x[i]);
        }
        ll px[2],py[2],cnt=0;
        bool flag=false;
        for(int i=s;i<=t;i++){
            ll l=-inf,r=inf;
            border(i,l,r,n);
            if(r-l==0){
                if(cnt<2) px[cnt]=i,py[cnt]=r,cnt++;
            }else if(r-l>0){
                if(cnt<2) px[cnt]=i,py[cnt]=l,cnt++;
                if(cnt<2) px[cnt]=i,py[cnt]=r,cnt++;
            }
            if(cnt==2&&r>=l){
                if((i-px[0])*(r-py[1])!=(i-px[1])*(r-py[0])) flag=true;
                if((i-px[0])*(l-py[1])!=(i-px[1])*(l-py[0])) flag=true;
            }
            if(flag) break;
        }
        if(!flag) return "Petya";
        else return "Masha";
	}


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 1, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Petya"; verify_case(0, Arg2, winner(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0, 4, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Masha"; verify_case(1, Arg2, winner(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0, 100, 100, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 100, 100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Masha"; verify_case(2, Arg2, winner(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0, 50, 100, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, -1, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Petya"; verify_case(3, Arg2, winner(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {-100000, 0, 100000, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, -1, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Masha"; verify_case(4, Arg2, winner(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
	ConvexPolygonGame ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
