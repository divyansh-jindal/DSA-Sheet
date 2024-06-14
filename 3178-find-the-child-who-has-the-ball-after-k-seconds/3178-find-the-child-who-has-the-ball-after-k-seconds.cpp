class Solution {
public:
    int numberOfChild(int n, int k) {
        n--;
        int rnd=k/n;
        int rem=k%n;
        
        if(rnd%2==0) return rem;
        else return n-rem;
    }
};