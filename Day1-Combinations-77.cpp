class Solution {
public:
    vector<vector<int>> result;
    int n;
    void recurse(vector<int> &comb,int i,int k){
        if(k==0){
            result.push_back(comb);
            return;
        }
        if(i>n)return;
        if(k>n-i+1)return;

        //take the ith element
        comb.push_back(i);
        recurse(comb,i+1,k-1);
        //skip the ith element
        comb.pop_back();
        recurse(comb,i+1,k);
    }
    vector<vector<int>> combine(int n, int k) {
        this->n=n;
        vector<int> comb;
        recurse(comb,1,k);
        return result;
    }
};
