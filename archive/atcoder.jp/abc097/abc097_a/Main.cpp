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

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ab = abs(b - a);
    int bc = abs(b - c);
    int ac = abs(c - a);
    if( ac <= d || (ab <= d && bc <= d)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
