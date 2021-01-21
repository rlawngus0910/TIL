#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector <pair<int, int>> v;
bool cmp(const pair<int, int>& a, const pair <int, int>& b) {
	return a.second < b.second || (a.second == b.second && a.first > b.first);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0,a,b; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end(),cmp);
	int sum = 0;
	int pricesum = v[0].second;
	int ans = 2147483647;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		//cout << v[i].first << ' ' << v[i].second << '\n';
		sum += v[i].first;
		if (i != 0 && (v[i - 1].second == v[i].second))
			pricesum += v[i].second;
		else
			pricesum = 0;
		if (sum >= m) {
			cnt = 1;
			ans = min(ans, v[i].second + pricesum);
		}
	}
	if (cnt == 1)
		cout << ans;
	else
		cout << "-1";
}