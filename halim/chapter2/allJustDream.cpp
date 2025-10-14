//! Kattis - Dream
//!
//! Submitted By: Shrikrishna Bhat

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<string> timeline;
    unordered_map<string, int>
        last_active;  // event -> index in timeline (0..T-1), -1 if inactive

    while (n--) {
        char type;
        cin >> type;
        if (type == 'E') {
            string ev;
            cin >> ev;
            timeline.push_back(ev);
            last_active[ev] = (int)timeline.size() - 1;
        } else if (type == 'D') {
            int k;
            cin >> k;
            while (k-- > 0 && !timeline.empty()) {
                string ev = timeline.back();
                timeline.pop_back();
                last_active[ev] = -1;
            }
        } else {  // 'S'
            int m;
            cin >> m;
            vector<string> must_have, must_not;
            for (int i = 0; i < m; ++i) {
                string s;
                cin >> s;
                if (s[0] == '!')
                    must_not.push_back(s.substr(1));
                else
                    must_have.push_back(s);
            }

            int T = (int)timeline.size();

            // Quick check: is scenario true now?
            bool ok_now = true;
            for (auto& e : must_have) {
                auto it = last_active.find(e);
                if (it == last_active.end() || it->second == -1) {
                    ok_now = false;
                    break;
                }
            }
            if (ok_now) {
                for (auto& e : must_not) {
                    auto it = last_active.find(e);
                    if (it != last_active.end() && it->second != -1) {
                        ok_now = false;
                        break;
                    }
                }
            }
            if (ok_now) {
                cout << "Yes\n";
                continue;
            }

            // If any must_have never happened -> impossible (undo cannot
            // resurrect)
            bool impossible = false;
            for (auto& e : must_have) {
                auto it = last_active.find(e);
                if (it == last_active.end() || it->second == -1) {
                    impossible = true;
                    break;
                }
            }
            if (impossible) {
                cout << "Plot Error\n";
                continue;
            }

            // compute minimal undo required to deactivate all must_not active
            // events
            int need_undo = 0;  // minimal k required
            for (auto& e : must_not) {
                auto it = last_active.find(e);
                if (it != last_active.end() && it->second != -1) {
                    int idx = it->second;
                    int req = T - idx;  // minimal k to remove this event
                    if (req > need_undo) need_undo = req;
                }
            }

            // compute maximal k allowed to keep all must_have
            int max_k_allowed = T;  // if no must_have, can undo up to T
            for (auto& e : must_have) {
                int idx = last_active[e];  // guaranteed exists and != -1
                int allowed = T - idx - 1;
                if (allowed < max_k_allowed) max_k_allowed = allowed;
            }

            if (need_undo <= max_k_allowed) {
                cout << need_undo << " Just A Dream\n";
            } else {
                cout << "Plot Error\n";
            }
        }
    }
    return 0;
}