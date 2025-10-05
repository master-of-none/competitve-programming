/* @JUDGE_ID: 1709779 12709 C++ "Brothers"*/

//
// Created by Shrikrishna Bhat on 05/10/25.
//

#include <iostream>
using namespace std;

int main() {
    while (true) {
        int T;
        cin >> T;
        if (T == 0) break;

        int maxH = 0;
        int maxVolume = 0;

        for (int i = 0; i < T; ++i) {
            int L, W, H;
            cin >> L >> W >> H;
            int volume = L * W * H;

            if (H > maxH) {
                maxH = H;
                maxVolume = volume;
            } else if (H == maxH) {
                if (volume > maxVolume) maxVolume = volume;
            }
        }

        cout << maxVolume << endl;
    }
    return 0;
}