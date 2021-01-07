/* File name: LJLeeLinkedList.cpp
 * Created Date: 6th Jan. 2021
 * Last Modified: 6th Jan. 2021
 * Description: A simple Double Linked List example code
 * License: JJe++ License(See Announcement)
 * */
// headers
#include <iostream>
#include <exception>
using namespace std;

//data types

class Node
{
private:
    int inner_data;
    Node* next_node;
    Node* prev_node;
public:
    const int& data = inner_data;
    Node(int init):inner_data(init), next_node(nullptr), prev_node(nullptr){}
    Node(int init, Node* p):inner_data(init), next_node(nullptr), prev_node(p)
    {
        if (prev_node != nullptr)
            prev_node->set_next(this);
    }
    Node(int init, Node*p, Node*n):inner_data(init), next_node(n), prev_node(p)
    {
        if (prev_node != nullptr)
            prev_node->set_next(this);
        if (next_node != nullptr)
            next_node->set_prev(this);
    }
    inline void set_prev(Node* p)
    {
        prev_node = p;
    }
    inline void set_next(Node* n)
    {
        next_node = n;
    }
    void map_prev(Node* p)
    {
        set_prev(p);
        if (prev_node != nullptr)
            prev_node->set_next(this);
    }
    void map_next(Node* n)
    {
        set_next(n);
        if (next_node != nullptr)
            next_node->set_next(this);
    }
    ~Node()
    {
        if (prev_node != nullptr)
            prev_node->set_next(next_node);
        if (next_node != nullptr)
            next_node->set_prev(prev_node);
    }
    Node* next(){return next_node;}
    Node* prev(){return prev_node;}
};

class DoubleList
{
private:
    Node* head, *tail;
    Node* current;
    long long length;
    bool goto_index(long long i)
    {
        if ((i < length - 1) || (i < 0))
            return false;
        current = head;
        while(i > 0)
            current = current->next();
        return true;
    }
public:
    DoubleList():
        head(nullptr), tail(nullptr), current(nullptr), length(0)
    {}
    DoubleList(int init):
        length(1)
    {
        head = new Node(init);
        tail = current = head;
    }
    const int& operator[](long long i)
    {
        if (!goto_index(i))
            throw exception();
        return current->data;
    }
    void append(const int& data)
    {
        tail = new Node(data, tail);
        if (length == 0)
            head = current = tail;
        ++length;
    }
    bool insert(long long i, const int& data)
    {
        if (i == 0)
            current = head = new Node(data, nullptr, head);
        else if(goto_index(i))
            current = new Node(data, current->prev(), current);
        else
            return false;
        ++length;
        return true;
    }
    const int remove_at(long long i)
    {
        if (!goto_index(i))
            throw exception();
        auto retval = current->data;
        if (current == head)
            head = current->next();
        if (current == tail)
            tail = current->prev();
        --length;
        delete current;
        return retval;
    }
    ~DoubleList()
    {
        if (goto_index(0))
        {
            while(current->next()!= nullptr)
                delete current->next();
            delete current;
        }
    }
};
int main()
{
    cout << "Double linked list" << endl;
    DoubleList dlist(13);
    dlist.append(37);
    dlist.insert(1, 59);
    dlist.remove_at(1);
    return 0;
}
