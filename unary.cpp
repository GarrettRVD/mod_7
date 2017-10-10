#include <iostream>
using namespace std;

class Counter
{
private:
    unsigned int count;         // count

public:
    Counter():count(0)          // constructor
    {};

    unsigned int get_count()    // returns count
    {
        return count;
    }

    void operator ++()          // The operator keyword is used to overload the operator in hand
    {
        ++count;                // increment prefix
    }

};

int main()
{
    Counter c1, c2;

    cout << "c1 = " << c1.get_count() << endl;
    cout << "c2 = " << c2.get_count() << endl;

    ++c1;
    ++c2;
    ++c2;
    ++c2;
    ++c2;

    cout << "c1 = " << c1.get_count() << endl;
    cout << "c2 = " << c2.get_count() << endl;
    // c1 = ++2

    return 0;
}