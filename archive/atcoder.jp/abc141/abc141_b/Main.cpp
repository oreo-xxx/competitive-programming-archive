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
    string s; cin >> s;
    int n = s.size();
    for(int i = 0; i < n; ++i){
        if( (i + 1) % 2 == 0){
            if(s[i] == 'R'){
                cout << "No" << endl;
                return 0;
            }
        }
        else{
            if(s[i] == 'L'){
                cout << "No" << endl;
                return 0;

            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}

