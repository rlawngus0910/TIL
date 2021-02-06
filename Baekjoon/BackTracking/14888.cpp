#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int A[101];
vector <int> v;
int p, m, g, d;
void dfs(int idx, int num) {
	if (idx == N - 1) {
		v.push_back(num);
		return;
	}
	if (p > 0) {
		p--;
		dfs(idx + 1, num + A[idx + 1]);
		p++;
	}
	if (m > 0) {
		m--;
		dfs(idx + 1, num - A[idx + 1]);
		m++;
	}
	if (g > 0) {
		g--;
		dfs(idx + 1, num * A[idx + 1]);
		g++;
	}
	if (d > 0) {
		d--;
		dfs(idx + 1, num / A[idx + 1]);
		d++;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	cin >> p >> m >> g >> d;
	dfs(0, A[0]);
	sort(v.begin(), v.end());
	
	cout << v[v.size()-1] << '\n' << v[0];
}