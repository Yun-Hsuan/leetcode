#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxSlideingWindow(vector<int>& nums, int k);

vector<int> maxSlideingWindow(vector<int>& nums, int k){
	if(nums.size() == 0 || k == 0)
		return vector<int>();
	vector<int> ans;
	deque<size_t> max_pos;
	size_t i;
	for(i = 0; i < (size_t)k; i++){
		while((!max_pos.empty()) && nums[i] >= nums[max_pos.back()])
			max_pos.pop_back();
		max_pos.push_back(i);
	}
	for(; i < nums.size(); i++){
		ans.push_back(nums[max_pos.front()]);	
		while((!max_pos.empty()) && max_pos.front() <= i - k)
			max_pos.pop_front();
		while((!max_pos.empty()) && nums[i] >= nums[max_pos.back()])
			max_pos.pop_back();
		max_pos.push_back(i);
	}
	ans.push_back(nums[max_pos.front()]);	
	return ans;
}

int main(){

	int ary[] = {3, 2, 1, 4, 3, 2, 123, 34, 2, 1, 1, 1, 2, 3};
	vector<int> nums(ary, ary+14);

	vector<int> b = maxSlideingWindow(nums, 1);

	for(size_t i = 0; i < nums.size(); i++)
		cout << nums[i] << "  ";
	cout << endl;
	
	for(size_t i = 0; i < b.size(); i++)
		cout << b[i] << "  ";
	cout << endl;

	
	return 0;
}
