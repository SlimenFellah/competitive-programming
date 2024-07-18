//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return maximum XOR subset in set[]

class Solution
{
    public:
    int maxSubsetXOR(int arr[], int N)
    {
        // Initialize index for the position of the current bit in arr
        int index = 0;

        // Traverse through all bits of integer starting from the most significant bit (31st bit)
        for (int bit = 31; bit >= 0; bit--) {
            // Initialize the maximum element and the index for the current bit
            int maxElementIndex = index;
            int maxElement = INT_MIN;

            // Find the maximum element with the current bit set
            for (int i = index; i < N; i++) {
                if ((arr[i] & (1 << bit)) != 0 && arr[i] > maxElement) {
                    maxElement = arr[i];
                    maxElementIndex = i;
                }
            }

            // If there was no element with the current bit set, continue to the next bit
            if (maxElement == INT_MIN)
                continue;

            // Swap the maximum element with the current index element
            swap(arr[index], arr[maxElementIndex]);

            // Store the index of the chosen element
            maxElementIndex = index;

            // Iterate over all elements and remove the current bit from all other elements with the same bit set
            for (int i = 0; i < N; i++) {
                if (i != maxElementIndex && (arr[i] & (1 << bit)) != 0) {
                    arr[i] = arr[i] ^ arr[maxElementIndex];
                }
            }

            // Increment index to move to the next bit
            index++;
        }

        // Initialize the result
        int result = 0;

        // XOR all the elements to get the final result
        for (int i = 0; i < N; i++) {
            result ^= arr[i];
        }

        return result;
        //Your code here
    }
};

//{ Driver Code Starts.
int main()
{

    int t,n,a[100004],k;
    scanf("%d",&t);
    while(t--)
    {
        //cin>>n;
       scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        Solution obj;
        printf("%d\n",obj.maxSubsetXOR(a,n));
       // cout<<bin(a,0,n-1,k)<<endl;
    }
}
// } Driver Code Ends