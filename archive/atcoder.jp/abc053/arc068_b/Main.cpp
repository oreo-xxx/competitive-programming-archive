#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;

int main(){
    int n; cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n; ++i){
    	int tmp; cin >> tmp;
        ++mp[tmp];
    }
    int total = mp.size();
    int num = 0;
    for(auto it : mp){
    	if(it.second % 2 == 0){++num;}
    }
    if(num % 2 == 1){--total;}
    cout << total << endl;
    return 0;
}