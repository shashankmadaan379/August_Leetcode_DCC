class Solution {
public:
    int dp[301];
    int helper(string s,set<string>&wordDict,int i){
        if(i==s.size())return true;
        string temp;
        if(dp[i]!=-1)return dp[i];
        for(int j=i;j<s.size();j++){
            temp+=s[j];
            if(wordDict.find(temp)!=wordDict.end()){
                if(helper(s,wordDict,j+1))return dp[i]=1;
            }
        }
        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        memset(dp,-1,sizeof dp);
        for(auto it:wordDict){st.insert(it);}
        return helper(s,st,0);
    }
};
