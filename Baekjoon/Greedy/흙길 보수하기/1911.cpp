#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, l;
vector <pair<int, int>> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> l;
	for (int i = 0,s,f; i < n; i++) {
		cin >> s >> f;
		v.push_back({ s,f });
	}
	sort(v.begin(), v.end());
	int start = v[0].first;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (v[i].first >= start) {
			start = v[i].first;
		}
		int len = v[i].second - start;
		if (start < v[i].second) {
			start += (len / l) * l;
			if (len % l != 0) start += l;
			ans += (len / l);
			if (len % l != 0) ans++;
		}
	}
	cout << ans;
}