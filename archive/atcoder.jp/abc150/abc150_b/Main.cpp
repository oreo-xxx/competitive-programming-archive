#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using pll = pair<ll, ll>;
using edge = pair<int, ll>;
using Graph = vector<vector<int>>; 
using WeightedGraph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
  int n;string s;
  cin >> n >> s;
  int ans = 0;
  for(int i = 0; i+2 < n; ++i){
    if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C'){
      ++ans;
    }
  }
  cout << ans << endl;
}
