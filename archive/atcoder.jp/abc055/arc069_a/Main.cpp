#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,  int>;

const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
     ll n,m;
     cin >>n >> m;
     ll ans =0;
     if(2*n>m){ans = m/2;}
     else{
         ans += n; m-=2*n;
         ans += m/4;
     }
    cout << ans << endl;
}