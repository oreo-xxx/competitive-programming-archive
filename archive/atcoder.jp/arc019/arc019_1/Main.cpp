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
  string s; cin >> s;
  int n = s.size();
  map<char, int> mp;
  mp['O'] = 0;
  mp['D'] = 0;
  mp['I'] = 1;
  mp['Z'] = 2;
  mp['S'] = 5;
  mp['B'] = 8;
  for(int i = 0; i < n; ++i){
    if(mp.count(s[i])==0){
      cout << s[i];
    }
    else{
      cout << mp[s[i]];
    }
  }
  cout << endl;
}
