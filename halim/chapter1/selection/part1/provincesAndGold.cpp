#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int gold, silver, copper;
  cin >> gold >> silver >> copper;

  int power = 3 * gold + 2 * silver + copper;
  string victory;

  if (power >= 8)
    victory = "Province";
  else if (power >= 5)
    victory = "Duchy";
  else if (power >= 2)
    victory = "Estate";

  string treasure;
  if (power >= 6)
    treasure = "Gold";
  else if (power >= 3)
    treasure = "Silver";
  else
    treasure = "Copper";

  if (victory.empty())
    cout << treasure << endl;
  else
    cout << victory << " or " << treasure << endl;

  return 0;
}