class Solution {
public:
    int largestAltitude(vector<int>& gain) {
          vector<int>temp = {0};
       for(auto it:gain){
           temp.push_back(it + temp.back());
       } 
       return *max_element(temp.begin(), temp.end());
    }
};