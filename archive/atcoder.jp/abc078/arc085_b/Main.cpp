#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;


int main(){
	int n,z,w; cin >> n >> z>> w;
	
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >>a[i];
    }
    if(n>1){
    int ans =max(abs(a[n-1]-w), abs(a[n-2]- a[n-1]));
    cout << ans << endl;
    }
    else{
    	cout << abs(a[0]-w) << endl;
    }
    return 0;
}