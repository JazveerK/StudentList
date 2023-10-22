// Jazveer Kaler
//  10/22/2023
//  Studentlist
//  Description: This program will display a menu of options to the user. The
//  user will be able to add a student, delete it, and print out all students

#include <cctype>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// creates a struct
struct student {
  char firstName[15];
  char lastName[15];
  int ID;
  float gpa;
};

// function prototypes
void add(vector<student *> *studentList);
void print(vector<student *> *studentList);
void del(vector<student *> *studentList);

int main() {
  bool running = true;
  char command[15];

  vector<student *> *studentList = new vector<student *>();

  // while loop that runs the program
  while (running == true) {

    // takes in commands
    cout << "Type in a command: ADD, PRINT, DELETE, or QUIT " << endl;
    cin.get(command, 16);
    cin.ignore(16, '\n');

    // ADD
    if (strcmp(command, "ADD") == 0) {
      add(studentList);
    }

    // PRINT
    else if (strcmp(command, "PRINT") == 0) {
      print(studentList);
    }

    // DELETE
    else if (strcmp(command, "DELETE") == 0) {
      del(studentList);
    }

    // QUIT
    else if (strcmp(command, "QUIT") == 0) {
      cout << "Program ended." << endl;
      running = false;
    }
  }
  return 0;
}

void add(vector<student *> *v) {
  char inputFN[10];
  char inputLN[10];
  int inputID;
  float inputGPA;

  // takes in information
  cout << "Student First Name: " << endl;
  cin >> inputFN;
  cout << "Student Last Name: " << endl;
  cin >> inputLN;
  cout << "Student ID: " << endl;
  cin >> inputID;
  cout << "Student GPA: " << endl;
  cin >> inputGPA;
  cin.ignore(11, '\n');

  // Levi Lao
  // inputs to vector
  student *Student = new student();
  strcpy(Student->firstName, inputFN);
  strcpy(Student->lastName, inputLN);
  Student->ID = inputID;
  Student->gpa = inputGPA;
  v->push_back(Student);

  cout << "Student Added" << endl << endl;
}

void print(vector<student *> *v) {
  // iterates through the vector and prints out the information
  vector<student *>::iterator i = v->begin();
  for (i; i < v->end(); i++) {
    cout << (*i)->firstName << " " << (*i)->lastName << ", " << (*i)->ID << ", "
         << fixed << setprecision(2) << (*i)->gpa
         << endl; // Levi Lao helped with precision
  }

  cout << "Students Printed" << endl << endl;
}

void del(vector<student *> *v) {
  int search = 0;
  cout << "Enter the ID for the student you want to delete: " << endl;
  cin >> search;
  // search variable to find student

  // iterates through for loop to find student to delete
  vector<student *>::iterator i = v->begin();
  for (i; i < v->end(); i++) {
    cout << "testing" << endl;
    if (search == (*i)->ID) {
      delete *i;
      v->erase(i);
      break;
    }
  }

  cout << "Student Deleted" << endl;
  cin.ignore(81, '\n');
  cout << " " << endl;
}