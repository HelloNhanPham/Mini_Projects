#include <iostream>
#include <vector>
#include "Point.cpp"
using namespace std;

int main()
{
    CGPA obj;
    while (true)
    {
        int n;
        cout << "The number of subjects is: ";
        cin >> n;
        int point, coefficient;
        for (int i = 0; i < n; ++i)
        {
            cout << "Point and coefficient of subject " << i + 1 << ": ";
            cin >> point >> coefficient;
            obj.addPoint(point, coefficient);
        }
        while (true)
        {
            obj.display();
            cout << "Do you want to change any value [Y/N]: ";
            char choose;
            cin >> choose;
            if (choose == 'N')
                break;
            if (choose == 'Y')
            {
                cout << "Which number of line do you want to change: ";
                int selection, newPoint, newCoefficient;
                cin >> selection;
                cout << "Input new point and new coefficient: ";
                cin >> newPoint;
                cin >> newCoefficient;
                obj.change(selection - 1, newPoint, newCoefficient);
            }
        }
        cout << "CGPA is: " << obj.calc() << endl;
        cout << "Do you want to continue [Y/N]: ";
        char choose;
        cin >> choose;
        if (choose == 'N')
            break;
        if (choose == 'Y')
            obj.clear();
    }
    return 0;
}