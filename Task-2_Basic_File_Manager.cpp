#include<bits/stdc++.h>
#include<direct.h>
#include<conio.h>
#include<stdio.h>
using namespace std;
class manager{
public: 
void menu();
void create_file();
void create_folder();
void delete_folder();
void delete_file();
void copy_file();
void open_file();
void rename_file();
void message();
void move_file();
void delete_s_file();
};



void manager :: menu()
{
    system("cls");
    cout<<setw(15)<<setfill('-')<<"MENU"<<setw(11)<<setfill('-')<<"-"<<endl;
    cout<<"1.Create New Folder"<<endl;
    cout<<"2.Delete Folder"<<endl;
    cout<<"3.Create New File"<<endl;
    cout<<"4.Delete File"<<endl;
    cout<<"5.Copy File"<<endl;
    cout<<"6.Move file"<<endl;
    cout<<"7.Rename File"<<endl;
    cout<<"8.Open File"<<endl;
    cout<<"0.Exit.."<<endl;
    cout<<setw(15)<<setfill('-')<<"-"<<setw(11)<<setfill('-')<<"-"<<endl;
    int choice;
    cout<<"Enter Choice: "<<flush;
    cin>>choice;
    switch(choice){
        case 1: 
            create_folder();
            message();
            getch();
            menu();
            break;
        case 2:
            delete_folder();
            message();
            getch();
            menu();
            break;
        case 3: 
            create_file();
            message();
            getch();
            menu();
            break;
        case 4: 
            delete_file();
            message();
            getch();
            menu();;
            break;
        case 5:
            copy_file();
            message();
            getch();
            menu();
            break;
        case 6: 
            move_file();
            message();
            getch();
            menu();
            break;
        case 7: 
            rename_file();
            message();
            getch();
            menu();
            break;
        case 8: 
            open_file();
            break;
        case 0:
            exit(0);
            
            
    }
}
void manager::create_file(){
    string path;
    cout<<"Enter File Name: "<<flush;
    cin>>path;
    ofstream fout(path, ios::app);
    string s;
    level:
    cout<<"Enter the Data (which would you like to store): "<<flush;
    
    while(fout)
    {
        cin.ignore();
        getline(cin,s);
        cout<<"Press 0 to exit.. else continue..."<<endl;
        int n;
        cout<<"Enter: "<<flush;
        cin>>n;
        fout<<s<<endl;
        if(n != 0) goto level; else break;
        
    }
    fout.close();
}



void manager ::create_folder()
{
    char* folderName;
    cout<<"Enter Folder Name: "<<flush;
    cin>>folderName;
    
    if(mkdir(folderName)){
        cout<<"Folder is Not Created"<<endl;
        cout<<"Try again!"<<endl;
    } else{
        cout<<"Folder is Created"<<endl;
    }
     
}


void manager::delete_folder()
{
    char* folder;
    cout<<"Enter the folder Name: "<<flush;
    cin>>folder;
    if(rmdir(folder)){
        cout<<"Folder is not Deleted"<<endl;
    }else{
        cout<<"Folder is Deleted"<<endl;
    } 
}
 

 void manager ::copy_file()
 {
    string s;
    string source;
    cout<<"Enter Old File Name: "<<flush;
    cin>>source;
    fstream s_file(source, ios::in);
    string destination ;
    cout<<"Enter New File Name: "<<flush;
    cin>>destination;
    fstream d_file(destination, ios::app);
    while(getline(s_file,s))
    {
        d_file<<s<<endl;
    }
    s_file.close();
    d_file.close();
    cout<<"Successfully Copied File"<<endl;
    
 }


void manager ::delete_file()
{
    char* fileName;
    cout<<"Enter the File Name: "<<flush;
    cin>>fileName;
    if(remove(fileName)){
        cout<<"Error"<<endl;
    }else{
        cout<<"Successfully Deleted File"<<endl;
    }
    
}

void manager::open_file(){
    string path,data;
    cout<<"Enter file Name: "<<flush;
    cin>>path;
    fstream fin(path,ios::in);
    system("cls");
    while(!fin.eof())
    {
        getline(fin,data);
        cout<<data<<endl;
    }
    message();
    getch();
    menu();
     
    
}
void manager::rename_file()
{
    string fileName,re_fileName;
    cout<<"Enter The Old File Name: "<<flush;
    cin>>fileName;
    cout<<endl<<"Enter New file Name:"<<flush;
    cin>>re_fileName;
    if(rename((char*)&fileName,(char*)&re_fileName) ){
        cout<<"Rename is not Successful"<<endl;
    }else{
        cout<<"Successfully Rename"<<endl;
    }
    
}
void manager::message()
{
     cout<<"Press any key to HOME"<<endl;
}
void manager::move_file()
{
   string path, destination;
   cout<<"Enter the Source file Name:"<<flush;
   cin>>path;
   fstream fin(path,ios::in);
   cout<<"Enter the Destination File Name: "<<flush;
   cin>>destination;
   fstream fout(destination,ios::app);
   string data;
    while(!fin.eof())
    {
        fin>>data;
        fout<<data<<endl;
    }
    fin.close();
    fout.close();
    delete_s_file();
}
void manager ::delete_s_file()
{
    char* fileName;
    cout<<"Enter Again Source File Name: "<<flush;
    cin>>fileName;
    if(remove(fileName)){
        cout<<"Error"<<endl;
    }else{
        cout<<"Successfully Moved File"<<endl;
    }
    
}
/// //////////////////////////main function//////////////////////////
void open_project()
{
    system("cls");
    cout<<"WELCOME TO OUR PROJECT"<<endl;
    getch();
    cout<<"Project Name: Basic File Manager"<<endl;
    getch();
    cout<<"            Given by: CodeAlpha"<<endl;
    getch();
}

int main()
{
    open_project();
    manager m;
    m.menu();
}
