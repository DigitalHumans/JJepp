/*
 * file name : linked_list_template_4release2_iw.cpp
 * created   : 2021-01-09
 * modified  : 2021-01-09
 * author    : iw (sangwoo kim)
 */


#include <iostream>
#include <string>
#include <cstring>

using namespace std;

template <typename T>
class standard_data//data 의 형태나 종류만 편집하면  node에 다른 종류의 데이터도 담을 수 있음
{
    private:
    T value;

    int number_of_elements = 1;
    
    public:
    void dump()//string str, long num)//static 접근제어자를 이용하지 않아도 힘수가 차지하는 공간은 4byte 포인터로 일정한가??
    {
        cout<<value<<endl;
    }
    void get_property()
    {
        cout<<"property_of_this_data"<<endl;
        cout<<"number_of_elements : "<<number_of_elements<<endl;
        cout<<"elements_1    type : "<<typeid(value).name()<<endl;
        cout<<"elements_1    data : "<<value<<endl;
    }

    int get_elements_N()
    {
        return number_of_elements;
    }
    
    T get_data_0()
    {
        return value;
    }
    
    //http://www.tcpschool.com/cpp/cpp_template_function
    //템플릿에 관한 부분
    void edit_data(int element_number, T input)
    {
        
        switch(element_number)
        {
            case 0:
            value = input;
            break;
            default:
            cout<<"invalid access : element_number is out of range"<<endl;
        }
        return;
    }
};


class example_data//data 의 형태나 종류만 편집하면  node에 다른 종류의 데이터도 담을 수 있음
{
    private:
    string str = "초기값";
    int num = 777;
    
    int number_of_elements = 2;

    public:
    void dump()//string str, long num)//static 접근제어자를 이용하지 않아도 힘수가 차지하는 공간은 4byte 포인터로 일정한가??
    {
        cout<<example_data::str<<endl;
        cout<<example_data::num<<endl;
    }
    void get_property()
    {
        
        cout<<"property_of_this_data"<<endl;
        cout<<"number_of_elements : "<<number_of_elements<<endl;
        cout<<"elements_1    type : "<<typeid(str).name()<<endl;
        cout<<"elements_1    data : "<<str<<endl;
        cout<<"elements_2    type : "<<typeid(num).name()<<endl;
        cout<<"elements_2    data : "<<num<<endl;
    }
    int get_elements_N()
    {
        return number_of_elements;
    }
    
    const char* get_data_0()
    {
        return str.c_str();
    }
    int get_data_1()
    {
        return num;  
    }
    
    //http://www.tcpschool.com/cpp/cpp_template_function
    //템플릿에 관한 부분
    template <typename T>//템플릿의 적용범위는 정확히 어디까지지??// 바로 아래 함수까지 만이라고 합니다.
    void edit_data(int element_number, T input)
    {
        switch(element_number)
        {
            case 0:
            str = input;
            break;
            case 1:
            num = (long) input;
            break;
            default:
            cout<<"invalid access : element_number is out of range"<<endl;
        }
        return;
    }
};

template <typename T>
struct node 
{
    long serial_num;
    struct node* ptr_previous = NULL;
    struct node* ptr_next = NULL;
    class standard_data<T> data;
};

template <> struct node <example_data>
{
    long serial_num;
    struct node* ptr_previous = NULL;
    struct node* ptr_next = NULL;
    class example_data data;
};

template <typename T>
class linked_list
{
    private://테스트후 private로 바꾸기
    struct node<T>* head_pointer = NULL;//시작점 주소          //private를 구현해야 함 // 길이가 0 인경우 NULL
    struct node<T>* tail_pointer = NULL;//끝점 주소            //private를 구현해야 함 // 길이가 0 인경우 NULL 
    long length = -1;//최초 리스트의 초기값은 -1로 한다.     //private를 구현해야 함 
    long serial = -1;
    public:
    linked_list()//컨스트럭터, 길이가 0인 리스트로 초기화 하기  
    {
        length = 0;// 길이가 0인 리스트 객체의 head
        serial = 0;
    }

    linked_list(long input_length)//컨스트럭터, 초기화 하기  
    {
        length = 0;//(=//this();   //?)
        serial = 0;
        add(input_length);
    }
    
    long get_length()
    {
        return length;
    }

    void add()
    {
        add(1);
    }

    void add(long number_of_elements)
    {
        long i = 0;
        while(i < number_of_elements)
        {
        struct node<T>* temp_node = NULL;
        struct node<T>* temp_node_previous = NULL;
        //make 2 temporary spaces
        temp_node_previous = tail_pointer;//get ptr of previous node(=last node). tail_pointer: had been initialized to NULL;
        
        if(head_pointer == NULL)
        {
            head_pointer = new struct node<T>();
            temp_node = head_pointer;
        }
        else
        {
            temp_node = new struct node<T>();
            (*temp_node_previous).ptr_next = temp_node;
        }

        (*temp_node).ptr_previous = temp_node_previous;
        (*temp_node).ptr_next = NULL;
        (*temp_node).serial_num = serial++;//management length

        tail_pointer = temp_node;

        length++;
        i++;
        }
    }

    void substrct()
    {
        struct node<T>* temp_node = tail_pointer;
        struct node<T>* temp_node_previous = (*temp_node).ptr_previous;

        (*temp_node_previous).ptr_next = NULL;
        tail_pointer = temp_node_previous;
        length--;//management length
        delete temp_node;
    }

    void erase()
    {
        substrct();
    }

    void erase(long index)
    {    
        struct node<T>* temp_node = search_ptr(index);
        struct node<T>* temp_node_previous = (*temp_node).ptr_previous;
        struct node<T>* temp_node_next = (*temp_node).ptr_next;
        
        length--;//management length

        delete temp_node;

        if(temp_node_previous == NULL)
        {
            head_pointer = temp_node_next;
            (*temp_node_next).ptr_previous = (struct node<T>*)temp_node_previous;
            return;
        }
        if(temp_node_next == NULL)
        {
            tail_pointer = temp_node_previous;
            (*temp_node_previous).ptr_next = (struct node<T>*)temp_node_next;
            return;
        }
        (*temp_node_previous).ptr_next = (struct node<T>*)temp_node_next;
        (*temp_node_next).ptr_previous = (struct node<T>*)temp_node_previous;
    }

    void erase(long index_1, long index_2)
    {
        struct node<T>* temp_node_beginning = NULL;
        struct node<T>* temp_node_end = NULL;

        struct node<T>* node_front_ptr_previous = NULL;
        struct node<T>* node_end_ptr_next = NULL;

        if(index_2 - index_1 == 0)
        {
            erase(index_1);
            return;
        }


        if(index_2 - index_1 > 0)
        {
            temp_node_beginning = search_ptr(index_1);//index_1 이 더 작은 수인 경우
            temp_node_end = search_ptr(index_2);
        }
        if(index_2 - index_1 < 0)
        {
            temp_node_beginning = search_ptr(index_2);//index_2 가 더 작은 수인 경우
            temp_node_end = search_ptr(index_1);

        }

        node_front_ptr_previous = (*temp_node_beginning).ptr_previous;
        node_end_ptr_next = (*temp_node_end).ptr_next;

        struct node<T>* temp_1 = temp_node_beginning;
        struct node<T>* temp_2 = temp_node_end;

        (*temp_1).ptr_previous = NULL;
        (*temp_2).ptr_next = NULL;//



        while(temp_1 != NULL)//맨 뒤 부터 중간까지 지워나갈 때 중단하지 못 하는 오류 발견...?
        {
            temp_1 = (*temp_2).ptr_previous; 
            delete temp_2;
            length--;
            temp_2 = temp_1;
        }   
        
        if(node_front_ptr_previous == NULL && node_end_ptr_next != NULL)//head_pointer가 삭제 및 재설정되는 상황
        {
            head_pointer = node_end_ptr_next;
            (*head_pointer).ptr_previous = NULL;
        }
        if(node_front_ptr_previous != NULL && node_end_ptr_next == NULL)//tail_pointer가 삭제 및 재설정되는 상황
        {
            tail_pointer = node_front_ptr_previous;
            (*tail_pointer).ptr_next = NULL;
        }
        if(node_front_ptr_previous == NULL && node_end_ptr_next == NULL)//head_pointer 와 tail_pointer가 모두 삭제 및 NULL로 재설정되는 상황//전체삭제의 경우
        {
            head_pointer = NULL;
            tail_pointer = NULL;
        }
        if(node_front_ptr_previous != NULL && node_end_ptr_next != NULL)//리스트의 중간 부분이 삭제되어 연결이 재설정되는 상황//중간삭제의 경우
        {
            (*node_front_ptr_previous).ptr_next = node_end_ptr_next;
            (*node_end_ptr_next).ptr_previous = node_front_ptr_previous;
        }
    }
    
    void insert()
    {
        add();
    }

    void insert(long gap_num)
    {
        if(gap_num<0 || gap_num > length)
        {
            cout<<"insert place have to be not seprerate"<<endl;
            return;
        }

        long gap_num_1 = gap_num-1;
        long gap_num_2 = gap_num;

        struct node<T>* temp_front = search_ptr(gap_num_1);
        struct node<T>* new_temp_node = new struct node<T>();
        struct node<T>* temp_near = search_ptr(gap_num_2);
        length++;

        (*new_temp_node).serial_num = serial++;
        (*new_temp_node).ptr_previous = temp_front;
        (*new_temp_node).ptr_next = temp_near;

        if(temp_front != NULL)
        {
            (*temp_front).ptr_next = new_temp_node;
        }
        else
        {
            head_pointer = new_temp_node;
        }
        if(temp_near != NULL)
        {
            (*temp_near).ptr_previous = new_temp_node;
        }
        else
        {
            tail_pointer = new_temp_node;
        }
    } 
    void insert(long gap_num, int number_of_elements)
    {
        if(gap_num<0 || gap_num > length)
        {
            cout<<"insert place have to be not seprerate"<<endl;
            return;
        }
        if(number_of_elements < 0)
        {
            cout<<"do performace nothig"<<endl;
            return;
        }

        long gap_num_1 = gap_num-1;
        long gap_num_2 = gap_num;

        struct node<T>* gap_temp_front = search_ptr(gap_num_1);
        struct node<T>* gap_temp_near = search_ptr(gap_num_2);

        struct node<T>* new_node_front = NULL;
        struct node<T>* new_node_near = NULL;

        struct node<T>* new_node_temp_past = NULL;
        struct node<T>* new_node_temp_future = NULL;        

        new_node_temp_future = new struct node<T>();
        length++;//management length
        (*new_node_temp_future).serial_num = serial++;
        new_node_front = new_node_temp_future;//set front point

        new_node_temp_past = new_node_temp_future;//start point will be 'past' in next process relatively
        number_of_elements--;//situation of number_of_elements < 0 had been already filtered upon If-Branch

        while(number_of_elements > 0)
        {
            new_node_temp_future = new struct node<T>();
            length++;//management length
            (*new_node_temp_future).serial_num = serial++;
            (*new_node_temp_future).ptr_previous = new_node_temp_past;
            (*new_node_temp_past).ptr_next = new_node_temp_future;
            new_node_temp_past = new_node_temp_future;
            number_of_elements--;
        }

        new_node_near = new_node_temp_past;

        (*new_node_front).ptr_previous = gap_temp_front;
        (*new_node_near).ptr_next = gap_temp_near;

        if(gap_temp_front != NULL)
        {
            (*gap_temp_front).ptr_next = new_node_front;
        }
        else
        {
            head_pointer = new_node_front;
        }
        if(gap_temp_near != NULL)
        {
            (*gap_temp_near).ptr_previous = new_node_near;
        }
        else
        {
            tail_pointer = new_node_near;
        }
    }    

    struct node<T>* search_ptr(long index)//반환형 점검하기********************************************
    {
        struct node<T>* temp_1 = head_pointer;
        struct node<T>* temp_2 = tail_pointer;
        int i = 0;
        if(index<0 || index > length-1)
        {
            cout<<"invalid access : index is out of range-----"<<endl;
            return NULL;
        }
        if(index <= (length/2))
        {
            while(i < index)
            {
                temp_2 = (*temp_1).ptr_next; 
                temp_1 = temp_2;
                i++;
            }
            return temp_1;
        }
        if(index > (length/2))
        {
            i = length-1;
            while(i > index)
            {
                temp_1 = (*temp_2).ptr_previous; 
                temp_2 = temp_1;
                i--;
            }
            return temp_2;
        }
        return NULL;
    }

    template <typename k>
    void change(long index, int element_number, k input)
    {
        struct node<T>* temp = search_ptr(index);
        (*temp).data.edit_data(element_number, input);
        return;
    }

    struct node<T>& search_ref(long index)//작동여부가 정확한지 확인 받아보기
    {
        struct node<T>* temp = search_ptr(index);
        return (*temp);//굉장히 위험한 코드//반드시 참조자로 변환할 것.
    }


    void dump(long index)
    {
        cout<<"덤핑 시작"<<endl;        
        struct node<T>* temp_1 = head_pointer;
        struct node<T>* temp_2 = tail_pointer;

        if(index<0 || index > length-1)
        {
            cout<<"invalid access : index is out of range"<<endl;
            return;
        }
            int i = 0;
            while(i < index)
            {
                (*temp_1).data.dump();
                temp_2 = (*temp_1).ptr_next; 
                temp_1 = temp_2;
                i++;
            }
            cout<<"----------"<<endl<<"덤핑 완료"<<endl;
        return;
    }

    
    void dump(long index_1, long index_2)
    {
        if(index_1<0 || index_1 > length-1 || index_2<0 || index_2 > length-1)
        {
            cout<<"invalid access : serial_number is out of range"<<endl;
            return;
        }

        if(index_2 - index_1 == 0)
        {
            (*search_ptr(index_1)).data.dump();
            return;
        }

        struct node<T>* temp_node_beginning = NULL;
        struct node<T>* temp_node_end = NULL;

        temp_node_beginning = search_ptr(index_1);
        temp_node_end = search_ptr(index_2);

        struct node<T>* temp_1 = temp_node_beginning;
        struct node<T>* temp_2 = temp_node_end;
        if(index_2 - index_1 > 0)//순행
        {
            while(temp_1 != temp_node_end)
            {
                (*temp_1).data.dump();
                temp_2 = (*temp_1).ptr_next; 
                temp_1 = temp_2;
            }   
            (*temp_node_end).data.dump();
        }
        if(index_2 - index_1 < 0)//역행
        {
            while(temp_1 != temp_node_end)
            {
                (*temp_1).data.dump();
                temp_2 = (*temp_1).ptr_previous; 
                temp_1 = temp_2;
            }   
            (*temp_node_end).data.dump();
        }
    }

    void dump_serial_num(long index_1, long index_2)
    {
        if(index_1<0 || index_1 > length-1 || index_2<0 || index_2 > length-1)
        {
            cout<<"invalid access : serial_number is out of range"<<endl;
            return;
        }

        if(index_2 - index_1 == 0)
        {
            (*search_ptr(index_1)).data.dump();
            return;
        }

        struct node<T>* temp_node_beginning = NULL;
        struct node<T>* temp_node_end = NULL;

        temp_node_beginning = search_ptr(index_1);
        temp_node_end = search_ptr(index_2);

        struct node<T>* temp_1 = temp_node_beginning;
        struct node<T>* temp_2 = temp_node_end;
        if(index_2 - index_1 > 0)//순행
        {
            while(temp_1 != temp_node_end)
            {
                cout<<"---<"<<(*temp_1).serial_num<<">---"<<endl;
                (*temp_1).data.dump();
                temp_2 = (*temp_1).ptr_next; 
                temp_1 = temp_2;
            }   
            cout<<"---<"<<(*temp_node_end).serial_num<<">---"<<endl;
            (*temp_node_end).data.dump();
            cout<<"----------"<<endl<<"덤핑 완료"<<endl;
        }
        if(index_2 - index_1 < 0)//역행
        {
            while(temp_1 != temp_node_end)
            {
                cout<<"---<"<<(*temp_1).serial_num<<">---"<<endl;
                (*temp_1).data.dump();
                temp_2 = (*temp_1).ptr_previous; 
                temp_1 = temp_2;
            }   
            cout<<"---<"<<(*temp_node_end).serial_num<<">---"<<endl;
            (*temp_node_end).data.dump();
            cout<<"----------"<<endl<<"덤핑 완료"<<endl;
        }
    }

    void dump_all()
    {
        cout<<"덤핑 시작"<<endl;        
        struct node<T>* temp_1 = head_pointer;
        struct node<T>* temp_2 = tail_pointer;

        while(temp_2 != NULL)
            {
                (*temp_1).data.dump();
                temp_2 = (*temp_1).ptr_next; 
                temp_1 = temp_2;
            }
        cout<<"----------"<<endl<<"덤핑 완료"<<endl;
        return;
    }


    void dump_all_serial_num()
    {
        cout<<"덤핑 시작"<<endl;        
        struct node<T>* temp_1 = head_pointer;
        struct node<T>* temp_2 = tail_pointer;

        while(temp_2 != NULL)
            {
                cout<<"---<"<<(*temp_1).serial_num<<">---"<<endl;
                (*temp_1).data.dump();
                temp_2 = (*temp_1).ptr_next; 
                temp_1 = temp_2;
            }
        cout<<"----------"<<endl<<"덤핑 완료"<<endl;
        return;
    }


    void serial_num_init()
    {
        serial = 0;
        struct node<T>* temp_1 = head_pointer;
        struct node<T>* temp_2 = tail_pointer;

        while(temp_2 != NULL)
            {
                (*temp_1).serial_num = serial;
                temp_2 = (*temp_1).ptr_next; 
                temp_1 = temp_2;
                serial++;
            }
        cout<<"complete init serial number"<<endl;
        return;
    }

    void clear()
    {
        serial = 0;
        struct node<T>* temp_1 = head_pointer;
        struct node<T>* temp_2 = tail_pointer;

        while(temp_2 != NULL)
            {
                // memset(arr1, 'c', 5 * sizeof(char));
                // 출처: https://blockdmask.tistory.com/441 [개발자 지망생]
                memset((&(*temp_1).data), 0, sizeof((*temp_1).data));
                temp_2 = (*temp_1).ptr_next; 
                temp_1 = temp_2;
                serial++;
            }
        cout<<"complete init data"<<endl;
        return;
    }

    void help()
    {
        cout<<"----------<HELP>----------"<<endl;
        cout<<"<list_class>"<<endl;
        cout<<""<<endl;
        cout<<"-CREATE-"<<endl;
        cout<<""<<endl;
        cout<<"linked_list<T> LIST_NAME();                      : create T type list without node"<<endl;
        cout<<"linked_list LIST_NAME();                         : create list without node"<<endl;
        cout<<"linked_list LIST_NAME(NUM);                      : create list with NUM of node"<<endl;
        cout<<"T                                                : INPUT type for tamplate : It is provided basic type and user-def type('example_data' is already include for user-def)"<<endl;
        cout<<""<<endl;
        cout<<"-USE-"<<endl;
        cout<<""<<endl;
        cout<<"▷ GENERAL"<<endl;
        cout<<""<<endl;
        cout<<"LIST_NAME.help();                                : show help list"<<endl;
        cout<<""<<endl;
        cout<<"▶ NODE_management"<<endl;
        cout<<""<<endl;
        cout<<"LIST_NAME.get_length()                           : return length"<<endl;
        cout<<"LIST_NAME.add()                                  : add a node as last node"<<endl;
        cout<<"LIST_NAME.add(NUM)                               : add NUM of nodes as last node"<<endl;
        cout<<"LIST_NAME.substract()                            : erease last node"<<endl;
        cout<<"LIST_NAME.erease()                               : == substract"<<endl;
        cout<<"LIST_NAME.erease(INDEX)                          : erease a node of index"<<endl;
        cout<<"LIST_NAME.erease(INDEX_1, INDEX_2)               : erease nodes of range INDEX_1 to INDEX_2"<<endl;
        cout<<"LIST_NAME.insert()                               : == add"<<endl;
        cout<<"LIST_NAME.insert(INDEX)                          : insert new a node that node have index as INDEX"<<endl;
        cout<<"LIST_NAME.insert(INDEX, NUM)                     : insert new NUM of nodes from INDEX"<<endl;
        cout<<"LIST_NAME.search_ptr(INDEX)                      : return <struct node*> of INEDX"<<endl;
        cout<<"LIST_NAME.search_ref(INDEX)                      : retuen <struct node&> of INEDX"<<endl;
        cout<<"LIST_NAME.serial_num_init()                      : reset and redefine serial number of nodes 0 to length-1"<<endl;
        cout<<""<<endl;
        cout<<"▷ DATA_management"<<endl;
        cout<<""<<endl;
        cout<<"LISTNAME.dump(INDEX)                             : out-put data of nodes, untill reach INDEX of node from first node"<<endl;
        cout<<"LISTNAME.dump(INDEX_1, INDEX_2)                  : out-put data of nodes, untill reach INDEX_2 of node from INDEX_1"<<endl;
        cout<<"LISTNAME.dump_serial_num(INDEX_1, INDEX_2)       : out-put serial_number and data of nodes, untill reach INDEX_2 of node from INDEX_1"<<endl;
        cout<<"LISTNAME.dump_all()                              : out-put data of nodes untill reach last node from first node"<<endl;
        cout<<"LISTNAME.dump_all_serial_num()                   : dump_all data with serial_number"<<endl;
        cout<<"LISTNAME.change(INDEX, NUM, INPUT)               : edit INDEX_node data of <NUM>-th as INPUT"<<endl;
        cout<<""<<endl;
        cout<<"▶ DATA_use_member_function"<<endl;
        cout<<""<<endl;
        cout<<"LISTNAME.search_ref(INDEX).data.get_elements_N() : show number of elements in data "<<endl;
        cout<<"LISTNAME.search_ref(INDEX).data.get_property()   : show instruction for property of data "<<endl;
        cout<<"LISTNAME.search_ref(INDEX).data.get_data_NUM()   : return INDEX_node data of <NUM>-th as OUTPUT"<<endl;
        cout<<""<<endl;
        cout<<"----------<HELP>----------"<<endl;
        cout<<""<<endl;
    }

    ~linked_list()
    {
        cout<<"소멸자 호출 완료"<<endl;

        struct node<T>* temp_1 = head_pointer;
        struct node<T>* temp_2 = tail_pointer;

        while(temp_1 != NULL)
        {
            temp_1 = (*temp_2).ptr_previous; 
            delete temp_2;
            temp_2 = temp_1;
        }
        cout<<"소멸자 동작 완료"<<endl;
        return;
        
    }


};




int main()
{

    linked_list<example_data> list_1(3);//사용자 정의타입 사용
    list_1.add(7);
    cout<<"생성완료"<<endl;

    linked_list<int> list_2(3);// 기본 타입 사용
    list_2.add(7);
    cout<<"생성완료"<<endl;

    list_1.help();
    cout<<list_1.get_length()<<endl;
    list_1.dump_all();
    list_1.dump_all_serial_num();
    list_1.clear();
    list_1.dump_all_serial_num();

    list_1.change(0, 0, "가족");
    list_1.change(2, 0, "사랑");
    list_1.change(2, 1, 486);
    list_1.change(3, 0, "천사");
    list_1.change(3, 1, 1004);
    list_1.change(7, 0, "무관심");
    list_1.change(7, 1, 104+97+116+101);
    list_1.change(8, 1, 7942);
    list_1.change(9, 0, "미움");
    list_1.dump_all_serial_num();
    list_1.erase();
    list_1.dump_all_serial_num();
    list_1.erase(7);
    list_1.dump_all_serial_num();
    list_1.erase(4, 6);
    list_1.dump_all_serial_num();
    list_1.serial_num_init();
    list_1.dump_all_serial_num();
    list_1.insert(0);
    list_1.dump_all_serial_num();
    list_1.insert(2, 5);
    list_1.dump_all_serial_num();
    list_1.serial_num_init();
    list_1.dump_all_serial_num();
    cout<<list_1.search_ref(8).data.get_data_0()<<endl;
    cout<<list_1.search_ref(8).data.get_data_1()<<endl;

    cout<<""<<endl;
    cout<<"길이 확인"<<endl;
    cout<<list_1.get_length()<<endl;

    list_1.erase(0);
    list_1.erase(1, 6);
    list_1.serial_num_init();
    list_1.dump_all_serial_num();
    list_1.dump(2, 1);
    cout<<"출력 확인"<<endl;
    list_1.dump_all_serial_num();
    cout<<"출력 확인"<<endl;
    list_1.dump_serial_num(1, 2);
    list_1.dump_serial_num(2, 1);

    cout<<list_1.search_ref(2).data.get_data_0()<<endl;
    cout<<list_1.search_ref(2).data.get_data_1()<<endl;


    cout<<"-------------------------------------------------------------------------------------"<<endl;


    cout<<list_2.get_length()<<endl;
    list_2.dump_all();
    list_2.dump_all_serial_num();
    list_2.clear();
    list_2.dump_all_serial_num();

    list_2.change(2, 0, 486);
    list_2.change(3, 0, 1004);
    list_2.change(4, 0, 271828182845);
    list_2.change(5, 0, 7942);
    list_2.change(6, 0, 31415926545);

    list_2.dump_all_serial_num();
    list_2.erase();
    list_2.dump_all_serial_num();
    list_2.erase(7);
    list_2.dump_all_serial_num();
    list_2.erase(4, 6);
    list_2.dump_all_serial_num();
    list_2.serial_num_init();
    list_2.dump_all_serial_num();
    list_2.insert(0);
    list_2.dump_all_serial_num();
    list_2.insert(2, 5);
    list_2.dump_all_serial_num();
    list_2.serial_num_init();
    list_2.dump_all_serial_num();
    cout<<list_2.search_ref(8).data.get_data_0()<<endl;

    cout<<""<<endl;
    cout<<"길이 확인"<<endl;
    cout<<list_2.get_length()<<endl;

    list_2.erase(0);
    list_2.erase(1, 6);
    list_2.serial_num_init();
    list_2.dump_all_serial_num();
    list_2.dump(2, 1);
    cout<<"출력 확인"<<endl;
    list_2.dump_all_serial_num();
    cout<<"출력 확인"<<endl;
    list_2.dump_serial_num(1, 2);
    list_2.dump_serial_num(2, 1);

    cout<<list_2.search_ref(2).data.get_data_0()<<endl;

    return 0;
}

// ----------<HELP>----------
// <list_class>

// -CREATE-

// linked_list<T> LIST_NAME();                      : create T type list without node
// linked_list LIST_NAME();                         : create list without node
// linked_list LIST_NAME(NUM);                      : create list with NUM of node
// T                                                : INPUT type for tamplate : It is provided basic type and user-def type('example_data' is already include for user-def)

// -USE-

// ▷ GENERAL

// LIST_NAME.help();                                : show help list

// ▶ NODE_management

// LIST_NAME.get_length()                           : return length
// LIST_NAME.add()                                  : add a node as last node
// LIST_NAME.add(NUM)                               : add NUM of nodes as last node
// LIST_NAME.substract()                            : erease last node
// LIST_NAME.erease()                               : == substract
// LIST_NAME.erease(INDEX)                          : erease a node of index
// LIST_NAME.erease(INDEX_1, INDEX_2)               : erease nodes of range INDEX_1 to INDEX_2
// LIST_NAME.insert()                               : == add
// LIST_NAME.insert(INDEX)                          : insert new a node that node have index as INDEX
// LIST_NAME.insert(INDEX, NUM)                     : insert new NUM of nodes from INDEX
// LIST_NAME.search_ptr(INDEX)                      : return <struct node*> of INEDX
// LIST_NAME.search_ref(INDEX)                      : retuen <struct node&> of INEDX
// LIST_NAME.serial_num_init()                      : reset and redefine serial number of nodes 0 to length-1

// ▷ DATA_management

// LISTNAME.dump(INDEX)                             : out-put data of nodes, untill reach INDEX of node from first node
// LISTNAME.dump(INDEX_1, INDEX_2)                  : out-put data of nodes, untill reach INDEX_2 of node from INDEX_1
// LISTNAME.dump_serial_num(INDEX_1, INDEX_2)       : out-put serial_number and data of nodes, untill reach INDEX_2 of node from INDEX_1
// LISTNAME.dump_all()                              : out-put data of nodes untill reach last node from first node
// LISTNAME.dump_all_serial_num()                   : dump_all data with serial_number
// LISTNAME.change(INDEX, NUM, INPUT)               : edit INDEX_node data of <NUM>-th as INPUT

// ▶ DATA_use_member_function

// LISTNAME.search_ref(INDEX).data.get_elements_N() : show number of elements in data 
// LISTNAME.search_ref(INDEX).data.get_property()   : show instruction for property of data 
// LISTNAME.search_ref(INDEX).data.get_data_NUM()   : return INDEX_node data of <NUM>-th as OUTPUT

// ----------<HELP>----------
