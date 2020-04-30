#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
	int n; cin >> n;
	vector<int> h(n);
	for(int i = 0; i < n; ++i){
		cin >> h[i];
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){
		int j = i+1;
		for(; j < n; ++j){
			if(h[j-1]<h[j]){break;}
        }
        ans = max(ans, j-i-1);
        i = j-1;
    }
    
    cout << ans << endl;
    return 0;
}