#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using edge = int;
using graph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main() {
	ll  n,c;cin >>n>> c;
	vector<ll> a(n);
	for(int i = 0; i < n; ++i) cin >>a[i];
	map<ll, int> mp, mp2;
	for(int i = 0; i < n; ++i){
      if(i%2)mp[a[i]]++;
      else mp2[a[i]]++;
    }
    int s1=0, s2=0;
    int t1=0, t2=0;
    ll k1 =-1, k2=-1;
    for(auto it:mp) {
      if(t1<it.second){
        t2=t1;
        t1=it.second;
        k1=it.first;
      }
      else if(t2<it.second){
        t2=it.second;
      }
    }
    for(auto it:mp2) {
      if(s1<it.second){
        s2=s1;
        s1=it.second;
        k2=it.first;
      }
      else if(s2<it.second){
        s2=it.second;
      }
    }
    
	ll ans= c*(n-t1-s1);
    if(k1==k2){
      ans=min(n-t1-s2, n-t2-s1);
      ans*=c;
    }
    cout << ans << endl;
}
