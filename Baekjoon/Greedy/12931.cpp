#include <iostream>
#include <vector>
using namespace std;
int n,ans;
vector <int> v;
bool zeroCheck() {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] != 0) return false;
	}
	return true;
}
void divideTwo() {
	for (int i = 0; i < v.size(); i++) {
		v[i] = v[i] / 2;
	}
	ans++;

}

void minusOne() {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] % 2 != 0) {
			v[i]--;
			ans++;
		}
	}
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0,x; i < n; i++) {
		cin >> x;
		if (x == 0) continue;
		v.push_back(x);
	}

	while (!zeroCheck()) {
		minusOne();
		divideTwo();
	}
	if (ans == 0) cout << "0";
	else cout << ans - 1;
}