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
  vector<int> a;
  for(int i = 1; i < 555556; ++i){
    string s = to_string(i);
    int n = s.size();
    bool f = true;
    for(int j = 0; j < n; ++j){
      if(s[j]!=s[0]){
        f = false;
        break;
      }
    }
    if(f) a.push_back(i);
  }
  int k; cin >> k;
  --k;
  cout << a[k] << endl;
}
