
/*
 * file name : sh'sLinkedList.cpp
 * created   : 2021-01-05
 * modified  : 2021-01-11
 * author    : ksoonhyung
 */

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Node
{
public:
    T    value{};                        //링크드리스트의 요소 값
    Node *next_node{};                   //다음 링크드리스트 요소를 가리키는 포인터
    Node(int value = 0)
    {
        this -> value = value;
    }
};

template <typename T>
void append(Node<T> *list, int value);              //링크드리스트의 마지막에 요소를 추가
template <typename T>
void change(Node<T> *list, int index, int value);   //링크드리스트의 특정 요소의 값 수정
template <typename T>
void insert(Node<T> **list, int index, int value);  //링크드리스트의 특정 위치에 요소 추가
template <typename T>
void remove(Node<T> **list, int index);             //링크드리스트의 특정 요소 삭제
template <typename T>
int  getValue(Node<T> *list, int index);            //링크드리스트의 특정 요소 값 리턴
template <typename T>
void printList(Node<T> *list);                      //링크드리스트 순서대로 출력

int main()
{
    Node<int> *list = new Node<int>(1);           //리스트 생성
    printList(list);                    //{ 1 }

    for(int i=2; i<15; i+=2)            //리스트 값 추가
    {
        append(list, i);
    }
    printList(list);                     //{ 1 2 4 6 8 10 12 14 }

    change(list, 2, 777);                //2 index 값 777 로 변경
    printList(list);                     //{ 1 2 777 6 8 10 12 14 }

    insert(&list,5,666);                 //5 index에 노드 추가
    printList(list);                     //{ 1 2 777 6 8 666 10 12 14 }

    remove(&list,0);                     //0 index 삭제
    printList(list);                     //{ 2 777 6 8 666 10 12 14 }

    cout << getValue(list, 2) << endl;   //777
}

template <typename T>
void append(Node<T> *list, int value)              //링크드리스트의 마지막에 요소를 추가
{
    Node<T> *p = list;                     //리스트 탐색에 사용할 포인터
    for(int i=0; ;i++)
    {
        if(p->next_node == 0)           //다음 노드가 없으면, p는 리스트의 끝을 가리킨다.
        {
            Node<T> *tmp = new Node<T>;       //새로운 노드 생성
            tmp->value = value;         //새 노드에 parameter 로 받은 값 입력
            p->next_node = tmp;         //새로 만든 노드와 리스트의 끝을 연결
            return;
        }
        p = p->next_node;               //루프 시 다음 노드로 넘어간다.
    }
}
template <typename T>
void change(Node<T> *list, int index, int value)   //링크드리스트의 특정 요소의 값 수정
{
    Node<T> *p = list;                     //리스트 탐색에 사용할 포인터
    for(int i=0; ;i++)
    {
        if(i == index)           //인덱스에 해당하는 노드를 찾으면
        {
            p->value = value;    //값 change
            return;
        }
        p = p->next_node;               //루프 시 다음 노드로 넘어간다.        
    }
}
template <typename T>
void insert(Node<T> **list, int index, int value)   //링크드리스트의 특정 위치에 요소 추가
{
    Node<T> *p = *list;                     //리스트 탐색에 사용할 포인터
    if(index == 0)                       //첫 노드 위치에 값을 추가하려면,
    {
        Node<T> *tmp      = new Node<T>;      //새로운 노드 생성
        tmp->value     = value;         //새 노드에 parameter 로 받은 값 입력
        tmp->next_node = *list;          //새 노드와 원래 첫 노드 연결
        *list = tmp;
        return;
    }
    for(int i=0; i<index; i++)
    {
        if(i == index-1)           //인덱스 바로 앞 노드를 찾으면
        {
            Node<T> *pre_tmp = p;              //노드 연결을 위해 추가할 인덱스 전 노드 주소 저장
            p = p->next_node;               //추가할 노드 다음 노드를 가리킴
            Node<T> *tmp = new Node<T>(value);    //추가할 노드 생성
            pre_tmp->next_node = tmp;       //이전 노드와 추가 노드 연결
            tmp->next_node     = p;         //추가 노드와다음 노드 연결
            return;
        }
        else if(p->next_node == 0) return;   //지정한 인덱스가 리스트보다 길면 종료
        p = p->next_node;               //루프 시 다음 노드로 넘어간다.        
    }
}
template <typename T>
void remove(Node<T> **list, int index)              //링크드리스트의 특정 요소 삭제
{
    Node<T> *p = *list;                     //리스트 탐색에 사용할 포인터
    if(index == 0)                       //0번 인덱스 노드를 삭제하려면,
    {
        Node<T> *x_tmp = *list;               //delete를 위해 주소 저장
        *list = p->next_node;          //다음 노드를 첫번째 노드로 설정
        delete x_tmp;                      //삭제할 노드 메모리 반환
        return;
    }
    for(int i=0; i<index; i++)
    {
        if(i == index-1)           //인덱스 바로 앞 노드를 찾으면
        {
            Node<T> *pre_tmp = p;              //노드 연결을 위해 삭제할 인덱스 전 노드 주소 저장
            p = p->next_node;               //삭제할 노드를 가리킴
            Node<T> *x_tmp = p;                //delete를 위해 주소 저장
            p = p->next_node;               //삭제할 노드 다음 노드를 가리킴
            pre_tmp->next_node = p;         //삭제할 노드 앞뒤 노드 연결
            delete x_tmp;                   //삭제할 노드 메모리 반환       
            return;
        }
        else if(p->next_node == 0) return;   //지정한 인덱스가 리스트보다 길면 종료
        p = p->next_node;                    //루프 시 다음 노드로 넘어간다.        
    }
}
template <typename T>
int  getValue(Node<T> *list, int index)         //링크드리스트의 특정 요소 값 리턴
{
    Node<T> *p = list;                          //리스트 탐색에 사용할 포인터
    for(int i=0; i<index; i++)
        p = p->next_node;                    //인덱스 노드까지 탐색
    return p->value;
}
template <typename T>
void printList(Node<T> *list)                   //링크드리스트 순서대로 출력
{
    Node<T> *p = list;                          //리스트 탐색에 사용할 포인터
    cout << "{ ";
    for(int i=0; ;i++)
    {
        cout << p->value << ' ';    //i번째 value 출력
        if(p->next_node == 0) break;
        p = p->next_node;
    }
    cout << "}" << endl;
}