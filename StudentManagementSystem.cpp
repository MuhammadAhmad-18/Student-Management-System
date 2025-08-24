#include <iostream>
using namespace std;
// STUDENTS RECORDS MANAGEMENT SYSTEM

// FUNCTION FOR TOTAL MARKS AND AVERAGES
void totalMarks_totalAvereges(int studentID[], int subjectMarks[10][5], int totalMarks[], double averageMarks[], int n, int t, int a)
{

    for (int i = 0; i < n; i++)
    {
        totalMarks[i] = 0;
        for (int j = 0; j < 5; j++)
        {
            totalMarks[i] = totalMarks[i] + subjectMarks[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        averageMarks[i] = 0;
        for (int j = 0; j < 5; j++)
        {
            averageMarks[i] = averageMarks[i] + (subjectMarks[i][j] / 5.0);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << "TOTAL MARKS of ID: " << studentID[i] << " are " << totalMarks[i] << " and AVERAGE is " << averageMarks[i] << endl;
    }
    cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;
}

// FUNCTION FOR TOP SCORER
void topScorer(int studentID[], int totalMarks[], int n, int t)
{
    int index;
    for (int i = 0; i < n; i++)
    {
        if (totalMarks[0] < totalMarks[i])
        {
            swap(totalMarks[0], totalMarks[i]);
            index = i;
        }
    }
    cout << "TOP SCORER is ID: " << studentID[index] << " with TOTAL MARKS of " << totalMarks[0] << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;
}

// FUNCTION FOR SEARCH OF STUDENT SUBJECT MARKS USING ID
void search_for_student(int studentID[], int subjectMarks[10][5], int n)
{
    int student_ID;
    for (int i = 0; i < n; i++)
    {
        cout << "| Enter the student ID to check his subject marks | OR | To exit enter 0 |" << endl;
        cin >> student_ID;
        if (student_ID == 0)
        {
            break;
        }
        int index;
        for (int i = 0; i < n; i++)
        {
            if (studentID[i] == student_ID)
            {
                index = i;
            }
        }

        for (int j = 0; j < 5; j++)
        {
            cout << "Subject " << j + 1 << ": " << subjectMarks[index][j] << "\t";
        }
        cout << endl;
    }

    cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;
}

// FUNCTION FOR STUDENTS BELOW AVERAGES
void studentBelowAverage(int studentID[], double averageMarks[], int n)
{
    cout << "Students Below Average" << endl;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (averageMarks[i] < 50)
        {
            cout << "Student ID : " << studentID[i] << " is below average" << endl;
            count++;
        }
    }
    if (count == 0)
    {
        cout << "NO Student below average" << endl;
    }

    cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;
}

// FUNCTION FOR SORTING
void sorting(int studentID[], int subjectMarks[10][5], int n)
{

    for (int i = 0; i < 10; i++)
    {

        for (int j = 0; j < 5; j++)
        {
            for (int k = j + 1; k < 5; k++)
            {
                if (subjectMarks[i][j] > subjectMarks[i][k])
                {
                    swap(subjectMarks[i][j], subjectMarks[i][k]);
                }
            }
        }
    }
    cout << "ID" << "\t\t\t" << "MARKS" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << studentID[i] << "\t\t\t";
        for (int j = 0; j < 5; j++)
        {
            cout << "Subject " << j + 1 << ": " << subjectMarks[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;
}

// FUNCTION FOR MARKS UPDATION
void updateMarks(int studentID[], int subjectMarks[10][5], int n)
{

    int input_id;
    cout << "Enter the ID of the student: " << endl;
    cin >> input_id;

    int indexOfStudent;
    for (int i = 0; i < n; i++)
    {
        if (studentID[i] == input_id)
        {
            indexOfStudent = i;
        }
    }

    int input_subject;
    cout << "Enter the subject you want to change marks: " << endl;
    cin >> input_subject;

    int new_marks;
    cout << "Enter the new marks: " << endl;
    cin >> new_marks;

    subjectMarks[indexOfStudent][input_subject - 1] = new_marks;

    cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;
}
// MAIN FUNCTION
int main()
{
    cout << "|--------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << "|--------------------------------------------------------------------------------------------------------------------|" << endl;

    cout << "|                                                                                                                    |" << endl;
    cout << "|                                    WELCOME TO STUDENT RECORD'S MANAGEMENT SYSTEM                                   |" << endl;
    cout << "|                                                                                                                    |" << endl;

    cout << "|--------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << "|--------------------------------------------------------------------------------------------------------------------|" << endl;

    int studentID[] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110}; // array for student IDs'
    int n = sizeof(studentID) / sizeof(studentID[0]);
    int subjectMarks[10][5]; // array for subject marks
    cout << "First Enter the Marks of Students According To Their ID." << endl;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << "Enter the marks for ID: " << studentID[i] << " \t\tsubject: " << j + 1 << " : ";
            cin >> subjectMarks[i][j];

            if (subjectMarks[i][j] < 0)
            {
                cout << "Invalid marks, Enter marks again" << endl;
                cout << "Enter the marks for ID: " << studentID[i] << " \t\tsubject: " << j + 1 << " : ";
                cin >> subjectMarks[i][j];
            }
        }
        cout << endl;
    }

    int totalMarks[10]; // array to store total marks
    int t = 10;
    double averageMarks[10]; // array to store average marks
    int a = 10;

    int inputFromUser;
    for (int i = 0;; i++)
    {

        cout << "Enter ['1'] to View the Total Marks and Total Avereges." << endl;
        cout << "Enter ['2'] to View the Top Scorer." << endl;
        cout << "Enter ['3'] to Search for Student's Subject Marks using ID." << endl;
        cout << "Enter ['4'] to View Student's IDs' Below Average." << endl;
        cout << "Enter ['5'] to Update marks." << endl;
        cout << "Enter ['6'] to View the Sorted list of Student's Subject Marks" << endl;
        cout << "For exit, enter ['0']." << endl;

        cin >> inputFromUser;
        if (inputFromUser == 0)
        {
            break;
        }
        // switch statement to call different functions
        switch (inputFromUser)
        {
        case 1: // call for calculation of total marks and total average
            totalMarks_totalAvereges(studentID, subjectMarks, totalMarks, averageMarks, n, t, a);
            break;
        case 2: // call to show top scorer
            totalMarks_totalAvereges(studentID, subjectMarks, totalMarks, averageMarks, n, t, a);
            topScorer(studentID, totalMarks, n, t);
            break;
        case 3: // call to search for subject marks using ID
            search_for_student(studentID, subjectMarks, n);
            break;
        case 4: // call to show student below average
            totalMarks_totalAvereges(studentID, subjectMarks, totalMarks, averageMarks, n, t, a);
            studentBelowAverage(studentID, averageMarks, n);
            break;
        case 5: // call to update marks
            updateMarks(studentID, subjectMarks, n);
            break;
        case 6: // call for sorting
            sorting(studentID, subjectMarks, n);
            break;
        default:
            cout << "INVALID INPUT" << endl;
            break;
        }
    }

    cout << "|--------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << "|--------------------------------------------------------------------------------------------------------------------|" << endl;

    cout << "|                                                                                                                    |" << endl;
    cout << "|                                    THANKS FOR USING STUDENT RECORD'S MANAGEMENT SYSTEM                                   |" << endl;
    cout << "|                                                                                                                    |" << endl;

    cout << "|--------------------------------------------------------------------------------------------------------------------|" << endl;
    cout << "|--------------------------------------------------------------------------------------------------------------------|" << endl;

    return 0;
}