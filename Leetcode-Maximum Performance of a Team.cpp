class Solution {
public:
    #define mod 1000000007
    #define ll long long
    //this is a Greedy algo problem
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        ll ans  =0;
        //pairing the respective efficiency and speed and storing it in a single vector 
        //so that we can sort
        vector<pair<ll,ll>>Paired(n);
        for(ll i =0; i<n ;++i){
            Paired.push_back({efficiency[i] , speed[i]});
        }
        //sorting the vec in decreasing order of the efficiency 
        sort(Paired.rbegin(),Paired.rend());
        multiset<ll>st;
        ll sum = 0;
        for(ll i=0;i<n;++i){
            //at each iteration we are considering the current the effi as the minEff and
            //keeping track of k-1 efficiencies
            ll min_eff = Paired[i].first;
            //taking sum of speeds 
            sum+=Paired[i].second;
            //maximizing the prod of min_eff and maximum sum of speeds
            ans = max(ans , min_eff*sum);
            st.insert(Paired[i].second);
            //once we have added k speeds we will remove the lowest speed and in next itreation add
            //new one 
            if(st.size()==k){
                sum-=(*st.begin());
                st.erase(st.begin());
            }
            
        }
        
         return (int)(ans%mod);
        
        
    }
};
//Time Complexity: O(N * log(N)) where N is the length of speed or efficiency, for the sorting of ord and for the priority queue / heap
//Space Complexity: O(N) for ord and multiset

//Using a Priority Queue
class Solution {
public:
    #define mod 1000000007
    #define ll long long
    //this is a Greedy algo problem
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        ll ans  =0;
        //pairing the respective efficiency and speed and storing it in a single vector 
        //so that we can sort
        vector<pair<ll,ll>>Paired(n);
        for(ll i =0; i<n ;++i){
            Paired.push_back({efficiency[i] , speed[i]});
        }
        //sorting the vec in decreasing order of the efficiency 
        sort(Paired.rbegin(),Paired.rend());
        priority_queue<ll>q;
        ll sum = 0;
        for(ll i=0;i<n;++i){
            //at each iteration we are considering the current the effi as the minEff and
            //keeping track of k-1 efficiencies
            ll min_eff = Paired[i].first;
            //taking sum of speeds 
            sum+=Paired[i].second;
            //maximizing the prod of min_eff and maximum sum of speeds
            ans = max(ans , min_eff*sum);
            //we are pushing the with negative sign hence the lowest speed will be on top of queue
            q.push(-Paired[i].second);
            //once we have added k speeds we will remove the lowest speed and in next itreation add
            //new one 
            if(st.size()==k){
                //adding means subtracting lowest speed among k speed
                sum+=q.top();
                q.pop();
            }
            
        }
        
         return (int)(ans%mod);
        
        
    }
};