//this a BFS graph traversal
class Solution {
public:
    //1000
   //9000
    //0100
    //0900
    //0010
    //0090
    //0001
    //0009
    //there are 10^4 total combinations each digit can rotate 0 to 9 and there are 4 digit
    //forwards the current digit
    string ForwardRotate(string s , int i){
        s[i] = '0' + ((s[i] - '0')+1) %10 ;
        return s ;
               
    }
    //reverse current digit
     string ReverseRotate(string s , int i){
        s[i] = '0' + ((s[i] - '0')-1+10) %10 ;
        return s ;
               
    }
    int openLock(vector<string>& deadends, string target) {
        if(target=="0000") return 0;
        unordered_set<string>dead(begin(deadends),end(deadends));
        if(dead.find("0000")!=dead.end()) return -1;
        unordered_set<string>seen;
        seen.insert("0000");
        queue<string>q;
        q.push("0000");
        int minTurns=0;
        while(!q.empty()){
          int size = q.size();  
            minTurns++;
          for(int i=0 ;i<size ; ++i){
              string currStr = q.front();
              q.pop();
              for(int j=0 ;j<4 ;++j){
                  string fwd_str =  ForwardRotate(currStr ,j);
                  string rev_str =  ReverseRotate(currStr ,j);
                  if(seen.find(fwd_str) == end(seen) && dead.find(fwd_str) == end(dead)){
                      if(fwd_str == target) return minTurns;
                      else{
                          q.push(fwd_str);
                          seen.insert(fwd_str);
                      } 
                  }
                   if(seen.find(rev_str) == end(seen) && dead.find(rev_str) == end(dead)){
                      if(rev_str == target) return minTurns;
                     else{
                          q.push(rev_str);
                          seen.insert(rev_str);
                      } 
                  }
                  
              }
              
          }
   
         
            
        }
               
        return -1;
    }
};
//Time Complexity : O(N), where N is the number of strings in deadends and O(N) is required to insert
// all the strings into the hashset. The BFS traversal requires O(1). It may be strange 
//but that's how you calculate big O complexity. The time required by our BFS traversal 
//doesn't depend on the input and in the worst case, we end up making 10000 iterations at max.
//Space Complexity : O(N)