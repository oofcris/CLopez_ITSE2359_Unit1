#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    const int size = 55;

    string names[size];
    int ages[size];
    double gpa[size];

    ifstream infile("student_data.txt");
    if (!infile)
    {
        cout << "File could not be open" << endl;
        return 0;
    }

    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (infile >> names[i] >> ages[i] >> gpa[i])
        {
            count++;
        }
    }
    infile.close();

    double avg = 0;
    for (int i = 0; i < count; i++)
    {
        avg += gpa[i];
    }
    cout << "Average GPA: " << avg / count << endl;

    double highgpa = gpa[0];
    for (int i = 1; i < count; i++)
    {
        if (gpa[i] > highgpa)
            highgpa = gpa[i];
    }

    cout << "Highest GPA: " << highgpa << endl;
    cout << "Students with the highest GPA:" << endl;
    for (int i = 0; i < count; i++)
    {
        if (gpa[i] == highgpa)
            cout << names[i] << endl;
    }

    int oldest = ages[0];
    int youngest = ages[0];

    for (int i = 1; i < count; i++)
    {
        if (ages[i] > oldest)
            oldest = ages[i];
        if (ages[i] < youngest)
            youngest = ages[i];
    }

    cout << "Oldest students:" << endl;
    for (int i = 0; i < count; i++)
    {
        if (ages[i] == oldest)
            cout << names[i] << endl;
    }

    cout << "Youngest students:" << endl;
    for (int i = 0; i < count; i++)
    {
        if (ages[i] == youngest)
            cout << names[i] << endl;
    }

    return 0;
}
