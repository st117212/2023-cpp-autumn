#include <iostream>

struct Node
{
    int data;
    Node* next;

    Node() : data(0), next(nullptr)
    {
    }
    Node(int data) : data(data), next(nullptr)
    {
    }
    ~Node()
    {
    }

    friend std::ostream& operator<<(std::ostream& stream, Node& node)
    {
        stream << node.data;
        return stream;
    }
};

class LinkedList {
public:
    LinkedList() : head(nullptr)
    {
    }
    ~LinkedList()
    {
        dispose();
    }

    int Length();
    bool IsEmpty();
    void PushHead(int data);
    void Insert(int index, int data);
    void PushTail(int data);
    int PopHead();
    int Extract(int index);
    int PopTail();
    int Data(int index) const;
    void swap(int ia, int ib);
    void sort();

    friend std::ostream& operator<<(std::ostream& stream, const LinkedList& list)
    {
        Node* current = list.head;
        while (current != nullptr)
        {
            stream << *current << " ";
            current = current->next;
        }
        return stream;
    }

private:
    void dispose();
    bool IndexValid(int index);
    void InsertNode(int index, Node* node);
    int PopData(Node* node);
    Node* ExtractNode(int index);
    Node* head;
};

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

    list.PushHead(3);
    list.PushHead(4);
    list.PushHead(1);
    list.PushHead(2);
    list.PushHead(7);
    list.PushHead(5);
    list.PushHead(8);
    list.PushHead(6);
    std::cout << list << std::endl;
    list.sort();
    std::cout << list << std::endl;
    return EXIT_SUCCESS;
}

int LinkedList::Length()
{
    int count = 0;
    Node* current = head;
    while (current != nullptr)
    {
        ++count;
        current = current->next;
    }
    return count;
}

bool LinkedList::IsEmpty()
{
    return head == nullptr;
}

void LinkedList::PushHead(int data)
{
    Node* node = new Node(data);
    InsertNode(0, node);
}

void LinkedList::Insert(int index, int data)
{
    Node* node = new Node(data);
    InsertNode(index, node);
}

void LinkedList::PushTail(int data)
{
    Node* node = new Node(data);
    InsertNode(Length(), node);
}

int LinkedList::PopHead()
{
    return PopData(ExtractNode(0));
}

int LinkedList::Extract(int index)
{
    return PopData(ExtractNode(index));
}

int LinkedList::PopTail()
{
    return PopData(ExtractNode(Length() - 1));
}

int LinkedList::Data(int index) const
{
    Node* current = head;
    for (int i = 0; i < index && current != nullptr; ++i)
    {
        current = current->next;
    }
    return current != nullptr ? current->data : 0;
}

void LinkedList::swap(int ia, int ib)
{
    if (ia == ib || !IndexValid(ia) || !IndexValid(ib))
    {
        return;
    }
    if (ia > ib)
    {
        std::swap(ia, ib);
    }
    Node* nodeA = ExtractNode(ia);
    Node* nodeB = ExtractNode(ib - 1);
    if (nodeA == nullptr || nodeB == nullptr)
    {
        return;
    }
    InsertNode(ia, nodeB);
    InsertNode(ib, nodeA);
}

void LinkedList::sort()
{
    for (int i = Length() - 1; i >= 0; --i)
    {
        for (int j = 0; j < i; ++j)
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
    while (head != nullptr)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
bool LinkedList::IndexValid(int index)
{
    if (index < 0)
    {
        return false;
    }
    Node* current = head;
    for (int i = 0; i < index && current != nullptr; ++i)
    {
        current = current->next;
    }
    return current != nullptr;
}

Node* LinkedList::ExtractNode(int index)
{
    if (!IndexValid(index))
    {
        return nullptr;
    }
    if (index == 0)
    {
        Node* temp = head;
        head = head->next;
        return temp;
    }
    Node* current = head;
    for (int i = 0; i < index - 1; ++i)
    {
        current = current->next;
    }
    Node* temp = current->next;
    current->next = temp->next;
    return temp;
}

void LinkedList::InsertNode(int index, Node* node)
{
    if (index <= 0 || head == nullptr)
    {
        node->next = head;
        head = node;
    }
    else
    {
        Node* current = head;
        for (int i = 0; i < index - 1 && current->next != nullptr; ++i)
        {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
    }
}

int LinkedList::PopData(Node* node)
{
    if (node == nullptr)
    {
        return 0;
    }
    int res = node->data;
    delete node;
    return res;
}
