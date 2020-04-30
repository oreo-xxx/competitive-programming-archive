#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
    int n; cin >> n;
    if(n == 1){cout << "Hello World" << endl; }
    else{
    	int a, b; cin >> a >> b;
        int ans = a + b;
        cout << ans << endl;
    }
    return 0;
}