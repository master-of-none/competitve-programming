#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int minTankSize(int n, int x, const vector<int> &stations) {
    int maxDistance = 0;

    //! Forward journey distances
    int prev = 0;
    for (int i = 0; i < n; i++) {
        maxDistance = max(maxDistance, stations[i] - prev);
        prev = stations[i];
    }

    maxDistance = max(maxDistance, x - prev);

    //! Special case: distance from x back to last station (if any)
    //! This is the same as x - last_station, so we need 2 * (x - last_station)
    if (n > 0) {
        maxDistance = max(maxDistance, 2 * (x - stations[n - 1]));
    } else {
        // If no stations, need to go from 0 to x and back
        maxDistance = max(maxDistance, 2 * x);
    }

    return maxDistance;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }

        sort(stations.begin(), stations.end());

        cout << minTankSize(n, x, stations) << endl;
    }

    return 0;
}