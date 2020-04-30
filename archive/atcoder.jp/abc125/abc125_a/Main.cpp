#include<iostream>

using namespace std;


int main()
{
    int a;
    cin >> a;
    int b;
    cin >> b;
    int t;
    cin >> t;

    float total_time = (float)t + 0.5;
    int n = total_time / a;

    int answer = n * b;

    cout << answer << endl;

    return 0;
}
