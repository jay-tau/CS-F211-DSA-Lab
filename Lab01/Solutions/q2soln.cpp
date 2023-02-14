// do not edit the header files
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;



int main() {
  // start writing your code from here
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin>>n;
    vector<int> arr(n,0);
    
    //taking input
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int x=arr[n-1];//required sum
    
    //initializing the two pointers
    int left=0;
    int right=n-1;
    
    
    while(left<=right)
    {
        
        // if the current sum is equal to 'x', then print the result and move both pointers. 
        if(arr[left]+arr[right]==x)
        {
            cout<<arr[left]<<" "<<arr[right]<<endl;
            left++;
            right--;
        }
        //if the current sum is less than 'x' then we need a bigger sum.
        //so we move the left pointer towards right (increment it)
        else if(arr[left]+arr[right]<x)
        {
            left++;
        }
        //if the current sum is more than 'x' then we need a smaller sum.
        //so we move the right pointer towards left (decrement it)
        else
        {
            right--;
        }
    }
    
    
    
    return 0;
}
