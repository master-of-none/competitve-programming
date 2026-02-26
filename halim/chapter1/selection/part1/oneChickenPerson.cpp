#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M;

  if (M > N) {
    if (M - N == 1) {
      cout << "Dr. Chaz will have " << M - N
           << " piece of chicken left over!\n";
      return 0;
    }
    cout << "Dr. Chaz will have " << M - N << " pieces of chicken left over!\n";
  } else if (M < N) {
    if (N - M == 1) {
      cout << "Dr. Chaz needs " << N - M << " more piece of chicken!\n";
      return 0;
    }
    cout << "Dr. Chaz needs " << N - M << " more pieces of chicken!\n";
  }
}