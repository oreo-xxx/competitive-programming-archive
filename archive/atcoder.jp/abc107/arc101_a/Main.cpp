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
    int k; cin >> k;
    vector<int> x(n);
    for(int i = 0; i < n; ++i){
        cin >> x[i];
    }

    vector<int> dists(n- k + 1);
    for(int i = 0; i < n - k + 1; ++i){
        dists[i] = (x[i + k - 1] - x[i]) + min( abs(x[i]), abs(x[i + k - 1]));
    }

    sort(dists.begin(), dists.end());

    cout << dists[0] << "\n";

    return 0;
}