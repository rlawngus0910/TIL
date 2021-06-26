#include <iostream>
using namespace std;
int n, sw[101], st;
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> sw[i];
	}
	cin >> st;
	while (st--) {
		int s, num;
		cin >> s >> num;
		if (s == 1) {
			for (int i = num; i <= n; i += num) {
				if (sw[i] == 0) sw[i] = 1;
				else sw[i] = 0;
			}
		}
		else {
			if (sw[num] == 0) sw[num] = 1;
			else sw[num] = 0;
			
			if (num == 1 || num == n) {
				continue;
			}

			int left = num - 1;
			int right = num + 1;
			while (sw[left] == sw[right]) {
				
				if (sw[left] == 0) sw[left] = 1;
				else sw[left] = 0;

				if(sw[right] == 0) sw[right] = 1;
				else sw[right] = 0;

				left--;
				right++;

				if (left == 0 || right == n + 1) break;
			}

		}
	}

	for (int i = 1; i <= n; i++) {
		cout << sw[i] << ' ';
		if (i % 20 == 0) cout << '\n';
	}

}