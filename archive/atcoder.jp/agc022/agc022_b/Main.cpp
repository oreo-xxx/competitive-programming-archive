#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int, int>;
using pll = pair<int, int>;
using Edge = pair<int, ll>;
using Graph = vector<vector<int>>;
using WeightedGraph = vector<vector<Edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

void printv(const vector<int>& vec){
	for (int i = 0; i < vec.size(); ++i) {
		cout << vec[i];
		if (i != vec.size() - 1) cout << ' ';
		else cout << endl;
	}
}

int main(){
	int n; cin >> n;
	if(n==3){
		printv({2,5,63});
		return 0;
	}
	if(n==4){
		printv({ 2,5,20,63 });
		return 0;
	}

	vector<int> two, three, six;
	for(int i = 2; i <= 30000; ++i){
		if(i%6==0)six.push_back(i);
		else if(i%2==0)two.push_back(i);
		else if(i%3==0)three.push_back(i);
	}

	vector<int> ans { two[0], two[1], three[0], three[1]};
	n -= 4;

	for (int i = 2; i + 1 < three.size(); i += 2) {
		if (n <= 1)break;
		ans.push_back(three[i]);
		ans.push_back(three[i + 1]);
		n -= 2;
	}
	for(int i = 2; i+1 < two.size(); i+=2){
		if (n <= 1)break;
		ans.push_back(two[i]);
		ans.push_back(two[i+1]);
   		n-=2;
	}

	for (int i = 0; i < six.size(); ++i) {
		if (n == 0)break;
		ans.push_back(six[i]);
		--n;
	}

	sort(ans.begin(), ans.end());

	printv(ans);
	
	return 0;
}