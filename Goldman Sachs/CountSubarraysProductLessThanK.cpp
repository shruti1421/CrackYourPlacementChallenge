//Question Link: https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long start=0,prod=1,cnt=0;
        
        for(int i=0;i<n;i++)
        {
            prod*=a[i];
            
            while(start<=i&&prod>=k)
            {
                prod/=a[start];
                start++;
            }
            
            if(start<=i)
            {
                cnt+=i-start+1;
            }
        }
        
        return cnt;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends