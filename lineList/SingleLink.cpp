#include <iostream>
using namespace std;

class Node{
	int data;
	Node* next;

	public:
	Node(){};
	void SetData(int aData){data = aData;}
	void SetNext(Node* aNext){ next = aNext;}
	int Data(){return data;}
	Node* Next(){ return next;}
};

class List{
	Node* head;
	public:
	List(){head = NULL;}
	void Print();
	void Append(int data);
	void Delete(int data);
};

void List::Print(){
	Node* tmp = head;

	if(tmp ==NULL){
		cout << "EMPTY"	<< endl;
	}

	if(tmp->Next() == NULL){
		cout <<tmp->Data();	
		cout << "--->" ;
		cout << "--->"<< endl;

	}else{
		do{
			cout << tmp->Data();	
			cout << "--->";
			tmp = tmp->Next();
		}while(tmp != NULL);
		cout << "NULL" << endl;
	}
}

void List::Append(int data){

	Node* newNode = new Node();
	newNode->SetData(data);
	newNode->SetNext(NULL);
	
	Node* tmp = head;


}







