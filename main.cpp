#include <iostream>
using namespace std;

struct Employee
{
    string first_name;
    string last_name;
    int id;
    string first_dayOfWork;
    long phoneNumber;
    string address;
    int workHours;
    double salary;
    struct Employee *next;
};

Employee* findEmployee(struct Employee* find_node, int node_id)
{
    while (find_node != NULL)
    {
        if(find_node->id==node_id)
        {
            cout<<"Employee Name: "<<find_node->first_name<<" "<<find_node->last_name<<endl;
            cout<<"Employee ID: "<<find_node->id<<endl;
            cout<<"Employee First Day Of Work: "<<find_node->first_dayOfWork<<endl;
            cout<<"Employee Phone Number: "<<find_node->phoneNumber<<endl;
            cout<<"Employee Address: "<<find_node->address<<endl;
            cout<<"Employee Work Hours: "<<find_node->workHours<<endl;
            cout<<"Employee Salary: "<<find_node->salary<<" S.R"<<endl<<endl;
            return find_node;
        }
        find_node = find_node->next;
    }
    cout<<"There is no record of this employee in this system."<<endl<<endl;
    return find_node;
}

int find(struct Employee* find_node, int node_id)
{
    while (find_node != NULL)
    {
        if(find_node->id==node_id)
        {
            return find_node->id;
        }
        find_node = find_node->next;
    }
    return 0;
}


void deleteEmployee(struct Employee **head_ref, int key)
{
    struct Employee* temp = *head_ref, *prev;
    if (temp != NULL && temp->id == key)
    {
        *head_ref = temp->next;
        delete(temp);
        cout<<"The employee record was deleted successfully."<<endl<<endl;
        return;
    }

    while (temp != NULL && temp->id != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout<<"There is no employee with the id "<< key << " in the system."<<endl<<endl;
        return;
    }
    prev->next = temp->next;
    delete(temp);
    cout<<"The employee record was deleted successfully."<<endl<<endl;
}

void append(struct Employee** head, string node_first_name, string node_last_name, int node_id, string first_dayOfWork, long phoneNumber, string address, int workHours, double node_salary)
{
    struct Employee* newNode = new Employee;
    struct Employee *last = *head;
    newNode->first_name = node_first_name;
    newNode->last_name = node_last_name;
    newNode->id = node_id;
    newNode->first_dayOfWork = first_dayOfWork;
    newNode->phoneNumber = phoneNumber;
    newNode->address = address;
    newNode->workHours = workHours;
    newNode->salary = node_salary;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = newNode;
    return;
}

void updateSalary(struct Employee* find_node, int node_id, int salary){
  struct Employee* f = new Employee;
  f = findEmployee(find_node,node_id);
  f->salary = salary;
}

void displayList(struct Employee *node)
{

    if (node==NULL)
    {
        cout << "NO Employee."<<endl<<endl;
        return;
    }
            cout<<"Employee Name: "<<node->first_name<<" "<<node->last_name<<endl;
            cout<<"Employee ID: "<<node->id<<endl;
            cout<<"Employee First Day Of Work: "<<node->first_dayOfWork<<endl;
            cout<<"Employee Phone Number: "<<node->phoneNumber<<endl;
            cout<<"Employee Address: "<<node->address<<endl;
            cout<<"Employee Work Hours: "<<node->workHours<<endl;
            cout<<"Employee Salary: "<<node->salary<<" S.R"<<endl<<endl;
            cout<<"---------------------------------------"<<endl<<endl;
            displayList(node->next);

    }
int main()
{
    int x;
    struct Employee* head = NULL;
    cout<<"*******************"<<endl;
    cout<<"*****EMPLOYEE MANAGEMENT SYSTEM******"<<endl;
    cout<<"*******************"<<endl<<endl;
    cout<<" 1-->Press '1' to INSERT EMPLOYMENT: "<<endl;
    cout<<" 2-->Press '2' to FIND EMPLOYMENT INFO ID: "<<endl;
    cout<<" 3-->Press '3' to DELETE EMPLOYMENT ID: "<<endl;
    cout<<" 5-->Press '4' to DISPLAY ALL EMPLOYMENTS: "<<endl;
    cout<<" 6-->Press '5' to Update Salary: "<<endl;
    cout<<" 7-->Press '6' to EXIT: "<<endl<<endl;
    cin>>x;
    while(x!=0)
    {
        if(x==1)
        {
            string fname;
            string lname;
            int id;
            string first_dayOfWork;
            long phoneNumber;
            string address;
            int workHours;
            double salary;
            int s;
            cout<<"Enter employee ID: ";
            cin>>id;
            s = find(head, id);
            if(id<= s){
               cout<<"Employee is exist"<<endl;
            }
            else{
                 cout<<"Enter employee First Name: ";
            cin>>fname;
            cout<<"Enter employee Last Name: ";
            cin>>lname;
            cout<<"Enter employee first day Of Work: ";
            cin>>first_dayOfWork;
            cout<<"Enter employee phone number: ";
            cin>>phoneNumber;
            cout<<"Enter employee address: ";
            cin>>address;
            cout<<"Enter employee work hours: ";
            cin>>workHours;
            cout<<"Enter employee salary: ";
            cin>>salary;
            cout<<"The employee record was added successfully."<<endl<<endl;
            append(&head, fname, lname, id, first_dayOfWork, phoneNumber, address, workHours, salary);
            }
        }
        else if(x==2)
        {
            int id;
            cout<<"Enter employee ID: ";
            cin>>id;
            findEmployee(head, id);
        }
        else if(x==3)
        {
            int id;
            cout<<"Enter employee ID: ";
            cin>>id;
            deleteEmployee(&head, id);
        }

        else if(x==4)
        {
            cout<<"The list of employees in the system are: "<<endl<<endl;
            displayList(head);
        }

        else if(x==5)
        {
            int id;
            int newSalary;
            cout<< "Enter employee id"<< endl;
            cin>> id;
            cout<< "Enter new salary"<< endl;
            cin>> newSalary;
            updateSalary(head, id, newSalary);
        }
        else if(x==6)
        {
            exit(0);
        }
        else
        {
        cout<<"*******************"<<endl;
        cout<<"*****EMPLOYEE MANAGEMENT SYSTEM******"<<endl;
        cout<<"*******************"<<endl<<endl;
        cout<<" 1-->Press '1' to INSERT EMPLOYMENT: "<<endl;
        cout<<" 2-->Press '2' to FIND EMPLOYMENT INFO ID: "<<endl;
        cout<<" 3-->Press '3' to DELETE EMPLOYMENT ID: "<<endl;
        cout<<" 5-->Press '4' to DISPLAY ALL EMPLOYMENTS: "<<endl;
        cout<<" 6-->Press '5' to Update Salary: "<<endl;
        cout<<" 7-->Press '6' to EXIT: "<<endl<<endl;
        cin>>x;
        }
        cout<<"*******************"<<endl;
        cout<<"*****EMPLOYEE MANAGEMENT SYSTEM******"<<endl;
        cout<<"*******************"<<endl<<endl;
        cout<<" 1-->Press '1' to INSERT EMPLOYMENT: "<<endl;
        cout<<" 2-->Press '2' to FIND EMPLOYMENT INFO ID: "<<endl;
        cout<<" 3-->Press '3' to DELETE EMPLOYMENT ID: "<<endl;
        cout<<" 5-->Press '4' to DISPLAY ALL EMPLOYMENTS: "<<endl;
        cout<<" 6-->Press '5' to Update Salary: "<<endl;
        cout<<" 7-->Press '6' to EXIT: "<<endl<<endl;
        cin>>x;
    }

}
