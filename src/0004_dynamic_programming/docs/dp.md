## Dynamic Programming

We typically apply dynamic programming to optimization problems. Such problems can have many possible solutions. Each solution has a value, and we wish to find a solution with the optimal (minimum or maximum) value. We call such a solution an optimal solution to the problem, as opposed to the optimal solution, since there may be several solutions that achieve the optimal value. When developing a dynamic-programming algorithm, we follow a sequence of four steps:

1. Characterize the structure of an optimal solution.
2. Recursively define the value of an optimal solution.
3. Compute the value of an optimal solution, typically in a bottom-up fashion.
4. Construct an optimal solution from computed information.

### **Pattern 1: Fibonacci / Linear Recurrence**

- **State Definition:** `dp[i]` represents the answer for state `i`, which depends on a fixed number of previous states (like `i-1`, `i-2`).
- **Problems:**
    
    #### Fibonacci Number [Easy]
    
    #### Tribonacci Number [Easy]
    
    #### Climbing Stairs [Easy]
    
    #### Min Cost Climbing Stairs [Easy]
    
    #### House Robber I [Medium]
    
    #### House Robber II [Medium]
    
    #### Tiling Problem (1x2 tiles) [Easy]
    
    Given a 2 × n board and tiles of size 2 × 1, find the total number of ways to completely fill the board using these tiles. Each tile can be placed either horizontally i.e., as a 1 x 2 tile or vertically i.e., as 2 x 1 tile.
    Two tiling arrangements are considered different if the placement of at least one tile differs.
    
    **Approach for solution**
    
    We create a 1D DP array dp[n+1] to store the results of already computed subproblems, since there is only one parameter — n — that changes in the recursive solution.
    First, we will solve some smaller problems for which we define the base cases:
    
    dp[0] = 1 — There is one way to fill a 2×0 board.
    dp[1] = 1 — There is only one way to fill a 2×1 board.
    We start from these base cases, and then we have two choices:
    
    Place one vertical tile, leaving a 2×(i−1) board - dp[i−1]
    Place two horizontal tiles, leaving a 2×(i−2) board - dp[i−2]
    After filling the DP table iteratively, dp[n] will give the total number of ways to completely fill the 2×n board
    
    ```
    dp[0]=1
    dp[1]=1
    
    for(i=2;i<=n;i++)
    	dp[i]=dp[i-2]+dp[i-1]
    	
    return dp[n]
    ```
    
    #### Friends Pairing Problem [Medium]
    
    Given n friends, each one can remain single or can be paired up with some other friend. **each friend can be paired only once**. find out the total number of ways in which friends can remain single or can be paired up.
    
    examples:
    
    input  : n = 3
    output : 4
    explanation:
    {1}, {2}, {3} : all single
    {1}, {2, 3} : 2 and 3 paired but 1 is single.
    {1, 2}, {3} : 1 and 2 are paired but 3 is single.
    {1, 3}, {2} : 1 and 3 are paired but 2 is single.
    note that {1, 2} and {2, 1} are considered same.
    
    mathematical explanation:
    the problem is simplified version of how many ways we can divide n elements into multiple groups (here group size will be max of 2 elements).
    In case of n = 3, we have only 2 ways to make a group:
    1) all elements are individual(1,1,1)
    2) a pair and individual (2,1)
    In case of n = 4, we have 3 ways to form a group:
    1) all elements are individual (1,1,1,1)
    2) 2 individuals and one pair (2,1,1)
    3) 2 separate pairs (2,2)
    
    **Approach for solution**
    
    If the nth friend stays single, the problem reduces to n−1 friends; if it pairs up, it has (n−1) choices and the problem reduces to n−2 friends. This leads to the recurrence: 
    
    $$
    f(n) = f(n - 1) + (n - 1) * f(n - 2)
    $$
    
    #### Ways to Cover Distance [Medium]
    
    Given a distance 'dist', count total number of ways to cover the distance with 1, 2 and 3 steps.
    
    **Approach for solution**
    
    Simple recurrence relation
    
    $$
    f(x)=f(x-1)+f(x-2)+f(x-3)
    $$
    

### **Pattern 2: Subset / 0-1 Knapsack**

- **State Definition:** `dp[i][w]` represents the maximum value/ways using the first `i` items with a remaining capacity `w`.
- **Problems:**
    
    #### 0/1 Knapsack Problem [Medium]
    
    #### Subset Sum Problem [Medium]
    
    #### Count Subsets with Given Sum [Medium]
    
    #### Partition Equal Subset Sum [Medium]
    
    #### Target Sum (Leetcode 494) [Medium]
    
    #### Minimum Subset Sum Difference [Medium]
    
    #### Can Partition K Equal Subsets [Medium]
    

### **Pattern 3: Unbounded Knapsack**

- **State Definition:** `dp[w]` represents the optimal answer for capacity `w`, where items can be chosen an unlimited number of times.
- **Problems:**
    
    #### Unbounded Knapsack [Medium]
    
    #### Coin Change (Min Coins) [Medium]
    
    #### Coin Change II (Number of Ways) [Medium]
    
    #### Rod Cutting Problem [Medium]
    
    #### Integer Break (Leetcode 343) [Medium]
    
    #### Minimum Coins to Make Change [Medium]
    

### **Pattern 4: Longest Increasing Subsequence (LIS) & Variants**

- **State Definition:** `dp[i]` represents the length of the longest valid subsequence ending at index `i`.
- **Problems:**
    
    #### Longest Increasing Subsequence (LIS) [Medium]
    
    #### Longest Decreasing Subsequence [Medium]
    
    #### Longest Bitonic Subsequence [Medium]
    
    #### Longest String Chain [Medium] *(Added)*
    
    #### Maximum Length of Pair Chain [Medium]
    
    #### Russian Doll Envelopes [Hard]
    

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