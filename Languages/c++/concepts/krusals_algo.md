# Krusals Algorithm for finding minimum spanning tree

Given an undirected, connected and weighted graph, find Minimum Spanning Tree (MST) of the graph using Kruskal's algorithm.

Steps involved:
* Sort all the edges in non-decreasing order of their weight.
* Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If cycle is not formed so far. If cycle is not formed, included this else discard it. 
* Repeat step#2 until there are (V-1) edges in the spanning tree.

Key Points:
* ```c++ 
vector<pair<int, <pair<int, int>>>> edges
```
* sort to sort the edges in non decreasing order
* Union find Algo to check if the current edge forms a cycle if it is added in the current MST. If yes discard it, else include it (union).
