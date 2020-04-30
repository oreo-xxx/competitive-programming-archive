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

int GCD(int a, int b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

int main() {
    int d, g; cin >> d >> g;
    vector<int> p(d);
    vector<int> c(d);
    for (int i = 0; i < d; ++i) {
        cin >> p[i] >> c[i];
    }

    const int INF = 1 << 29;
    int ans = INF;
    for(int bit = 0; bit < (1 << d); ++bit){
        int sum = 0;
        int num = 0;
        for(int i = 0; i < d; ++i) {
            if (bit & (1 << i)) {
                sum += (i + 1) * 100 * p[i] + c[i];
                num += p[i];
            }
        }
        if(sum < g) {
            for (int i = d - 1; i >= 0; --i) {
                if (bit & (1 << i)) {
                    continue;
                }
                for (int j = 0; j < p[i]; ++j) {
                    if (sum >= g) {
                        break;
                    }
                    sum += 100 * (i + 1);
                    ++num;
                }
            }
        }
        ans = min(ans, num);
    }

    cout << ans << endl;
}