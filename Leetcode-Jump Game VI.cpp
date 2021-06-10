//this is a recursive approch 
//time : O(k^N) N elements have k choices
//O(k^N), where N is the size of array and k is max jump length. 
//We have k choices at each index and we are trying out each choice everytime 
//and recursing for remaining indices. So overall time complexity becomes k*k*k*...N times = O(k^N)
//Space : O(N), required by the recursive stack.
//this solution give TLE
class Solution {
public:
    int maxResult(vector<int>& nums, int k ,int i=0){
        if(i>=nums.size() -1) return nums.back();
        int maxScore = INT_MIN;
        for(int j=1 ;j<=k;++j){ // each index has K choices hence we are choosing maximum
           maxScore = max(maxScore ,nums[i]+maxResult(nums,k,i+j) );
        }
        return maxScore;
    }
};

//Approch 2 :
// (Dynamic Programming (Memoization)- Top-Down Approach)
//Time Complexity : O(k*N) For each index, we are trying out k jumps and storing the 
//results to avoid future recomputations. Overall, the time complexity required is k+k+k...N times = O(k*N)
//Space Complexity : O(N)
//gives TLE
int helper(vector<int>&nums ,vector<int>&dp, int k,int i){
		if(dp[i]!=INT_MIN) return dp[i]; //if result for curr index is already calculated return dp[i]
		
		for(int j=1 ; j<=k ;++j){//each index has K choices hence we are choosing maximum
			if(i+j<size(nums)){
				dp[i] = max(dp[i] , nums[i] + helper(nums,dp,k,i+j));
			}	

		}
		return dp[i];
}

class Solution {
public:
    int maxResult(vector<int>& nums, int k ,int i=0){
    	vector<int>dp(nums.size() ,INT_MIN);
        dp.back() = nums.back(); //since that's the only score we can obtain starting at n-1th index
        return helper(nums,dp,k,0);
    }
};

//Solution - III (Dynamic Programming (Tabulation) - Bottom-Up Approach)
//Time Complexity : O(k*N)
//Space Complexity : O(N)
class Solution {
public:
    int maxResult(vector<int>& nums, int k ,int i=0){
        vector<int>dp(nums.size() ,INT_MIN);
        dp[0] = nums[0];
        for(int i=1 ;i<nums.size() ;++i){
        	for(int j=1 ;j<=k &&  i - j >= 0;++j){
        		dp[i] = max(dp[i] , nums[i] + dp[i-j]);
        	}

        }
        return dp[nums.size()-1];
    }
};

//Solution - IV (Optimized Dynamic Programming)
//In the above dynamic programming approach, we can observe 
//that in the equation dp[i] = max(dp[i], dp[i - j] + nums[i]), 
//we are always choosing the dp[i-j] which has the maximum score.

//So, instead of iterating k times, we can just store the maximum amongst the previous
// dp[i-1], dp[i-2], ...dp[i-k] and use it directly in the equation hence we will use multiset to keep them sorted
//Whenever we reach i > k, the dp[i-k - 1] will be useless to us, since there's no way we can reach
// current index i from i-k - 1th index.
// So, we will just remove it from our set. 
//Finally, the above equation - dp[i] = max(dp[i], dp[i - j] + nums[i]), 
//can now be solved in O(logk) instead of O(k)

//Time Complexity : O(N*log(k))
//Space Complexity : O(N)
class Solution {
public:
    int maxResult(vector<int>& nums, int k ,int i=0){
        vector<int>dp(nums.size() ,INT_MIN);
        multiset<int>st({dp[0]=nums[0]}); //insert into dp
        for(int i=1 ;i<nums.size() ;++i){
        	if(i>k) st.erase(st.find(dp[i-k-1])); //erase elements from which we cant jump to current index
        	st.insert(dp[i] = *(rbegin(st)) + nums[i]); // //taking maximum previous score from set and updating multiset
        }
        return dp[nums.size()-1];
    }
};

//Solution - V (Further Optimized DP)

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
	vector<int> dp(size(nums));
	dp[0] = nums[0];
	deque<int> q{ 0 };
	for(int i = 1; i < size(nums); i++) {
		if(q.front() < i - k) q.pop_front();         // can't reach current index from index stored in q     
		dp[i] = nums[i] + dp[q.front()];             // update max score for current index
		while(!q.empty() && dp[q.back()] <= dp[i])   // pop indices which won't be ever chosen in the future
		    q.pop_back();
		q.push_back(i);                              // insert current index
	}
	return dp.back();
}
};
//Time Complexity : O(N)
//Space Complexity : O(N) required for dp and q