## Graph

### Data Structures for Disjoint Sets

### 

### Basics of Graph

### Breadth First Search

Given a graph $G = (V, E)$  and a distinguished source vertex $s$ , breadth-first search systematically explores the edges of $G$ to “discover” every vertex that is reachable from $s$ . It computes the distance (smallest number of edges) from $s$ to each reachable vertex. It also produces a “breadth-first tree” with root $s$ that contains all reachable vertices. For any vertex v reachable from $s$, the simple path in the breadth-first tree from $s$ to $v$ corresponds to a “shortest path” from $s$ to $v$ in $G$, that is, a path containing the smallest number of edges. The algorithm works on both directed and undirected graphs.

```
BFS(G, s)
    for each vertex u in G.V - {s}
        u.color = WHITE
        u.distance = INFINITE
        u.parent = NIL
    s.color = GRAY
    s.distance = 0
    s.parent = NIL
    Q = NIL
    ENQUEUE(Q, s)
    while Q != NIL
        u = DEQUEUE(Q)
        for each vertex v in G.Adj[u]
            if v.color == WHITE
                v.color = GRAY
                v.distance = u.distance + 1
                v.parent = u
            ENQUEUE(Q, v)
        u.color = BLACK

```

**Time Complexity**

### Depth First Search

```
DFS(G)
    for each vertex u in G.V
        u.color = WHITE
        u.parent = NIL
    time = 0
    for each vertex u in G.V
        if u.color == WHTIE
            DFS-VISIT(G, u)
```

```
DFS-VISIT(G, u)
    time = time + 1
    u.discoveryTime = time
    u.color = GRAY
    for each vertex v in G.Adj[u]
        if v.color == WHTIE
            v.parent = u
            DFS-VISIT(G, v)
    u.color = BLACK
    time = time + 1
    u.finishingTime = time
```

### Topological Sort

A ***topological sort*** of a **Directed Acyclic Graph** (DAG),  is a linear ordering of all its vertices such that if $G$ contains an edge $(u, v)$, then u appears before $v$  in the ordering. (***If the graph contains a cycle, then no linear ordering is possible.***) We can view a topological sort of a graph as an ordering of its vertices along a horizontal line so that all directed edges go from left to right. Topological sorting is thus different from the usual kind of “sorting”.

```
TOPOLOGICAL-SORT(G)
    call DFS(G) to compute finishing times v.finishingTime for each vertex v
    as each vertex is finished, insert it onto the front of a linked list
    return the linked list of vertices
```

**Time Complexity**
We can perform a topological sort in time $O(V+E)$  since depth-first search takes $O(V+E)$  time and it takes $O(1)$ time to insert each of the vertices onto the front of the linked list.

**Kahn Algorithm For Topological Sort**

```
KAHN-TOPOLOGICAL-SRT(G)
    Q = NIL
    // Topologically sorted list
    L = NIL
    for each vertex u in G.V
        if u.indegree == 0
            ENQUEUE(Q, u)
    
    while Q != NIL
        u = DEQUEUE(Q)
        insert u onto the last of L
        for each vertex v in G.Adj[u]
            v.indegree--
            if v.indegree == 0
                ENQUEUE(Q, v)
    
    if length of L != |G.V|
        return "The Graph G has a cycle" 
```

The running time of Kahn topological sort for a directed graph $G=(V,E)$ is $O(V+E)$

### Strongly Connected Components

```
STRONGLY-CONNECTED-COMPONENTS(G)
    call DFS(G) to compute finishing times u.finishingTime for each vertex u
    compute T = G-TRANSPOSE
    call DFS(T), but is the main loop of DFS, consider the vertices in order of decreasing u.finishingTime (as computed in line 1)
    output the vertices of each tree in the depth-first forest formed in line 3 as a separate strongly connected component
```

**Time Complexity**
The above mentioned linear-time i.e., $O(V+E)$ algorithm computes the strongly connected components of a directed graph $G = (V, E)$ using two depth-first searches, one on $G$ and one on $T$ (where $T = G^T$ )

### Articulation points, bridges and biconnected components

### Hamiltonian Path

A **Hamiltonian Path** is a path in an undirected or directed graph that visits each vertex exactly once. If such a path exists, it’s known as a Hamiltonian path. A graph that contains a Hamiltonian path is called a **traceable graph**.
If the Hamiltonian path forms a cycle (meaning it returns to the starting vertex and includes every vertex exactly once), it is called a **Hamiltonian Cycle**.

Below is the pseudo-code for finding a Hamiltonian Cycle and Path, where the the graph is $G=(V,E)$ and the path is $P$

```
IS-SAFE(G,P, u, v)
    if G.Adj[u] != v
        return false
    if v already exists in Path P
        return false
    return true
```

```
HAMCYCLE-UTIL(G, P, u)
    if u == last vertex of G
        if G.Adj[u] contains starting vertex of path P
            return true
        else
            return false
    
    for each vertex v in G.V
        if (IS-SAFE(G, P, u, v) == true)
            add v in path P
            if (HAMCYCLE-UTIL(G, P, v) == true)
                return true
            remove v from path P
    return false
```

```
HAMCYCLE(G)
    let P be a path
    add any one vertex u in P
    if (HAMCYCLE-UTIL(G, P, u) == false)
        return false
    return true
```

**Time Complexity**

The time requried for this above approach would be $O(V!)$ for a given undirected graph $G=(V,E)$.

### Euler Path

**Euler Path** is a path in a graph that visits every edge exactly once. **Eulerian Circuit** is an Eulerian Path that starts and ends on the same vertex. 

Following are some interesting properties of undirected graphs with an Eulerian path and cycle. We can use these properties to find whether a graph is Eulerian or not.

**Eulerian Cycle:** An undirected graph has Eulerian cycle if following two conditions are true.

1. All vertices with non-zero degree are connected. We don’t care about vertices with zero degree because they don’t belong to Eulerian Cycle or Path (we only consider all edges).
2. All vertices have even degree.

**Eulerian Path:** An undirected graph has Eulerian Path if following two conditions are true.

1. Same as condition (1) for Eulerian Cycle.
2. If zero or two vertices have odd degree and all other vertices have even degree. Note that only one vertex with odd degree is not possible in an undirected graph (sum of all degrees is always even in an undirected graph)

Note that a graph with no edges is considered Eulerian because there are no edges to traverse.

Below is the pseudo-code for finding an Euler Path and Cycle, where the graph is $G=(V,E)$

```
DFS(G, u)
    u.visited = true
    for each vertex v in G.Adj[u]
        if v.visited == false
            DFS(G, v)
```

```
IS-CONNECTED(G)
    for each vertex u in G.V
        u.visited = false
        
    for each vertex u in G.V
        if u.degree != 0
            break
    if G.E is null
        return true
    DFS(G, u)
    
    for each vertex u in G.V
        if u.visited == false && u.degree > 0
            return false
    
    return true
```

```
IS-EULERIAN(G)
    if IS-CONNECTED(G) ==  false
        return G is not Eulerian
    odd = 0
    for each vextex u in G.V
        if u.degree & 1 == true
            odd++
    if odd == 0
        return G is Eulerian
    if odd == 2
        return G is Semi Eulerian
    if odd > 2
        return G is not Eulerian
```

these are the checks for eulerian path and circuit in undirected graph.

quite different approach to check for eulerian path and circuit in directed graph

hierholzer algorithm for finding the eulerian path

### Minimum Spanning Tree

Electronic circuit designs often need to make the pins of several components electrically equivalent by wiring them together. To interconnect a set of $n$ pins, we can use an arrangement of  $n-1$ wires, each connecting two pins. Of all such arrangements, the one that uses the least amount of wire is usually the most desirable. We can model this wiring problem with a connected, undirected graph $G=(V,E)$ where $V$ is the set of pins, $E$ is the set of possible interconnections between pairs of pins, and for each edge$(u, v) \in E$
, we have a weight $w(u,v)$ specifying the cost (amount of wire needed) to connect $u$ and $v$. We then wish to find an acyclic subset  $T \subseteq E$ that connects all of the vertices and whose total weight

$$
 w(T) = \sum_{(u, v) \in T} w(u, v)
$$

is minimized. Since T is acyclic and connects all of the vertices, it must form a tree, which we call a spanning tree since it “spans” the graph $G$. **We call the problem of determining the tree $T$ the minimum-spanning-tree problem.**

**Generic Minimum Spanning Tree**

```
GENERIC-MST(G,w)
    A = NIL
    while A does not form a spanning tree
        find an edge (u,v) that is safe for A
        A = A union  {(u,v)}
    return A
```

Now we need some definitions

// the above thing is incomplete

### Kruskal’s algorithm

```
MAKE-SET(x)
    x.parent = x
    x.rank = 0
```

```
UNION(x, y)
    LINK(FIND-SET(x), FIND-SET(y))
```

```
LINK(x, y)
    if x.rank > y.rank
        y.parent = x
    else
        x.parent = y
        if x.rank == y.rank
            y.rank = y.rank + 1
```

```
FIND-SET(x)
    if x!= x.parent
        x.parent = FIND-SET(x.parent)
    return x.parent
```

```
MST-KRUSKAL(G, w)
    A = NIL
    for each vertex v in G.V
        MAKE-SET(v)
    sort the edges of G.E into non-decreasing order by weight w
    for each edge (u, v) in G.E, taken in non-decreasing order by weight
        if FIND-SET(u) != FIND-SET(v)
            A = A U {(u, v)}
            UNION(u, v)
    return A
```

The running time of kruskal’s algorithm for a graph $G=(V,E)$ is $O(E \lg V)$

### Prim’s algorithm

```
MST-PRIM(G, w, r)
    for each u in G.V
        u.key = INFINITE
        u.parent = NIL
    r.key = 0
    Q = G.V
    while Q != NIL
        u = EXTRACT-MIN(Q)
        for each v in G.Adj[u]
            if v belongs to Q and w(u, v) < v.key
                v.parent = u
                v.key = w(u, v)
```

The running time of kruskal’s algorithm for a graph $G=(V,E)$ is $O(E \lg V)$

### Single Source Shortest Paths

$$
\delta(u,v) =
\begin{cases} 
\min \{ w(p) : u \overset{p}{\rightsquigarrow} v \} & \text{if a path exists from } u \text{ to } v, \\
\infty & \text{otherwise.}
\end{cases}
$$

```
INITIALIZE-SINGLE-SOURCE(G, s)
    for each vertex v in G.V
        v.distance = INFINITE
        v.parent = NIL
    s.distance = 0
```

```
RELAX(u, v, w)
    if v.distance > u.distance + w(u, v)
        v.distance = u.distance + w(u, v)
        v.parent = u
```

### Bellman-Ford Algorithm

The Bellman-Ford algorithm solves the **single-source shortest-paths problem** in the general case in which **edge weights may be negative**. Given a weighted, directed graph $G=(V, E)$ with source $s$ and weight function $w:E \to \mathbb R$, the Bellman-Ford algorithm returns a boolean value indicating whether or not there is a **negative-weight cycle** that is reachable from the source. If there is such a cycle, the algorithm indicates that no solution exists. If there is no such cycle, the algorithm produces the shortest paths and their weights. 

The algorithm relaxes edges, progressively decreasing an estimate $v.distance$ on the weight of a shortest path from the source $s$ to each vertex  $v \in V$ until it achieves the actual shortest-path weight $\delta(s,v)$. The algorithm returns TRUE if and only if the graph contains no negative-weight cycles that are reachable from the source.

```
BELLMAN-FORD(G, w, s)
    INITIALIZE-SINGLE-SOURCE(G, s)
    for i=1 to |G.V|-1
        for each edge (u, v) in G.E
            RELAX(u, v, w)
    for each edge (u, v) in G.E
        if v.distance > u.distance + w(u, v)
            return false
        return true
```

The running time for Bellman Ford algorithm for a graph $G=(V, E)$ is $O(VE)$

### Single Source Shortest Path in Directed Acyclic Graphs (DAGs)

```
DAG-SHORTEST-PATH(G, w, s)
    topologically sort the vertices of G
    INITIALIZE-SINGLE-SOURCE(G, s)
    for each vertex u, taken in topologically sorted order
        for each vertx v in G.Adj[u]
            RELAX(u, v, w)
```

The running time for the above algorithm for a graph $G=(V, E)$ is $O(V+E)$

### Dijkstra Algorithm

```
DIJKSTRA(G, w, s)
    INITIALIZE-SINGLE-SOURCE(G, s)
    S = NIL
    Q = G.V
    while Q != NIL
        u = EXTRACT-MIN(Q)
        S = S U {u}
        for each vertex v in G.Adj[u]
            RELAX(u, v, w)
```

The time complexity for Dijkstra algorithm for a weighted directed graph $G=(V, E)$ is $O((V+E) \lg V)$

### Difference Constraints and Shortest Paths

```
DIFFERENCE-CONSTRAINTS(G, w)
    compute G', where G'.V = G.V U {s}
    G'.E = G.E U {(s, v) : v in G.V}
    w(s, v) = 0 for all v in G.V
    if BELLMAN-FORD(G, w, s) == true
        return solution
    return no solution for these difference constraints
```

The running time of finding solution for difference constraints using Bellman Ford algorithm for a graph $G=(V, E)$ is $O(VE)$

### All-Pair Shortest Paths

### Floyd-Warshall Algorithm

```
MAKE-INITIAL-PREDECESSOR-MATRIX(W)
    
```

```
FLOYD-WARSHALL(W)
    n = W.rows
    D = W
    for k = 1 to n
        for i = 1 to n
            for j = 1 to n
                D[i][j] = min(D[i][j], D[i][k] + D[j][k])
    return D
```

The running time of Floyd Warshall algorithm on a directed graph $G=(V,E)$ where negative edges are $O(V^3)$

### Johnson’s Algorithm

Johnson’s algorithm uses the technique of **reweighting**, which works as follows. If all edge weights $w$  in a graph $G=(V,E)$  are nonnegative, we can find shortest paths between all pairs of vertices by running Dijkstra’s algorithm once from each vertex; with the Fibonacci-heap min-priority queue, the running time of this all-pairs algorithm is $O(V^2 \lg V + VE)$. **If $G$   has negative-weight edges but no negative-weight cycles, we simply compute a new set of nonnegative edge weights  that allows us to use the same method. The new set of edge weights  $\^w$ must satisfy two important properties:**

```
JOHNSON(G, w)
    compute G', where G'.V = G.V U {s}
    G'.E = G.E U {(s, v) : v in G.V}
    w(s, v) = 0 for all v in G.V
    if BELLMAN-FORD(G', w, s) == FALSE
        print "The Input Graph G contains a negative-weight cycle
    else
        for each vertex v in G'.V
            set h(v) to the value of delta(s, v) computed by Bellman-Ford Algorithm
        for each edge (u, v) in G'.E
            w'(u, v) = w(u, v) + h(u) - h(v)
        let D = d(u, v) be a new n*n matrix
        for each vertex u in G.V
            run DIJKSTRA(G, w', u) to compute delta'(u, v) for all vertex in G.V
            for each vertex v in G.V
                d[u][v] = delta'(u, v) + h(v) - h(u)
        return D
```

If we implement the min-priority queue in Dijkstra’s algorithm by a Fibonacci heap, Johnson’s algorithm runs in $O(V^2 \lg V + VE)$ time. The simpler binary minheap implementation yields a running time of $O(VE \lg V)$which is still asymptotically faster than the Floyd-Warshall algorithm if the graph is sparse

### Maximum Flow

We can think of each directed edge in a flow network as a conduit for the material. Each conduit has a stated capacity, given as a maximum rate at which the material can flow through the conduit. Vertices are conduit
junctions, and other than the source and sink, material flows through the vertices without collecting in them. In other words, the rate at which material enters a vertex must equal the rate at which it leaves the vertex. We call this property **flow conservation**  and it is equivalent to Kirchhoff’s current law when the material is electrical current.

In the maximum-flow problem, we wish to compute the greatest rate at which we can ship material from the source to the sink without violating any capacity constraints.

**Flow Networks**

A flow network $G=(V,E)$ is a directed graph in which each edge$(u,v) \in E$ has a nonnegative **capacity** $c(u,v) \geq 0$.  We further require that if $E$ contains an edge $(u, v)$ then there is no edge $(v, u)$ in the reverse direction. (We shall see shortly how to work around this restriction.) If $(u,v) \notin E$, then for convenience we define$c(u, v)=0$ , and we disallow self-loops. We distinguish two vertices in a flow network: a ***source*** $s$ and a ***sink*** $t$.

Let $G=(V, E)$  be a flow network with a capacity function $c$. Let $s$  be the source of the network, and let $t$  be the sink. A flow in $G$  is a real-valued function $f:V \times V \rightarrow \mathbb{R}$ that satisfies the following two properties:

**Capacity constraint:**  For all $(u, v) \in V$, we require $0 \leq f(u,v) \leq c(u,v)$
The capacity constraint simply says that the flow from one vertex to another must be non-negative and must not exceed the given capacity.

**Flow conservation:**  For all $u \in V - \{s,t\}$, we require

$$
 \sum_{v \in V}f(v,u) = \sum_{v \in V} f(u,v)
$$

where $(u,v) \notin E$ , there can be no flow $u$ to $v$ and $f(u,v)=0$

The flow-conservation property says that the total flow into a vertex other than the source or sink must equal the total flow out of that vertex—informally, “***flow in equals flow out.***”

```
FORD-FULKERSON-METHOD(G, s, t)
    initialize flow f to 0
    while there exists an augmenting path p in the residual network G`
        augment flow f along p
    return f
```

**Residual Networks**

Suppose we have a flow  network $G=(V,E)$ with source $s$ and sink $t$ .  Let $f$ be a flow in $G$ and consider a pair of vertices $u,v \in V$ .  We define the ***residual capacity***  $c_f(u,v)$ by

$$
 c_f(u,v)= 
\begin{cases}
c(u,v)-f(u,v) & \text{if } (u,v) \in E,\\
f(v,u) & \text{if } (v,u) \in E,\\
0 & \text{otherwise}
\end{cases}
$$

Because of our assumption that $(u,v) \in E$ implies $(v,u) \notin E$ ,  exactly one case in the above equation applies to each ordered pair of vertices

Given a flow network $G=(V,E)$ and a flow $f$ , the ***residual network*** of $G$ induces by $f$ is $G_f=(V,E_f)$ , where

$$
E_f=\{(u,v) \in V \times V \colon c_f(u,v)>0\}
$$

That is, as promised above, each edge of the residual network or ***residual edge***, can admit a flow that is greater than $0$. The edges in $E_f$ are either edges in $E$ or their reversals, and thus

$$
|E_f| \leq2|E|
$$

A flow in a residual network provides a roadmap for adding flow to the original flow network. If $f$ is a flow in $G$ and $f'$  is a flow in the corresponding residual network $G_f$, we define $f \uparrow f'$ , the ***augmentation*** of flow $f$  by $f'$ , to be a function from $V \times V \text{ to } \mathbb{R}$ , defined by

$$
f \uparrow f'(u,v)=
\begin{cases}
f(u,v) + f'(u,v) - f'(v,u) & \text{ if } (u,v) \in E,\\
0 & \text{ otherwise }
\end{cases}
$$

**Cuts of Flow Networks**

A ***cut $(S, T)$*** of flow network $G=(V, E)$ is a partition of $V$ into $S$ and $T=V-S$ such that $s \in S$ and $t \in T$. If $f$ is a flow then the ***net flow***  $f(S,T)$ across the cut $(S,T)$ is defined to be

$$
f(S,T)=\sum_{u\in S}\sum_{v \in T}f(u,v)-\sum_{u \in S}\sum_{v \in T}f(v,u)
$$

The capacity of the cut $(S,T)$ is

$$
c(S,T)=\sum_{u \in S}\sum_{v \in T}c(u,v)
$$

A ***minimum cut*** of a network is a cut whose capacity is minimum over all cuts of the network.

### Ford-Fulkerson Algorithm

```
FORD-FULKERSON(G, s, t)
    for each edge (u,v) in G.E
        (u, v).flow = 0
    while there exists a path p from s to t in the residual network G'
        c'(p) = min{ c'(u,v) : (u,v) is in p }
        for each edge (u,v) in p
            if (u,v) in E
                (u,v).flow = (u,v).flow + c'(p)
            else
                (v,u).flow = (v,u).flow - c'(p)
```

The running time of Ford-Fulkerson algorithm is $O(E \cdot \lvert f \rvert)$, where $f$ is the maximum flow in the graph $G$,  since the flow value increases by at least one unit in each iteration.

### Edmonds-Karp Algorithm

```
EDMONDS-KARPG, s, t)
    for each edge (u,v) in G.E
        (u, v).flow = 0
    while there exists a path p from s to t in the residual network G' found by BFS
        c'(p) = min{ c'(u,v) : (u,v) is in p }
        for each edge (u,v) in p
            if (u,v) in E
                (u,v).flow = (u,v).flow + c'(p)
            else
                (v,u).flow = (v,u).flow - c'(p)
```

The running time of Edmonds-Karp algorithm is $O(VE^2)$, for a given graph $G=(V,E)$,  because the total number of flow augmentations performed by the algorithm is $O(VE)$

### Maximum Bipartite Matching

**Bipartite Graphs** are graphs in which the vertex set can be partitioned into $V=L \cup R$, where$L$  and $R$  are disjoint and all edges in $E$  go between $L$  and $R$. **We further assume that every vertex in $V$  has at least one incident edge.**

A **Matching** in a bipartite graph is a set of edges where each edge connects a vertex from set $L$ to a vertex from set $R$ , such that no two edges share a common vertex (either from $L$ or $R$ ). In other words, each vertex is incident to at most one edge in the matching.

### Push-relabel Algorithms

Push-relabel algorithms work in a more localized manner than the Ford Fulkerson method. Rather than examine the entire residual network to find an augmenting path, push-relabel algorithms work on one vertex at a time, looking only at the vertex’s neighbors in the residual network. Furthermore, unlike the Ford Fulkerson method, push-relabel algorithms do not maintain the flow-conservation property throughout their execution. They do, however, maintain a preflow, which is a function

$$
\sum_{v \in V}f(v,u) - \sum_{v\in V}f(u,v) \geq 0
$$

for all vertices $u \in V- \{s\}$. That is, the flow into a vertex may exceed the flow out. We call the quantity

$$
e(u) = \sum_{v \in V}f(v,u) - \sum{v \in V}f(u,v)
$$

the ***excess flow*** into vertex $u$. The excess at a vertex is the amount by which the flow in exceeds the flow out. We say that a vertex  $u \in V -\{s,t\}$ is ***overflowing*** if $e(u)>0$.

**Push operation**

```
PUSH(u, v)
    // Applies when: u is overflowing, c'(u, v) > 0 and u.h = v.h + 1
    // Action: Push del'(u, v) = min(u.e, c'(u, v)) units of flow from u to v
    if(u, v) in E
        (u, v).f = (u, f).f + del'(u, v)
    else
        (v, u).f = (v, u).f - del'(u, v)
    u.e = u.e - del'(u, v)
    v.e = v.e + del'(u, v)
```

**Relabel Operation**

The basic operation RELABEL(u) applies if $u$ is overflowing and if $u.h \leq v.h$ for all edges $(u, v) \in E_f$. 

```
RELABEL(u)
    // Applies when: u is overflowing and for all v in V such that (u, v) in E'
                     we have u.h <= v.h
    // Acttion: Increase the height of u
    u.h = 1 + min{v.h: (u,v) in E'}
```

**The Goldberg’s Generic Push Relabel Algorithm**

The generic push-relabel algorithm uses the following subroutine to create an initial preflow in the flow network.

```
INITIALIZE-PREFLOW(G, s)
    for each vertex v in G.V
        v.h = 0
        v.e = 0
    for each edge (u, v) in G.E
        (u, v).f = 0
    s.h = |G.V|
    for each vertex v in s.Adj
        (s, v).f = c(s, v)
        v.e = c(s, v)
        s.e = s.e - c(s, v)
```

```
GENERIC-PUSH-RELABEL(G)
    INITIALIZE-PREFLOW(G, s)
    while there exists an applicable push or relabel operation
        select an applicable push or relabel operation and perform it
```

The running time of **Generic Push Relabel** algorithm is $O(V^2E)$ for a given graph $G=(V,E)$

**The Relabel-to-Front Algorithm**

The relabel-to-front algorithm maintains a list of the vertices in the network. Beginning at the front, the algorithm scans the list, repeatedly selecting an over flowing vertex $u$ and then “discharging” it, that is, performing push and relabel operations until $u$  no longer has a positive excess. Whenever we relabel a vertex, we move it to the front of the list (hence the name “relabel-to-front”) and the algorithm begins its scan anew.

The correctness and analysis of the relabel-to-front algorithm depend on the notion of “admissible” edges: those edges in the residual network through which flow can be pushed. 

***Admissible edges and network***

If $G=(V,E)$ is a flow network with source $s$  and sink $t$,  $f$ is a preflow in $G$,and $h$ is a height function, then we say that $(u,v)$ is an admissible edge if $c_f(u,v)>0$ and $h(u)=h(v)+1$. Otherwise, $(u,v)$ is ***inadmissible***. The ***admissible network***  is$G_{f,h}=(V,E_{f,h})$,where$E_{f,h}$ is the set of admissible edges. The admissible network consists of those edges through which we can push flow.

***Discharging an overflowing vertex***

An overflowing vertex $u$ is ***discharged*** by pushing all of its excess flow through admissible edges to neighboring vertices, relabeling $u$ as necessary to cause edges leaving $u$  to become admissible. The pseudocode goes as follows

```
DISCHARGE(u)
    while u.e > 0
        v = u.current
        if v ==  NIL
            RELABEL(u)
            u.current = u.N.head
        else if c'(u, v) > 0 adn u.h == v.h + 1
            PUSH(u, v)
        else
            u.current = v.next-neighbor
```

```
RELABEL-TO-FRONT(G, s, t)
    INITIALIZE-PREFLOW(G, s)
    L = G.V - {s, t} in any order
    for each vertex u in G.V - {s, t}
        u.current = u.N.head
    u = L.head
    while u != NIL
        oldHeight = u.h
        DISCHARGE(u)
        if u.h > oldHeight
            move u to the front of list L
        u = u.next
```

The running time of **Relabel-to-Front** algorithm is $O(V^3)$ for a given graph $G=(V,E)$