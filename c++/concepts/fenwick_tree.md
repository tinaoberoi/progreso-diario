# Fenwick Tree or Binary Indexed Tree
* Provides a way to represent an array of numbers in an array, allowing **prefix sums** to be calculated efficiently. 
* For example, an array is [2, 3, -1, 0, 6] the length 3 prefix [2, 3, -1] with sum 2 + 3 + -1 = 4). 
* Calculating prefix sums efficiently is useful in various scenarios.
* Last set bit ==> x&~(x)
* Every index i in BIT[] stores cummulative sum from i to `i - (i<<r) +1` (both inclusive) where r represents last set bit in index i 
[Read this](https://www.hackerearth.com/practice/notes/binary-indexed-tree-or-fenwick-tree/)
