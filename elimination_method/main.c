#include <iostream>
#include <vector>
#include <chrono>
using namespace std::chrono;

class EliminationMethod2DLineIntersection
{
public:
    void intersection(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
    void printIntersection();
private:
    std::vector<double> a, b, c, d;    //four coordinates constituting 2 Dimensional Lines.
    double int_x_, int_y_;
    bool are_parallel_;
};
void EliminationMethod2DLineIntersection::intersection(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
    double x12 = x1 - x2;
    double x34 = x3 - x4;
    double y12 = y1 - y2;
    double y34 = y3 - y4;
    double c = x12 * y34 - y12 * x34;
    are_parallel_ = (c==0);
    if(!are_parallel_)
    {
    	double a = x1 * y2 - y1 * x2;
    	double b = x3 * y4 - y3 * x4;
        int_x_ = (a * x34 - b * x12) / c;
        int_y_ = (a * y34 - b * y12) / c;
    } 
}
void EliminationMethod2DLineIntersection::printIntersection() {
    if(!are_parallel_)
    {
	std::cout << std::endl;
        std::cout << "Intersection point coordinates : \n";
        std::cout << "Xin : " << int_x_ << std::endl;
        std::cout << "Yin : " << int_y_ << std::endl;
    }
    else
    {
	std::cout << std::endl;    
        std::cout << "Lines are parallel";
    }
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
    EliminationMethod2DLineIntersection obj;
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
    obj.intersection(x1, y1, x2, y2, x3, y3, x4, y4);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop-start);
    obj.printIntersection();
    std::cout << "Elimination Method took " << duration.count() << " ns." << std::endl;
}       

