#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;
//const int MOD = 998244353;

// Lib
//

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    string S; cin >> S;
    map<char, int> num;
    for (auto c : S){
        num[c]++;
    }

    ll ml = 0;
    ll rem = 0;
    for (auto itr : num) {
        ml += itr.second / 2 * 2; // 偶数にする
        rem += itr.second % 2;
    }

    // 余ったら
    if (rem > 0) {
        ++ml;
        --rem;
    }

    cout << ml * ml + rem << endl;

    return 0;
}
