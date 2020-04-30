#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;


int main(){
	int n; cin >>n;
	map<int, int> mp;
	for(int i = 0; i < n; ++i){
		int a; cin >>a;
		++mp[a];
    }
    int ans = 0;
    for(auto it : mp){
    	if(it.second%2!=0){++ans;}
    }
    cout << ans << endl;
    return 0;
}