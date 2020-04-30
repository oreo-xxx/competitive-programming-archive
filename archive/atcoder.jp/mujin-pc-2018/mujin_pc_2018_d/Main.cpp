#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
//const int MOD = 1000000007;
const int MOD = 998244353;

// Lib
//

int rev(int x) {
    long long res = 0;
    while (x > 0) { res *= 10; res += x % 10; x /= 10; }
    return res;
}

int memo[1010][1010];
int f(int x, int y) { // =1:無限ループ =2:停止 =3:未確定
    if (memo[y][x]) return memo[y][x];
    memo[y][x] = 3;

    if (x == 0 or y == 0) return memo[y][x] = 2;

    int _x = x, _y = y;

    if(x < y) x = rev(x);
    else y = rev(y);

    if (x < y) y = y - x;
    else x = x - y;

    int nxt = f(x, y);
    if (nxt == 1) return memo[_y][_x] = 1;
    else if (nxt == 2) return memo[_y][_x] = 2;
    else if (nxt == 3) return memo[_y][_x] = 1;
}

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int N, M; cin >> N >> M;
    int ans = 0;
    for(int x = 1; x < N + 1; ++x){
        for(int y = 1; y < M + 1; ++y){
            if (f(x, y) == 1){
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
