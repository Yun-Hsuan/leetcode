#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

void printVec(vector< vector<int> >& vec);
int excludeCard(vector<int> posCard, vector< vector<int> >& cards);
void printVec(vector<int>& vec);
std::vector< vector<int> > findPath(size_t startCard, vector<vector<int> >& card);
void reShape(size_t label, vector<int>& cardlabel);
void reShape(size_t label1, size_t label2, vector<int>& cardlabel);
void setCol(int elem, vector< vector<int> > M);
bool findCard(vector<int>& outCard, vector< vector<int> >& cards, int pos1, vector<int>& card1, int pos2, vector<int>& card2, vector< vector<int> >& posPath);

void printVec(vector< vector<int> >& vec){
	for(size_t i = 0; i < vec.size(); i++){
		for(size_t j = 0; j < vec[i].size(); j++)	
			printf("%d ", vec[i][j]);
		printf("\n");
	}
}

int excludeCard(vector<int> posCard, vector< vector<int> >& cards){
	int exu;
	for(size_t i = 0; i < cards.size(); i++)
		if(find(posCard.begin(), posCard.end(), i) == posCard.end())
			exu = i;
	return exu;
}

void setCol(int col, int elem, vector< vector<int> > M){
	for(size_t i = 0; i < M.size(); i ++){
		M[i][col] = elem;
	}
}

void reShape(int label, vector<int>& cardlabel){
	for(size_t i = 0; i < cardlabel.size(); i++){
		if(cardlabel[0] != label){
			cardlabel.push_back(cardlabel[0]);
			cardlabel.erase(cardlabel.begin());
		}
	}
}

bool fitCard(size_t label1, size_t label2, vector<int>& cardlabel){
	cardlabel.push_back(cardlabel[0]);
	vector<int>::iterator it1 = find(cardlabel.begin(), cardlabel.end(), label1);
	int pos = it1 - cardlabel.begin();
	//cout << "label1:" << label1 << "  label2: "<< label2 << " label: " << cardlabel[pos] << "  pos: " << pos << endl;
	if(it1 != cardlabel.end() && it1 != cardlabel.end() - 1 && (size_t)cardlabel[pos+1] == label2){
		cardlabel.pop_back();
		//cout << "True" << endl;
		return true;
	}
	cardlabel.pop_back();
	return false;
}

bool fitCard(size_t label1, size_t label2, size_t label3, vector<int>& cardlabel){
	cardlabel.push_back(cardlabel[0]);
	cardlabel.push_back(cardlabel[1]);
	vector<int>::iterator it1 = find(cardlabel.begin(), cardlabel.end(), label1);
	int pos = it1 - cardlabel.begin();
	//printVec(cardlabel);
	//cout << "label1:" << label1 << " label: " << cardlabel[pos] << "  pos: " << pos << endl;
	if(it1 != cardlabel.end() && it1 != cardlabel.end() - 1 && it1 != cardlabel.end() - 2 && (size_t)cardlabel[pos+1] == label2 && (size_t)cardlabel[pos+2] == label3){
		cardlabel.pop_back();
		cardlabel.pop_back();
		return true;
	}
	cardlabel.pop_back();
	cardlabel.pop_back();
	return false;
}

void printVec(vector<int>& vec){
	for(size_t i = 0; i < vec.size(); i++)	
		printf("%d ", vec[i]);
	printf("\n");
}

void merge(vector< vector<int> >& vec1, vector< vector<int> >& vec2);

void merge(vector< vector<int> >& vec1, vector< vector<int> >& vec2){

	for(size_t i = 0; i < vec2.size(); i++)
		vec1.push_back(vec2[i]);
}

bool findCard(vector<int>& outCard, vector< vector<int> >& cards, int pos1, vector<int>& card1, int pos2, vector<int>& card2, vector< vector<int> >& posPath){

	vector<int>::iterator it;
	vector<int> posCard;
	bool flag = false;
	//cout << "Out Card:";
	//printVec(outCard);
	for(size_t i = 0; i < cards.size(); i++){
		it = find(outCard.begin(), outCard.end(), i);
		if(it != outCard.end())
			continue;
		if(fitCard(card1[pos1], card2[pos2], cards[i])){
			posCard.push_back(i);	
			flag = true;
		}
	}

	if(flag == false)
		return flag;
	//cout << "-----------------------" << endl;
	
	vector< vector<int> > tmp;
	vector<int> buf = outCard;
	buf.push_back(100);
	//cout << "Pos Card:";
	//printVec(posCard);
	for(size_t j = 0; j < posCard.size(); j++){
		buf.back() = posCard[j];
		tmp.push_back(buf);
	}
	posPath = tmp;
	//cout << "--end--------------------" << endl;

	return flag;
}

std::vector< vector<int> > findPath(size_t startCard, vector<vector<int> >& cards){
	
	vector< vector<int> > ans;

	vector<int> cardCenter = cards[startCard];
	for(size_t i = 0; i < cards.size(); i++){
		vector< vector<int> >	posPath(1);
		posPath[0].push_back(startCard);
		if(startCard == i)
			continue;
		vector<int>	card2 = cards[i];
		posPath[0].push_back(i);
		reShape(cards[startCard][0], card2);
		vector< vector<int> > node1 = posPath;
		if(!findCard(posPath[0], cards, 1, cardCenter, 5, card2, node1))
			continue;	
		for(size_t j = 0; j < node1.size(); j++){
			vector<int> card3 = cards[node1[j].back()];
			reShape(cardCenter[1], card3);	
			vector< vector<int> > node2 = node1;
			if(!findCard(node1[j], cards, 2, cardCenter, 5, card3, node2))
				continue;	
			for(size_t k = 0; k < node2.size(); k++){
				vector<int> card4 = cards[node2[k].back()];
				reShape(cardCenter[2], card4);	
				vector< vector<int> > node3 = node2;
				if(!findCard(node2[k], cards, 3, cardCenter, 5, card4, node3))
					continue;
				for(size_t l = 0; l < node3.size(); l++){
					vector<int> card5 = cards[node3[l].back()];
					reShape(cardCenter[3], card5);	
					vector< vector<int> > node4 = node3;
					if(!findCard(node3[l], cards, 4, cardCenter, 5, card5, node4))
						continue;
					for(size_t m = 0; m < node4.size(); m++){
						vector<int> card6 = cards[node4[m].back()];
						reShape(cardCenter[4], card6);	
						vector<int> card7 = cards[excludeCard(node4[m], cards)];
						reShape(card2[1], card7);
						//printVec(node4[m]);
						if(fitCard(card2[1], cardCenter[5], card6[5], card7)){
							vector<int>	buf = node4[m];
							buf.push_back(excludeCard(node4[m], cards));
							ans.push_back(buf);
						}
					}
				}
			}
		}
	}
	/*
	for(size_t i = 0; i < ans.size(); i++){
		cout << "Ans: ";
		printVec(ans[i]);
	}
	*/
	return ans;
}

int main(){
	
	int label0[] = {0, 1, 2, 3, 4, 5};
	int label1[] = {2, 5, 4, 0, 1, 3};
	int label2[] = {0, 1, 3, 4, 5, 2};
	int label3[] = {3, 5, 0, 4, 5, 1};
	int label4[] = {2, 4, 1, 5, 0, 3};
	int label5[] = {1, 4, 5, 2, 3, 0};
	int label6[] = {2, 1, 3, 0, 4, 5};
	vector< vector<int> > card;
	card.push_back(vector<int>(label0, label0+6));
	card.push_back(vector<int>(label1, label1+6));
	card.push_back(vector<int>(label2, label2+6));
	card.push_back(vector<int>(label3, label3+6));
	card.push_back(vector<int>(label4, label4+6));
	card.push_back(vector<int>(label5, label5+6));
	card.push_back(vector<int>(label6, label6+6));

	// Start from card[0]
	vector< vector<int> > ans;
	vector< vector<int> > buf;
	for(size_t i = 0; i < 7; i++){
		if(i == 0)
			ans = findPath(i, card);
		else{
			buf = findPath(i, card);
			merge(ans, buf);
		}
	}
	printVec(ans);

	return 0;
}
