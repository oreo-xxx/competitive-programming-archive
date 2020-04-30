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
  int n= 5;
  vector<ll> a(n);
  set<ll>ans;
  for(int i = 0; i < n; ++i)cin >> a[i];
  for(int i = 0; i < n; ++i){  
    for(int j = i+1; j < n; ++j){
      for(int k = j+1; k < n; ++k){
        if(i==j||j==k||k==i)continue;
        ll tmp = a[i]+a[j]+a[k];
        ans.insert(-1*tmp);
      }
    }
  }
  int count=0;
  for(auto it : ans){
    if(count==2){
      cout << -1*it << endl;
    }
    ++count;
  }
}

