#include <bits/stdc++.h>

using namespace std;
// Node structure for linked list
struct Node
{
    int id;
    string name;
    string specialization; // Only for doctors
    string location;       // Only for branches
    string address;        // Only for patients
    string appointment;    // Only for patients
    Node* next;
};
// manage linked list operations
class LinkedList{
public:
    Node* head;

    LinkedList()
    {
        head = NULL;
    }

    // Function to check linked list is empty or not
    bool isempty(){
        if(head==NULL){
            return true;
        }else{
            return false;
        }
    }

    // Function to add a new node
    void addNode(int id, string name, string specialization = "", string location = "", string address = "", string appointment = "")
    {
        Node* newNode = new Node;
        newNode->id = id;
        newNode->name = name;
        newNode->specialization = specialization;
        newNode->location = location;
        newNode->address = address;
        newNode->appointment = appointment;
        newNode->next = head;
        head = newNode;
    }

    // Function to display all nodes
    void displayNodes()
    {
        Node* temp = head;
        while (temp != NULL)
        {
            cout << "ID: " << temp->id << ", Name: " << temp->name;
             if (!temp->specialization.empty())
                cout << ", Specialization: " << temp->specialization;
            if (!temp->location.empty())
                cout << ", Location: " << temp->location;
            if (!temp->address.empty())
                cout << ", Address: " << temp->address;
            if (!temp->appointment.empty())
                cout << ", Appointment: " << temp->appointment;
            cout << endl;
            temp = temp->next;
        }
    }

    // Function to search for a node by ID
     Node* searchById(int id)
     {
        Node* temp = head;
        while (temp != NULL)
        {
            if (temp->id == id)
            {
                cout << temp->id << "" << temp->name << "" << temp->location ;
                return temp;
            }
            temp = temp->next;

        }
        return NULL;
    }

    // Function to remove a node by ID
    void removeNode(int id)
    {
        Node* temp = head;
        Node* prev = NULL;

        while (temp != NULL)
        {
            if (temp->id == id)
            {
                if (prev != NULL)
                {
                    prev->next = temp->next;
                }
                else
                {
                    head = temp->next;
                }
                delete temp;
                cout << "Node with ID " << id << " removed successfully." << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }

        cout << "Node with ID " << id << " not found." << endl;
    }
};
// Hospital Management System class
class HospitalManagementSystem{
public:
    LinkedList hospitalList;
    LinkedList doctorList;
    LinkedList patientList;

    // Function to add a new branch
     void addBranch(int id, string name, string location)
    {
        hospitalList.addNode(id, name, "", location);
        cout << "Branch added successfully." << endl;
    }

     // Function to display all branches
    void displayBranches()
    {
        hospitalList.displayNodes();
    }

    // Function to search for a branch by ID
    Node* searchBranchById(int id)
    {
        return hospitalList.searchById(id);
    }

    // Function to remove a branch (Bonus)
    void removeBranch(int id)
    {
        hospitalList.removeNode(id);
    }

    // Function to add a new doctor
    void addDoctor(int id, string name, string specialization, int branchId)
    {
        Node* branch = searchBranchById(branchId);
        if (branch != NULL)
        {
            doctorList.addNode(id, name, specialization, branch->name);
            cout << "Doctor added successfully." << endl;
        }
        else
        {
            cout << "Branch with ID " << branchId  << " not found." << endl;
        }
    }

    // Function to remove a doctor
    void removeDoctor(int id)
    {
        doctorList.removeNode(id);
    }

    // Function to display all appointments
    void displayAppointments()
    {
        patientList.displayNodes();
    }

    // Function to add a new patient
    void addPatient(int id, string name, string address)
    {
        patientList.addNode(id, name, "", "", address);
        cout << "Patient added successfully." << endl;
    }

    // Function to remove a patient
    void removePatient(int id)
    {
        patientList.removeNode(id);
    }

     // Function to book an appointment
    void bookAppointment(int patientId)
    {
        Node* patient = patientList.searchById(patientId);
        if (patient != NULL)
        {
            cout << "Appointment booked for patient " << patient->name << " with ID " << patientId << "." << endl;
        }
        else
        {
            cout << "Patient with ID " << patientId << " not found." << endl;
        }
    }

    // Function to search for a patient by name
    Node* searchPatientByName(string name)
    {
        Node* temp = patientList.head;
        while (temp != NULL)
        {
            if (temp->name == name)
            {
                cout << temp->id << "" << temp->name << "" << temp->address ;
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

    // Function to update patient information (Bonus)
    void updatePatientInformation(int id, string newName, string newAddress)
    {
        Node* patient = patientList.searchById(id);
        if (patient != NULL)
        {
            patient->name = newName;
            patient->address = newAddress;
            cout << "Patient information updated successfully." << endl;
        }
        else
        {
            cout << "Patient with ID " << id << " not found." << endl;
        }
    }


    // Function to display all appointments in each branch (Bonus)
    void displayAppointmentsInEachBranch()
    {
         Node* doctorNode = doctorList.head;


    while (doctorNode != NULL)
    {
        cout << "Doctor: " << doctorNode->name << ", Branch: " << doctorNode->location << endl;

        Node* patientNode = patientList.head;


        while (patientNode != NULL)
        {
            // Check if the patient's appointment is equal with the current doctor's branch
            if (patientNode->location == doctorNode->location)
            {
                cout << "  Patient: " << patientNode->name << ", Appointment: " << patientNode->appointment << endl;
            }

            patientNode = patientNode->next;
        }

        cout << endl;
        doctorNode = doctorNode->next;
    }
    }

};
int main()
{
    HospitalManagementSystem ab ;

    cout<<"Hello..! \n";

    int id1,id2,id3;
    string name1,name2,name3,location1,location2,location3;

    cout<<"Please, add your first branch (id, name, location). \n";
    cin>>id1>>name1>>location1;
    ab.addBranch(id1,name1,location1);
    ab.displayBranches();

    cout<<"Please, add your second branch (id, name, location). \n";
    cin>>id2>>name2>>location2;
    ab.addBranch(id2,name2,location2);
    ab.displayBranches();

    cout<<"Please, add your third branch (id, name, location). \n";
    cin>>id3>>name3>>location3;
    ab.addBranch(id3,name3,location3);
    ab.displayBranches();

    int helper1,helper2;

    cout<<"Can you search about branch by id. \n";
    cin>>helper1;
    ab.searchBranchById(helper1);

    cout<<"Can you search about another branch by id. \n";
    cin>>helper2;
    ab.searchBranchById(helper2);

    int a1=0,a2=0;

    cout<<"Can you remove branch by id. \n";
    cin>>a1;
    ab.removeBranch(a1);

    cout<<"Can you remove another branch by id. \n";
    cin>>a2;
    ab.removeBranch(a2);


    int x1,x2,x3,x4,x5,y1,y2,y3,y4,y5;
    string q1,q2,q3,q4,q5,w1,w2,w3,w4,w5;

    cout<<"Please, add your first doctor information (Id, Name, Specialization, Branch Id). \n";
    cin>>x1>>q1>>w1>>y1;
    ab.addDoctor(x1,q1,w1,y1);

    cout<<"Please, add your Second doctor information (Id, Name, Specialization, Branch Id). \n";
    cin>>x2>>q2>>w2>>y2;
    ab.addDoctor(x2,q2,w2,y2);


    cout<<"Please, add your third doctor information(Id, Name, Specialization, Branch Id). \n";
    cin>>x3>>q3>>w3>>y3;
    ab.addDoctor(x3,q3,w3,y3);


    cout<<"Please, add your fourth doctor information(Id, Name, Specialization, Branch Id). \n";
    cin>>x4>>q4>>w4>>y4;
    ab.addDoctor(x4,q4,w4,y4);


    cout<<"Please, add your fifth doctor information(Id, Name, Specialization, Branch Id). \n";
    cin>>x5>>q5>>w5>>y5;
    ab.addDoctor(x5,q5,w5,y5);


    int t1,t2;
    cout<<"Please, remove doctor information by id. \n";
    cin>>t1;
    ab.removeDoctor(t1);

    cout<<"Please, remove another doctor information by id. \n";
    cin>>t2;
    ab.removeDoctor(t2);


    int k1;
    string o1,p1;


    cout<<"Please,add your first patient \n";
    cin>>k1>>o1>>p1;
    ab.addPatient(k1,o1,p1);

}
