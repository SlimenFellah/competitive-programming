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
        vector<int> in(26, 0), out(26, 0);
        vector<vector<int>> graph(26);
        
        for (const string& s : A) {
            int u = s.front() - 'a';
            int v = s.back() - 'a';
            out[u]++;
            in[v]++;
            graph[u].push_back(v);
        }
        
        for (int i = 0; i < 26; ++i) {
            if (in[i] != out[i]) {
                return 0;
            }
        }
        
        vector<bool> visited(26, false);
        function<void(int)> dfs = [&](int node) {
            visited[node] = true;
            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    dfs(neighbor);
                }
            }
        };
        
        int startNode = -1;
        for (int i = 0; i < 26; ++i) {
            if (out[i] > 0) {
                startNode = i;
                break;
            }
        }
        
        if (startNode == -1) {
            return 1;
        }
        
        dfs(startNode);
        for (int i = 0; i < 26; ++i) {
            if (out[i] > 0 && !visited[i]) {
                return 0;
            }
        }
        
        vector<bool> reverseVisited(26, false);
        vector<vector<int>> reverseGraph(26);
        for (int i = 0; i < 26; ++i) {
            for (int neighbor : graph[i]) {
                reverseGraph[neighbor].push_back(i);
            }
        }
        
        function<void(int)> reverseDfs = [&](int node) {
            reverseVisited[node] = true;
            for (int neighbor : reverseGraph[node]) {
                if (!reverseVisited[neighbor]) {
                    reverseDfs(neighbor);
                }
            }
        };
        
        reverseDfs(startNode);
        for (int i = 0; i < 26; ++i) {
            if (out[i] > 0 && !reverseVisited[i]) {
                return 0;
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