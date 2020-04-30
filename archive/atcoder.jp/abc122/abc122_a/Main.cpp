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
    char c; cin >> c;
    char ans;
    if(c == 'A'){
        ans = 'T';
    }
    else if(c == 'T'){
        ans = 'A';
    }
    else if(c == 'C'){
        ans = 'G';
    }
    else{
        ans = 'C';
    }
    cout << ans << endl;

    return 0;
}

