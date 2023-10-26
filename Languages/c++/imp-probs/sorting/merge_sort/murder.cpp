/*
Once detective Saikat was solving a murder case. While going to the crime scene he took the stairs and saw that a number is written on every stair. He found it suspicious and decides to remember all the numbers that he has seen till now. While remembering the numbers he found that he can find some pattern in those numbers. So he decides that for each number on the stairs he will note down the sum of all the numbers previously seen on the stairs which are smaller than the present number. Calculate the sum of all the numbers written on his notes diary.
Answer may not fit in integer . You have to take long.
Input
First line gives T, number of test cases.

2T lines follow.

First line gives you the number of stairs N

Next line gives you N numbers written on the stairs.
Output
For each test case output one line giving the final sum for each test case.
Constraints
T<=10

1<=N<=10^5

All numbers will be between 0 and 10^6.
Sample Input:
1
5
1 5 3 6 4
Sample Output:
15
Explanation:
For the first number, the contribution to the sum is 0.
For the second number, the contribution to the sum is 1.
For the third number, the contribution to the sum is 1.
For the fourth number, the contribution to the sum is 9 (1+5+3).
For the fifth number, the contribution to the sum is 4 (1+3).
Hence the sum is 15 (0+1+1+9+4).
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int merge(vector<int>& A, int start, int mid, int end){
    int p = start, q = mid, k =0;
    int sum = 0;
    vector<int> temp(end-start+1);
    while(p<mid && q<=end){
        if(A[p] < A[q]){
            sum+=A[p]*(end-q+1);
            temp[k++] = A[p++];
        }else{
            temp[k++] = A[q++];
        }
    }

    while(p<mid){
        temp[k++] = A[p++];
    }
    while(q<=end){
        temp[k++] = A[q++];
    }

    for(int i=0; i<k; i++){
        A[start++] = temp[i];
    }
    return sum;
}

int merge_sort(vector<int>& A, int start, int end){
    int count = 0;
    if(start<end){
        int mid = start + (end-start)/2;
        int left_count = merge_sort(A, start, mid);
        int right_count = merge_sort(A, mid+1, end);

        int merge_count = merge(A, start, mid+1, end);
        return left_count + right_count + merge_count;
    }
    return count;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for(int i =0; i<n; i++){
            cin>>A[i];
        }
        int sum = merge_sort(A, 0, n-1);
        cout<<sum<<endl;
    }
    
    return 0;
}