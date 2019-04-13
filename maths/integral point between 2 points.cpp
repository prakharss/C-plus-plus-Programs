//https://math.stackexchange.com/questions/918362/what-is-the-number-of-integer-coordinates-on-a-line-segment //imp to understand

// C++ code to find the number of integral points
// lying on the line joining the two given points
#include <iostream>
#include <cmath>
using namespace std;
 
// Class to represent an Integral point on XY plane.
class Point
{
public:
    int x, y;
    Point(int a=0, int b=0):x(a),y(b) {}
};
 
// Utility function to find GCD of two numbers
// GCD of a and b
int gcd(int a, int b)
{
    if (b == 0)
       return a;
    return gcd(b, a%b);
}
 
// Finds the no. of Integral points between
// two given points.
int getCount(Point p, Point q)
{
    // If line joining p and q is parallel to
    // x axis, then count is difference of y
    // values
    if (p.x==q.x)
        return abs(p.y - q.y) - 1;
 
    // If line joining p and q is parallel to
    // y axis, then count is difference of x
    // values
    if (p.y == q.y)
        return abs(p.x-q.x) - 1;
 
    return gcd(abs(p.x-q.x), abs(p.y-q.y))-1;
}
 
// Driver program to test above
int main()
{
    Point p(1, 9);
    Point q(8, 16);
 
    cout << "The number of integral points between "
         << "(" << p.x << ", " << p.y << ") and ("
         << q.x << ", " << q.y << ") is "
         << getCount(p, q);
 
    return 0;
}
