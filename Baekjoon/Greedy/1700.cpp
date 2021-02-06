#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int N, K;
vector<int> multi;
int useCount[101];
int pr[101];
bool use[101];
int fin[101];
int ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> pr[i];
		useCount[pr[i]]++;
	}
	int cnt = 0; 
	int ans = 0;
	for (int i = 0; i < K; i++) {
		if (use[pr[i]]) continue;
		if (cnt < N) {
			if (!use[pr[i]]) {
				use[pr[i]] = true;
				multi.push_back(pr[i]);
				cnt++;
			}
		}
		else {
			for (int j = i+1; j < K; j++) {
				if (use[pr[j]] && fin[pr[j]] == 0) {
					int findPr = pr[j];
					int findidx = j;
					fin[pr[j]] = findidx;
				}
			}
			int a = 0;
			int eraseIdx = 0;
			for (int j = 0; j < multi.size(); j++) {
				if (fin[multi[j]] == 0) {
					eraseIdx = j;
					break;
				}
				else {
					if (a < fin[multi[j]]) {
						a = fin[multi[j]];
						eraseIdx = j;
					}
				}
			}
			use[multi[eraseIdx]] = false;
			multi.erase(multi.begin() + eraseIdx);
			multi.push_back(pr[i]);
			use[pr[i]] = true;
			ans++;
			memset(fin, 0, sizeof(fin));
		}
	}
	cout << ans;
}