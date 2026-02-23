/*
    A graph G=(V,E) is a data structure that consists of a set of vertices V and a set of edges E. 
    Each edge connects two vertices in the graph. 
    Graphs can be directed or undirected, depending on whether the edges have a direction or not.

    - Directed Graph: In a directed graph, the edges have a direction, meaning that they go from one vertex to another. 
        For example, if there is an edge from vertex A to vertex B, it does not imply that there is an edge from vertex B to vertex A.
    
    - Undirected Graph: In an undirected graph, the edges do not have a direction, 
        meaning that they connect two vertices without any specific order.
    
    - Weighted Graph: A weighted graph is a graph in which each edge has a weight or cost associated with it. 
        The weight can represent various things, such as distance, time, or capacity.

    - Unweighted Graph: An unweighted graph is a graph in which all edges have the same weight or cost,(1 by default) meaning that there is no distinction between the edges in terms of their weight.

    Path: A path in a graph is a sequence of vertices that are connected by edges. 
    A path can be simple, meaning that it does not contain any repeated vertices,
    Cycle: meaning that it starts and ends at the same vertex.

    Cyclic graphs: A cyclic graph is a graph that contains at least one cycle, which is a path that starts and ends at the same vertex.

    Degree of a vertex: The degree of a vertex in an 
    (i) undirected graph is the number of edges that are incident to it. 
    (ii)directed graph, the degree of a vertex is typically represented as two separate values:    
        - In-degree: The number of edges that are directed towards the vertex.
        - Out-degree: The number of edges that are directed away from the vertex.

    
*/