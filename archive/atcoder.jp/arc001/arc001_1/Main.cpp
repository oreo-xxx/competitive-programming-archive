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
  int n; string s;
  cin >> n >> s;
  map<char, int> mp;
  mp['1']=0;
  mp['2']=0;
  mp['3']= 0;
  mp['4']= 0;
  for(int i = 0; i < n; ++i){
    ++mp[s[i]];
  }
  int m = INF32, M = 0;
  for(auto it : mp){
    m = min(m, it.second);
    M = max(M, it.second);
  }
  cout << M << " " << m << endl;
}

