#include <iostream>
using namespace std;
int cash, juga[14];
int bnp, timing;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> cash;
	int jcash = cash;
	int scash = cash;
	for (int i = 0; i < 14; i++)
		cin >> juga[i];
	
	for (int i = 0; i < 14; i++) {
		if (jcash >= juga[i]) {
			bnp += (jcash / juga[i]);
			jcash = jcash - (juga[i] * (jcash / juga[i]));
		}
	}
	int pluscnt = 0;
	int minuscnt = 0;
	for (int i = 1; i < 14; i++) {
		if (juga[i] > juga[i - 1]) {
			pluscnt++;
			minuscnt = 0;
		}
		else if (juga[i] < juga[i - 1]) {
			minuscnt++;
			pluscnt = 0;
		}
		else {
			pluscnt = 0;
			minuscnt = 0;
		}
		if (pluscnt >= 3) {
			if (timing > 0) {
				scash += timing * juga[i];
				timing = 0;
			}
			pluscnt = 0;
		}
		else if (minuscnt >= 3) {
			if (scash >= juga[i]) {
				timing += (scash / juga[i]);
				scash -= (juga[i] * (scash / juga[i]));
			}
		}
	}
	if (jcash + (bnp * juga[13]) > scash + (timing * juga[13]))
		cout << "BNP";
	else if (jcash + (bnp * juga[13]) < scash + (timing * juga[13]))
		cout << "TIMING";
	else
		cout << "SAMESAME";
}