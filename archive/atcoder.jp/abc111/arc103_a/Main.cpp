#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N; cin >> N;
    map<int, int> v1 {};
    map<int, int> v2 {};

    for(int i = 0; i < N / 2; ++i){
        int a; cin >> a;
        auto itr = v1.find(a);
        if( itr != v1.end() ) {
            v1[a] += 1;
        } else {
            v1[a] = 1;
        }
        cin >> a;
        itr = v2.find(a);
        if( itr != v2.end() ) {
            v2[a] += 1;
        } else {
            v2[a] = 1;
        }
    }

    int max1 = 0;
    int total1 = 0;
    int key1 = -1;
    for(auto itr = v1.begin(); itr != v1.end(); ++itr) {
        if(max1 < itr->second){
            key1 = itr->first;
            max1 = itr->second;
        }
        total1 += itr->second;
    }

    int max2 = 0;
    int total2 = 0;
    for(auto itr = v2.begin(); itr != v2.end(); ++itr) {
        if(itr->first != key1){
            max2 = max(max2, itr->second);
        }
        total2 += itr->second;
    }

    int ans = total1 - max1 + total2 - max2;

    max1 = 0;
    total1 = 0;
    key1 = -1;
    for(auto itr = v2.begin(); itr != v2.end(); ++itr) {
        if(max1 < itr->second){
            key1 = itr->first;
            max1 = itr->second;
        }
        total1 += itr->second;
    }

    max2 = 0;
    total2 = 0;
    for(auto itr = v1.begin(); itr != v1.end(); ++itr) {
        if(itr->first != key1){
            max2 = max(max2, itr->second);
        }
        total2 += itr->second;
    }

    int ans2 = total1 - max1 + total2 - max2;

    printf("%d\n", min(ans, ans2));
    return 0;
}