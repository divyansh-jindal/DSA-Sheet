//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		void helper(string s, vector<string> &ans, string temp) {
        if (s.length() == 0) {
            if(temp=="") return;
            ans.push_back(temp);
            return;
        }
        helper(s.substr(1), ans, temp + s[0]);
        helper(s.substr(1), ans, temp);
    }

    vector<string> AllPossibleStrings(string s) {
        vector<string> result;
        helper(s, result, "");
        sort(result.begin(), result.end());
        
        return result;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends