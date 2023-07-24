#include <iostream>
#include <chrono>
using namespace std::chrono;

class TwoDimensionalLineIntersection
{
public:
    void intersection(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
    void printIntersection();
private:
    double int_x_, int_y_;
    bool are_parallel_;
};
void TwoDimensionalLineIntersection :: intersection(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
    double slopeOfLine1;
    double slopeOfLine2;
    if(x2 - x1 != 0)
        slopeOfLine1 = (y2 - y1)/(x2 - x1);
    else
        slopeOfLine1 = 0;
    if(x4 - x3 != 0)
        slopeOfLine2 = (y4 - y3)/(x4 - x3);
    else
        slopeOfLine1 = 0;
    are_parallel_ = (slopeOfLine1==slopeOfLine2);
    if(!are_parallel_)
    {

        int_x_ = ((x1*y2 - y1*x2)*(x3 - x4) - (x3*y4 - y3*x4)*(x1 - x2) )/( ((x1 - x2)*(y3 - y4))- ((y1 - y2)*(x3 - x4)));
        int_y_ = ((x1*y2 - y1*x2)*(y3 - y4) - (x3*y4 - y3*x4)*(y1 - y2) )/( ((x1 - x2)*(y3 - y4))- ((y1 - y2)*(x3 - x4)));
    } 
}
void TwoDimensionalLineIntersection ::printIntersection()
{
    if(!are_parallel_)
    {
        std::cout << "\nIntersection Coordinate : ";
        std::cout << "\nX-coordinate : " << int_x_;
        std::cout << "\nY-coordinate : " << int_y_;
    } else
        std::cout << "\nLines are Parallel.";
}
double RandomFloat(double a, double b) {
    double random = ((double) rand()) / (double) RAND_MAX;
    double diff = b - a;
    double r = random * diff;
    return a + r;
}

int main()
{
    double random_min = 100.0;
    double random_max = 1000.0;
    TwoDimensionalLineIntersection t;
    double x1, y1, x2, y2, x3, y3, x4, y4;
    std::cout << "\nEnter the Coordinates for Line-1 : ";
    x1 = RandomFloat(random_min, random_max);
    std::cout << "\nLine-1 | x1-coordinate : " << x1;
    //std::cin >> x1;
    y1 = RandomFloat(random_min, random_max);
    std::cout << "\nLine-1 | y1-coordinate : " << y1;
    //std::cin >> y1;
    x2 = RandomFloat(random_min, random_max);
    std::cout << "\nLine-1 | x2-coordinate : " << x2;
    //std::cin >> x2;
    y2 = RandomFloat(random_min, random_max);
    std::cout << "\nLine-1 | y2-coordinate : " << y2;
    //std::cin >> y2;
    std::cout << "\nEnter the Coordinates for Line-2 : ";
    x3 = RandomFloat(random_min, random_max);
    std::cout << "\nLine-2 | x3-coordinate : " << x3;
    //std::cin >> x3;
    y3 = RandomFloat(random_min, random_max);
    std::cout << "\nLine-2 | y3-coordinate : " << y3;
    //std::cin >> y3;
    x4 = RandomFloat(random_min, random_max);
    std::cout << "\nLine-2 | x4-coordinate : " << x4;
    //std::cin >> x4;
    y4 = RandomFloat(random_min, random_max);
    std::cout << "\nLine-2 | y4-coordinate : " << y4;
    //std::cin >> y4;
    auto start = high_resolution_clock::now();
    t.intersection(x1, y1, x2, y2, x3, y3, x4, y4);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop-start);
    t.printIntersection();
    std::cout << std::endl;
    std::cout << "Determinant Method took " << duration.count() << " ns." << std::endl;
}       

