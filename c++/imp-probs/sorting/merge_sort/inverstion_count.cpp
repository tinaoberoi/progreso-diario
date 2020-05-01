/*

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll merge(vector<ll> Arr, int start, int mid, int end){
    ll count = 0;
    int p = start, q = mid+1;
    vector<ll> A(end-start+1, -1);
    int k = 0;
    for(int i = start; i<=end; i++){
        if(p>mid){
            Arr[k++] = A[q++];
        }
        else if(q>end){
            Arr[k++] = A[p++];
        }
        else if (A[p] < A[q]){
            Arr[k++] = A[p++];
        }
        else {
            Arr[k++] = A[q++];
            count+=mid-p+1;
        }
    }

    for(int i =0; i<k; i++){
        Arr[start++] = A[i];
    }
    return count;
}

ll merge_sort(vector<ll> Arr, int start, int end){
    int total_count = 0;
    if(start<end){
        ll mid = start + (end-start)/2;
        ll left_count = merge_sort(Arr, start, mid);
        ll right_count = merge_sort(Arr, mid+1, end);

        ll merge_count = merge(Arr, start, mid, end);

        return merge_count+left_count+right_count;
    }
    return total_count;
}

int main() {
    int n;
    cin >> n;
    vector<ll> Arr(n);
    
    for(int i =0; i<n; i++){
        cin>>Arr[i];
    }
    
    cout<<merge_sort(Arr, 0, n-1);
	// Write your code here
    
}