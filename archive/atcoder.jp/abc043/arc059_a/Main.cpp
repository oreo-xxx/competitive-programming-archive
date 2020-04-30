#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
	int n; cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
    }
    int ans = INF32;
    for(int c= -100; c <= 100; ++c){
    int tmp = 0; 
    for(int i = 0; i < n; ++i){
		tmp += (c - a[i])*(c - a[i]);
    }
    ans = min (ans, tmp);
    }
    
    cout << ans << endl;
    return 0;
}