#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,  int>;

const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

template<class T> int LIS(vector<T> a,  bool is_strong = true) {
    const T INF = 1<<30; // to be set appropriately
    int n = (int)a.size();
    vector<T> dp(n, INF);
    for (int i = 0; i < n; ++i) {
        if (is_strong) *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
        else *upper_bound(dp.begin(), dp.end(), a[i]) = a[i];
    }
    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}

map<int, priority_queue<int>> mp, mp2;

int main() {
	int n; cin >> n;
	
	for(int i = 0; i < n; ++i){
		int w, h; cin >>w>> h;
		mp[w].push(h);
    }
    vector<int> a, b;
    for(auto it : mp){
        while(!it.second.empty()){
            a.push_back( it.second.top() );
            it.second.pop();
        }
    }
     
    cout <<LIS(a)<< endl;
}