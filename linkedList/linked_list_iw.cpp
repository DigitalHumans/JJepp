#include <iostream>

using namespace std;

private class linked_list
{
    private struct node* head_pointer;//시작점 주소
    long length  

    void linked_list()//컨스트럭터, 초기화 하기  
    {
        head_pointer = new struct node();
    }

    void linked_list(struct node address)//컨스트럭터, 초기화 하기  
    {
        head_pointer = address;
    }

    struct node* search(long serial_num)
    {
        if(serial_num<=0 || serial_num > length)
        {
            cout<<"invalid access : serial_number is out of range"<<endl;
            return 0;
        }

        
        return ;
    }

    void get_ptr()
    {
        
    }


    void add()
    {
        temp_node_previous = get_ptr(length);
        //get ptr of last node.
        struct node* temp_node = new struct node();
        struct node* temp_node_previous = ptr_previous;
        //make 2 temporary spaces
        
        //get pointer of previous node
        (*temp_node).ptr_previous = temp_node_previous; 
        (*temp_node).ptr_next = NULL;
        (*temp_node).serial_num = length+1
        //linking and set serial_num
        (*temp_node_previous).ptr_next = temp_node;
    }

    void add(string push_pop)
    {
        if(push_pop == "PUSH")
        {

        }
        if(push_pop == "POP")
        {

        }
    }

    void add(long serial_num)
    {
        
    }

    void subtract()
    {
        struct node* temp_node = get_ptr(length);
        struct node* temp_node_previous = ptr_previous;
        (*temp_node).
    }

    void dump(long serial_num)
    {
        if(serial_num<=0 || serial_num > length)
        {
            cout<<"invalid access : serial_number is out of range"<<endl;
            return 0;
        }
        while(serial_num > 0)
    }

    // void dump(long serial_num_1, long serial_num_2)
    // {
    //     if(serial_num<=0 || serial_num > length)
    //     {
    //         cout<<"invalid access : serial_number is out of range"<<endl;
    //         return 0;
    //     }

    //     if(serial_num<=0 || serial_num > length)
    //     {
    //         cout<<"invalid access : serial_number is out of range"<<endl;
    //         return 0;
    //     }
    //     while(serial_num > 0)
    // }

    void destroyer()
    {

    }


}

//리스트 클래스
//노드르 연결 해체 중간 삽입하는 메소드와 자료편집 메소드
//자료를 추출하는 메소드


//
//노드에는 메모리 절약을 위해 데이터의 공간만 담는다. 메소드는 담지 않는다.


struct example_data//data 의 형태나 종류만 편집하면  node에 다른 종류의 데이터도 담을 수 있음
{
    string str;
    long num;
}

//동적할당으로 데이터의 종류를 바꾸면 좋을 듯

struct node 
{
    long serial_num;
    struct node* ptr_previous = NULL;
    struct node* ptr_next = NULL;
    struct example_data data;
}


