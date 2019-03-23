c++
runtime 44ms
memory usage 22mb

#include 
class Solution {
public:
double findMedianSortedArrays(vector& nums1, vector& nums2)
{
vector num_merged;
double expected=0.;
std::merge( nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),std::back_inserter(num_merged) );
int l=static_cast(num_merged.size());
if( l%2 == 0 )
expected =( num_merged.at(l/2 - 1) + num_merged.at(l/2) )/2.0 ;
else
expected =( num_merged.at( int(l/2) ) );
return expected;
}
};