/*Pick's Theeorem:
 A = I + (B/2) -1

A ==> Area of Polygon
B ==> Number of integral points on edges of polygon
I ==> Number of integral points inside the polygon

Using the above formula, we can deduce,
I = (2A - B + 2) / 2 
We can find A (area of triangle) using below Shoelace formula.

A =  1/2 * abs(x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)) 
How to find B (number of integral points on edges of a triangle)?
We can find the number of integral points between any two vertex (V1, V2) of the triangle using the following algorithm.

1. If the edge formed by joining V1 and V2 is parallel 
   to the X-axis, then the number of integral points 
   between the vertices is : 
        abs(V1.y - V2.y)-1

2. Similarly if edge is parallel to the Y-axis, then 
   the number of integral points in between is :
    abs(V1.x - V2.y)-1

3. Else, we can find the integral points between the
   vertices using below formula:
     GCD(abs(V1.x-V2.x), abs(V1.y-V2.y)) - 1
   The above formula is a well known fact and can be 
   verified using simple geometry. (Hint: Shift the 
   edge such that one of the vertex lies at the Origin.) 

Please refer below link for detailed explanation.
http://www.geeksforgeeks.org/number-integral-points-two-points/

Below is C++ implementation of the above algorithm.
*/
// C++ program to find Integral points inside a triangle
#include<bits/stdc++.h>
using namespace std;
 
// Class to represent an Integral point on XY plane.
class Point
{
public:
    int x, y;
    Point(int a=0, int b=0):x(a),y(b) {}
};
 
//utility function to find GCD of two numbers
// GCD of a and b
int gcd(int a, int b)
{
    if (b == 0)
       return a;
    return gcd(b, a%b);
}
 
// Finds the no. of Integral points between
// two given points.
int getBoundaryCount(Point p,Point q)
{
    // Check if line parallel to axes
    if (p.x==q.x)
        return abs(p.y - q.y) - 1;
    if (p.y == q.y)
        return abs(p.x-q.x) - 1;
 
    return gcd(abs(p.x-q.x),abs(p.y-q.y))-1;
}
 
// Returns count of points inside the triangle
int getInternalCount(Point p, Point q, Point r)
{
    // 3 extra integer points for the vertices
    int BoundaryPoints = getBoundaryCount(p, q) +
                         getBoundaryCount(p, r) +
                         getBoundaryCount(q, r) + 3;
 
    // Calculate 2*A for the triangle
    int doubleArea = abs(p.x*(q.y - r.y) + q.x*(r.y - p.y)  +
                         r.x*(p.y - q.y));
 
    // Use Pick's theorem to calculate the no. of Interior points
    return (doubleArea - BoundaryPoints + 2)/2;
}
 
// driver function to check the program.
int main()
{
    Point p(0, 0);
    Point q(5, 0);
    Point r(0, 5);
    cout << "Number of integral points inside given triangle is "
         << getInternalCount(p, q, r);
    return 0;
}
