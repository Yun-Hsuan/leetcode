#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums);

void moveZeroes(vector<int>& nums){
  int notZero = 0;
  int iterNum = nums.size();
  for(int i = 0; i < iterNum; i++)
    if(nums[0+notZero] == 0){
      nums.erase(nums.begin() + (notZero));
      nums.push_back(0);
    }else
      notZero++;
}

int main(){
  int num_array[] = {0, 0, 1, 2, 0, 4, 0};
  vector<int> nums( num_array, num_array + sizeof(num_array) / sizeof(int));
  for(size_t i = 0; i < nums.size(); i++)
    cout << nums[i] << endl;
  moveZeroes(nums);
  cout << "===========" << endl;
  for(size_t i = 0; i < nums.size(); i++)
    cout << nums[i] << endl;

  return 0;
}
