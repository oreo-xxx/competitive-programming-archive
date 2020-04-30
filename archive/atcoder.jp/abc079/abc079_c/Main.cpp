#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF = 1LL << 60;
const int MOD = 1000000007;

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif

    string s; cin >> s;
    int n = s.size() - 1;

    const char op_c[] = {'-', ' ', '+'};

    for(ll bit = 0; bit < (1 << n); ++bit){
        vector<int> op(n);
        for (int i = 0; i < n; ++i) {
            if (bit & (1<<i)) {
                op[i] = 1;
            }else{
                op[i] = -1;
            }
        }
        int ans = (int)(s[0] - '0');
        for(int i = 1; i < s.size(); ++i){
            ans += (int)(s[i] - '0') * op[i - 1];
        }
        if(ans == 7){
            cout << s[0] << op_c[op[0] + 1] << s[1] << op_c[op[1] + 1] << s[2] << op_c[op[2] + 1] << s[3] << "=7" << endl;
            return 0;
        }
    }
    cout << "false" << endl;
    return 0;
}

