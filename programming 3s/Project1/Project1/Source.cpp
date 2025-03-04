//������� 1. �������� ��� �������

#include <iostream>
using namespace std;

struct Point
{
    int x, y;
    Point(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
};
class Vector
{
    Point* p;
    int size;
public:
    Vector() : p(nullptr), size(0) {}
    // ����������� �� ���������
    Vector(int n) // ����������� �� ������ �����
    {
        size = n; // ������ ���� size
        p = new Point[size]; // �������� ������, ������ ���� p
        for (int i = 0; i < size; i++)
            p[i] = Point{};
        // �������������� �������� p[i] �������� ����������
    }
    ~Vector()
    {

        delete[] p; // ������������ ������, ������� ��� ������
        cout << "Destructor" << endl;
        //��������, ��� ���������� ��������
    }
    Point& operator[] (int i) // ���������� �������� []
    {
        static Point c;
        if (i >= 0 && i < size)
            return p[i];
        else
        {
            cout << "����� �� ������� �������" << endl;
            return c;
        }
    }
    void print()
    {
        for (int i = 0; i < size; i++)
            cout << p[i].x << "," << p[i].y << "\t";
        cout << endl;
    }
    void output1()
    {
        for (Vector::iterator i = begin(); i != end(); i++)
            cout << i->x << "," << i->y << '\t';
        cout << endl;
    }
    void output()
    {
        for (Point t : *this)
            cout << t.x << "," << t.y << '\t';
        cout << endl;
    }

    class iterator
    {
        Point* p;
        iterator(Point* pp) : p(pp) {}
    public:
        iterator() : p(nullptr) {}

        Point& operator * ()
        {
            if (p != nullptr)
            {
                return *p;
            }
            exit(1);
        }

        Point* operator -> ()
        {
            if (p != nullptr)
            {
                return p;
            }
            exit(1);
        }

        iterator& operator ++ ()
        {
            ++p;
            return *this;
        }

        iterator operator ++ (int)
        {
            iterator temp = *this;
            ++p;
            return temp;
        }

        iterator& operator -- ()
        {
            --p;
            return *this;
        }

        iterator operator -- (int)
        {
            iterator temp = *this;
            --p;
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

        bool operator < (iterator i)
        {
            return p < i.p;
        }

        bool operator <= (iterator i)
        {
            return p <= i.p;
        }

        bool operator > (iterator i)
        {
            return p > i.p;
        }

        bool operator >= (iterator i)
        {
            return p >= i.p;
        }

        iterator operator + (int n)
        {
            return iterator(p + n);
        }

        iterator operator - (int n)
        {
            return iterator(p - n);
        }

        ptrdiff_t operator - (iterator i)
        {
            return p - i.p;
        }

        friend class Vector;
    };

    iterator begin()
    {
        return iterator(p);
    }

    iterator end()
    {
        return iterator(p + size);
    }

};
int main()
{
    Vector v(5);
    for (int i = 0; i < 5; i++)
        v[i] = Point{ i,i + 1 };
    v.print();
    v.output1();
    v.output();
    return EXIT_SUCCESS;
}
