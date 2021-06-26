#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int ans = 1e9;
vector <pair<int, int>> v;
bool visit[11];
void go(int idx, int s, int b) {
	if (idx == n) return;

	ans = min(ans, abs(s - b));

	for (int i = idx + 1; i < n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			go(i, s * v[i].first, b + v[i].second);
			visit[i] = false;
		}
	}

}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0,s,b; i < n; i++) {
		cin >> s >> b;
		v.push_back({ s,b });
	}

	for (int i = 0; i < n; i++) {
		visit[i] = true;
		ans = min(ans, abs(v[i].first - v[i].second));
		go(i, v[i].first, v[i].second);
	}

	cout << ans;
}