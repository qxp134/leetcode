class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp;
        auto j = nums2.begin();
        auto i = nums1.begin();
        int num = nums1.size() + nums2.size();
        for(int count = 0;;count++){
            if(j == nums2.end()){
                temp.push_back(*i);
                i++;
            }
            else if(i == nums1.end()){
                temp.push_back(*j);
                j++;
            }
            else if(*i < *j){
                temp.push_back(*i);
                i++;
            }
            else{
                temp.push_back(*j);
                j++;
            }
            if(count == num/2)break;
        }
        if(num%2==1)return temp[num/2];
        else {
            double temp1 = temp[num/2];
            double temp2 = temp[num/2-1];
            return (temp1 + temp2)/2;
        }
    }
};