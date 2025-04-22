# Leetcode-Code-Testcase-Testcase-Test-Result-3015.-Count-the-Number-of-Houses-at-a-Certain-Distance-I
# 🔗 **Count of Pairs with Specific Distances in a Graph**

This repository contains an algorithm that computes the number of pairs of nodes in a graph where the shortest path between each pair is exactly equal to a specific distance. The graph is represented as a path with one additional edge between two nodes, and the goal is to compute the number of pairs of nodes that have a shortest path of distance `k` (where `k` ranges from 1 to `n`).

## 🚀 **Problem Overview**

Given:
- An undirected graph with `n` nodes, where nodes `1` to `n` are connected in a linear path.
- An additional edge between nodes `x` and `y`.

### Task:
- Find how many pairs of nodes `(i, j)` have the shortest path between them of exactly distance `k` for each `k` from `1` to `n-1`.

---

## 📊 **Solution Approach**

1. **Adjacency Matrix Construction:**
   - Build a matrix where `ans[i][j]` represents the shortest distance from node `i` to node `j`.

2. **Floyd-Warshall Algorithm:**
   - The Floyd-Warshall algorithm is used to compute the shortest paths between all pairs of nodes, considering both direct and indirect paths.

3. **Counting Distances:**
   - After computing the shortest distances, we count how many pairs of nodes `(i, j)` have a shortest path of exactly distance `k` for each `k`.

---

## 🧑‍💻 **Code Explanation**

The algorithm builds an adjacency matrix for the graph where:
- Direct connections between consecutive nodes have distance 1.
- The extra edge between nodes `x` and `y` is also set to have distance 1.
- The Floyd-Warshall algorithm is then applied to compute all-pairs shortest distances.
- Finally, the number of pairs of nodes with each possible shortest path distance is counted and returned.

### Key Steps:
- **Graph Initialization:** Set up the graph with the adjacency matrix and add the extra edge.
- **Shortest Path Calculation:** Use the Floyd-Warshall algorithm to calculate the shortest path for every pair of nodes.
- **Counting Pairs:** For each possible path length, count how many pairs of nodes have that exact distance.

---

📈 Time Complexity
The time complexity of this solution is O(n³) due to the Floyd-Warshall algorithm, which computes the shortest path between all pairs of nodes.

---

✨ Features
🧑‍💻 Efficiently computes shortest paths between all pairs of nodes.

💡 Applies Floyd-Warshall algorithm for optimal path calculation.

📊 Counts and returns the number of pairs for each possible shortest path distance.

---

## 🚀 **Usage Example**

### Input:

```cpp
int n = 5;  // Number of nodes
int x = 2;  // Edge between node x and y
int y = 4;
output
[Count of pairs with distance 1, Count of pairs with distance 2, ..., Count of pairs with distance n]
