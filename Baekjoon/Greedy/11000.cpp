#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector <pair<int, int>> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, f;
		cin >> s >> f;
		v.push_back({ s,1 });
		v.push_back({ f,-1 });
	}
	sort(v.begin(), v.end());
	int ans = 0;
	int temp = 0;
	for (int i = 0; i < v.size(); i++) {
		temp += v[i].second;
		ans = max(ans, temp);
	}
	cout << ans;
}