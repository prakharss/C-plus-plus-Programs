/*
A brute-force solution would be to try all possible subset with all different fraction but that will be too much time taking.

An efficient solution is to use Greedy approach. The basic idea of the greedy approach is to calculate the ratio value/weight 
for each item and sort the item on basis of this ratio. Then take the item with the highest ratio and add them until we can’t
add the next item as a whole and at the end add the next item as much as we can. Which will always be the optimal solution to 
this problem.
*/