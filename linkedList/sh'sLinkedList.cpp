/*
 * file name : sh'sLinkedList.cpp
 * created   : 2021-01-05
 * modified  : 2021-01-05
 * author    : ksoonhyung
 */

#include <iostream>

using namespace std;

class Node
{
    int  value{};        //링크드리스트의 요소 값
    Node *next_node{};  //다음 링크드리스트 요소를 가리키는 포인터

public:
    void append(int value);              //링크드리스트의 마지막에 요소를 추가
    void change(int index, int value);   //링크드리스트의 특정 요소의 값 수정
    Node *insert(int index, int value);   //링크드리스트의 특정 위치에 요소 추가
    void remove(int index);              //링크드리스트의 특정 요소 삭제
    int  getValue(int index);            //링크드리스트의 특정 요소 값 리턴
    void printList();                    //링크드리스트 순서대로 출력
};

int main()
{
    int *p(0);
    cout << p << endl;
}

void Node::append(int value)              //링크드리스트의 마지막에 요소를 추가
{
    Node *p = this;                     //리스트 탐색에 사용할 포인터
    for(int i=0; ;i++)
    {
        if(p->next_node == 0)           //다음 노드가 없으면, p는 리스트의 끝을 가리킨다.
        {
            Node *tmp = new Node;       //새로운 노드 생성
            tmp->value = value;         //새 노드에 parameter 로 받은 값 입력
            p->next_node = tmp;         //새로 만든 노드와 리스트의 끝을 연결
            break;
        }
        p = p->next_node;               //루프 시 다음 노드로 넘어간다.
    }
}
void Node::change(int index, int value)   //링크드리스트의 특정 요소의 값 수정
{
    Node *p = this;                     //리스트 탐색에 사용할 포인터
    for(int i=0; ;i++)
    {
        if(i == index)           //인덱스에 해당하는 노드를 찾으면
        {
            p->value = value;    //값 change
            break;
        }
        p = p->next_node;               //루프 시 다음 노드로 넘어간다.        
    }
}

Node *Node::insert(int index, int value)   //링크드리스트의 특정 위치에 요소 추가
{
    Node *p = this;                     //리스트 탐색에 사용할 포인터
    if(index = 0)                       //첫 노드 위치에 값을 추가하려면,
    {
        Node *tmp      = new Node;      //새로운 노드 생성
        tmp->value     = value;         //새 노드에 parameter 로 받은 값 입력
        tmp->next_node = this;          //새 노드와 원래 첫 노드 연결
        return;
    }
    for(int i=0; ;i++)
    {
        if(i == index-1)           //인덱스 바로 앞 노드를 찾으면
        {
            Node *tmp      = new Node;      //새로운 노드 생성
            tmp->value     = value;         //새 노드에 parameter 로 받은 값 입력
            tmp->next_node = p->next_node;  //새 노드와 다음 노드 연결
            p->next_node   = tmp;           //이전 노드와 새 노드 연결            
            break;
        }
        else if(p->nest_node == 0) break;   //지정한 인덱스가 리스트보다 길면 종료
        p = p->next_node;               //루프 시 다음 노드로 넘어간다.        
    }
}

void Node::remove(int index)              //링크드리스트의 특정 요소 삭제
{

}
int  Node::getValue(int index);            //링크드리스트의 특정 요소 값 리턴
void Node::printList();                    //링크드리스트 순서대로 출력