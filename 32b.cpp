/*
Name: Borze
Status: AC
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	string line;
	cin >> line;
	char last = line[0];
	if (last == '.') cout << 0;
	for(int i = 1; i < line.size(); i++){
		char curr = line[i];
		if (curr == '.' && (last == '.' || last == ' ')) {
			cout << 0;
			last = ' ';
		}
		else if (curr == '.' && last == '-') {
			cout << 1;
			last = ' ';
		}
		else if (curr == '-' && last == '-') {
			cout << 2;
			last = ' ';
		}
		else last = curr;
	}
	cout << "\n";
}
