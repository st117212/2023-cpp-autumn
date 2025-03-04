//Задание 2. Итератор для класса list

#include <iostream>
#include <algorithm>
using namespace std;
template <class T>
class List
{
    struct Node
    {
        T data;
        Node* next;
        Node(T d, Node* n = nullptr) : data(d), next(n) {}
    };
    Node* head;
    static Node* copy(Node* x)
    {
        if (x == nullptr) return nullptr;
        Node* y = copy(x->next);
        return new Node(x->data, y);
    }
public:
    List(Node* h = nullptr) : head(h) {}
    List(const List<T>& L) : head(copy(L.head)) {}
    List(List<T>&& L) : head(L.head) { L.head = nullptr; }
    List<T>& operator=(const List<T>& L)
    {
        if (this == &L) return *this;
        del();
        head = copy(L.head);
        return *this;
    }
    List<T>& operator=(List<T>&& L)
    {
        swap(head, L.head);
        return *this;
    }
    void del()
    {
        while (head != nullptr)
        {
            Node* t = head;
            head = head->next;
            delete t;
        }
        head = nullptr;
    }
    void input()
    {
        Node** t = &head;
        T d;
        del();
        int i = 0;
        while (i != 4 && cin >> d)
        {
            *t = new Node(d);
            t = &(*t)->next;
            ++i;
        }
    }
    void output1()
    {
        for (List<T>::iterator i = begin(); i != end(); i++)
            cout << *i << endl;

    }
    void output()
    {
        for (T x : *this)
            cout << x << '\t';
        cout << endl;
    }
    ~List() { del(); }
    class iterator
    {
        Node* p;
        iterator(Node* pp) : p(pp) {}
    public:
        iterator() : p(nullptr) {}
        T& operator * ()
        {
            return p->data;
        }
        T* operator -> ()
        {
            return &(p->data);
        }
        iterator operator ++ ()
        {
            if (p != nullptr)
            {
                p = p->next;
            }

            return *this;
        }
        iterator operator ++ (int)
        {
            iterator temp = *this;
            ++(*this);
            return temp;
        }
        bool operator == (iterator i)
        {
            return p == i.p;
        }
        bool operator != (iterator i)
        {
            return p != i.p;
        }
        friend class List<T>; // List<T> -- друг класса iterator

        // т.е. класс List<T> имеет доступ к закрытым членам
        // класса iterator
    };
    iterator begin() { return head; }
    iterator end() { return nullptr; }
};

int main()
{
    List<int> L;
    L.input();
    L.output();
    L.output1();
    return 0;
}
