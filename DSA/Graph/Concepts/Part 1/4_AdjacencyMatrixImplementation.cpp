/*

In this approach we represent the graph in a 2D array of V*V dimmension, where V is the number of vertices

---------------------------------------
For  (Un)Directed Unweighted graph
---------------------------------------

adj[i][j] = {
                1, if there is edge from 'ith' vertex to 'jth' vertex
                0, if there is no edge from 'ith' vertex to 'jth' vertex
            }

---------------------------------------
For  (Un)Directed Weighted graph
---------------------------------------

adj[i][j] = {
                <weight>, if there is edge from 'ith' vertex to 'jth' vertex
                
                any invalid value, which can't be weight', if there is no edge from 'ith' vertex to 'jth' vertex
            }
 
But this approach is not space efficient as we also have to store '0' if we have no edge from one vertex to another

*/