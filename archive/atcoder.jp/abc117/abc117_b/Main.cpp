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
    sort(a.begin(), a.end());
    int sum=0;
    for(int i = 0; i < n-1; ++i){
		sum += a[i];
    }
    string ans;
    if(a[n-1]<sum){
    	ans = "Yes";
    }
    else{
    	ans = "No";
    }
    cout << ans << endl;
    return 0;
}