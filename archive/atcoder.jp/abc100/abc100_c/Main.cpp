#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N; cin >> N;
    int ans = 0;
    for(int i = 0; i < N; ++i){
        int a; cin >> a;
        while(a % 2 == 0){
            a /= 2;
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}