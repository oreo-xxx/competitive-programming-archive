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

int n,k;
bool flag = false;

void dfs(int i, string& G, vector<char>& buf){
  if(i==n){
    int tmp = 0;
    for(int j = 0; j < n; ++j){
      cout << buf[j];
    }
    cout << endl;
  }
  else{
    for(int j = 0; j < 3; ++j){
      buf[i] = G[j];
      dfs(i+1, G, buf);
    }
  }
}

int main(){
  cin >> n;
  string a = "abc";
  vector<char> buf(n);
  dfs(0, a, buf);
}
