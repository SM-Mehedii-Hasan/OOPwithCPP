#include <iostream>
using namespace std;

class DynamicArray
{
    int s;   // size
    int cap; // capacity
    int *arr;

public:
    DynamicArray()
    {
        s = 0;
        cap = 1;
        arr = new int[cap];
    }

    void add(int element)
    {
        if (s == cap)
        {
            cap *= 2;
            int *arr2 = new int[cap];
            for (int i = 0; i < s; i++)
                arr2[i] = arr[i];
            delete[] arr;
            arr = arr2;
        }
        arr[s++] = element;
    }

    void remove()
    {
        if (s > 0)
        {
            s--;
            if (s > 0 && s <= cap / 2)
            {
                cap /= 2;
                if (cap < 1)
                    cap = 1;
                int *arr2 = new int[cap];
                for (int i = 0; i < s; i++)
                    arr2[i] = arr[i];
                delete[] arr;
                arr = arr2;
            }
        }
    }

    void print()
    {
        for (int i = 0; i < s; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    int capacity() { return cap; }
    int size() { return s; }

    ~DynamicArray()
    {
        delete[] arr;
    }
};

int main()
{
    DynamicArray d;
    cout << d.size() << " " << d.capacity() << endl;
    d.add(1);
    cout << d.size() << " " << d.capacity() << endl;
    d.add(2);
    cout << d.size() << " " << d.capacity() << endl;
    d.add(3);
    cout << d.size() << " " << d.capacity() << endl;
    d.add(4);
    cout << d.size() << " " << d.capacity() << endl;
    d.add(5);
    cout << d.size() << " " << d.capacity() << endl;
    d.print();
    d.remove();
    cout << d.size() << " " << d.capacity() << endl;
    d.remove();
    cout << d.size() << " " << d.capacity() << endl;
    d.remove();
    cout << d.size() << " " << d.capacity() << endl;
    d.remove();
    cout << d.size() << " " << d.capacity() << endl;
}
