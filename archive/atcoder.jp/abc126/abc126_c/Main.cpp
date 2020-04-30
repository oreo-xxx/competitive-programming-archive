#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N; cin >> N;
    int K; cin >> K;
    double ans = 0.0;

    double p = 1.0 / (double)N;

    for(int i = 1; i <= N; ++i){
        if(i < K){
            int num1 = ceil((double)K / (double)i);
            int num = (int) ceil( log2(num1) );
            double tmp = pow(0.5, (double)num);
            ans += tmp;
        }
        else{
            ans += 1.0;
        }
    }
    printf("%.12f\n", p * ans);
    return 0;
}