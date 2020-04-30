#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 30;
const ll MOD = 1000000007;

ll dp[101010];

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif

    string a, b, c; cin >> a >> b >> c;
    int a_index = 0, b_index = 0, c_index = 0;
    int a_size = a.size(), b_size = b.size(), c_size = c.size();

    char next_c = 'a';
    while(true){
        if(a_index == a_size + 1){
            cout << "A" << endl;
            break;
        }
        else if(b_index == b_size + 1){
            cout << "B" << endl;
            break;
        }
        else if(c_index == c_size + 1){
            cout << "C" << endl;
            break;
        }

        if(next_c == 'a'){
            next_c = a[a_index];
            ++a_index;
        }
        else if(next_c == 'b'){
            next_c = b[b_index];
            ++b_index;
        }
        else if(next_c == 'c'){
            next_c = c[c_index];
            ++c_index;
        }
    }

    return 0;
}

