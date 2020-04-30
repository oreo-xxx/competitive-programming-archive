#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Lib
//

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int a; cin >> a;
    string s; cin >> s;
    if(a >= 3200){
        cout << s << endl;
    }
    else{
        cout << "red" << endl;

    }

    return 0;
}
