#ifndef LINKED_LIST_H
#define LINKED_LIST_H
template <typename T>
class List
{
	struct Node
	{
		T data;
		Node* next;
		Node* prev;
	
		Node(T data) : data{data}, next{nullptr}, prev{nullptr} {}
		Node() : next{nullptr}, prev{nullptr} {}

	};
public:
	List() : head{nullptr}, tail{nullptr} {}
	~List()
	{
		Node* tmp = nullptr;
		while(head)
		{	
			Node* tmp = head;
			head = head -> next;
			delete tmp;
		}
		head = nullptr;	
	}

	void insertFront(T val)
	{
		Node* newNode = new Node(val);
		if(head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode -> next = head;
			head = newNode;
			newNode -> next -> prev = newNode;
			
		}
	}
	void insertBack(T val)
	{
		Node* newNode = new Node(val);
		if(tail -> next == nullptr)
		{
			tail -> next = newNode;
			tail = newNode;
		}
	
	}
	void del(T val)
	{
		Node* node = findNode(val);
		node -> prev -> next = node -> next;
		node -> next -> prev = node -> prev;
		delete node;
	}
	template <typename U>
	friend std::ostream& operator<<(std::ostream& stream, const List<U>& prnt)
	{
		prnt.print();
		return stream;
	}
	
private:
	
	Node* head;
	Node* tail;
	Node* findNode(T val)
	{
		Node* tmp = head;
		while(tmp)
		{
			if(tmp -> data == val)
				return tmp;
			tmp = tmp -> next;

		}
		std::cerr << "No element with data " << val << std::endl;
		return nullptr;
	}
	void print() const
        {
                Node* current = head;
                while(current != nullptr)
                {
                        std::cout << current -> data << " ";
                        current = current -> next;
                }
        }


};




#endif
