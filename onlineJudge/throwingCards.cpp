/*
Status: AC
*/
#include <iostream>
#include <queue>

using namespace std;

int main() {
  int n;
  while (cin >> n){
    if (n == 0) break;
    else if (n == 1) {
      cout << "Discarded cards:";
      cout << "\nRemaining card: 1" << "\n";
      continue;
    }
    queue<int> cards;
    for (int i = 3; i <= n; i++){
      cards.push(i);
    }
    cards.push(2);
    cout << "Discarded cards: 1";
    int temp;
    while(cards.size() > 1){
      cout << ", " << cards.front();
      cards.pop();
      temp = cards.front();
      cards.pop();
      cards.push(temp);
    }
    cout << "\nRemaining card: " << cards.front() << "\n";
  }
  return 0;
}
