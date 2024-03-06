//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    const int prime = 101;
    public:
        vector<int> search(string pattern, string text) {
            vector<int> indices;
        
            int patternLength = pattern.length();
            int textLength = text.length();
            int patternHash = 0; // Hash value for pattern
            int textHash = 0;    // Hash value for current window of text
        
            /*Good way to avoid collisions but when dealing with large patterns, the direct 
            calculation of the hash using powers of a prime can lead to overflow*/
            
            // for (int i = 0; i < patternLength; i++) {
            //     patternHash += pattern[i] * pow(prime, i);
            //     textHash += text[i] * pow(prime, i);
            // }
            
            // Calculate hash value for pattern and first window of text
            for (int i = 0; i < patternLength; i++) {
                patternHash += pattern[i];
                textHash += text[i];
            }
        
            // Slide the pattern window over text one by one
            for (int i = 0; i <= textLength - patternLength; i++) {
                if (patternHash == textHash) {
                    // Check if all characters match
                    bool match = true;
                    for (int j = 0; j < patternLength; j++) {
                        if (text[i + j] != pattern[j]) {
                            match = false;
                            break;
                        }
                    }
                    if (match) {
                        indices.push_back(i+1);
                    }
                }
        
                // Calculate hash value for next window of text
                if (i < textLength - patternLength) {
                    // textHash = (textHash - text[i])/prime  + (text[i+patternLength]*pow(prime, patternLength-1)); //for the prime logic
                    textHash = (textHash - text[i] + text[i+patternLength]);
                }
            }
        
            return indices;
     }
     
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends