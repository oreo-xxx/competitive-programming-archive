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
  int n= s.size();
  map<char, int> mp;
  for(int i = 0; i < 6; ++i){
    char c = 'A'+i;
    mp[c]=0;
  }
  
  for(int i = 0; i < n; ++i){
    ++mp[s[i]];
  }
  for(int i = 0; i < 5; ++i){
    char c = 'A'+i;
    cout << mp[c] << ' ';
  }
  cout << mp['F'] << endl;
}
