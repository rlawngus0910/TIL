#include <iostream>
#include <string>
using namespace std;
long A, B;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> A >> B;
	int ans = 0;
	while (B > A) {
		ans++;
		string b = to_string(B);
		if (b[b.size() - 1] == '1') {
			b.resize(b.size() - 1);
			B = stoi(b);
		}
		else if(B % 2 == 0) {
			B = B / 2;
		}
		else {
			break;
		}
		//cout << B << '\n';
	}
	if (A == B) cout << ans + 1;
	else cout << "-1";
}