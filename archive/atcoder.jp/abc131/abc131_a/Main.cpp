#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD =   1000000007;

int main()
{
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    string s; cin >> s;
    char tmp = s[0];
    bool flag = true;
    for(int i = 1; i < 4; ++i){
        if(tmp == s[i]){
            flag = false;
            break;
        }
        tmp = s[i];
    }

    if(flag){
        cout << "Good" << endl;
    }
    else{
         cout << "Bad" << endl;
    }

    return 0;
}
