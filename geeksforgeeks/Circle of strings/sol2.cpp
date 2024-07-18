//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    int isCircle(int N, vector<string> A)
    {
        // code here
        vector<int> parent(26), rank(26, 0), in(26, 0), out(26, 0);
        iota(parent.begin(), parent.end(), 0);

        // Function to find the root of a node with path compression
        function<int(int)> find = [&](int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };

        // Function to unite two sets
        auto unite = [&](int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                if (rank[rootX] > rank[rootY]) {
                    parent[rootY] = rootX;
                } else if (rank[rootX] < rank[rootY]) {
                    parent[rootX] = rootY;
                } else {
                    parent[rootY] = rootX;
                    rank[rootX]++;
                }
            }
        };

        // Process each string in the array
        for (const string& s : A) {
            int u = s.front() - 'a';
            int v = s.back() - 'a';
            out[u]++;
            in[v]++;
            unite(u, v);
        }

        // Check if in-degree equals out-degree for each character
        for (int i = 0; i < 26; ++i) {
            if (in[i] != out[i]) {
                return 0;
            }
        }

        // Check if all characters with non-zero degree are in the same connected component
        int root = -1;
        for (int i = 0; i < 26; ++i) {
            if (in[i] > 0 || out[i] > 0) {
                if (root == -1) {
                    root = find(i);
                } else if (find(i) != root) {
                    return 0;
                }
            }
        }

        return 1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<string> A;
        string s;
        
        for(int i = 0;i < N; i++)
        {
            cin>>s;
            A.push_back(s);
        }
        
        Solution ob;
        cout<<ob.isCircle(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends