## Pattern wise dynamic programming problems

### **Pattern 1: Fibonacci / Linear Recurrence**

- **State Definition:** `dp[i]` represents the answer for state `i`, which depends on a fixed number of previous states (like `i-1`, `i-2`).
- **Problems:**
    - Fibonacci Number [Easy]
    - Tribonacci Number [Easy]
    - Climbing Stairs [Easy]
    - Min Cost Climbing Stairs [Easy]
    - House Robber I [Medium]
    - House Robber II [Medium]
    - Tiling Problem (1x2 tiles) [Easy]
    - Friends Pairing Problem [Medium]
    - Ways to Cover Distance [Medium]

### **Pattern 2: Subset / 0-1 Knapsack**

- **State Definition:** `dp[i][w]` represents the maximum value/ways using the first `i` items with a remaining capacity `w`.
- **Problems:**
    - 0/1 Knapsack Problem [Medium]
    - Subset Sum Problem [Medium]
    - Count Subsets with Given Sum [Medium]
    - Partition Equal Subset Sum [Medium]
    - Target Sum (Leetcode 494) [Medium]
    - Minimum Subset Sum Difference [Medium]
    - Can Partition K Equal Subsets [Medium]

### **Pattern 3: Unbounded Knapsack**

- **State Definition:** `dp[w]` represents the optimal answer for capacity `w`, where items can be chosen an unlimited number of times.
- **Problems:**
    - Unbounded Knapsack [Medium]
    - Coin Change (Min Coins) [Medium]
    - Coin Change II (Number of Ways) [Medium]
    - Rod Cutting Problem [Medium]
    - Integer Break (Leetcode 343) [Medium]
    - Minimum Coins to Make Change [Medium]

### **Pattern 4: Longest Increasing Subsequence (LIS) & Variants**

- **State Definition:** `dp[i]` represents the length of the longest valid subsequence ending at index `i`.
- **Problems:**
    - Longest Increasing Subsequence (LIS) [Medium]
    - Longest Decreasing Subsequence [Medium]
    - Longest Bitonic Subsequence [Medium]
    - Longest String Chain [Medium] *(Added)*
    - Maximum Length of Pair Chain [Medium]
    - Russian Doll Envelopes [Hard]

### **Pattern 5: Longest Common Subsequence (LCS) & Variants**

- **State Definition:** `dp[i][j]` represents the answer for string A up to index `i` and string B up to index `j`.
- **Problems:**
    - Longest Common Subsequence (LCS) [Medium]
    - Longest Palindromic Subsequence [Medium]
    - Longest Repeating Subsequence [Medium]
    - Shortest Common Supersequence [Hard]
    - Edit Distance [Medium/Hard]
    - Minimum Insertions/Deletions to Convert A to B [Medium]

### **Pattern 6: DP on Grids / 2D Movement**

- **State Definition:** `dp[i][j]` represents the path count or optimal cost to reach cell `(i, j)` from `(0, 0)`.
- **Problems:**
    - Unique Paths I & II [Medium]
    - Minimum Path Sum [Medium]
    - Maximal Square (LeetCode 221) [Medium] *(Added)*
    - Minimum Falling Path Sum [Medium]
    - Dungeon Game [Hard]
    - Cherry Pickup I & II [Hard]

### **Pattern 7: DP on Strings / Splitting**

- **State Definition:** `dp[i]` represents the optimal way to split/parse a prefix of the string up to index `i`.
- **Problems:**
    - Word Break I & II [Medium/Hard]
    - Palindrome Partitioning I [Medium]
    - Interleaving String (LeetCode 97) [Medium] *(Added)*
    - Scramble String (Leetcode 87) [Hard]
    - Regular Expression Matching [Hard]
    - Wildcard Matching [Hard]

### **Pattern 8: DP on Subarrays (Kadane’s / Sliding Window)**

- **State Definition:** `dp[i]` represents the maximum/minimum sum of a contiguous subarray ending exactly at index `i`.
- **Problems:**
    - Maximum Subarray Sum (Kadane’s) [Medium]
    - Maximum Product Subarray [Medium]
    - Maximum Sum Circular Subarray [Medium]
    - Trapping Rain Water (DP Prefix/Suffix approach) [Hard] *(Added)*

### **Pattern 9: State Machine DP** *(Expanded)*

- **State Definition:** `dp[i][state]` represents the maximum profit/arrangements at step `i` while currently in a specific `state` (e.g., holding, empty, resting).
- **Problems:**
    - Best Time to Buy and Sell Stock I, II, III, IV [Easy to Hard]
    - Buy/Sell Stock with Cooldown / Transaction Fee [Medium]
    - Student Attendance Record II (LeetCode 552) [Hard] *(Added)*
    - Number of Ways to Stay in the Same Place (LeetCode 1269) [Hard] *(Added)*

### **Pattern 10: Game Theory / Optimal Strategy**

- **State Definition:** `dp[i][j]` represents the maximum score the current player can achieve from the remaining elements between indices `i` and `j`.
- **Problems:**
    - Predict the Winner [Medium]
    - Stone Game I, II, III, IV [Medium/Hard]
    - Can I Win (Leetcode 464) [Medium]
    - Optimal Strategy for a Game [Medium]
    - Nim Game [Easy]

### **Pattern 11: Digit DP** *(Moved down for progression)*

- **State Definition:** `dp[index][tight][sum/mask]` represents the count of valid numbers up to the current digit `index`, restricted by a `tight` boolean and a specific property.
- **Problems:**
    - Count Numbers with Unique Digits [Medium]
    - Count Numbers with Given Digit Sum [Medium]
    - Count Stepping Numbers [Medium]
    - Sum of Digits in a Range (SPOJ) [Hard]

### **Pattern 12: Bitmask DP**

- **State Definition:** `dp[mask][last]` represents the optimal cost to cover a subset of items (tracked by `mask` bits) ending at the `last` item.
- **Problems:**
    - Traveling Salesman Problem (TSP) [Hard]
    - Matchsticks to Square [Medium]
    - Number of Squareful Arrays [Hard]
    - Minimum Incompatibility (Leetcode 1681) [Hard]

### **Pattern 13: Interval DP / Matrix Chain Multiplication (MCM)** *(Merged)*

- **State Definition:** `dp[i][j]` represents the optimal cost to merge, cut, or evaluate the subarray/substring from index `i` to `j`.
- **Problems:**
    - Matrix Chain Multiplication [Hard]
    - Burst Balloons [Hard]
    - Palindrome Partitioning II (Min Cuts) [Hard]
    - Minimum Cost to Merge Stones [Hard]
    - Egg Dropping Puzzle [Hard]
    - Optimal Binary Search Tree [Hard]

### **Pattern 14: Coloring / Grouping DP**

- **State Definition:** `dp[i][color]` represents the minimum cost to paint/group up to index `i` with the $i$-th element assigned a specific `color`.
- **Problems:**
    - Paint House I & II [Medium/Hard]
    - Paint Fence [Medium]
    - Minimum Cost to Paint Houses with Neighborhoods [Hard]

### **Pattern 15: Jump Game DP**

- **State Definition:** `dp[i]` represents the minimum jumps required to reach the end from index `i`, or whether the end is reachable.
- **Problems:**
    - Jump Game I (Reach End) [Medium]
    - Jump Game II (Minimum Jumps) [Medium]
    - Jump Game III (Reach 0) [Medium]
    - Jump Game V (Max Points) [Hard]

### **Pattern 16: Tree DP & Rerooting** *(Expanded)*

- **State Definition:** `dp[u]` represents the answer for the subtree rooted at node `u`. Rerooting problems use a second pass to calculate answers from the parent's perspective.
- **Problems:**
    - Diameter of Binary Tree [Easy]
    - Longest Path in DAG [Medium]
    - Tree Matching (CSES) [Medium]
    - Max Sum from Root to Leaf [Medium]
    - Tree Distances I & II (CSES) [Hard - Rerooting] *(Added)*

### **Pattern 17: Advanced Optimization DP**

- **State Definition:** Applies mathematical optimizations to standard DP transitions to reduce time complexity (e.g., from $O(N^3)$ to $O(N^2)$).
- **Techniques & Problems:**
    - Knuth Optimization (MCM variants) [Hard]
    - Divide and Conquer Optimization [Hard]
    - Convex Hull Trick (CHT) [Hard]
    - Sliding Window Optimization (Monotonic Queues) [Hard]

### **Pattern 18: Miscellaneous / Hybrid DP**

- **State Definition:** Combinations of DP with backtracking, graphs, or highly specific math logic.
- **Problems:**
    - Minimum Swaps to Make Sequences Increasing [Hard]
    - Number of Ways to Reorder Array to Get Same BST [Hard]
    - Number of Ways to Paint N × 3 Grid [Hard]