#include <iostream.h>
#include <string.h>
#include <stdlib.h>
#include <fstream.h>

class contact
{
public:
  contact();
  ~contact();
  static int const GetNumber(){return number;}
  char* const GetName(){return &itsName[0];}
  int const GetPhone(){return itsPhone;}
  char* const GetEmail(){return &itsEmail[0];}
  void SetName(char* name){strcpy(itsName,name);}
  void SetPhone(int phone){itsPhone = phone;}
  void SetEmail(char* email){strcpy(itsEmail,email);}
private:
  char itsName[256];
  int itsPhone;
  char itsEmail[256];
  static int number;
};

contact::contact()
{number++;}

contact::~contact()
{number--;}

int contact::number = 0;

int menu();
void view(contact*);
void copy(contact&, contact&);
void set(contact&);
int fgetContact(contact&);
void save(contact*);

int main()
{
  contact* persons = new contact[0];
  contact* temp = new contact[0];

/*
  delete[] persons;
  persons = new contact[1];
  int a = fgetContact(persons[0]);
  cout << "a:\t" << a << endl; flush(cout);
*/

  delete[] temp;

  int choice = 0;
  while(choice != 5)
  {
    choice = menu();

    switch((int)choice)
    {
    case 1:
      view(persons);
      break;
    case 2:
    {
      int n = contact::GetNumber();
      temp = new contact[n];
      for(int i=0; i<n; i++)
        copy(temp[i], persons[i]);
      delete[] persons;
      persons = NULL;
      persons = new contact[n+1];
      for(int i=0; i<n; i++)
        copy(persons[i], temp[i]);
      delete[] temp;
      temp = NULL;
      set(persons[n]);
      break;
    }
    case 3:
    {
      int i;
      cout << "Enter index number:";
      cin >> i;
      if(i<contact::GetNumber())
        set(persons[i]);
      else
        cout << "There are not that contacts\n";
      break;
    }
    case 4:
    {
      char x[256];
      int n = contact::GetNumber();
      cout << "Enter index number:";
      cin.getline(x, 255);
      int index = atoi(x);

      if(index>=contact::GetNumber())
        cout << "There are not that contacts\n";

      contact* temp = new contact[n-1];
      for(int i=0; i<n; i++)
      {
        if(i>=index)
          copy(temp[i-1], persons[i]);
        else
          copy(temp[i], persons[i]);
      }
      delete[] persons;
      persons = NULL;
      persons = new contact[n-1];
      for(int i=0; i<n-1; i++)
        copy(persons[i], temp[i]);
      delete[] temp;
      temp = NULL;
      break;
    }
    case 5:
    save(persons);
    break;

    default:
      break;
    }
  }

  return 0;
}

int menu()
{
  char choice[256];

  cout << "\nWhat would you like to do?\n";
  cout << "1. View Contacts\n";
  cout << "2. Add a Contact\n";
  cout << "3. Modify a Contact\n";
  cout << "4. Delete a Contact\n";
  cout << "5. Quit this program\n";
  cin.getline(choice, 255);

  return atoi(choice);
}

void view(contact* persons)
{
  cout << "Name\t\tHome\t\tE-mail\n";
  cout << "----------------------------------------------------------------\n";
  for(int i=0; i<contact::GetNumber(); i++)
  {
    cout << persons[i].GetName() << "\t";
    cout << persons[i].GetPhone() << "\t";
    cout << persons[i].GetEmail() << "\t";
    cout << endl;
  }
}

void copy(contact& dest, contact& src)
{
  char name[256];
  strcpy(name,src.GetName());
  dest.SetName(name);

  int phone = src.GetPhone();
  dest.SetPhone(phone);

  char email[256];
  strcpy(email,src.GetEmail());
  dest.SetEmail(email);
}

void set(contact &persons)
{
  char name[256], phone[256], email[256];
  cout << "Enter contact's\n";
  cout << " name:";
  cin.getline(name, 255);
  cout << " phone number:";
  cin.getline(phone, 255);
  cout << " e-mail address:";
  cin.getline(email, 255);

  persons.SetName(name);
  persons.SetPhone(atoi(phone));
  persons.SetEmail(email);
}

int fgetContact(contact &persons)
{
  char buffer[256];
  int phone;
  int ret;

  ifstream infile("adrsbk.dat", ios::in);

  infile.getline(buffer, 255);
  persons.SetName(buffer);
  infile.getline(buffer, 255);
  phone = atoi(buffer);
  persons.SetPhone(phone);
  infile.getline(buffer, 255);
  persons.SetEmail(buffer);

  if(infile.eof() == NULL)
    ret = 0;
  else
    ret = 1;

  if(infile.is_open() != NULL)
    infile.close();

  return ret;
}

void save(contact * persons)
{
  char filename[256] = "adrsbk.dat";

  ofstream outfile(filename, ios::out);

  for(int i=0; i<contact::GetNumber(); i++)
  {
    outfile << persons[i].GetName() << endl;
    outfile << persons[i].GetPhone() << endl;
    outfile << persons[i].GetEmail() << endl;
    outfile << endl;
  }

  if(outfile.is_open() != NULL)
    outfile.close();
}