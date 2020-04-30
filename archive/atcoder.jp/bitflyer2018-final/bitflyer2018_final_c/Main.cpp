#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    string S; cin >> S;
    int stack[220000] = {0};
    int pointer = 110000;
    stack[pointer] = 1;
    long long res = 0;
    for (int i = 0; i < S.size(); ++i) {
        if (S[i] == '(') {
            ++pointer;
            stack[pointer] = 1;
        }
        else {
            --pointer;
            res += stack[pointer];
            ++stack[pointer];
        }
    }
    cout << res << endl;

    return 0;
}

