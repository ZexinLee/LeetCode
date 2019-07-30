class segmentTreeSum {
public:
    segmentTreeSum () {}
    segmentTreeSum(const vector<int>& nums) {
        origNums = nums;
        int origSize = origNums.size();
        if(origSize == 0) return;
        int tmp = (int)ceil(log2(origSize));
        int newSize = (1<<(tmp+1)) - 1;
        tree.resize(newSize, {-1, -1, INT_MIN});
        buildTree(nums, 0, 0, origSize-1);
    }
    int sumRange(int i, int j) {
        if(i<0 || j>=origNums.size() || i>j) return INT_MIN;
        return getSum(0, i, j);
    }
    void update(int i, int val) {
        if(i<0 || i>=origNums.size()) return;
        int diff = val - origNums[i];
        origNums[i] = val;
        updateTree(0, i, diff);
    }
private:
    vector<int> origNums;
    struct Element{int start; int end; int val;};
    vector<Element> tree;
    int buildTree(const vector<int>& nums, int treeIdx, int rangeStart, int rangeEnd) {
        if(rangeStart == rangeEnd) {
            tree[treeIdx] = {rangeStart, rangeEnd, nums[rangeStart]};
            return tree[treeIdx].val;
        }
        else {
            int mid = rangeStart + (rangeEnd - rangeStart) / 2;
            int lval = buildTree(nums, treeIdx*2+1, rangeStart, mid);
            int rval = buildTree(nums, treeIdx*2+2, mid+1, rangeEnd);
            tree[treeIdx] = {rangeStart, rangeEnd, lval+rval};
            return tree[treeIdx].val;
        }
    }
    int getSum(int treeIdx, int queryStart, int queryEnd) {
        if(tree[treeIdx].start > queryEnd || tree[treeIdx].end < queryStart) return 0;
        else if(queryStart <= tree[treeIdx].start && tree[treeIdx].end <= queryEnd) return tree[treeIdx].val;
        else return getSum(treeIdx*2+1, queryStart, queryEnd) + getSum(treeIdx*2+2, queryStart, queryEnd);
    }
    void updateTree(int treeIdx, int updateIdx, int diff) {
        if(treeIdx >= tree.size()) return;
        if(tree[treeIdx].start <= updateIdx && updateIdx <= tree[treeIdx].end){
            tree[treeIdx].val += diff;
            updateTree(treeIdx*2+1, updateIdx, diff);
            updateTree(treeIdx*2+2, updateIdx, diff);
        }
    }
};
//====================================================================
class NumArray {
public:
    NumArray(vector<int> nums) {
        segTreeSum = new segmentTreeSum(nums);
    }
    
    void update(int i, int val) {
        segTreeSum->update(i, val);
    }
    
    int sumRange(int i, int j) {
        return segTreeSum->sumRange(i, j);
    }
private:
    segmentTreeSum* segTreeSum;
};
