#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    const int SUBJECTS = 5;
    const int MAX_MARKS = 100;
    const int PASS_MARK = 35;

    int marks[SUBJECTS];
    int total = 0;
    bool pass = true;
    double percentage;
    string grade;

    cout << "GRADE CALCULATOR SYSTEM\n";
    cout << "Enter marks for five subjects (0-100).\n";

    // Input and validate marks
    for (int i = 0; i < SUBJECTS; i++) {
        do {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];

            if (marks[i] < 0 || marks[i] > MAX_MARKS) {
                cout << "Invalid marks! Enter 0 to 100.\n";
            }
        } while (marks[i] < 0 || marks[i] > MAX_MARKS);

        total += marks[i];

        if (marks[i] < PASS_MARK) {
            pass = false;
        }
    }

    // Calculate percentage
    percentage = (static_cast<double>(total) /
                  (SUBJECTS * MAX_MARKS)) * 100.0;

    // Calculate grade
    if (percentage >= 90)
        grade = "A+";
    else if (percentage >= 80)
        grade = "A";
    else if (percentage >= 70)
        grade = "B";
    else if (percentage >= 60)
        grade = "C";
    else if (percentage >= 40)
        grade = "D";
    else
        grade = "F";

    // Display result
    cout << fixed << setprecision(2);
    cout << "\n----- RESULT -----\n";

    for (int i = 0; i < SUBJECTS; i++) {
        cout << "Subject " << i + 1
             << ": " << marks[i] << "/100\n";
    }

    cout << "Total: " << total << "/500\n";
    cout << "Percentage: " << percentage << "%\n";
    cout << "Grade: " << grade << "\n";
    cout << "Result: " << (pass ? "PASS" : "FAIL") << "\n";

    return 0;
}
