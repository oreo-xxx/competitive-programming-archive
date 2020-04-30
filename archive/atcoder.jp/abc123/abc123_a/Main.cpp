#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int a, b, c, d, e, k;
    cin >> a >> b >> c >> d >> e >> k;

    if(e-a > k){
        cout << ":(" << endl;
    }
    else{
        cout << "Yay!" << endl;
    }
    return 0;
}

