#include <iostream>
#include <vector>

using namespace std;

void printVec(const vector<int>& labels){
	for(size_t i = 0; i < labels.size(); i++)
		cout << labels[i] << " ";
	cout << endl;
}

int main(){

	int mySize[] = {3, 2, 4};
	vector<int> eachSize(mySize, mySize+3);

	size_t groupSize = 0;
	for(size_t k = 0; k < eachSize.size(); k++)
		groupSize+=eachSize[k];

	int mylabel[11] = {9, 3, 2, 12, 33, 12, 10, 7, 5, 6, 0};
	vector<int>	labels(mylabel, mylabel+11);
	vector<int> lrsp_labels = labels;
	vector<int> rsp_labels = labels;
	
	int pos=0;	
	for(size_t i = 0; i < eachSize.size(); i++){
		for(size_t j = 0; j < groupSize; j++){
			if(j >= groupSize - (size_t)eachSize[i]){
				cout << 0+j-(groupSize-eachSize[i]) << endl;
				rsp_labels[pos]	= lrsp_labels[0+j-(groupSize-eachSize[i])];
			}
			else
				rsp_labels[pos] = lrsp_labels[j+eachSize[i]];
			pos++;
		}
		printVec(rsp_labels);
		lrsp_labels = rsp_labels;
		pos=0;
	}

	return 0;
}
