/*linked list
 detail: node-node-node-node

 made by: Ji Woo, Kim
 modified: 01.06, 2021
 */
#include <iostream>
using namespace std;
typedef struct Node {
	int key;
	struct Node* next;
}node;

int main() {

	node* head;
	node* nodes = (node*)malloc(4 * sizeof(node));
	int i;

	nodes[0].key = 100;	//initialize the key value
	nodes[1].key = 250;
	nodes[2].key = 467;

	nodes[0].next = &nodes[1];	//linking nodes
	nodes[1].next = &nodes[2];
	nodes[2].next = NULL;

	head = &nodes[0];	//start with node1

	int searchNum, found = 0;

	cout<<"original node-key value"<<endl;

	while (head != NULL) {
		cout<<head->key<<"\t";
		head = head->next;
	}
	nodes[3].key = 300;

	nodes[3].next = &nodes[2];
	nodes[1].next = &nodes[3];

	head = &nodes[0];

	cout<<"\ninserted node-key value"<<endl;
	while (head != NULL) {
		cout<<head->key<<"\t";
		head = head->next;
	}

	free(head);
	free(nodes);


}