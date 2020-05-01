#Bitset
* A bitset is array of bool, but each bool value is not stored separately but in an optimised way, consumes only 1 bit space.
* Thus space by bitset bs < bool bs[N] and vector bs(N)
* Limitation of bitset N must be known at compile time. 

``` c++
#include<bits/stdc++.h>
using namespace std;

#define M 32

int main(){

	// default constructor initializes with all bits 0
	bitset<M> bset1;

	// bset2 is initialized with bits 20
	bitset<M> bset2(20);

	//bset3 is initialized with bits of specified binarry string
	bitset<M> bset3(string("1100"));

	cout<<bset1<<endl; // 00000000000000000000000000000000
	cout<<bset2<<endl; // 00000000000000000000000000010100
	cout<<bset3<<endl; // 00000000000000000000000000001100

	//declarinf set8 with capacity of 8 bits
	bitset<8> set8; //00000000

	set8[1] = 1; //00000010
	set8[4] = 1; //00010010

	cout<<set8<<endl;

	int numberof1 = set8.count();

	int numberof0 = set8.size() - numberof1;

	// [any] function returns true if atleast 1 bit is set
	if(!set8.any()){
		cout << "set8 has no bit set.\n"; 
	}

	// [none] function returns true is none of the bit is set
	if(!bset1.none()){
		cout << "bset1 has some bit set\n";
	}

	// [bset.set()] sets all the bits
	cout<<set8.set()<<endl;

	//[bset.set(pos, b)] makes bset[pos] = b
	cout<<set8.set(pos, b)<<endl;

	//[bset.set(pos)] makes bset[pos] = 1
	cout<<set8.set(pos)<<endl;

	//reset function makes all bits 0
	cout<<set8.reset(2)<<endl;
	cout<<set8.reset()<<endl;

	//flip function
	cout<<set8.flip(2)<<endl;
	cout<<set8.flip()<<endl;

	return 0;
}
```