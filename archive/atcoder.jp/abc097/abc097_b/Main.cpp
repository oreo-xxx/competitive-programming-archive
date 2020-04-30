#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Library
//

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int x; cin >> x;
    int ans = 1;
    for(int i = 2; i * i < x; ++i){
        int tmp = 1;
        for(int j = 0; j < 11; ++j){
            if(tmp * i <= x){
                tmp *= i;
            }
            else{
                break;
            }
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}
