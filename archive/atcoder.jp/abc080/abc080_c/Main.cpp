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
	vector<bitset<10>> a;
	for(int i = 0; i < n; ++i){
		string s(10, ' ');
		for(int j = 0; j < 10; ++j){
			cin >>s[j];
        }
        bitset<10> b ( s);
        a.push_back(b);
    }
  
  vector<vector<int> >p(n, vector<int> (11));
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < 11; ++j){
      cin >> p[i][j];
    }
  }
  ll ans = -1* INF;
  for(int i = 1; i < (1<<10); ++i){
    bitset<10> s =(i);
    ll tmp = 0;
    for(int j = 0; j < n; ++j){
      bitset<10> ands = a[j]&s;
      ll num = ands.count();
      tmp += p[j][num];
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}
