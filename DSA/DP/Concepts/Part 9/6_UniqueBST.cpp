// LEETCODE 96

// SEARCH FOR "CATLIN NUMBER" AND SOLVE THE QUESTION BASED ON IT(important for interview)

/*

We will give chance to every node to become the node, and then calculate the final answer by adding all possible trees

now, suppose from [1, N] we have chosen some number 'i' to become root, 
then the LST from [1, i-1] will aslo be a BST and RST from [i+1 ,N] {BST[i+1, N] will be equivalent to BST[1, N-i]}will also be a BST, and the the number of possible BST with 'i' as root will be product(*) of number of possible BST in LST and and number of possible BST in RST.

f(i) --> Possible BST with 'i' as root and [i, i-1] as LST and [i+1 ,N] as RST
f(i) = f(i-1) * f(N-i)

Total BST for N nodes (1 to N) = f(1) + f(2) + f(3)......+ f(n)

*/