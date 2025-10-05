// #include "header.h"
// using namespace std;
//
// bool canFinish(int numCourses, vector<vector<int>> prerequisites) {
//     unordered_map<int, vector<int>> preMap;
//
//     for (int i = 0; i < numCourses; i++) {
//         preMap.insert(i, {});
//     }
//
//     for (auto& p : prerequisites) {
//         int crs = p[0];
//         int pre = p[1];
//
//         preMap[crs].push_back(pre);
//     }
//
//     set<int> visited;
//
//     function<bool(int crs)> dfs = [&](int crs) -> bool {
//         if (visited.find(crs) != visited.end()) {
//             return false;
//         }
//
//         if (preMap[crs].empty()) return true;
//
//         visited.insert(crs);
//
//         for (auto pre : preMap[crs]) {
//             if (!(dfs(pre))) return false;
//         }
//         visited.erase(crs);
//         preMap[crs] = {};
//         return true;
//     };
//
//     for (int i = 0; i < numCourses; i++)
//         if (not dfs(i)) return false;
//
//     return true;
// }
