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
  int n;cin >>n;
  map<string ,string > mp;
  for(int i = 0; i < n; ++i){
    string s;cin >>s;
    string t=s;
    reverse(t.begin(),t.end());
    mp[t]=s;
  }
  for(auto it : mp){
    cout << it.second << endl;
  }
}
