// Solution-1 --> Not Recommended
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        do{
            result.push_back(nums);
        }
        while(next_permutation(nums.begin(),nums.end()));
        return result;
    }
};

//Solution-2
class Solution {
public:
    vector<vector<int>> result;
    void permutation(vector<int>& nums,int i){
        if(i>=nums.size()){
            result.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            permutation(nums,i+1);

            //backtrack
            swap(nums[i],nums[j]);
        }
    } 
    vector<vector<int>> permute(vector<int>& nums) {
      permutation(nums,0);
      return result;
    }
};
