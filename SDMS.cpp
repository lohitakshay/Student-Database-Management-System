#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

// Defining structure student

struct student
{
    string f_name;
    string l_name;
    int roll_num;
    double cg;
};
student stud[100];
int numb = 0;

// Function for admin login verification

bool authenticateAdmin(const string &username, const string &password)
{
    if (username == "admin" && password == "pass")
    {
        return true;
    }
    return false;
}

// Function to add a student

void addstudent()
{
    cout << "Enter the details of the student" << endl;
    cout << "Enter the Roll Number" << endl;
    int roll_no;
    cin >> roll_no;

    for (int i = 0; i < numb; i++)
    {
        if (roll_no == stud[i].roll_num)
        {
            cout << "The given Roll Number is already assigned." << endl;
            cout << "\n"
                    "*********** \n"
                    "\n";
            return;
        }
    }
    cout << "Enter the first name of the student" << endl;
    cin >> stud[numb].f_name;

    cout << "Enter the last name of the student" << endl;
    cin >> stud[numb].l_name;

    cout << "Enter the CGPA obtained" << endl;
    cin >> stud[numb].cg;

    stud[numb].roll_num = roll_no;

    numb++;

    cout << "\n"
            "*********** \n"
            "\n";
}

// Function to search for a student by Roll Number

void findbyroll()
{
    cout << "Enter the Roll No of the student to search" << endl;
    int roll_no;
    cin >> roll_no;

    for (int i = 0; i < numb; i++)
    {
        if (roll_no == stud[i].roll_num)
        {
            cout << "Student's details - " << endl;
            cout << "The student name is " << stud[i].f_name << " " << stud[i].l_name << endl;
            cout << "The CGPA of the student is " << stud[i].cg << endl;
            cout << "\n"
                    "*********** \n"
                    "\n";

            return;
        }
    }
    cout << "No such Roll Number exists in the database." << endl;
    cout << "\n"
            "*********** \n"
            "\n";
}

// Function to find a student by First Name

void findbyfirst()
{
    cout << "Enter the first name of the student to search" << endl;
    string first;
    cin >> first;

    for (int i = 0; i < numb; i++)
    {
        if (first == stud[i].f_name)
        {
            cout << "Student's details - " << endl;
            cout << "The student name is " << stud[i].f_name << " " << stud[i].l_name << endl;
            cout << "The Roll Number of the student is " << stud[i].roll_num << endl;
            cout << "The CGPA of the student is " << stud[i].cg << endl;
            cout << "\n"
                    "*********** \n"
                    "\n";

            return;
        }
    }

    cout << "No such student exists in the database." << endl;
    cout << "\n"
            "*********** \n"
            "\n";
}

// Function to find the total number of students present in the database

void totalnum()
{
    cout << "The total number of students are " << numb << endl;
    cout << "\n"
            "*********** \n"
            "\n";
}

// Funtion to delete data of a particular student using Roll Number

void delstudent()
{
    cout << "Enter the Roll no of the student that should be deleted - " << endl;
    int roll_no;
    cin >> roll_no;

    for (int i = 0; i < numb; i++)
    {
        if (roll_no == stud[i].roll_num)
        {
            for (int j = i; j < numb - 1; j++)
            {
                stud[j] = stud[j + 1];
            }
            cout << "The given Roll Number is deleted successfully" << endl;
            cout << "\n"
                    "*********** \n"
                    "\n";
            numb--;
            return;
        }
    }

    cout << "The given Roll Number is not found or deleted" << endl;
    cout << "\n"
            "*********** \n"
            "\n";
}

// Funtion to update details of a student

void updatestudent()
{
    cout << "Enter the roll number whose details you want to update" << endl;
    int roll_no, rolls;
    cin >> roll_no;

    for (int i = 0; i < numb; i++)
    {
        if (roll_no == stud[i].roll_num)
        {
            cout << "1. update first name. \n"
                    "2. update last name. \n"
                    "3. update roll number.\n"
                    "4. update CGPA. \n";
            int choice;
            cin >> choice;
            if (choice == 1)
            {
                cout << "Enter the new first name :-" << endl;
                cin >> stud[i].f_name;
            }
            if (choice == 2)
            {
                cout << "Enter the new last name :-" << endl;
                cin >> stud[i].l_name;
            }
            if (choice == 3)
            {
                int g;
                while (true)
                {
                    cout << "Enter the new Roll Number :-" << endl;
                    cin >> rolls;
                    for (g = 0; g < numb; g++)
                    {
                        if (rolls == stud[g].roll_num)
                        {
                            cout << "The given roll number is already present." << endl;
                            break;
                        }
                    }
                    if (g == numb)
                    {
                        stud[i].roll_num = rolls;
                        break;
                    }
                }
            }
            if (choice == 4)
            {
                cout << "Enter the new CGPA :-" << endl;
                cin >> stud[i].cg;
            }

            cout << "Details found and updated successfully." << endl;
            cout << "\n"
                    "*********** \n"
                    "\n";
            return;
        }
    }

    cout << "No such student found in the database." << endl;
    cout << "\n"
            "*********** \n"
            "\n";
}

// Function to display the database

void display()
{
    cout << "\n"
            "*********** \n"
            "\n";
    if (numb == 0)
    {
        cout << "No students in the database, please give input." << endl;
    }
    else
    {
        for (int i = 0; i < numb; i++)
        {
            cout << "Name - " << stud[i].f_name << " " << stud[i].l_name << "  |  Roll Number - " << stud[i].roll_num << "  |  CGPA - " << stud[i].cg << endl;
        }
    }
    cout << "\n"
            "*********** \n"
            "\n";
}

// Function to save the data in a CSV file

void savedata()
{
    ofstream file("student_database.csv");
    if (file.is_open())
    {
        file << "First_Name,Last_Name,Roll_Number,CGPA" << endl;

        for (int i = 0; i < numb; i++)
        {
            file << stud[i].f_name << "," << stud[i].l_name << "," << stud[i].roll_num << "," << stud[i].cg << endl;
        }

        file.close();
        cout << "\n"
                "*********** \n"
                "\n";
        cout << "The student's data is stored in the CSV file successfully" << endl;
    }
    else
    {
        cout << "Failed to create CSV file" << endl;
    }
    cout << "\n"
            "*********** \n"
            "\n";
}

// Function to load previous data from the CSV file

void loadpdata()
{
    ifstream file("student_database.csv");
    if (!file.is_open())
    {
        cout << "Failed to open the file" << endl;
        return;
    }
    string line;
    getline(file, line);

    while (getline(file, line))
    {
        stringstream ss(line);

        string f_name, l_name;
        int roll_num;
        double cg;

        getline(ss, f_name, ',');
        getline(ss, l_name, ',');
        ss >> roll_num;
        ss.ignore();
        ss >> cg;

        stud[numb].f_name = f_name;
        stud[numb].l_name = l_name;
        stud[numb].roll_num = roll_num;
        stud[numb].cg = cg;

        numb++;
    }

    file.close();
}

int main()
{
    while (true)
    {
        loadpdata();

        int opt;
        cout << "Welcome to the Login page" << endl;
        cout << "1) Admin." << endl;
        cout << "2) Student." << endl;
        cout << "3) Exit." << endl;
        cout << "\nPlease enter the choice..." << endl;
        cin >> opt;

        // Here the admin logs in

        if (opt == 1)
        {
            string username, password;
            cout << "Please enter the ID..." << endl;
            cin >> username;
            cout << "Please enter the password..." << endl;
            cin >> password;

            if (authenticateAdmin(username, password))
            {
                cout << "Admin Login successfull \n"
                     << endl;
                while (true)
                {
                    cout << "Choices of the tasks that you want to perform" << endl;
                    cout << "1) To add new student's details." << endl;
                    cout << "2) To find student by Roll Number." << endl;
                    cout << "3) To find the student by First Name" << endl;
                    cout << "4) To find the total number of students" << endl;
                    cout << "5) To delete the student by roll number" << endl;
                    cout << "6) To update student's details by roll number" << endl;
                    cout << "7) To display all the students" << endl;
                    cout << "8) Save the data in CSV file" << endl;
                    cout << "9) Logout" << endl;
                    cout << "10) Exit the programme" << endl;

                    int choice;
                    cin >> choice;
                    switch (choice)
                    {
                    case 1:
                        addstudent();
                        break;
                    case 2:
                        findbyroll();
                        break;
                    case 3:
                        findbyfirst();
                        break;
                    case 4:
                        totalnum();
                        break;
                    case 5:
                        delstudent();
                        break;
                    case 6:
                        updatestudent();
                        break;
                    case 7:
                        display();
                        break;
                    case 8:
                        savedata();
                        break;
                    case 9:
                        cout << "***********" << endl;
                        cout << "\nLogging out..." << endl;
                        break;
                    case 10:
                        exit(0);
                        break;
                    default:
                        cout << "Invalid choice." << endl;
                        break;
                    }
                    if (choice == 9)
                    {
                        break;
                    }
                }
                cout << "\n"
                        "*********** \n"
                        "\n";
            }
            else
            {
                cout << "***********" << endl;
                cout << "\nInvalid ID or password" << endl;
                cout << "\n"
                        "*********** \n"
                        "\n";
            }
        }

        // Here the student logs in

        else if (opt == 2)
        {
            int id;
            string pass;
            cout << "Please enter the Roll Number" << endl;
            cin >> id;
            cout << "Please enter the password (last_name)" << endl;
            cin >> pass;
            while (true)
            {
                bool found = false;
                for (int j = 0; j < numb; j++)
                {
                    if (id == stud[j].roll_num && pass == stud[j].l_name)
                    {
                        cout << "Your details :-" << endl;
                        cout << "\n"
                             << "*********** \n"
                             << "\n";
                        cout << "Name - " << stud[j].f_name << " " << stud[j].l_name << "  |  Roll Number - " << stud[j].roll_num << "  |  CGPA - " << stud[j].cg << endl;
                        cout << "\n"
                             << "*********** \n"
                             << "\n";
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    cout << "***********" << endl;
                    cout << "\nNo such roll number exists in the database. [Ask admin to add or update your details]" << endl;
                    cout << "\n***********" << endl;
                }

                cout << "1) Check for another student." << endl;
                cout << "2) Logout." << endl;
                int choice;
                cin >> choice;

                if (choice == 1)
                {
                    cout << "Please enter the Roll Number" << endl;
                    cin >> id;
                    cout << "Please enter the password (last_name)" << endl;
                    cin >> pass;
                }
                else if (choice == 2)
                {
                    break;
                }
                else{
                    cout << "\n"
                             << "*********** \n"
                             << "\n";
                    cout<<"Invalid choice, Please try again..."<<endl;
                    cout << "\n"
                             << "*********** \n"
                             << "\n";
                    break;

                }
            }
        }

        else if (opt == 3)
        {
            cout << "***********" << endl;
            cout << "\nTerminating..." << endl;
            cout << "\n***********" << endl;
            exit(0);
        }
        else
        {
            cout << "***********" << endl;
            cout << "\nGive correct input..." << endl;
            cout << "\n***********" << endl;
            continue;
        }
    }

    return 0;
}
