#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using edge = int;
using graph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;


int main() {
	ll  n;cin >>n;
    ll x=0, y=0, p=0;
	for(int i = 0; i < n; ++i) {
      ll a, b, t;cin >> t>>a>> b;
      p=t-p;x=abs(a-x);y=abs(b-y);
      if(x+y>p || (x+y)%2 != p%2){
        cout << "No" << endl;
        return 0;
      }
    }
    cout << "Yes" << endl;
}
