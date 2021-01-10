#include<iostream>
#include<malloc.h>
using namespace std;

struct List_node
{	

	int DATA = 0;
	struct List_node *NEXT_NODE;
	List_node(int D):DATA(D){NEXT_NODE = NULL;}
};

int main(){
	List_node *HEAD = NULL;
	List_node *TAIL = NULL;
	List_node *CURSOR = NULL;
	List_node *NEW_NODE = NULL;
	int input_data;

	for(int i = 0; i < 5; i++){
		cout << "자연수를 입력해주세요 : ";
		cin >> input_data;
		NEW_NODE = new List_node(input_data); //새로운 노드를 선언하고.
		if(HEAD == NULL) //만약, HEAD가 가리키는 노드가 없으면,
			HEAD = NEW_NODE; //HEAD는 추가된 노드를 가르킨다.
		else//HEAD가 가리키는 노드가 있으면,
			TAIL -> NEXT_NODE = NEW_NODE; //TAIL이 가리키는 노드(=직전에 추가된 노드)의 NEXT변수가 새로 추가되는 노드를 가리키게 만들고.
		TAIL = NEW_NODE; //TAIL은 새로 추가한 노드를 가리킨다.
	}

	cout<<""<<endl;
	CURSOR = HEAD; //CURSOR는 첫번째 노드를 가리킨다.
	cout<<"1번째 노드에 저장된 데이터: "<<CURSOR->DATA<<endl; //CURSOR이 가리키는 노드에 저장된 데이터값을 출력한다.
	for(int j = 0; j < 4; j++){
		CURSOR = CURSOR -> NEXT_NODE; //CURSOR이 현재 가리키는 노드의 다음 노드를 가리킨다.
		cout<<j+2<<"번째 노드에 저장된 데이터: "<<CURSOR->DATA<<""<<endl; //CURSOR이 가리키는 노드에 저장된 데이터값을 출력한다.
	}

	//할당 해제
	if (HEAD == NULL)
		return 0;
	else{
		List_node *delNode = HEAD; //delNode를 만들고, HEAD를 가르킴.
		List_node *delNextNode = HEAD -> NEXT_NODE;//delNextNode를 만들고, HEAD의 NEXT 변수를 저장함.
		delete(delNode); //delNode에 배정된 Heap 메모리를 할당 해제 함.
		for(int k = 0; k < 4; k++)
		{
			delNode = delNextNode; //delNode는 delNextNode가 가르키는 NEXT 변수가 가르키는 노드를 가르킴.
			delNextNode = delNextNode->NEXT_NODE; //delNextNode는 현재 노드의 NEXT변수를 저장함.
			delete(delNode); ////delNode에 배정된 Heap 메모리를 할당 해제 함.
		}
	}
}