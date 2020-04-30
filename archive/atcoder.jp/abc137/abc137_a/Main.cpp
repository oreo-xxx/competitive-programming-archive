#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	
	int tmp1 = a+b;
	int tmp2 = a-b;
	int tmp3 = a*b;
	int ans = max(tmp1, max(tmp2, tmp3));
	cout << ans << endl;
	return 0;
}