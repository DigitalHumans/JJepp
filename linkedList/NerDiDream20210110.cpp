// made by NerDiDream
// made at 2021/01/10
// file name NerDiDream20210110.cpp

#include <iostream>
using namespace std;


struct Node
{
private: //마음대로 수정하지 말라고.
	int inner_data;
	Node* next_ptr;
	Node* prev_ptr;
public:
	const int& data = inner_data; //변경 불가능한 읽기 전용.
	Node(int init) : inner_data(init), next_ptr(nullptr), prev_ptr(nullptr){}
	Node(int init, Node* p) : inner_data(init), next_ptr(nullptr), prev_ptr(p)
	{
		if (prev_ptr != nullptr)
		{
			prev_ptr->set_next(this);
		}
	}
	Node(int init, Node* p, Node* n) : inner_data(init), prev_ptr(p), next_ptr(n) //새로운 노드의 초기값, prevptr, nextptr 설정
	{
		if (prev_ptr != nullptr)
		{
			prev_ptr->set_next(this); //새로운 노드의 이전 노드의 다음 노드를 새로운 노드로 설정.
		}
		if (next_ptr != nullptr)
		{
			next_ptr->set_prev(this); //새로운 노드의 다음 노드의 이전 노드를 새로운 노드로 설정.
		}
	}
	void set_next(Node* n)
	{
		next_ptr = n;
	}
	void set_prev(Node* p)
	{
		prev_ptr = p;
	}
	Node* next() { return next_ptr; }
	Node* prev() { return prev_ptr; }
	~Node()
	{
		if (next_ptr != nullptr)
		{
			next_ptr->set_prev(prev_ptr);
		}
		if (prev_ptr != nullptr)
		{
			prev_ptr->set_next(next_ptr);
		}
	}
};

class List
{
private:
	Node* head;
	Node* current;
	Node* tail;
	int node_length;
	bool goto_index(int index)
	{
		if ((index < 0) || (index >= node_length))
			return false;
		current = head;
		for (int i = 0; i < index; i++)
		{
			current = current->next();
		}
		return true;
	}
public:
	const int& length = node_length;
	List() : head(nullptr), current(nullptr), tail(nullptr), node_length(0){}
	List(int init) : node_length(1)
	{
		head = tail = current = new Node(init);
	}
	const int& operator[] (int index)
	{
		if (!goto_index(index))
			return 0;
		return current->data;
	}
	bool append_at(int index, int data)
	{
		if (index == 0)
		{
			current = head;
			head = new Node(data, nullptr, current);
			if (tail == nullptr)
			{
				current = tail = head;
			}
			++node_length;
			return true;
		}
		if (!goto_index(index - 1))
		{
			return false;
		}
		if (current == tail)
		{
			tail = new Node(data, current);
		}
		else
		{
			new Node(data, current, current->next());
		}
		++node_length;
		return true;
	}
	const int remove_at(int index)
	{
		if (!goto_index(index))
		{
			return 0;
		}
		if (index == 0)
		{
			head = current->next();
		}
		if (index == length - 1)
		{
			tail = current->prev();
		}
		const int retval{ current->data };
		delete current;
		--node_length;
		current = head;
		return retval;
	}
	~List()
	{
		if (goto_index(0))
		{
			while (current->next() != nullptr)
			{
				current->next()->~Node(); // 노드 삭제 (허용은 되지만...)
			}
			delete current; // 노드 삭제
		}
	}
};

int main()
{
	List a(13);
	a.append_at(1, 37);
	cout << a[0] << endl;
}
