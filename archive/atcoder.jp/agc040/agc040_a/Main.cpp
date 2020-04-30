#include<bits/stdc++.h>
using namespace std;

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define all(x) (x).begin(),(x).end()

int main(){
    string s; cin >> s;
    int n = s.size();
    vector<int> a(n+1);
    vector<ll> l(n+1);
    vector<ll> r(n+1);
    rrep(i, n){
        if(s[i] == '>'){
          r[i]=r[i+1]+1;
        }
    }
    rep(i, n){
        if(s[i]== '<'){
          l[i+1]=l[i]+1;
        }
    }
    rep(i, n+1){
      a[i]=max(l[i],r[i]);
    } 
    ll ans = 0;
    for(int i =0; i<=n;++i){
          ans += a[i];
          //cout << a[i] << " ";
    }
    
    cout << ans << endl;
    return 0;
}