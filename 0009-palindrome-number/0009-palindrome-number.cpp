class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int i= 0;
        int j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
    return true;
    }
};
/*
but in this question we used converted our int to string and string store s eaxh digit there for it makes the space complexity o(n)
but sometimes in interview we are asked to do this in O(1) space or cosntant space 
the we use this approach
class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        int rev = 0;

        while (x > rev) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }

        return (x == rev || x == rev / 10);
    }
};  
*/