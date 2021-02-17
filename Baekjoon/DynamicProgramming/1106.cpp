#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int c, n;
vector <pair<int, int>> v;
int d[1500];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n;
	for (int i = 0; i < n; i++) {
		int cost, num;
		cin >> cost >> num;
		v.push_back({ cost,num });
	}
	for (int i = 1; i <= c + 101; i++) {
		d[i] = 98765432;
	}
	for (int i = 0; i < v.size(); i++) {
		int cost = v[i].first;
		int customerNum = v[i].second;
		for (int j = customerNum; j <= c + 101;j++) {
			d[j] = min(d[j], cost + d[j - customerNum]);
		}
	}
	int ans = 98765432;
	for (int i = c; i <= c + 101; i++) {
		ans = min(ans, d[i]);
	}
	cout << ans;
}