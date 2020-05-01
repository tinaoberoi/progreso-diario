#include<bits/stdc++.h>
using namespace std;

void printKeypad(int num, string options[], string output){
    if(num == 0){
        cout<<output<<endl;
        return;
    }
    int lastDigit = num%10;
    string op = options[lastDigit];
    
    for(int i =0; i<op.length(); i++){
        printKeypad(num/10, options, op[i]+output);
    }
    return;
}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    string options[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string output = "";
    printKeypad(num, options, output);
    return;
}

int main(){
    printKeypad(23);
    return 0;
}