// File: binaryOperator
// Created by Garrett Van Dyke on 10/10/2017 for CS1410.
// Copyright (c) 2017 WSU
#include <iostream>
using namespace std;

// Constants, Classes, Structures
class Distance
{
private:
    int feet;
    float inches;
public:
    Distance() : feet(0), inches (0.0)      // constructor no arguments
    {};
    Distance(int f, float i)                // constructor with two arguments
    {
        feet = f;
        inches = i;
    };

    void getdist()                          // get length for user
    {
        cout << "\nEnter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }

    void showdist()                         // display distance
    {
        cout << feet << "\'-" << inches << "\"";
    }

    Distance operator +(Distance) const;    // add 2 distances
    void operator +=(Distance);             // add one distance
};
Distance Distance::operator +(Distance d2) const
{
    int f = feet + d2.feet;
    float i = inches + d2.inches;
    if(i >= 12.0)
    {
        i -= 12.0;
        f++;
    }

    return Distance(f, i);
}
void Distance::operator +=(Distance d2)     // add one distance to an existing one
{
    feet += d2.feet;
    inches += d2.inches;
    if(inches >= 12.0)
    {
        inches -= 12.0;
        feet++;
    }
}

// Prototypes


// Main Program
int main()
{
    Distance d1, d3;
    Distance d2(11, 6.25);

    d1.getdist();
    cout << "Distance d1 = ";
    d1.showdist();
    cout << endl;

    cout << "Distance d2 = ";
    d2.showdist();
    cout << endl;

    d3 = d1 + d2;
    cout << "Distance d3 = ";
    d3.showdist();
    cout << endl;

    d2 += d3;
    cout << "Distance d2 = ";
    d2.showdist();
    cout << endl;

    return 0;
}

// Function Definitions