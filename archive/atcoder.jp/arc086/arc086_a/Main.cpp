#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using pll = pair<ll, ll>;
using edge = pair<int, ll>;
using graph = vector<vector<int>>; 
using WeightedGraph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main() {
  int n,k;cin >> n >> k;
  map<int, int> mp;
  for(int i = 0; i < n; ++i){
    int a;cin >> a;
    ++mp[a];
  }
  vector<int> a;
  for(auto it : mp){
    a.push_back(it.second);
  }
  sort(a.begin(), a.end(), greater<int>());
  int ans = 0;
  for(int i = 0; i < min(k, (int)a.size()); ++i){
    ans+=a[i];
  }
  cout << n-ans << endl;
}
