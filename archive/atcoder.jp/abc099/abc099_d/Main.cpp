#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;

int t[3][30];

int calc(const vector<vector<int> >& d, const vector<vector<int> >& c, int c1, int c2, int c3){
	int ret =0;
	for(int i = 0; i < d.size(); ++i){
	    ret += d[i][c1]*t[0][i];
	    ret += d[i][c2]*t[1][i];
	    ret += d[i][c3]*t[2][i];
    }
	return ret;
}

int main(){
    int n, C; cin >>n>>C;
    vector<vector<int>> d(C, vector<int>(C));
    vector<vector<int>> c(n, vector<int>(n));
    for(int i = 0; i < C; ++i){
  	  for(int j = 0; j < C; ++j){
  	      cin >> d[i][j];	
        }
    }
    
    for(int i = 0; i < n; ++i){
  	  for(int j = 0; j < n; ++j){
  	      cin >> c[i][j]; --c[i][j];
            ++t[(i+j)%3][c[i][j]];
        }
    }
    
    int ans = INF32;
    for(int i = 0; i < C; ++i){
    	for(int j = 0; j < C; ++j){
    	    if(i==j) continue;
    	    for(int k = 0; k < C; ++k){
    	        if(j==k || k==i){continue;}
                int tmp =calc(d,c,i,j,k);
                ans = min(ans, tmp);
            }
        }
    }
    cout << ans << endl;
    return 0;
}