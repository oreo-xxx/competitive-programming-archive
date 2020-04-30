#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;


int main(){
	int h,w, n; cin >>h>>w>>n;
	vector<int> vec;
	for(int i = 1; i <= n; ++i){
		int a; cin >> a;
		for(int j = 0; j < a; ++j){
			vec.push_back(i);
        }
    }
	
	vector<vector<int> > ans(h, vector<int> (w));
	int cur=0;
  
	for(int i = 0; i < h; ++i){
if(i% 2==0){
		for(int j = 0; j < w; ++j){
			ans[i][j]=vec[cur];
			++cur;
        }
        }
else{
        for(int j = w-1; j >= 0; --j){
        	ans[i][j]=vec[cur];
        	++cur;
       }
}
       
    }
    
    for(int i = 0; i < h; ++i){
    	for(int j = 0; j < w; ++j){
    	    cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    
    return 0;
}