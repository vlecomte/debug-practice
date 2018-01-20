# Single source shortest path, negative weights
https://open.kattis.com/problems/shortestpath3

Sounds fairly innocent right.

For shortest paths with negative weights, Dijkstra doesn't work but Bellman-Ford is a safe choice, so we use that. We know that for the nodes which have a non -Infinity distance from s, we have the correct distance after n-1 steps at most, since the corresponding shortest path has at most n-1 edges. Similarly, given n more steps, for the nodes with -Infinity distance from s, the distance must decrease after n more steps, since the corresponding negative cycle has at most n edges.

But it keeps getting Wrong Answer...
