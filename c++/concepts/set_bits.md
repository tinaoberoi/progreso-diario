# Count no. of Set Bits using Brian Kernighan’s Algorithm:

*Subtracting 1 from a number flips all the bits including and after the rightmost set bit*
for example:
10 => 1010
9  => 1001
8  => 1000

So if we subtract 1 from n and then take & by itself, we unset the righmost set bit. If done in loop and keep count, we can count no. of set bits

```c++
class set_bits{
public:
	unsigned int count_set_bits(int n){
		unsigned int count = 0;
		while(n){
			n = n&(n-1);
			count++;
		}
		return count;
	}
};
```