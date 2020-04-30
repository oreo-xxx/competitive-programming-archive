#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include <cmath>
#include <climits>
#include <queue>

using namespace std;


int main() {
    int n; cin >> n;
    int m; cin >> m;
    vector<int> l(m);
    vector<int> r(m);
    vector<int> canpath(n);
    for(int i = 0; i < m; ++i){
        cin >> l[i];
        cin >> r[i];
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    int minimum = l[m - 1];
    int maximum = r[0];

    int ans = max(0, maximum - minimum + 1);
    cout << ans << "\n";

    return 0;
}