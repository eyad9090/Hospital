#include<bits/stdc++.h>
using namespace std;
//------data
const int specializations=20;
const int patients=5;
string patient_name[specializations][patients];
int patient_status[specializations][patients];
int idxs[specializations];

//-------helper functions
char to_upper(char c);
char to_lower(char c);
char is_lower(char c);
char is_upper(char c);
string to_lower(string str);
int string_to_integer(string number);
int get_integer_in_range(int range_start,int range_end);
bool is_only_character_space(string str);
string get_character_space(string message);

//--------main functions
void specializations_list();
void add_new_patient();
void print_patients();
void get_next_patient();
void menu();
void start_program();




int main()
{
    start_program();
    return 0;
}

//-------------helper functions
char to_upper(char c)
{
    if(is_lower(c))
    {
        c=(char)(c-'a'+'A');
    }
    return c;
}
char to_lower(char c)
{
    if(is_upper(c))
    {
        c=(char)(c-'A'+'a');
    }
    return c;
}
char is_lower(char c)
{
    if(c>='a'&&c<='z')
        return true;
    return false;
}
char is_upper(char c)
{
    if(c>='A'&&c<='Z')
        return true;
    return false;
}

string to_lower(string str)
{
    for(char &c:str)
    {
        if(is_upper(c))
        {
            c=to_lower(c);
        }
    }
    return str;
}


int string_to_integer(string number)
{
    int ans=0;
    for(int i=0; i<number.size(); i++)
    {
        if(number[i]>='0'&&number[i]<='9')
        {
            ans=ans*10+(number[i]-'0');
        }
        else
            return -1;
    }
    return ans;
}

int get_integer_in_range(int range_start,int range_end)
{
    string choice;
    cin>>choice;
    int ans=-1;
    while(ans==-1)
    {
        ans=string_to_integer(choice);
        if(ans>=range_start&&ans<=range_end)
        {
            return ans;
        }
        else
        {
            cout<<"Invalid\n";
            cout<<"Please enter valid number in range["
                <<range_start<<"-"<<range_end<<"]: ";
            cin>>choice;
            ans=-1;
        }
    }
}

bool is_only_character_space(string str)
{
    for(char c:str)
    {
        if( (c>='a'&&c<='z') || (c>='A'&&c<='Z')||c==' ' )
        {
            continue;
        }
        return false;
    }
    return true;
}
string get_character_space(string message)
{
    cout<<message;
    string str;
    fflush(stdin);
    getline(cin,str);
    while(!is_only_character_space(str))
    {
        cout<<"invalid\n";
        cout<<message;
        cin>>str;
    }
    str=to_lower(str);
    return str;
}



//main functions
void start_program()
{
    while(true)
    {
        cout<<"-------menu-----------\n\n";
        menu();
        cout<<"Please enter you choice:";
        int choice=get_integer_in_range(1,4);
        if(choice==1)
        {
            add_new_patient();
        }
        else if(choice==2)
        {
            print_patients();
        }
        else if(choice==3)
        {
            get_next_patient();
        }
        else if(choice==4)
        {
            return ;
        }
    }
}

void menu()
{
    cout<<"1) Add new patient\n"
        <<"2) Print all patients\n"
        <<"3) Get next patient\n"
        <<"4) Exit program\n";
}
void specializations_list()
{
    cout<<"1) Cardiologist\n"
        <<"2) Gynecologist\n"
        <<"3) Neurologist\n"
        <<"4) Dermatologist\n"
        <<"5) Family Medicine\n"
        <<"6) Pediatrician\n"
        <<"7) Endocrinologist\n"
        <<"8) Gastroenterologist\n"
        <<"9) Oncologist\n"
        <<"10) Psychiatrist\n"
        <<"11) Internist\n"
        <<"12) Allergist\n"
        <<"13) Nephrologist\n"
        <<"14) Emergency Medicine\n"
        <<"15) Radiologist\n"
        <<"16) Ophthalmologist\n"
        <<"17) Geriatrician\n"
        <<"18) Infectious Disease Specialist\n"
        <<"19) Otolaryngologist\n"
        <<"20) Pulmonologist\n";
}
void add_new_patient()
{
    cout<<"-----add patient option-------\n\n";
    specializations_list();
    cout<<"Please enter your specialization:";
    int spec=get_integer_in_range(1,specializations);
    int idx=idxs[spec];
    if(idx>=5)
    {
        cout<<"This specialization is full of patients\n";
        return ;
    }
    string name=get_character_space("please enter name:");
    cout<<"Please enter the status:";
    int status=get_integer_in_range(0,1);

    if(status==0)
    {
        patient_name[spec][idx]=name;
        patient_status[spec][idx]=status;
    }
    else
    {
        for(int i=idx;i>0;i--)
        {
            patient_name[spec][i]=patient_name[spec][i-1];
            patient_status[spec][i]=patient_status[spec][i-1];
        }
        patient_name[spec][0]=name;
        patient_status[spec][0]=status;
    }
    idxs[spec]++;
}
void print_patients()
{
    cout<<"-----Print patient option-------\n\n";
    specializations_list();
    cout<<"Please enter your specialization:";
    int spec=get_integer_in_range(1,specializations);
    int idx=idxs[spec];
    if(idx==0)
    {
        cout<<"There is not any patients\n";
        return;
    }
    cout<<"There are "<<idx<<" patients\n";
    for(int i=0;i<idx;i++)
    {
        cout<<patient_name[spec][i]<<"\t"
        <<(patient_status[spec][i]==0?"Normal":"Urgent")<<"\n";
    }
}

void get_next_patient()
{
    cout<<"-----get the next patient option-------\n\n";
    specializations_list();
    cout<<"Please enter your specialization:";
    int spec=get_integer_in_range(1,specializations);
    int idx=idxs[spec];
    if(idx==0)
    {
        cout<<"There is not patient\n";
        return ;
    }
    cout<<"Patient:"<<patient_name[spec][0]
    <<" please go with the doctor\n";
    for(int i=0;i<idx-1;i++)
    {
        patient_name[spec][i]=patient_name[spec][i+1];
        patient_status[spec][i]=patient_status[spec][i+1];
    }
    idxs[spec]--;
}






