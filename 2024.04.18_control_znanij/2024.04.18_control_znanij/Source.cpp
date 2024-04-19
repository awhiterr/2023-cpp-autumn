#include<iostream>

struct Node
{
	int data;
	Node* next;
	Node(int data, Node* next = nullptr) : data(data), next(next) {}
	Node(const Node& node) : data(node.data), next(nullptr) {}
	~Node()
	{
		data = 0;
		next = nullptr;
	}
	friend std::ostream& operator<<(std::ostream& stream, Node*& node)
	{
		stream << node->data << " ";
		return stream;
	}
};

class LinkedList
{
public:
	LinkedList() : head(nullptr) {};
	~LinkedList() { dispose(); }
	int Length();
	bool IsEmpty() { return head == nullptr;}
	void PushHead(int data);

	//вставляет элемент data на позицию index
	void Insert(int index, int data);
	void PushTail(int data);

	//извлекает головной элемент
	int PopHead();

	//извлекает данные из позиции index
	//и удаляет элемент из списка
	int Extract(int index);
	int PopTail();

	//получает данные из позиции index
	//без удаления из списка
	int Data(int index);
	void swap(int ia, int ib);
	void sort();
	//оператор вывода в поток

	friend std::ostream& operator<<(std::ostream& stream, const LinkedList& list);
private:
	void dispose();

	//извлекает данные из ноды и удаляет саму ноду
	int PopData(Node* node);
	void InsertNode(int index, Node* node); 
	Node* ExtractNode(int index); 
	bool IndexValid(int index);
	Node* head;
};

int LinkedList::Length()
{
	int len = 0;
	Node* tmp = head;
	while (tmp != nullptr)
	{
		tmp = tmp->next;
		++len;
	}
	return len;
}

void LinkedList::PushHead(int data)
{
	Node* node = new Node(data, head);
	head = node;
}

void LinkedList::Insert(int index, int data)
{
	if (index == 0)
	{
		return PushHead(data);
	}
	Node* tmp = head;
	for (int i = 0; i < index - 1; i++)
	{
		tmp = tmp->next;
	}
	Node* node = new Node(data, tmp->next);
	tmp->next = node;
	delete tmp;
}

void LinkedList::PushTail(int data)
{
	if (IsEmpty())
	{
		return PushHead(data);
	}

	Node* tmp = head;
	while (tmp->next != nullptr)
	{
		tmp = tmp->next;
	}
	tmp->next = new Node(data);
}

int LinkedList::PopTail()
{
	if (IsEmpty())
	{
		return 0;
	}
	Node* tmp = head;
	for (int i = 0; i < Length(); ++i)
	{
		tmp = tmp->next;
	}

	int res = tmp->data;
	delete tmp;
	return res;
}

int LinkedList::Extract(int index)
{
	if (IsEmpty())
	{
		return -1;
	}

	if (!IndexValid(index))
	{
		return -1;
	}
	Node* tmp = head;
	for (int i = 0; i < index - 1; ++i)
	{
		tmp = tmp->next;
	}
	int res = tmp->next->data;
	Node* res2 = tmp->next->next;
	delete tmp->next;
	tmp->next = res2;
	delete res2;
	return res;
}

int LinkedList::PopHead()
{
	if (IsEmpty())
	{
		return 0;
	}
	Node* tmp = head;
	head = head->next;
	int res = tmp->data;
	delete tmp;
	return res;
}
int LinkedList::Data(int index)
{
	if (!IndexValid(index) || (Length() - 1 < index))
	{
		return -1;
	}
	Node* tmp = head;
	for (int i = 0; i < index; ++i)
	{
		tmp = tmp->next;
	}
	int res = tmp->data;
	return res;
	delete tmp;
}

void LinkedList::swap(int ia, int ib)
{
	if (ia == ib || !IndexValid(ia) || !IndexValid(ib))
	{
		return;
	}
	if (ia > ib)
	{
		return swap(ib, ia);
	}
	Node* nodeb = ExtractNode(ib);
	Node* nodea = ExtractNode(ia);
	InsertNode(ia, nodeb);
	InsertNode(ib, nodea);
}

Node* LinkedList::ExtractNode(int index)
{
	if (!IndexValid(index))
	{
		return nullptr;
	}

	if (index == 0)
	{
		Node* tmp = head;
		head = head->next;
		return tmp;
	}

	if (index < Length())
	{
		Node* tmp = head;
		for (int i = 0; i < index - 1; i++)
		{
			tmp = tmp->next;
		}
		Node* res = tmp->next;
		tmp->next = tmp->next->next;
		return res;
	}

	if (index == Length() - 1)
	{
		Node* tmp = head;
		while (tmp->next->next != nullptr)
		{
			tmp = tmp->next;
		}
		Node* res = tmp->next;
		tmp->next = nullptr;
		return res;
	}
}

void LinkedList::sort()
{
	for (int i = 0; i < Length(); i++)
	{
		for (int j = 0; j < Length() - 1; j++)
		{
			if (Data(j) > Data(j + 1))
			{
				swap(j, j + 1);
			}
		}
	}
}

void LinkedList::dispose()
{
	while (!IsEmpty())
	{
		PopHead();
	}
}

int LinkedList::PopData(Node* node)
{
	int res = 0;
	if (node != nullptr)
	{
		res = node->data;
		delete node;
		node = nullptr;
	}
	return res;
}

void LinkedList::InsertNode(int index, Node* node)
{
	if (index == 0)
	{
		node->next = head;
		head = node;
		return;
	}

	if (!IndexValid(index))
	{
		return;
	}

	if (index == Length())
	{
		Node* tmp = head;
		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
		}
		tmp->next = node;
		return;
	}

	if (index < Length())
	{
		Node* tmp = head;
		for (int i = 0; i < index - 1; i++)
		{
			tmp = tmp->next;
		}
		node->next = tmp->next;
		tmp->next = node;
		return;
	}
}

bool LinkedList::IndexValid(int index)
{
	return (0 <= index && index < Length());
}

std::ostream& operator<<(std::ostream& stream, const LinkedList& list)
{
	Node* tmp = list.head;
	while (tmp != nullptr)
	{
		stream << tmp << " ";
		tmp = tmp->next;
	}
	return stream;
}

int main(int argc, char* argv[])
{
	LinkedList list;
	std::cout << list << std::endl;
	list.PushHead(1);
	std::cout << list << std::endl;
	list.PushTail(3);
	std::cout << list << std::endl;
	list.Insert(1, 2);
	std::cout << list << std::endl;
	list.Insert(3, 4);
	std::cout << list << std::endl << std::endl;
	std::cout << list << std::endl;
	std::cout << list.PopHead() << " ";
	std::cout << list.Extract(1) << " ";
	std::cout << list.PopTail() << " ";
	std::cout << list.Extract(0) << std::endl;
	std::cout << list << std::endl << std::endl;

	list.PushHead(3); list.PushHead(4); list.PushHead(1); list.PushHead(2);
	list.PushHead(7); list.PushHead(5); list.PushHead(8); list.PushHead(6);
	std::cout << list << std::endl;
	list.sort();
	std::cout << list << std::endl;
	return EXIT_SUCCESS;
}