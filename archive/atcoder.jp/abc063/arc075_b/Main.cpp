#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;

vector<ll> h;
ll n, a, b;

ll ceil_mod(ll a, ll b){
	ll ret = a/b;
	if(a%b!=0){++ret;}
	return ret;
}

bool check(ll mb){
    ll count = mb;
    for(int i = 0; i < n; ++i) {
    	ll tmp = h[i] - mb*b;
        if(tmp>0){
        	count -= ceil_mod(tmp, (a-b));
            if(count < 0){return false;}
        }
        else{
        	break;
        }
    }
    return true;
}

int main(){
    cin >> n >> a >> b;
    h.resize(n);
   ll hsum=0;
    for(int i = 0; i < n; ++i){
  	  cin >> h[i];
          hsum += h[i];
    }
    sort(h.begin(), h.end(), greater<ll>());
    
    ll lb=0, ub =ceil_mod(hsum , b);
    while(ub - lb > 1){
        ll mb = (lb + ub) / 2;
        if(check(mb)){
            ub = mb;
        }else{
            lb = mb;
        }
    }
    cout << ub << endl;
    
    return 0;
}
