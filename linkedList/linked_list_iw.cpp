#include <iostream>

using namespace std;

//리스트 클래스
//노드르 연결 해체 중간 삽입하는 메소드와 자료편집 메소드
//자료를 추출하는 메소드


//
//노드에는 메모리 절약을 위해 데이터의 공간만 담는다. 메소드는 담지 않는다.


struct example_data//data 의 형태나 종류만 편집하면  node에 다른 종류의 데이터도 담을 수 있음
{
    string str;
    long num;
};

//동적할당으로 데이터의 종류를 바꾸면 좋을 듯

struct node 
{
    long serial_num;
    struct node* ptr_previous = NULL;
    struct node* ptr_next = NULL;
    struct example_data data;
};

class linked_list
{
    struct node* head_pointer;//시작점 주소    //private를 구현해야 함
    struct node* tail_pointer;//끝점 주소      //private를 구현해야 함
    long length;                                //private를 구현해야 함

    linked_list()//컨스트럭터, 초기화 하기  
    {
        head_pointer = new struct node();
    }

    linked_list(struct node* address)//컨스트럭터, 초기화 하기  
    {
        head_pointer = address;
    }

    linked_list(long input_length)//컨스트럭터, 초기화 하기  
    {
        head_pointer = new struct node();
        for(int i = 0; i < input_length; i++)
        {
            add();
        }
    }

    struct node* search(long serial_num)
    {
        struct node* temp_1 = head_pointer;
        struct node* temp_2 = tail_pointer;

        int i = 1;

        if(serial_num<=0 || serial_num > length)
        {
            cout<<"invalid access : serial_number is out of range"<<endl;
            return NULL;
        }
        if(serial_num <= (length/2))
        {
            while(i < serial_num)
            {
                temp_2 = (*temp_2).ptr_next; 
                temp_1 = temp_2;
                i++;
            }
            return temp_1;
        }
        if(serial_num > (length/2))
        {
            i = length;
            while(i >= serial_num+1)
            {
                temp_1 = (*temp_2).ptr_previous; 
                temp_2 = temp_1;
                i++;
            }
            return temp_2;
        }
        return NULL;
    }

    // void get_ptr()
    // {
        
    // }// 이미 search 함수에서 포인터를 반환 하고 있음 


    void add()
    {
        struct node* temp_node = NULL;
        struct node* temp_node_previous = NULL:
        //make 2 temporary spaces

        if(head_pointer == NULL)
        {
            head_pointer == new struct node();
            
        }
        
        temp_node = new struct node();
        temp_node_previous = tail_pointer;//get ptr of last node.
        //make 2 temporary spaces
        
        //get pointer of previous node
        (*temp_node).ptr_previous = temp_node_previous; 
        (*temp_node).ptr_next = NULL;
        (*temp_node).serial_num = length+1;
        //linking and set serial_num
        (*temp_node_previous).ptr_next = temp_node;
    }

    // void add(string push_pop)
    // {
    //     if(push_pop == "PUSH")
    //     {

    //     }
    //     if(push_pop == "POP")
    //     {

    //     }
    // }

    // void add(long serial_num)
    // {
        
    // }

    void subtract()
    {
        struct node* temp_node = tail_pointer;
        struct node* temp_node_previous = (*temp_node).ptr_previous;

        (*temp_node_previous).ptr_next = NULL;
        tail_pointer = temp_node_previous;

        delete temp_node;
    }
    
    void dump(long serial_num)
    {
        if(serial_num<=0 || serial_num > length)
        {
            cout<<"invalid access : serial_number is out of range"<<endl;
            return;
        }
        while(serial_num > 0)
        {

        }
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

    ~linked_list()
    {
        while(head_pointer !=NULL)
        {
            struct node* temp_node = tail_pointer;
            struct node* temp_node_previous = (*temp_node).ptr_previous;

            (*temp_node_previous).ptr_next = NULL;
            tail_pointer = temp_node_previous;

            delete temp_node;
        }
    }


};




int main()
{

    return 0;
}