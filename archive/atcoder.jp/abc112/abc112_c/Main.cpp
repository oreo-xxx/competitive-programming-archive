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
    vector<int> x(n);
    vector<int> y(n);
    vector<int> h(n);
    int maxh = 0;
    for(int i = 0; i < n; ++i){
        cin >> x[i];
        cin >> y[i];
        cin >> h[i];
        maxh = max(maxh, h[i]);
    }

    for(int k = maxh + 210; k >= 0; --k){
        for(int i = 0; i <= 100; ++i){
            for(int j = 0; j <= 100; ++j){
                bool flag = true;
                for(int l = 0; l < n ; ++l){
                    if(max(k - abs(i - x[l]) - abs(j - y[l]), 0) != h[l]){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    cout << i << " " << j << " " << k << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}