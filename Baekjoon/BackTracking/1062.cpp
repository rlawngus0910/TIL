#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int N, K,ans;
int cnt;
bool alphabet[26];
string s[51];
void selectWord(int c,int idx) {
	if (idx == K) {
		int temp = 0;
		for (int i = 0; i < N; i++) {
			bool check = true;
			for (int j = 4; j < s[i].length() - 4; j++) {
				int checkChar = s[i][j] - 'a';
				if (!alphabet[checkChar]) {
					check = false;
					break;
				}
			}
			if (check) temp++;
		}
		ans = max(ans, temp);
		return;
	}

	if (idx >= 5) {
		for (int i = c; i < 26; i++) {
			if (!alphabet[i]) {
				alphabet[i] = true;
				selectWord(i+1,idx + 1);
				alphabet[i] = false;
			}
		}
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> s[i];
	}
	if (K < 5) {
		cout << "0";
		return 0;
	}
	if (K == 26) {
		cout << N;
		return 0;
	}
	else {
		alphabet[0] = true;
		alphabet[2] = true;
		alphabet[8] = true;
		alphabet[13] = true;
		alphabet[19] = true;
		selectWord(0,5);
	}
	cout << ans;
}