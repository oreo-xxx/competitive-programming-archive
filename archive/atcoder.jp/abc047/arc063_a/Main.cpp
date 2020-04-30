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
    string s;cin >>s;
    int n = s.size();
    char k =s[0];
    ll ans=0;
	for(int i = 0; i < n; ++i){
        if(k!=s[i]){
            k=s[i];
            ++ans;
        }
    }
    cout << ans << endl;
}
