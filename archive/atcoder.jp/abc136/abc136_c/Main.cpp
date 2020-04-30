#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD =   1000000007;

/// Lib
///

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    const string yes = "Yes";
    const string no = "No";

    int n; cin >> n;
    vector<int> h(n);
    for(int i = 0; i< n; ++i) {
        cin >> h[i];
    }
    int prev = h[0];
    string ans = yes;
    for(int i = 1; i < n; ++i) {
        if(prev <= h[i]){
            prev = h[i];
            continue;
        }
        else if(prev - 1 == h[i]){
            prev == h[i];
        }
        else{
            ans = no;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}
