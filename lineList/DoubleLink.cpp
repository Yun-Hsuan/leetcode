#include <iostream>
#include <vector>
using namespace std;

struct node{
	struct node *next;
	struct node *prev;
};

typedef struct node node_t;

struct list{
	node_t head;
	node_t tail;
};

typedef struct list list_t;

int main(){

	return 0;
}
