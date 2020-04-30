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

const int n = 8;
vector<string> s(n);

bool c_h(int i){
  int num = 0;
  for(int j = 0; j < n; ++j)if(s[i][j]=='Q')++num;
  return num==1;
}

bool c_v(int j){
  int num = 0;
  for(int i = 0; i < n; ++i)if(s[i][j]=='Q')++num;
  return num==1;
}

bool c_d(int i, int j){
  int num = 0;
  for(int c = -n; c <= n; ++c){
    if(c==0)continue;
    if(0<=i+c&&i+c<n&&0<=j+c&&j+c<n){
      if(s[i+c][j+c]=='Q')++num;
    }
   if(0<=i-c&&i-c<n&&0<=j+c&&j+c<n){
      if(s[i-c][j+c]=='Q')++num;
    }
  }
  return num==0;
}

bool dfs(int i){
  if(i==n)return true;
  if(c_h(i))return dfs(i+1);
  
  for(int j = 0; j < n; ++j){
    s[i][j]='Q';
    if(!c_v(j) || !c_d(i,j)){
      s[i][j]='.';
      continue;
    }
    if(dfs(i+1))return true;
    else s[i][j]= '.';
  }
  return false;
}

int main(){
  for(int j = 0; j < n; ++j)cin >> s[j];
  
  bool ini = true;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      if(s[i][j]=='Q'){
        ini &= c_h(i);
        ini &= c_v(j);
        ini &= c_d(i,j);
      }
    }
  }
  bool ans = dfs(0);
  if(ans&&ini)for(int i = 0; i < n; ++i)cout << s[i] << endl;
  else cout << "No Answer" << endl;
}
