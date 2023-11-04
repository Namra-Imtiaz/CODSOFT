#include<iostream>
#include<conio.h>
using namespace std;

class library
{
private:
    struct Node
    {
        int id;
        string name, author, publisher;
        Node* next_add;
    };

public:
    Node* head = NULL;
    void menu();
    void insert();
    void search();
    void update();
    void del();
    void sort();
    void show();
};

void library::menu()
{
    int found = 0;
    char ch;
p:
    system("cls");
    int choice;
    cout << "LIBRARY MANAGEMENT SYSTEM" << endl;
    cout << "1. Insert new record" << endl;
    cout << "2. Search record" << endl;
    cout << "3. Update record" << endl;
    cout << "4. Delete record" << endl;
    cout << "5. Show records" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        insert();
        break;
    case 2:
        search();
        break;
    case 3:
        update();
        break;
    case 4:
        del();
        break;
    case 5:
        sort();
        show();
        break;
    case 6:
        exit(0);
    default:
        cout << "Invalid choice" << endl;
    }
    cout << "Do you want to continue (y/n)? ";
    cin >> ch;
    if (ch == 'y' || ch == 'Y')
        goto p;
}

void library::insert()
{
    system("cls");
    cout << "LIBRARY MANAGEMENT SYSTEM" << endl;
    Node* new_node = new Node;
    cout << "Book id: ";
    cin >> new_node->id;
    cout << "Book name: ";
    cin >> new_node->name;
    cout << "Author name: ";
    cin >> new_node->author;
    cout << "Publisher name: ";
    cin >> new_node->publisher;
    new_node->next_add = NULL;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        Node* ptr = head;
        while (ptr->next_add != NULL)
        {
            ptr = ptr->next_add;
        }
        ptr->next_add = new_node;
    }
    cout << "New book inserted successfully!" << endl;
}

void library::search()
{
    system("cls");
    int t_id, found = 0;
    cout << "LIBRARY MANAGEMENT SYSTEM" << endl;
    if (head == NULL)
    {
        cout << "Linked list is empty" << endl;
    }
    else
    {
        cout << "Book id: ";
        cin >> t_id;
        Node* ptr = head;
        while (ptr != NULL)
        {
            if (t_id == ptr->id)
            {
                system("cls");
                cout << "LIBRARY MANAGEMENT SYSTEM" << endl;
                cout << "Book id: " << ptr->id << endl;
                cout << "Book name: " << ptr->name << endl;
                cout << "Author name: " << ptr->author << endl;
                cout << "Publisher name: " << ptr->publisher << endl;
                found++;
            }
            ptr = ptr->next_add;
        }
        if (found == 0)
        {
            cout << "Book id is invalid" << endl;
        }
    }
}

void library::update()
{
    system("cls");
    int t_id, found = 0;
    cout << "LIBRARY MANAGEMENT SYSTEM" << endl;
    if (head == NULL)
    {
        cout << "Linked list is empty" << endl;
    }
    else
    {
        cout << "Book id: ";
        cin >> t_id;
        Node* ptr = head;
        while (ptr != NULL)
        {
            if (t_id == ptr->id)
            {
                system("cls");
                cout << "LIBRARY MANAGEMENT SYSTEM" << endl;
                cout << "Book id: ";
                cin >> ptr->id;
                cout << "Book name: ";
                cin >> ptr->name;
                cout << "Author name: ";
                cin >> ptr->author;
                cout << "Publisher name: ";
                cin >> ptr->publisher;
                found++;
                cout << "Book updated successfully" << endl;
            }
            ptr = ptr->next_add;
        }
        if (found == 0)
        {
            cout << "Book id is invalid" << endl;
        }
    }
}

void library::del()
{
    system("cls");
    int t_id, found = 0;
    cout << "LIBRARY MANAGEMENT SYSTEM" << endl;
    if (head == NULL)
    {
        cout << "Linked list is empty" << endl;
    }
    else
    {
        cout << "Book id: ";
        cin >> t_id;
        if (t_id == head->id)
        {
            Node* ptr = head;
            head = head->next_add;
            delete ptr;
            cout << "Deleted book successfully!" << endl;
            found++;
        }
        else
        {
            Node* pre = head;
            Node* ptr = head;
            while (ptr != NULL)
            {
                if (t_id == ptr->id)
                {
                    pre->next_add = ptr->next_add;
                    delete ptr;
                    cout << "Deleted successfully" << endl;
                    found++;
                    break;
                }
                pre = ptr;
                ptr = ptr->next_add;
            }
        }
        if (found == 0)
        {
            cout << "Book id is invalid" << endl;
        }
    }
}

void library::sort()
{
    if (head == NULL)
    {
        system("cls");
        cout << "Linked list is empty" << endl;
        getch();
        menu();
    }
    int count = 0, t_id;
    string t_name, t_author, t_publisher;
    Node* ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next_add;
    }
    for (int i = 1; i <= count; i++)
    {
        Node* ptr = head;
        for (int j = 1; j < count; j++)
        {
            if (ptr->id > ptr->next_add->id)
            {
                t_id = ptr->id;
                t_name = ptr->name;
                t_author = ptr->author;
                t_publisher = ptr->publisher;

                ptr->id = ptr->next_add->id;
                ptr->name = ptr->next_add->name;
                ptr->author = ptr->next_add->author;
                ptr->publisher = ptr->next_add->publisher;

                ptr->next_add->id = t_id;
                ptr->next_add->name = t_name;
                ptr->next_add->author = t_author;
                ptr->next_add->publisher = t_publisher;
            }
            ptr = ptr->next_add;
        }
    }
}

void library::show()
{
    system("cls");
    cout << "LIBRARY MANAGEMENT SYSTEM" << endl;
    Node* ptr = head;
    while (ptr != NULL)
    {
        cout << "Book id: " << ptr->id << endl;
        cout << "Book name: " << ptr->name << endl;
        cout << "Author name: " << ptr->author << endl;
        cout << "Publisher name: " << ptr->publisher << endl;
        cout << "==========================" << endl;

        ptr = ptr->next_add;
    }
}

int main()
{
    library obj;
    obj.menu();
}

