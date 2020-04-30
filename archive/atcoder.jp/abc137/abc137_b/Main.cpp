#include<bits/stdc++.h>
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
    int k,x; cin >> k >> x;
    int range = 2 * (k-1) + 1;
    for(int i = 1; i <= range; ++i){
    	  int ans = x -k +i;
          cout << ans << endl;
    }
    return 0;
}