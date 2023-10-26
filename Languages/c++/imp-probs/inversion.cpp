#include<bits/stdc++.h>
using namespace std;

void invertbits(int num){
	// calculating number of bits
	int x = log2(num) + 1;

    //inverting he bits 1 by 1
	for(int i =0; i<x; i++){
		num = (num ^ (1 << i));
	}

	cout<<num<<endl;
}

void invertusingbitset(int num){
	int x = log2(num) + 1;

	bitset<32> b (num);
	for(int i =0; i<x; i++){
		b.flip(i);
	}

    // converting bitset to number
	cout<<b.to_ulong()<<endl;

}

int main(){
    int num;
    cin>>num;
    invertbits(num);   	
    invertusingbitset(num);
	return 0;
}