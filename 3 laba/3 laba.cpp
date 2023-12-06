#include <iostream> 
#include <vector> 
#include <cmath> 

using namespace std;

int input()
{
    int x;
    cout << "Enter the vertex coordinate" << endl;
    cin >> x;
    while (cin.fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Check the correctness of the entered data!" << endl;
        cout << "Enter the vertex coordinate" << endl;
        cin >> x;
    }
    return x;
}


class Point {
public:
    int X;
    int Y;
    double myTan;
    Point() : X(0), Y(0), myTan(0) {}
};


bool isLessTan(const Point& left, const Point& right)
{
    return left.myTan <= right.myTan ? true : false;
}


bool isLessX(const Point& left, const Point& right)
{
    return left.X == right.X ? left.Y < right.Y : left.X < right.X;
}



template<class T>
void mySort(T* arr, int l, int r, bool(*isLess)(const T&, const T&)) {
    for (int i = l; i < r; i++) {
        for (int j = l; j < r - 1; j++) {
            if (isLess(arr[j + 1], arr[j])) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}


template<class T>
void allFunc(T* arr, int arrSize) {
    Point pt = arr[0];
    int pointAddress = 0;

    for (int i = 1; i < arrSize; i++) {
        if (!isLessX(pt, arr[i])) {
            pt = arr[i];
            pointAddress = i;
        }
    }
    swap(arr[0], arr[pointAddress]);

    for (int i = 1; i < arrSize; i++)
        arr[i].myTan = atan2(arr[i].X - arr[0].X, arr[i].Y - arr[0].Y);

    mySort(&arr[0], 1, arrSize, isLessTan);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    char ans = 'y';
    while (ans == 'y')
    {
        vector<Point> arr;
        Point pt;
        int x = 0;
        int y = 0;
        int number;
        cout << "Enter the number of polyline points " << endl;
        cin >> number;
        for (int j = 0; j < number; j++) {
            pt.X = input();
            pt.Y = input();
            arr.push_back(pt);
        }


        allFunc(&arr[0], arr.size());
        cout << "The final result" << endl;
        for (int i = 0; i < arr.size(); i++) {
            cout << "(" << arr[i].X << ", ";
            cout << arr[i].Y << ")" << endl;
        }
        cout << "If you want to repeat the program, press y " << endl;
        cin >> ans;
    }
    return 0;
}