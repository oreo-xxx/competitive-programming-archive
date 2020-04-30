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
    int a, b; cin >> a >> b;

    if(a <= 0 && 0 <= b){
        cout << "Zero" << endl;
    }
    else if (0 < a){
        cout << "Positive" << endl;
    }
    else {
        int num = b - a + 1;
        if (num % 2 == 0) {
            cout << "Positive" << endl;
        }
        else{
            cout << "Negative" << endl;
        }
    }

    return 0;
}
