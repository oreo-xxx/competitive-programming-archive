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

    int n, a; cin >> n >> a;
    if(n % 500 <= a){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
