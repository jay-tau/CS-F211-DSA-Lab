/*
    Pleasw write your answers alongside the space provided
    a) Pseduo-code:
    
    selection-sort(A)
    n=A.length
    for i=1 to n-1
       smallest = i
       for j=i+1 to n
          if A[j]<A[smallest]
            then smallest=j
       exchange A[i] with A[smallest]
    
    
    b) What loop invariant property does the algorithm have:
    
    At the start of each iteration of the outer loop, the subarray (from index 1 to i-1) is sorted for the first i-1 elements.

    [There can be multiple answers, you will get marks only if your answer is conceptually correct and makes sense.]
         
    
    c)i) Best Case runtime complexity: Theta(n^2)
      ii) Worst Case runtime complexity: Theta(n^2)
      
      
      [This time we are giving marks for the O(n^2) or just (n^2) answer as well, but the correct answer here is Theta(n^2). From the next lab you will have to write the time complexity with the correct notation. If you can't find the symbols then you can write it in words as well like the above solution.]
  
*/



// do not change any of the header files
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;


int main() {

      // Start writing your code from here
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    
    int n;
    cin>>n;
    vector<int> a(n+1,0); 
    
    for(int i=1; i<=n; i++) //using 1-based indexing
    
    {
        cin>>a[i];
    }
    
    

    int smallest; 
    
    for(int i=1; i<=n-1; i++)
    {
        smallest  = i;
        for(int j=i+1; j<=n; j++)
        {
            if(a[j]<a[smallest])
            {
                smallest = j;
            }
        }
        
        
        //exchange
        int temp; //temp variable for swapping
        temp = a[smallest];
        a[smallest] = a[i];
        a[i] = temp;
    }
    
    
    //printing the output
    for(int i=1; i<=n; i++)
    {
        cout<<a[i]<<' ';
    }

    
    return 0;

    
}