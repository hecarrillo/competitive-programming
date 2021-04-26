#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; cin >> n;

	while(n--){
		int c; cin >> c;
		unordered_map<char, int> pay;

		while(c--){
			char letter; int cost; cin >> letter; cin >> cost;
			pay.insert({letter, cost});
		}

		int lines; cin >> lines;
		int totalPayment = 0;
		string line;
		cin.ignore();

		while(lines--){
			getline(cin, line);
			for (char & e : line){
				if(pay.find(e) == pay.end()) continue;
				totalPayment += pay[e];
			}
		}

		cout << totalPayment/100.00 << "$" << "\n";
	}
}
