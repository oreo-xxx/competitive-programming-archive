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
    int D; cin >> D;
    if(D == 25){
        cout << "Christmas" << endl;
    }
    else if(D == 24){
        cout << "Christmas Eve" << endl;
    }
    else if(D == 23){
        cout << "Christmas Eve Eve" << endl;
    }
    else if(D == 22){
        cout << "Christmas Eve Eve Eve" << endl;
    }
    return 0;
}
