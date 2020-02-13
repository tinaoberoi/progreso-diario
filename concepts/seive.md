# Seive
Findind primes smaller than or equal to n
## Algorithm:
* Create a list of consec integers from 2 to n.
* initilly let p = 2, first prime number.
* update all multiples greater than or equal to p2 

```c++
void sieve(int n){
	for(int p =2; p*p<=n; p++){
		if(prime[p] == true){
			for(int i =p*p; i<=n; i+=p){
				prime[i] = false;
			}
		}
	}

	for(int p=2; p<n; p++){
		if(prime[p]){
			cout<<p<<" ";
		}
	}
}
```

* Complexity : O()