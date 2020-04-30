#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;
int w = 100100;

int main(){
	int n, c; cin >> n >> c;
	vector<vector<int> > a(c, vector<int>(w));
	for(int i = 0; i < n; ++i){
		  int s,t,ci; cin >> s >> t >> ci;
		  --s; --ci;
		  ++a[ci][s];
		  --a[ci][t];
    }
    
    for(int i = 0; i < c; ++i){
    	for(int j = 0; j < w-1; ++j){
    	    a[i][j+1] += a[i][j];    	    
        }
for(int j = 0; j < w; ++j){
    	    a[i][j] = min(1, a[i][j]);    	    
        }
    }
    int ans = 0;
    for(int i = 0; i < w; ++i){
    	int tmp = 0;
    	for(int j = 0; j < c; ++j){
    	    tmp  += a[j][i];
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
