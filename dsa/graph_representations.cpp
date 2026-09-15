#include <iostream>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

// ============================================================================
// Graph Representations: Count Vertices (V) and Directed Edges (E)
// Bidirectional edge = 2 directed edges
// ============================================================================

// ----------------------------------------------------------------------------
// 1. Adjacency Matrix (AM)
// Time: O(V^2) to count edges, O(1) to count vertices
// Space: O(V^2)
// ----------------------------------------------------------------------------
void countAM(int V, const vector<vector<int>>& adjMatrix) {
  int edgeCount = 0;
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (adjMatrix[i][j]) {
        edgeCount++;
      }
    }
  }
  cout << "AM - Vertices: " << V << ", Directed Edges: " << edgeCount << endl;
}

// ----------------------------------------------------------------------------
// 2. Adjacency List (AL)
// Time: O(V + E) to count edges, O(1) to count vertices
// Space: O(V + E)
// ----------------------------------------------------------------------------
void countAL(int V, const vector<vector<int>>& adjList) {
  int edgeCount = 0;
  for (int i = 0; i < V; i++) {
    edgeCount += adjList[i].size();
  }
  cout << "AL - Vertices: " << V << ", Directed Edges: " << edgeCount << endl;
}

// ----------------------------------------------------------------------------
// 3. Edge List (EL)
// Time: O(1) - just return stored size, O(E) to build from scratch
// Space: O(E)
// ----------------------------------------------------------------------------
void countEL(int V, const vector<pair<int, int>>& edgeList) {
  cout << "EL - Vertices: " << V << ", Directed Edges: " << edgeList.size()
       << endl;
}

// ============================================================================
// Task 2: Count in-degree and out-degree of vertex v
// in-degree(v)  = edges coming INTO v
// out-degree(v) = edges going OUT OF v
// ============================================================================

// ----------------------------------------------------------------------------
// 1. Adjacency Matrix (AM)
// Time: O(V) for both in/out degree
// Space: O(V^2)
// ----------------------------------------------------------------------------
pair<int, int> degreeAM(int V, int v, const vector<vector<int>>& adjMatrix) {
  int inDegree = 0, outDegree = 0;
  for (int i = 0; i < V; i++) {
    if (adjMatrix[v][i]) outDegree++;  // edges FROM v
    if (adjMatrix[i][v]) inDegree++;   // edges TO v
  }
  return {inDegree, outDegree};
}

// ----------------------------------------------------------------------------
// 2. Adjacency List (AL) - vector<vii> (weighted)
// Time: O(1) for out-degree, O(V + E) for in-degree
// Space: O(V + E)
// ----------------------------------------------------------------------------
pair<int, int> degreeAL(int V, int v, const vector<vii>& AL) {
  int inDegree = 0, outDegree = 0;

  // Out-degree: size of v's list
  outDegree = AL[v].size();

  // In-degree: scan all edges to find those pointing to v
  for (int i = 0; i < V; i++) {
    for (auto& edge : AL[i]) {
      if (edge.first == v) inDegree++;  // edge.first = destination
    }
  }
  return {inDegree, outDegree};
}

// ----------------------------------------------------------------------------
// 3. Edge List (EL)
// Time: O(E) for both in/out degree
// Space: O(E)
// ----------------------------------------------------------------------------
pair<int, int> degreeEL(int V, int v, const vector<pair<int, int>>& edgeList) {
  int inDegree = 0, outDegree = 0;
  for (auto& edge : edgeList) {
    if (edge.first == v) outDegree++;  // edge starts from v
    if (edge.second == v) inDegree++;  // edge ends at v
  }
  return {inDegree, outDegree};
}

int main() {
  int V = 4;

  // Adjacency Matrix
  vector<vector<int>> adjMatrix = {
      {0, 1, 1, 0}, {0, 0, 1, 0}, {1, 0, 0, 0}, {0, 0, 0, 0}};

  // Adjacency List (unweighted)
  vector<vector<int>> adjList = {
      {1, 2},  // 0 -> 1, 2
      {2},     // 1 -> 2
      {0},     // 2 -> 0
      {}       // 3 -> (none)
  };

  // Edge List
  vector<pair<int, int>> edgeList = {{0, 1}, {0, 2}, {1, 2}, {2, 0}};

  // Weighted Adjacency List (vector<vii>)
  // AL[i] = {{neighbor, weight}, ...}
  vector<vii> weightedAL = {
      {{1, 5}, {2, 3}},  // 0 -> 1(w=5), 2(w=3)
      {{2, 2}},          // 1 -> 2(w=2)
      {{0, 4}},          // 2 -> 0(w=4)
      {}                 // 3 -> (none)
  };

  cout << "=== Task 1: Count V and E ===" << endl;
  countAM(V, adjMatrix);
  countAL(V, adjList);
  countEL(V, edgeList);

  cout << "\n=== Task 2: In/Out Degree of Vertex 2 ===" << endl;

  auto [inAM, outAM] = degreeAM(V, 2, adjMatrix);
  cout << "AM - In-degree: " << inAM << ", Out-degree: " << outAM << endl;

  auto [inAL, outAL] = degreeAL(V, 2, weightedAL);
  cout << "AL - In-degree: " << inAL << ", Out-degree: " << outAL << endl;

  auto [inEL, outEL] = degreeEL(V, 2, edgeList);
  cout << "EL - In-degree: " << inEL << ", Out-degree: " << outEL << endl;

  return 0;
}
