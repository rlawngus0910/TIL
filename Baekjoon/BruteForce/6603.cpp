#include <iostream>
#include <cstring>
using namespace std;
int k;
int lotto[13];
int sel[6];
void dfs(int idx, int depth) {
	if (depth == 6) {
		for (int i = 0; i < 6; i++) 
			cout << sel[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = idx; i < k; i++) {
		sel[depth] = lotto[i];
		dfs(i + 1, depth + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while (1) {
		cin >> k;
		if (!k) return 0;
		for (int i = 0; i < k; i++)
			cin >> lotto[i];
		dfs(0, 0);
		cout << '\n';
		memset(lotto, 0, sizeof(lotto));
		memset(sel, 0, sizeof(sel));
	}
}