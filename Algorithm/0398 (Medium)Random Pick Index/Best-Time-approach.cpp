template<class T, int K>
struct ReservoirSampler final {
public:
  std::array<T, K> sample;
  
  void introduce(const T& element) {
    ++i;
    if (i < K) {
      sample[i] = element;
    } else {
      int j = rand() % i;
      if (j < K)
        sample[j] = element;
    }
  }
    
private:
  int i = 0;
};

class Solution {
public:
  Solution(vector<int>& nums) : nums(std::move(nums)) {}

  int pick(int target) {
    ReservoirSampler<int, 1> sampler;
    for (int i = 0; i < nums.size(); ++i)
      if (nums[i] == target)
        sampler.introduce(i);
    return sampler.sample[0];
  }

private:
  vector<int> nums;
};

static auto const magic = [](){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();