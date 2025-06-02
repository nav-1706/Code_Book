/*

Here we represent graph in the form of *array of unordered-map*, rest everting is same as "Adjecency List Implementation"

In which 'key' represent neighbour vertex and 'value' represent weight

This implementation improves the time efficiency when we have to find if a vertex is neighbour of some vertex (as searching in map is possible at constant time)

It is 2nd most used implementation

Implementation:

unordered_map<int, vector<int>graph; --> unweighted
unordered_map<int, vector<pair<int,int>>graph --> weighted

*/
