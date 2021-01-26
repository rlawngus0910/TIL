#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <string>
using namespace std;
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };

bool isVaild(int x, int y) {
	return x >= 0 && x < 3 && y >= 0 && y < 3;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s = "";
	set<string> check;
	queue<pair<string, int>> q;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			char tmp;
			cin >> tmp;
			s += tmp;
		}
	}
	//cout << s;
	check.insert(s);
	q.push({ s,0 });
	int ans = -1;
	while (!q.empty()) {
		//cout << "?";
		string current = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (current == "123456780") {
			ans = cnt;
		}
		int start = current.find('0');

		int x = start / 3;
		int y = start % 3;

		for (int i = 0,tx,ty; i < 4; i++) {
			tx = x + dx[i];
			ty = y + dy[i];
			if (isVaild(tx, ty)) {
				string next = current;
				
				swap(next[x * 3 + y], next[tx * 3 + ty]);
				if (check.find(next) == check.end()) {
					check.insert(next);
					//cout << next << '\n';
					q.push({ next,cnt + 1 });
				}
			}
		}
	}
	cout << ans;
}