class Solution {
public:
    unordered_map<char,vector<string>> mp;
    vector<string> result;
    void backtrack(string &digits,int start,string curr){
        if(start==digits.size()){
            result.push_back(curr);
            return;
        }
        vector<string> temp=mp[digits[start]];
        for(int i=0;i<temp.size();i++){
            string st=temp[i];
            curr+=st;
            backtrack(digits,start+1,curr);
            curr.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return result;
        }
        mp['2']={"a","b","c"};
        mp['3']={"d","e","f"};
        mp['4']={"g","h","i"};
        mp['5']={"j","k","l"};
        mp['6']={"m","n","o"};
        mp['7']={"p","q","r","s"};
        mp['8']={"t","u","v"};
        mp['9']={"w","x","y","z"};
        backtrack(digits,0,"");
        return result;
    }
};
