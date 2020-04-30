#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;

int main(){
    int h, w, d; cin >> h >> w >> d;
    vector<vector<P> >vec(d, vector<P>((h*w)/d+1) );
    for(int i = 0; i < h; ++i){
    	for(int j = 0; j < w; ++j){
    	    int a; cin >>a;
            vec[a%d][a/d]= {i+1, j+1};
        }
    }
    vector<vector<int> >sum(d, vector<int>((h*w)/d+2));
    
    for(int i = 0; i < d; ++i){
    	  for(int j = 1; j < (h*w)/d+1; ++j){
    	      int tmp1 = abs(vec[i][j].first - vec[i][j-1].first );
              int tmp2 = abs(vec[i][j].second - vec[i][j-1].second );
    	      sum[i][j+1] = sum[i][j] + tmp1+ tmp2;
         }
    }

    int q; cin >> q;
    for(int i = 0; i < q; ++i){
    	  int l, r; cin >> l >> r; 
          cout << sum[l%d][r/d+1] - sum[l%d][l/d+1] << endl;
    }
    return 0;
}