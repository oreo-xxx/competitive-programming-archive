#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;

int main(){
    int n, h; cin >>n >>h;
    vector<P> vec(n);
    ll max_ = 0;
    for(int i = 0; i < n; ++i){
        cin >>vec[i].second >> vec[i].first ; 
        max_ = max(max_ , vec[i].second);
    }
    sort(vec.begin(), vec.end(), greater<P>());
   
    ll ans = 0;
    for(int i = 0; i < n; ++i){
    	if(vec[i].first < max_ ){break;}
    	h -= vec[i].first ;
        ++ans;
        if(h <= 0){h = 0;break;}
    }
    ans += (h/max_ );
    if(h%max_ !=0){++ans;}
    cout << ans << endl;
    return 0;
}