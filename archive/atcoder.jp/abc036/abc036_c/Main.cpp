#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,  int>;

const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
  int n;cin >>n;
  vector<int> a(n);
  map<int, int> mp;

  for(int i = 0; i < n; ++i){
    cin >>a[i];
    ++mp[a[i]];
  }
  map<int, int> kv;
  int i=0;
  for(auto it : mp){
    kv[it.first]=i;
    ++i;
  }
  for(int i = 0; i < n; ++i){
    cout << kv[a[i]] << endl;
  }
}
