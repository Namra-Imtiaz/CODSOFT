#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int ID = 0;

struct todolist {
    int id;
    string task;
};

void banner() {
    cout << "_________________________________" << endl;
    cout << "\t MY TO DO" << endl;
    cout << "_________________________________" << endl;
}

void add_task() {
    system("cls");
    banner();
    todolist todo;
    cout << "enter new task: ";
    cin.ignore();   // Clear the newline character from previous input
    getline(cin, todo.task);
    char save;
    cout << "save? Y/N" << endl;
    cin >> save;
    if (save == 'Y' || save == 'y') {
        ID++;
        ofstream fout;
        fout.open("todo.txt", ios::app);
        fout << ID << endl;
        fout << todo.task << endl;
        fout.close();

        system("cls");
        cout << "added successfully" << endl;
    }
    else {
        system("cls");
        cout << "not saved" << endl;
    }
}

void show_task() {
    system("cls");
    banner();
    todolist todo;
    ifstream fin;
    fin.open("todo.txt");
    cout << "Tasks: " << endl;
    
    while (fin >> todo.id) {
        fin.ignore();   // Clear the newline character
        getline(fin, todo.task);
        if (!todo.task.empty()) {
            cout << "\t " << todo.id << ": " << todo.task << endl;
        }
    }
    
    fin.close();
    
    char exit;
    cout << "Exit? y/n" << endl;
    cin >> exit;
    
    if (exit != 'y') {
        show_task();
    }
    system("cls");
}


int search_task() {
    system("cls");
    banner();
    int id;
    cout << "enter task id" << endl;
    cin >> id;
    todolist todo;
    ifstream fin("todo.txt");
    while (!fin.eof()) {
        fin >> todo.id;
        fin.ignore();   // Clear the newline character
        getline(fin, todo.task);
        if (todo.id == id) {
            system("cls");
            cout << "\t " << todo.id << ": " << todo.task << endl;
            fin.close();
            return id;
        }
    }
    fin.close();
    system("cls");
    cout << "not found" << endl;
    return 0;
}

void delete_task() {
    system("cls");
    int id = search_task();
    if (id != 0) {
        char del;
        cout << "delete y/n" << endl;
        cin >> del;
        if (del == 'y') {
            todolist todo;
            ofstream tempfile;
            tempfile.open("temp.txt");
            ifstream fin;
            fin.open("todo.txt");
            int index = 1;
            while (fin >> todo.id) {
                fin.ignore();   // Clear the newline character
                getline(fin, todo.task);
                if (todo.id == id) {
                    continue;  // Skip the task to delete
                }
                tempfile << todo.id << endl;
                tempfile << todo.task << endl;
            }
            fin.close();
            tempfile.close();
            remove("todo.txt");
            rename("temp.txt", "todo.txt");
            system("cls");
            cout << "deleted successfully" << endl;
        }
        else {
            system("cls");
            cout << "not deleted" << endl;
        }
    }
}


void update_task() {
    system("cls");
    banner();
    int id = search_task();
    if (id != 0) {
        todolist todo;
        ifstream fin("todo.txt");
        ofstream tempfile("temp.txt");
        while (fin >> todo.id) {
            fin.ignore();   // Clear the newline character
            getline(fin, todo.task);
            if (todo.id == id) {
                cout << "Enter updated task: ";
                cin.ignore();   // Clear the newline character
                getline(cin, todo.task);
            }
            tempfile << todo.id << endl;
            tempfile << todo.task << endl;

            // Break out of the loop once the task is updated
            if (todo.id == id) {
                break;
            }
        }
        // Continue copying the remaining tasks
        while (fin >> todo.id) {
            fin.ignore();   // Clear the newline character
            getline(fin, todo.task);
            tempfile << todo.id << endl;
            tempfile << todo.task << endl;
        }
        fin.close();
        tempfile.close();
        remove("todo.txt");
        rename("temp.txt", "todo.txt");
        system("cls");
        cout << "Updated successfully" << endl;
    }
}

int main() {
    system("cls");
    while (true) {
        banner();
        cout << "1. Add task" << endl;
        cout << "2. Show task" << endl;
        cout << "3. Search task" << endl;
        cout << "4. Delete task" << endl;
        cout << "5. Update task" << endl;
        cout << "6. Exit" << endl;

        int choice;
        cout << "Enter choice" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                add_task();
                break;
            case 2:
                show_task();
                break;
            case 3:
                search_task();
                break;
            case 4:
                delete_task();
                break;
            case 5:
                update_task();
                break;
            case 6:
                exit(0); // Gracefully exit the program
            default:
                cout << "Invalid Input" << endl;
        }
    }
    return 0;
}
