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

int n;
vector<string> v,w;
map<char, string> mp;

bool dfs(int i, int j, int m){
  if(i==n)return true;
  
  char c = v[i][j];
  
  if(j==v[i].size()-1){
    string rem = w[i].substr(m);
    if(mp.count(c)){
      if(mp[c]==rem){
        if(dfs(i+1,0,0))return true;
      }
    }
    else if(0<rem.size() && rem.size()<4){
      mp[c]= rem;
      if(dfs(i+1,0,0))return true;
      else mp.erase(c);
    }
  }
  else{
    if(mp.count(c)){
      int len = mp[c].size();
      if(m+len < w[i].size()){
        if(w[i].substr(m,len)==mp[c]){
          if(dfs(i, j +1, m + len))return true;
        }
      }
    }
    else{
      for(int len = 1; len < 4; ++len){
        if(m+len<w[i].size()){
          mp[c]=w[i].substr(m,len);
          if(dfs(i, j + 1, m+len))return true;
          else mp.erase(c);
        }
      }
    }
  }
  return false;
}

int main(){
  int k; cin >> k >> n;
  v.resize(n);
  w.resize(n);
  for(int i = 0; i < n; ++i)cin >> v[i] >> w[i];
  dfs(0,0,0);
  for(auto it : mp)cout << it.second  << endl;
}
