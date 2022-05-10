//Question Link: https://practice.geeksforgeeks.org/problems/print-anagrams-together/1/
// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code herev
        vector<vector<string>> ans;
        
        unordered_map<string,int> mp;
        
        int i=0;
        
        for(auto &x: string_list)
        {
            
            string str=x;
            sort(str.begin(),str.end());
            if(mp.find(str)!=mp.end())
            {
                int index=mp[str];
                ans[index].push_back(x);
            }
            else
            {
                vector<string> v;
                v.push_back(x);
                ans.push_back(v);
                sort(x.begin(),x.end());
                mp[x]=i;
                i++;
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends