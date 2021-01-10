/*
file name : 210106_m_linkedList
author : kimminju
created : 2021/01/10
*/

/*
linked list : 프로그래밍에서 쓰이는 자료 구조의 일종 / 메모리 공간인 Node에 data, pointer 저장
- Node 들이 한줄로 연결된 방식으로 데이터 저장 
- 자료의 추가, 삭제가 단 시간에 가능 / 배열, 트리에 비해 데이터를 검색하는 시간이 길어짐
- Head : first Node / Tail : last Node / -> : Node를 가리키는 pointer
- 이중 연결리스트 (양방향) / 단일 연결리스트(단방향) / 원형 연결리스트(마지막노드->처음 노드)

Node - data를 저장할 변수 / 다음 node의 address를 저장할 자기참조 구조체 포인터 변수로 구성 
*/

#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    struct Node* next; //선언한 노드 구조체의 주소 저장
} node;

void addNode(node*, int);
void deleteNode(node*);


int main(){
    //노드 생성
    node* head=new node; //헤드 노드를 메모리 동적 할당으로 생성
    head->next=NULL; //헤드 노드는 데이터를 저장하지 않음. 다음 노드는 NULL
    int i, j=0;
    int h, g=0;

    cout<<"Add Node: How many nodes? ";
    cin>>j;

    for(i=0; i<j; i++){
        int num1=0;
        cout<<"Enter num to add:";
        cin>>num1;
        addNode(head, num1);
        //head node와 그 다음 노드 사이에 새로운 node가 생성되므로, 
        //10 20 30 순서로 입력했다면 30 20 10 순으로 출력됨. 
        
    }


    cout<<"del Node: How many nodes? ";
    cin>>g;

    for(h=0; h<g; h++){
        deleteNode(head);
    }

    // 결과 노드 출력 //
    node* curr=head->next; //노드를 스캔할 curr 구조체 포인터에 머리노드가 가리키는 노드의 주소 대입
    while(curr!=NULL){ //curr에 저장된 값이 NULL이 아닐때 반복 (반복 시작)
        cout<<curr->data<<" "; //data 출력
        curr=curr->next; //첫번째로 생성한 노드의 newNode->next는 NULL이므로 반복문 탈출
    }

    delete[]head;
}


void addNode(node* head, int data){
    node* newNode=new node;
    newNode->data=data; //newNode의 data에 data 저장
    newNode->next=head->next; //newNode의 next node는 head node가 가리키던 다음 주소 저장
    head->next=newNode; //head node의 next node는 newNode의 address 저장
    cout<<"Head Node 뒤에 new Node 추가 : "<<data<<endl;

}

void deleteNode(node* head){ //head의 주소만 받음
    node* targetNode=head->next; //삭제할 노드의 주소가 들어갈 임시 변수 targetNode
    head->next=targetNode->next;
    delete[]targetNode; //할당한 targetNode의 메모리 공간을 해제 
    cout<<"Head node 뒤의 노드 삭제"<<endl;

}

