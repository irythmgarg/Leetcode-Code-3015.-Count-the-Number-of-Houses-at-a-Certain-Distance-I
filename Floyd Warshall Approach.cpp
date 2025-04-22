class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        // Initialize the adjacency matrix with INT_MAX (infinity) for all pairs.
        // This will be used to store the shortest paths between nodes.
        vector<vector<int>> ans(n, vector<int>(n, INT_MAX));

        // Set the distances for the adjacent nodes in the path (linear connection).
        // The graph is a path, so each node is connected to its adjacent node with distance 1.
        for (int i = 0; i < n - 1; i++) {
            ans[i][i + 1] = 1;
            ans[i + 1][i] = 1;
        }

        // Add the extra edge between node x and node y.
        ans[x - 1][y - 1] = 1;
        ans[y - 1][x - 1] = 1;

        // Initialize an array to store the number of pairs with each distance value.
        vector<int> onans(n);

        // Set the diagonal of the adjacency matrix to 0 as the distance from a node to itself is 0.
        for (int via = 0; via < n; via++) {
            ans[via][via] = 0;
        }

        // Apply Floyd-Warshall algorithm to compute the shortest paths between all pairs of nodes.
        // This step ensures that for each pair of nodes (i, j), we have the shortest path distance.
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (ans[i][via] != INT_MAX && ans[via][j] != INT_MAX) {
                        ans[i][j] = min(ans[i][j], ans[i][via] + ans[via][j]);
                    }
                }
            }
        }

        // Count the number of pairs that have the shortest path distance equal to each possible value k (1 to n).
        for (int k = 1; k <= n; k++) {
            int naxi = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // Count the number of pairs with distance exactly k.
                    if (ans[i][j] == k) {
                        naxi++;
                    }
                }
            }
            // Store the count of pairs with distance k in the result array.
            onans[k - 1] = naxi;
        }

        // Return the final array containing the count of pairs for each distance.
        return onans;
    }
};
