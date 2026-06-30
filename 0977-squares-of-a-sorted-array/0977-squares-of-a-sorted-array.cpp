class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>pos;
        vector<int>neg;
        for(int x: nums){
            if(x<0){
                neg.push_back(x);
            }
            else{
                pos.push_back(x);
            }
        }
        if(pos.size()==0){ //when all the elements in the og array are negative 

        for(int &x:neg ){
            x=x*x;
        }
        reverse(neg.begin(),neg.end());
        return neg;
        }
        else if (neg.size()==0){
            for(int &x: pos){
                x=x*x;
            }
            return pos;
        }
        else{
            int i= 0 ;
            int j=0;
            int n= pos.size();
            int m=neg.size(); 
            vector<int>result;
            for(int &x:neg){
                x=x*x;
            }
            reverse(neg.begin(),neg.end());

            for(int &x : pos){
                x=x*x;
            }
            while(i<n and j<m){
                if(pos[i]<neg[j]){
                    result.push_back(pos[i]);
                    i++;
                }
                else{
                    result.push_back(neg[j]);
                    j++;
                }
            }
            while(i<n){ //when j has iterated over all the elements of its respective array but still some elemts are left int the positice array 

            result.push_back(pos[i]);
            i++;
            }
            while(j<m){
                result.push_back(neg[j]);
                j++;
            }

        return result;
        }
    }
};