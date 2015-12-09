#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int missingNum(vector<int>& nums);
int missingNum2(vector<int>& nums);

int missingNum(vector<size_t>& nums){
  sort(nums.begin(), nums.end());
  size_t max = nums[nums.size()-1];
  size_t min = nums[0];
  size_t missval = 0;
  size_t mean = 0;
  if(min != 0)
    return 0;
  if(max == nums.size()-1)
    return nums.size();
  do{
    mean = (max + min) / 2;
    if( mean == nums[mean]){
      min = nums[mean+1];
      //cout << "min: " <<  min << endl;
      if(min != nums[mean]+1)
	missval = nums[mean]+1;
    }else{
      max = nums[mean-1];
      if(max != nums[mean]-1)
	missval = nums[mean]-1;
    }
  }while(missval == 0);
  return missval;
}

int missingNum2(vector<int>& nums){
  vector<bool> list(nums.size()+1, false);
  for(vector<int>::const_iterator it = nums.begin(); it != nums.end(); it++)
    list[*it] = true;
  size_t missval =  find(list.begin(), list.end(), false) - list.begin();
  return missval;
}

int main(){
//int num_array[] = {0, 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15};
  int num_array[] = {1, 0, 2, 4};
  vector<int> nums( num_array, num_array + sizeof(num_array) / sizeof(int));
  cout << missingNum2(nums) << endl;
  return 0;
}
