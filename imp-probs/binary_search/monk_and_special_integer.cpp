/* 
(https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/monk-and-special-integer-code-monk/description/)

Explaination:
Sum of all subarrays of k <= x then all subarrays sum of size 1, 2,.., k-1 <= x
1. Apply binary search to find last index such that p[i]*2 < r*2

Time Complexity of each is O(nlogn + qlogn)
Space Complexity O(N)
*/