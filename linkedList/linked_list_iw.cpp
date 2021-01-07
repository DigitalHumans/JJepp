#include <iostream>

using namespace std;

//리스트 클래스
//노드르 연결 해체 중간 삽입하는 메소드와 자료편집 메소드
//자료를 추출하는 메소드


//
//노드에는 메모리 절약을 위해 데이터의 공간만 담는다. 메소드는 담지 않는다.





class example_data//data 의 형태나 종류만 편집하면  node에 다른 종류의 데이터도 담을 수 있음
{
    private:
    string str = "초기값";
    int num = 777;
    
    public:
    void dump()//string str, long num)//static 접근제어자를 이용하지 않아도 힘수가 차지하는 공간은 4byte 포인터로 일정한가??
    {
        cout<<example_data::str<<endl;
        cout<<example_data::num<<endl;
    }
    void get_property()
    {
        int number_of_elements = 2;
        cout<<"property_of_this_data"<<endl;
        cout<<"number_of_elements : "<<number_of_elements<<endl;
        cout<<"elements_1    type : "<<typeid(str).name()<<endl;
        cout<<"elements_1    data : "<<str<<endl;
        cout<<"elements_2    type : "<<typeid(num).name()<<endl;
        cout<<"elements_2    data : "<<num<<endl;
    }
    //http://www.tcpschool.com/cpp/cpp_template_function
    //템플릿에 관한 부분

   template <typename T>//템플릿의 적용범위는 정확히 어디까지지??// 바로 아래 함수까지 만이라고 합니다.
    void edit_data(int element_number, T input)
    {
        
        switch(element_number)
        {
            case 0:
            cout<<"자료변경 메소드 분기 0 시작"<<endl;
            str = input;

            break;
            case 1:
            cout<<"자료변경 메소드 분기 1 시작"<<endl;
            
            num = (long) input;
            
            break;
            default:
            cout<<"invalid access : element_number is out of range"<<endl;
        }
    }
};
// class example_data_test//data 의 형태나 종류만 편집하면  node에 다른 종류의 데이터도 담을 수 있음
// {
//     private:
//     string str = "초기값";
//     long num = 777;
// };
//동적할당으로 데이터의 종류를 바꾸면 좋을 듯

struct node 
{
    long serial_num;
    struct node* ptr_previous = NULL;
    struct node* ptr_next = NULL;
    class example_data data;
};

class linked_list
{
    public://테스트후 private로 바꾸기
    struct node* head_pointer = NULL;//시작점 주소          //private를 구현해야 함 // 길이가 0 인경우 NULL
    struct node* tail_pointer = NULL;//끝점 주소            //private를 구현해야 함 // 길이가 0 인경우 NULL 
    long length = -1;//최초 리스트의 초기값은 -1로 한다.     //private를 구현해야 함 
    long serial = -1;
    public:
    linked_list()//컨스트럭터, 길이가 0인 리스트로 초기화 하기  
    {
        length = 0;// 길이가 0인 리스트 객체의 head
        serial = 0;
    }

    // linked_list(struct node* head_address, struct node* tail_address)//컨스트럭터, 초기화 하기  
    // {
    //     length = 0;
    //     head_pointer = head_address;
    //     tail_pointer = tail_address;
    // }

    linked_list(long input_length)//컨스트럭터, 초기화 하기  
    {
        length = 0;//(=//this();   //?)
        serial = 0;
        cout<<"생성자 호출 완료"<<endl;
        // head_pointer = new struct node();
        add(input_length);
        cout<<"생성자 동작 완료"<<endl;
    }
    
    long get_length()
    {
        return length;
    }

    void add(long number_of_elements)
    {
        long i = 0;
        while(i < number_of_elements)
        {
        cout<<"add 호출 완료"<<endl;
        struct node* temp_node = NULL;
        struct node* temp_node_previous = NULL;
        //make 2 temporary spaces
        temp_node_previous = tail_pointer;//get ptr of previous node(=last node). tail_pointer: had been initialized to NULL;
        cout<<"add 초기화 완료"<<endl;
        if(head_pointer == NULL)
        {
            head_pointer = new struct node();
            cout<<"add 분기1 완료"<<endl;
            temp_node = head_pointer;
        }
        else
        {
            temp_node = new struct node();
            cout<<"add 분기2 완료"<<endl;
            (*temp_node_previous).ptr_next = temp_node;
        }
        cout<<"add 노드할당 완료"<<endl;
        (*temp_node).ptr_previous = temp_node_previous;
        (*temp_node).ptr_next = NULL;
        (*temp_node).serial_num = serial++;//management length
        cout<<"add 노드연결 및 순번매기기 완료"<<endl;
        //linking and set serial_num
        tail_pointer = temp_node;
        cout<<"add 꼬리노드 대입연산 완료"<<endl;

        length++;
        i++;
        }
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
        length--;//management length
        delete temp_node;
    }

    void subtract(long serial_num)
    {    
        

        struct node* temp_node = search(serial_num);
        struct node* temp_node_previous = (*temp_node).ptr_previous;
        struct node* temp_node_next = (*temp_node).ptr_next;
        
        length--;//management length
        
        cout<<"subtract 초기화 완료"<<endl;
        cout<<(void*)temp_node_previous<<endl;
        cout<<(void*)temp_node_next<<endl;
        

        delete temp_node;

        
        if(temp_node_previous == NULL)
        {
            head_pointer = temp_node_next;
            (*temp_node_next).ptr_previous = (struct node*)temp_node_previous;
            return;
        }
        if(temp_node_next == NULL)
        {
            tail_pointer = temp_node_previous;
            (*temp_node_previous).ptr_next = (struct node*)temp_node_next;
            return;
        }
        (*temp_node_previous).ptr_next = (struct node*)temp_node_next;
        (*temp_node_next).ptr_previous = (struct node*)temp_node_previous;

        cout<<"subtract 삭제후 연결 완료"<<endl;
    }

    void subtract(long serial_num_1, long serial_num_2)
    {

        struct node* temp_node_beginning = NULL;
        struct node* temp_node_end = NULL;

        struct node* node_front_ptr_previous = NULL;
        struct node* node_end_ptr_next = NULL;

        if(serial_num_2 - serial_num_1 == 0)
        {
            cout<<"삭제 구간 분기 확인_0"<<endl;
            subtract(serial_num_1);
            return;
        }


        if(serial_num_2 - serial_num_1 > 0)
        {
            cout<<"삭제 구간 분기 확인_1"<<endl;
            temp_node_beginning = search(serial_num_1);//serial_num_1 이 더 작은 수인 경우
            temp_node_end = search(serial_num_2);
            cout<<"삭제 구간 분기 확인_1 종료"<<endl;
            cout<<endl<<"ptr_next      : "<<(*head_pointer).ptr_next<<endl;
            cout<<endl<<"ptr_previous  : "<<(*head_pointer).ptr_previous<<endl<<endl;
            
        }
        if(serial_num_2 - serial_num_1 < 0)
        {
            cout<<"삭제 구간 분기 확인_2"<<endl;
            temp_node_beginning = search(serial_num_2);//serial_num_2 가 더 작은 수인 경우
            temp_node_end = search(serial_num_1);
            cout<<endl<<"ptr_next      : "<<(*head_pointer).ptr_next<<endl;
            cout<<endl<<"ptr_previous  : "<<(*head_pointer).ptr_previous<<endl<<endl;
        }

        cout<<"------------------------------"<<endl;
        cout<<endl<<"ptr_next       : "<<(*temp_node_beginning).ptr_next<<endl;
        cout<<endl<<"ptr_           : "<<temp_node_beginning<<endl;
        cout<<endl<<"ptr_previous   : "<<(*temp_node_beginning).ptr_previous<<endl<<endl;
        cout<<endl<<"ptr_next       : "<<(*temp_node_end).ptr_next<<endl;
        cout<<endl<<"ptr_           : "<<temp_node_end<<endl;
        cout<<endl<<"ptr_previous   : "<<(*temp_node_end).ptr_previous<<endl<<endl;
        cout<<"------------------------------"<<endl;

        node_front_ptr_previous = (*temp_node_beginning).ptr_previous;
        node_end_ptr_next = (*temp_node_end).ptr_next;
        
        cout<<"------------------------------"<<endl;
        // cout<<endl<<"ptr_next       : "<<(*node_front_ptr_previous).ptr_next<<endl;
        // cout<<endl<<"ptr_           : "<<node_front_ptr_previous<<endl;
        // cout<<endl<<"ptr_previous   : "<<(*node_front_ptr_previous).ptr_previous<<endl<<endl;
        // cout<<endl<<"ptr_next       : "<<(*node_end_ptr_next).ptr_next<<endl;
        // cout<<endl<<"ptr_           : "<<node_end_ptr_next<<endl;
        // cout<<endl<<"ptr_previous   : "<<(*node_end_ptr_next).ptr_previous<<endl<<endl;
        cout<<"------------------------------"<<endl;

        struct node* temp_1 = temp_node_beginning;

        struct node* temp_2 = temp_node_end;

        // (*temp_1).ptr_previous == NULL;
        // (*temp_2).ptr_next == NULL;//비교연산한 실-수 박제.....이걸로 몇시간 태움....

        (*temp_1).ptr_previous = NULL;
        (*temp_2).ptr_next = NULL;//



        while(temp_1 != NULL)//맨 뒤 부터 중간까지 지워나갈 때 중단하지 못 하는 오류 발견...?
        {
            cout<<endl<<"ptr_next       : "<<(*temp_1).ptr_next<<endl;
            cout<<endl<<"ptr_           : "<<temp_1<<endl;
            cout<<endl<<"ptr_previous   : "<<(*temp_1).ptr_previous<<endl<<endl;
            // cout<<"삭제 내용 확인 시작"<<endl;
            // (*temp_2).data.dump();
            // cout<<"삭제 내용 확인 종료"<<endl;
            temp_1 = (*temp_2).ptr_previous; 
            delete temp_2;
            length--;
            temp_2 = temp_1;
        }   
        
        if(node_front_ptr_previous == NULL && node_end_ptr_next != NULL)//head_pointer가 삭제 및 재설정되는 상황
        {
            cout<<"삭제 분기 확인_1"<<endl;
            head_pointer = node_end_ptr_next;
            (*head_pointer).ptr_previous = NULL;
        }
        if(node_front_ptr_previous != NULL && node_end_ptr_next == NULL)//tail_pointer가 삭제 및 재설정되는 상황
        {
            
            cout<<"삭제 분기 확인_2"<<endl;
            cout<<endl<<"ptr_next      : "<<(*head_pointer).ptr_next<<endl;
            cout<<endl<<"ptr_previous  : "<<(*tail_pointer).ptr_previous<<endl<<endl;
            tail_pointer = node_front_ptr_previous;
            (*tail_pointer).ptr_next = NULL;
            cout<<endl<<"ptr_next      : "<<(*head_pointer).ptr_next<<endl;
            cout<<endl<<"ptr_previous  : "<<(*tail_pointer).ptr_previous<<endl<<endl;
        }
        if(node_front_ptr_previous == NULL && node_end_ptr_next == NULL)//head_pointer 와 tail_pointer가 모두 삭제 및 NULL로 재설정되는 상황//전체삭제의 경우
        {
            cout<<"삭제 분기 확인_3"<<endl;
            head_pointer = NULL;
            tail_pointer = NULL;
        }
        if(node_front_ptr_previous != NULL && node_end_ptr_next != NULL)//리스트의 중간 부분이 삭제되어 연결이 재설정되는 상황//중간삭제의 경우
        {
            cout<<"삭제 분기 확인_3"<<endl;
            (*node_front_ptr_previous).ptr_next = node_end_ptr_next;
            (*node_end_ptr_next).ptr_previous = node_front_ptr_previous;
        }


        
           
    }
    
    void insert(long gap_num)
    {
        //일련 번호 관리 필요
        if(gap_num<0 || gap_num > length)
        {
            cout<<"insert place have to be not seprerate"<<endl;
            return;
        }
        long gap_num_1 = gap_num-1;
        long gap_num_2 = gap_num;


        struct node* temp_front = search(gap_num_1);
        struct node* new_temp_node = new struct node();
        struct node* temp_near = search(gap_num_2);

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
            (*temp_near).ptr_next = new_temp_node;
        }
        else
        {
            tail_pointer = new_temp_node;
        }
    } 
    void insert(long gap_num, int number_of_elements)
    {
        //일련 번호 관리 필요
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

        struct node* gap_temp_front = search(gap_num_1);
        struct node* gap_temp_near = search(gap_num_2);

        struct node* new_node_front = NULL;
        struct node* new_node_near = NULL;

        struct node* new_node_temp_past = NULL;
        struct node* new_node_temp_future = NULL;        

        new_node_temp_future = new struct node();

        new_node_front = new_node_temp_future;//set front point

        new_node_temp_past = new_node_temp_future;//start point will be 'past' in next process relatively
        number_of_elements--;//situation of number_of_elements < 0 had been already filtered upon If-Branch

        while(number_of_elements > 0)
        {
            new_node_temp_future = new struct node();
            (*new_node_temp_future).ptr_previous = new_node_temp_past;
            (*new_node_temp_past).ptr_next = new_node_temp_future;
            new_node_temp_past = new_node_temp_future;
            number_of_elements--;
        }

        new_node_near = new_node_temp_past;//set near point


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
            (*gap_temp_near).ptr_next = new_node_near;
        }
        else
        {
            tail_pointer = new_node_near;
        }
    }    

     struct node* search(long serial_num)
    {
        struct node* temp_1 = head_pointer;
        struct node* temp_2 = tail_pointer;
        cout<<"head_pointer : "<<head_pointer<<endl;
        cout<<"tail_pointer : "<<tail_pointer<<endl;
        cout<<"serial_num   : "<<serial_num<<endl;
        cout<<"length       : "<<length<<endl;
        int i = 0;
        cout<<"search 초기화 완료"<<endl;
        if(serial_num<0 || serial_num > length-1)
        {
            cout<<"invalid access : serial_number is out of range-----"<<endl;
            return NULL;
        }
        if(serial_num <= (length/2))
        {
            cout<<"search 분기1 시작"<<endl;
            while(i < serial_num)
            {
                temp_2 = (*temp_1).ptr_next; 
                temp_1 = temp_2;
                i++;
            }
            return temp_1;
        }
        if(serial_num > (length/2))
        {
            cout<<"search 분기2 시작"<<endl;
            i = length-1;
            while(i > serial_num)
            {
                temp_1 = (*temp_2).ptr_previous; 
                cout<<"search 분기2.1 시작"<<endl;
                temp_2 = temp_1;
                cout<<"search 분기2.2 시작"<<endl;
                i--;
            }
            return temp_2;
        }
        cout<<"search 분기3(나머지)"<<endl;
        return NULL;
    }

    // void get_ptr()
    // {
        
    // }// 이미 search 함수에서 포인터를 반환 하고 있음 
    template <typename T>
    int change(long serial_num, int element_number, T input)
    {
        struct node* temp = search(serial_num);
        (*temp).data.edit_data(element_number, input);
    }


    void dump(long serial_num)
    {
        cout<<"덤핑 시작"<<endl;        
        struct node* temp_1 = head_pointer;
        struct node* temp_2 = tail_pointer;

        if(serial_num<=0 || serial_num > length-1)
        {
            cout<<"invalid access : serial_number is out of range"<<endl;
            return;
        }
            int i = 0;
            while(i < serial_num)
            {
                (*temp_1).data.dump();
                temp_2 = (*temp_1).ptr_next; 
                temp_1 = temp_2;
                i++;
            }
            cout<<"덤핑 완료"<<endl;
        return;
    }

    void dump_all()
    {
        cout<<"덤핑 시작"<<endl;        
        struct node* temp_1 = head_pointer;
        struct node* temp_2 = tail_pointer;

        while(temp_2 != NULL)
            {
                (*temp_1).data.dump();
                temp_2 = (*temp_1).ptr_next; 
                temp_1 = temp_2;
            }
        cout<<"덤핑 완료"<<endl;
        return;
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
        cout<<"소멸자 호출 완료"<<endl;
        // while(head_pointer != NULL)
        // {
        //     struct node* temp_node = tail_pointer;
        //     struct node* temp_node_previous = (*temp_node).ptr_previous;

        //     (*temp_node_previous).ptr_next = NULL;
        //     tail_pointer = temp_node_previous;

        //     delete temp_node;
        // }

        struct node* temp_1 = head_pointer;
        struct node* temp_2 = tail_pointer;

        while(temp_1 != NULL)
        {
            // (*temp_2).data.dump();
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
    linked_list list_1(3);
    list_1.add(7);
    cout<<"생성완료"<<endl;
    linked_list list_2();
    cout<<"생성완료"<<endl;
    // struct node* COUT_TEMP = list_1.search(3);
    // cout<<endl<<"head           : "<<(*COUT_TEMP).serial_num<<endl;
    // cout<<endl<<"tail           : "<<list_1.tail_pointer<<endl<<endl;

    cout<<"삭제 전 길이 확인_2"<<endl;
    cout<<list_1.get_length()<<endl;
    list_1.subtract(5, 9);//마지막 요소를 삭제 했을때 메모리 누출에러
    cout<<"삭제 후 길이 확인_2"<<endl;
    cout<<list_1.get_length()<<endl;
    list_1.dump_all();
    cout<<"전체 덤핑 출력_3"<<endl;


    return 0;
}


//소멸자 애러 해결 완료
