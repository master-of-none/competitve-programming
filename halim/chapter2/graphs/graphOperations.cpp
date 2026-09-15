#include <iostream>
#include <vector>
using namespace std;

int main() {
  int vertices;
  cout << "Enter Total number of vertices\n";
  cin >> vertices;
  vector<vector<int>> adjacencyList(vertices + 1);

  for (int i = 0; i < vertices; i++) {
    cout << "Enter total neighbors for " << i;
    int neighbors;
    cin >> neighbors;
    for (int j = 0; j < neighbors; j++) {
      int v;
      cin >> v;
      adjacencyList[i].push_back(v);
    }
  }
}