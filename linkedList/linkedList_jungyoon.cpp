/*
file name: linkedList_jungyoon.cpp
created: 2021.01.06
author: jungyoon Kim
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct ListNode{
    char data;
    struct ListNode *link;
} ListNode;

int main(){
    ListNode *pt1, *pt2, *pt3, *pt4; // 노드 할당을 위한 포인터 변수 선언
    ListNode *list;

    // 노드 4개 생성(메모리 할당)
    pt1 = (ListNode *)malloc(sizeof(ListNode));
    pt2 = (ListNode *)malloc(sizeof(ListNode));
    pt3 = (ListNode *)malloc(sizeof(ListNode));
    pt4 = (ListNode *)malloc(sizeof(ListNode));
    
    // 생성된 노드에 데이터 입력
    pt1 -> data = 'D';
    pt1 -> link = NULL;
    pt2 -> data = 'A';
    pt2 -> link = NULL;
    pt3 -> data = 'T';
    pt3 -> link = NULL;
    pt4 -> data = 'A';
    pt4 -> link = NULL;

    // 데이터가 입력된 노드의 상태(독립적)
    cout << "pt1 = " << pt1 << ", pt1 -> data = " << pt1 -> data << ", pt1 -> link = " << pt1 -> link << endl;
    cout << "pt2 = " << pt2 << ", pt2 -> data = " << pt2 -> data << ", pt2 -> link = " << pt2 -> link << endl;
    cout << "pt3 = " << pt3 << ", pt3 -> data = " << pt3 -> data << ", pt3 -> link = " << pt3 -> link << endl;
    cout << "pt4 = " << pt4 << ", pt4 -> data = " << pt4 -> data << ", pt4 -> link = " << pt4 -> link << endl;
    cout << endl;

    // 노드 연결
    pt1 -> link = pt2;
    pt2 -> link = pt3;
    pt3 -> link = pt4;

    // 연결된 노드의 상태
    cout << "pt1 = " << pt1 << ", pt1 -> data = " << pt1 -> data << ", pt1 -> link = " << pt1 -> link << endl;
    cout << "pt2 = " << pt2 << ", pt2 -> data = " << pt2 -> data << ", pt2 -> link = " << pt2 -> link << endl;
    cout << "pt3 = " << pt3 << ", pt3 -> data = " << pt3 -> data << ", pt3 -> link = " << pt3 -> link << endl;
    cout << "pt4 = " << pt4 << ", pt4 -> data = " << pt4 -> data << ", pt4 -> link = " << pt4 -> link << endl;
    cout << endl;

    // 연결한 데이터 최종본 출력
    list = pt1;
    while(list != NULL){
        cout << list -> data;
        list = list -> link;
    }
    cout << endl;

    // 노드 반환
    free(pt1);
    free(pt2);
    free(pt3);
    free(pt4);

    return 0;
}