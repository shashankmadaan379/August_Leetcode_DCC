class Solution {
public:
    int mod=1e9+7;
    int dp[102][102],total_songs;
    long long helper(int n,int goal,int k){
        if(n==0 and goal==0)return 1;
        if(n==0 or goal==0)return 0;
        if(dp[n][goal]!=-1)return dp[n][goal];
        long long new_song=helper(n-1,goal-1,k)*(total_songs-n+1);
        if(n-k>0){
            new_song+=helper(n,goal-1,k)*(n-k);
        }
        return dp[n][goal]=(new_song)%mod;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        memset(dp,-1,sizeof(dp));
        total_songs=n;
        return helper(n,goal,k);
    }
};
