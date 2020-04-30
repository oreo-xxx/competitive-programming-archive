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
  vector<int> x(n);
  priority_queue<int> q1;
  priority_queue<int, vector<int>, greater<int>> q2;
  map<int, int> mp;
  for(int i = 0; i < n; ++i){
    cin >> x[i];
    mp[x[i]]= i + 1;
  }
  for(int i = 0; i < k-1; ++i){
    q1.push(x[i]);
  }
  for(int i = k-1; i < n; ++i){
    if(q1.size()==0){
      q2.push(x[i]);
    }
    else if(q1.top()<x[i]){
      q2.push(x[i]);
    }
    else{
      int tmp= q1.top(); q1.pop();
      q1.push(x[i]);
      q2.push(tmp);
    }
    cout << mp[q2.top()] << endl;
  }
}
