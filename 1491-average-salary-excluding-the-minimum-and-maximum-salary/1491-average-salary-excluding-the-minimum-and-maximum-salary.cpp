class Solution {
public:
    double average(vector<int>& salary) {
        
        int n=salary.size();
        sort(salary.begin(),salary.end());
      
        double min1=*min_element(salary.begin(),salary.end());
        double max1=*max_element(salary.begin(),salary.end());
        
        double x=accumulate(salary.begin(),salary.end(),0);
       
        x=x-(max1+min1);
        double y=x/(n-2);
        
        return y;
    }
};