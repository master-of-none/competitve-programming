#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Medicine {
  long long nextTime;
  int priority;
  string name;
  int frequency;
};

struct Compare {
  bool operator()(const Medicine& a, const Medicine& b) const {
    if (a.nextTime != b.nextTime)
      return a.nextTime > b.nextTime;

    return a.priority > b.priority;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while (T--) {
    int n, k;
    cin >> n >> k;

    priority_queue<Medicine, vector<Medicine>, Compare> pq;

    for (auto i = 0; i < n; i++) {
      string name;
      int frequency;

      cin >> name >> frequency;

      pq.push({frequency, i, name, frequency});
    }
    for (auto i = 0; i < k; i++) {
      Medicine current = pq.top();
      pq.pop();

      cout << current.nextTime << " " << current.name << "\n";

      current.nextTime += current.frequency;

      pq.push(current);
    }
  }

  return 0;
}
