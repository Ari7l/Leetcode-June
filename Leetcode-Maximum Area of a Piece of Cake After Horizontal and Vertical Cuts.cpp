//


class Solution {
public:
    //to find the maximum area of the cake cut after all the cuts are applied 
    //we sorted the horizontalCuts and verticalCuts and calculated the maximum consecutive gap between h cuts
    //and verti cuts
    //and the prod of these is max area 
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int mod = 1000000007;
        int maxH = 0 ,maxW = 0,maxA =0;
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end()); 
        maxH = h - horizontalCuts[horizontalCuts.size()-1];//taking care of diff between last cut and end of cake
        maxH = max(maxH ,horizontalCuts[0]);//diff between first cut and start of cake
        for(int i =1 ;i<horizontalCuts.size();++i){
            maxH = max(maxH ,abs(horizontalCuts[i] - horizontalCuts[i-1]));
        }
        maxW = w - verticalCuts[verticalCuts.size()-1];
         maxW = max(maxW ,verticalCuts[0]);
        for(int i =1 ;i<verticalCuts.size();++i){
            maxW = max(maxW ,abs(verticalCuts[i] - verticalCuts[i-1]));
        }
        maxA = long(long( maxH) * long(maxW)) %mod;
        
        return maxA%mod;
    }
};