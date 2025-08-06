#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h> // For color output

using namespace std;

// Set color using Windows API
void setColor(int colorCode) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorCode);
}

int main() {
    int numCourses;
    float totalCredits = 0, totalGradePoints = 0;

    setColor(11); // Aqua Title
    cout << "==============================================" << endl;
    cout << "          CGPA CALCULATOR - C++ PROJECT        " << endl;
    cout << "==============================================" << endl;

    setColor(15); // White
    cout << "\nEnter number of courses: ";
    cin >> numCourses;

    string courseNames[numCourses];
    float gpas[numCourses];
    float credits[numCourses];
    float gradePoints[numCourses];

    for (int i = 0; i < numCourses; i++) {
        cout << "\n";
        setColor(14); // Yellow for heading
        cout << "Course #" << i + 1 << " Details\n";

        setColor(15); // White
        cout << "Enter course name: ";
        cin.ignore(); // clear buffer
        getline(cin, courseNames[i]);

        cout << "Enter GPA (e.g. 4.0, 3.7, 3.0, etc.): ";
        cin >> gpas[i];

        while (gpas[i] < 0.0 || gpas[i] > 4.0) {
            cout << "Invalid GPA. Please enter a value between 0.0 and 4.0: ";
            cin >> gpas[i];
        }

        cout << "Enter credit hours: ";
        cin >> credits[i];

        gradePoints[i] = gpas[i] * credits[i];
        totalGradePoints += gradePoints[i];
        totalCredits += credits[i];
    }

    float cgpa = totalGradePoints / totalCredits;

    // Report Section
    cout << "\n\n";
    setColor(11); // Aqua Header
    cout << "==========================================================" << endl;
    cout << "                    Semester Grade Report                 " << endl;
    cout << "==========================================================" << endl;

    setColor(10); // Light green table headers
    cout << left << setw(25) << "Course"
         << setw(10) << "GPA"
         << setw(15) << "Credit Hours"
         << setw(15) << "Grade Points" << endl;
    cout << "----------------------------------------------------------" << endl;

    setColor(15); // White rows
    for (int i = 0; i < numCourses; i++) {
        cout << left << setw(25) << courseNames[i]
             << setw(10) << fixed << setprecision(2) << gpas[i]
             << setw(15) << credits[i]
             << setw(15) << fixed << setprecision(2) << gradePoints[i] << endl;
    }

    setColor(10); // Green total section
    cout << "----------------------------------------------------------" << endl;
    cout << left << setw(35) << "Total Credit Hours: " << totalCredits << endl;
    cout << left << setw(35) << "Total Grade Points: " << totalGradePoints << endl;
    cout << left << setw(35) << "Final CGPA: " << fixed << setprecision(2) << cgpa << endl;
    cout << "==========================================================" << endl;

    setColor(14); // Yellow thank you
    cout << "\nThank you for using the CGPA Calculator!\n";

    setColor(7); // Reset to default
    return 0;
}

