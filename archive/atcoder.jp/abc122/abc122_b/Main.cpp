#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Library
//

bool check(const char key) {
    bool ret = false;
    switch (key) {
        case 'A':
            ret = true;
            break;
        case 'C':
            ret = true;
            break;
        case 'G':
            ret = true;
            break;
        case 'T':
            ret = true;
            break;
        default:
            break;
    }
    return ret;
}


int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif

    string s; cin >> s;
    s += "!";
    int ans = 0;
    int tmp = 0;
    bool flag = false;
    for(int i = 0; i < s.size(); ++i){
        if(flag){
            if(check(s[i])){
                ++tmp;
            }
            else{
                ans = max(ans, tmp);
                flag = false;
                tmp = 0;
            }
        }
        else{
            if(check(s[i])){
                ++tmp;
                flag = true;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
