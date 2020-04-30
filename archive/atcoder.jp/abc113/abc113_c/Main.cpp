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
    int n;
    int m;
    cin >> n; cin >> m;
    vector<pair<int, int> >inputs(m);
    vector<int> vec[n + 1];
    map<int, int> mp[n + 1];

    for(int i =0; i < m; ++i){
        int p; cin >> p;
        int y; cin >> y;
        inputs[i] = {p, y};
        vec[p].push_back(y);
    }

    for(int i = 1; i < n+1; ++i){
        sort(vec[i].begin(), vec[i].end());
        for(int j = 0; j < vec[i].size(); ++j){
            mp[i][vec[i][j]] = j;
        }
    }

    for(int i =0; i < m; ++i){
        int p = inputs[i].first;
        int y = inputs[i].second;
        int index = mp[p][y];
        printf("%06d%06d\n", p ,index + 1);
    }
    return 0;
}