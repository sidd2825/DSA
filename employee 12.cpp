#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Record {
    int id;
    string name;
    int salary;
    string designation;

public:
    Record();
    int getIdno();
    void getData();
    void putData();
};

Record::Record() {
    id = 0;
    name = "";
    designation = "";
    salary = 0;
}

int Record::getIdno() {
    return id;
}

void Record::getData() {
    cout << "\nEnter Details: ";
    cout << "\nId no: ";
    cin >> id;
    cout << "Name: ";
    cin >> name;
    cout << "Salary: ";
    cin >> salary;
    cout << "Designation: ";
    cin >> designation;
}

void Record::putData() {
    cout << "\nId No.: " << id;
    cout << "\t\tName: " << name;
    cout << "\nSalary: " << salary;
    cout << "\tDesignation: " << designation;
}

class File {
    fstream fs;

public:
    void insert();
    void display();
    void search(int);
    int Delete(int);
    int edit(int);
};

void File::insert() {
    Record r;
    r.getData();
    fs.open("EmployeeDB", ios::in | ios::out | ios::app | ios::binary);
    fs.write(reinterpret_cast<char*>(&r), sizeof(r));
    fs.close();
}

void File::display() {
    Record r;
    fs.open("EmployeeDB", ios::in | ios::binary);
    while (fs.read(reinterpret_cast<char*>(&r), sizeof(r))) {
        r.putData();
    }
    fs.close();
}

void File::search(int id) {
    Record r;
    bool found = false;
    fs.open("EmployeeDB", ios::in | ios::binary);
    while (fs.read(reinterpret_cast<char*>(&r), sizeof(r))) {
        if (r.getIdno() == id) {
            found = true;
            r.putData();
            break;
        }
    }
    fs.close();
    if (!found) {
        cout << "\nRecord not found.";
    }
}

int File::Delete(int id) {
    Record r;
    bool found = false;
    fstream temp;
    fs.open("EmployeeDB", ios::in | ios::binary);
    temp.open("Temp", ios::out | ios::binary);
    while (fs.read(reinterpret_cast<char*>(&r), sizeof(r))) {
        if (r.getIdno() == id) {
            found = true;
        } else {
            temp.write(reinterpret_cast<char*>(&r), sizeof(r));
        }
    }
    fs.close();
    temp.close();
    remove("EmployeeDB");
    rename("Temp", "EmployeeDB");
    return found ? 1 : 0;
}

int File::edit(int id) {
    Record r;
    bool found = false;
    fs.open("EmployeeDB", ios::in | ios::out | ios::binary);
    while (fs.read(reinterpret_cast<char*>(&r), sizeof(r))) {
        if (r.getIdno() == id) {
            found = true;
            r.getData();
            fs.seekp(-static_cast<int>(sizeof(r)), ios::cur);
            fs.write(reinterpret_cast<char*>(&r), sizeof(r));
            break;
        }
    }
    fs.close();
    return found ? 1 : 0;
}

int main() {
    File f;
    int choice, id;
    do {
        cout << "\n\n\t----- MENU -----";
        cout << "\n1. Insert a New Entry";
        cout << "\n2. Display All Records";
        cout << "\n3. Search for a Record";
        cout << "\n4. Delete a Record";
        cout << "\n5. Edit a Record";
        cout << "\n6. Quit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                f.insert();
                break;
            case 2:
                f.display();
                break;
            case 3:
                cout << "\nEnter ID to search: ";
                cin >> id;
                f.search(id);
                break;
            case 4:
                cout << "\nEnter ID to delete: ";
                cin >> id;
                if (f.Delete(id)) {
                    cout << "\nRecord deleted successfully.";
                } else {
                    cout << "\nRecord not found.";
                }
                break;
            case 5:
                cout << "\nEnter ID to edit: ";
                cin >> id;
                if (f.edit(id)) {
                    cout << "\nRecord edited successfully.";
                } else {
                    cout << "\nRecord not found.";
                }
                break;
            case 6:
                break;
            default:
                cout << "\nInvalid choice.";
        }
    } while (choice != 6);
    return 0;
}

