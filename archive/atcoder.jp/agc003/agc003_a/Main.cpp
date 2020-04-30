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
    string S; cin >> S;
    map<char, bool> mp;
    for (int i = 0; i < S.size(); ++i){
        mp[S[i]] = true;
    }

    bool flag = true;
    if (mp['N'] != mp['S']){
        flag = false;
    }
    if (mp['W'] != mp['E']){
        flag = false;
    }

    if (flag){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}
