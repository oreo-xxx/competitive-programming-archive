#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int a, b, c; cin >> a >> b >> c;
    int ans = min(b/a, c);
    cout << ans << endl;

    return 0;
}
