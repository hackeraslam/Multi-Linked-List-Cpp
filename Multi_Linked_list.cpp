// Author: Aslam Khan
// Email : aslamkhanofficial@yahoo.com
// Institute : Air University Islamabad

#include<iostream>
#include<string>
using namespace std;

class Personal
{
public:
	string name;
	string fname;
	string cls;
	int roll;
	Personal()
	{
		name = "";
		fname = "";
		cls = "";
		roll = 0;
	}
};

class Student_node
{
public:
	Personal info;
	Student_node* next;
	
	Student_node()
	{
		Personal();
		next = NULL;
	}

};



class Subject_node
{
public:
	string subject;
	int key;
	Subject_node* sub_next;
	Student_node* child;

	Subject_node()
	{
		subject = "";
		int key = 0;
		sub_next = NULL;
		child = NULL;
	}
};

class Subject_list
{
public:
	Subject_node* sub_head;

	Subject_list()
	{
		sub_head = NULL;
	}
	void Add_Subject(Subject_node* n);
	void Display_list();
	void Add_student(Subject_node* n);
	void Display_student(int , Subject_node*);
	void Display_student_list(Subject_node*);
};



int main()
{
	Subject_list Sub;
	string subject;
	int key;
	int ch;
	while (true)
	{
		system("cls");
		cout << "1 = Add New Subject" << endl;
		cout << "2 = Show All Subjects" << endl;
		cout << "3 = Subject Detail" << endl;
		cout << "Enter Choice = ";
		cin >> ch;
		system("cls");
		
		bool flag = false;
		Subject_node* n = new Subject_node();
		Subject_node* temp = Sub.sub_head;
		switch (ch)
		{
		case 1:
			system("cls");
			cin.ignore();
			cout << "Enter Subject Name = ";
			getline(cin, subject);
			cout << "Enter Subject Key = ";
			cin >> key;
			cin.ignore();
			n->subject = subject;
			n->key = key;
			n->child = NULL;
			Sub.Add_Subject(n);
			system("pause");
			system("cls");
			break;

		case 2:
			system("cls");
			Sub.Display_list();
			system("pause");
			system("cls");
			break;

		case 3:
			cout << "Enter Subject Key = ";
			cin >> key;
			cin.ignore();
			
			
			if (Sub.sub_head == NULL)
			{	
				system("cls");
				cout << "Subject List is Empty.." << endl;
				system("pause");
				system("cls");
			}
			else
			{
				while (temp != NULL)
				{
					if (key == temp->key)
					{
						flag = true;
						break;
					}
					temp = temp->sub_next;

				}
			}
			if (flag == true)
			{
				do {
					int rol;
					system("cls");
					cout << "1 = Add Student to List " << endl;
					cout << "2 = Show Student List" << endl;
					cout << "3 = Search Student" << endl;
					cout << "0 = Return MainManu" << endl;
					cin >> ch;
					cin.ignore();
					switch (ch)
					{
					case 1:
						Sub.Add_student(temp);
						system("pause");
						break;
					case 2:
						system("cls");
						Sub.Display_student_list(temp);
						system("pause");
						system("cls");
						break;
					case 3:
						cout << "Enter Roll Number ";
						cin >> rol;
						cin.ignore();
						system("cls");
						Sub.Display_student(rol, temp);
						system("pause");
						system("cls");
						
						break;
					case 0:

						break;
					default:
						cout << "Invalid Opetion Selected.." << endl;
						break;
					}
				} while (ch != 0);
			}

			break;
		
		default:
			cout << "Invalid Option Selected.." << endl;
			break;
		}




	}



	system("pause");
}



void Subject_list::Add_Subject(Subject_node* n)
{
	Subject_node* temp = sub_head;
	if (sub_head == NULL)
	{
		sub_head = n;
		cout << "Subject is Added Sucessfully..." << endl;
	}
	else
	{
		while (temp->sub_next != NULL)
		{
			temp = temp->sub_next;
		}
		temp->sub_next = n;
		cout << "Subject is Added Sucessfully..." << endl;
	}

}

void Subject_list::Display_list()
{
	Subject_node* temp = sub_head;
	if (sub_head == NULL)
	{
		cout << "List is Empty..." << endl;
		
	}
	else
	{
		while (temp != NULL)
		{
			cout << "Subject : " << temp->subject << "\tKey : " << temp->key << endl;
			temp = temp->sub_next;
		}
	}
}

void Subject_list::Add_student(Subject_node* n)
{
	Student_node* s = new Student_node();
	Personal P;
	string name;
	string fname;
	string cls;
	int roll;
	cout << "Enter Name = ";
	getline(cin, name);
	cout << "Enter Father Name = ";
	getline(cin, fname);
	cout << "Enter Class = ";
	getline(cin, cls);
	cout << "Enter Roll Number = ";
	cin >> roll;
	P.name = name;
	P.fname = fname;
	P.cls = cls;
	P.roll = roll;
	s->info = P;
	if (n->child == NULL)
	{
		n->child = s;
		cout << "Student Data is Entered Sucessfully.." << endl;
	}
	else
	{
		Student_node* temp = n->child;
		while (temp->next != NULL)
		{
			temp = temp->next;

		}
		temp->next = s;
		cout << "Student data is Added Sucessfully..." << endl;
	}
	
}

void Subject_list::Display_student(int k, Subject_node* n)
{
	if (n->child == NULL)
	{
		cout << "Subject LIst is Empty..." << endl;
	}
	else
	{
		bool flag = false;
		Student_node* temp = n->child;
		while (temp != NULL)
		{
			if (temp->info.roll == k)
			{
				flag = true;
				break;
			}
			else
			{
				flag = false;
				temp = temp->next;
			}
		}
		if (flag == true)
		{
			cout << "Name = " << temp->info.name << endl;
			cout << "Father Name  = " << temp->info.fname << endl;
			cout << "Class = " << temp->info.cls << endl;
			cout << "Roll No. = " << temp->info.roll << endl;
			cout << endl;
		}
		else
		{
			cout << "No Record Found.." << endl;
		}

	}
}


void Subject_list::Display_student_list(Subject_node* n)
{
	Student_node* temp = n->child;
	if (n->child == NULL)
	{
		cout << "Subject List is Empty..." << endl;
	}
	else
	{
		while (temp != NULL)
		{
			cout << "Name = " << temp->info.name << "\t Roll No. = " << temp->info.roll << endl;
			temp = temp->next;
		}
	}


}
