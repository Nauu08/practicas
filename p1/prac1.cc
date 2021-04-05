//DNI 24422696P Mario Arnau Sabater

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

struct Date{
  int day;
  int month;
  int year;
};

struct Task{
  string name;
  Date deadline;
  bool isDone;
  int time;
};

struct List{
  string name;
  vector<Task> tasks;
};

struct Project{
  int id;
  string name;
  string description;
  vector<List> lists;
};

enum Error{
  ERR_OPTION,
  ERR_EMPTY,
  ERR_LIST_NAME,
  ERR_TASK_NAME,
  ERR_DATE,
  ERR_TIME
};

void error(Error e){
  switch(e){
    case ERR_OPTION:
      cout << "ERROR: wrong menu option" << endl;
      break;
    case ERR_EMPTY:
      cout << "ERROR: empty string" << endl;
      break;
    case ERR_LIST_NAME:
      cout << "ERROR: wrong list name" << endl;
      break;
    case ERR_TASK_NAME:
      cout << "ERROR: wrong task name" << endl;
      break;
    case ERR_DATE:
      cout << "ERROR: wrong date" << endl;
      break;
    case ERR_TIME:
      cout << "ERROR: wrong expected time" << endl;
  }
}

void showMainMenu(){
  cout << "1- Edit project" << endl
       << "2- Add list" << endl
       << "3- Delete list" << endl 
       << "4- Add task" << endl
       << "5- Delete task" << endl
       << "6- Toggle task" << endl
       << "7- Report" << endl
       << "q- Quit" << endl
       << "Option: ";
}

void editProject(Project &toDoList){
    
    cout<<"Enter Project Name: "<<endl;
    getline(cin,toDoList.name);
    
    do{

        error(ERR_EMPTY);

        cout<<"\nEnter a Correct Project Name: "<<endl;
        getline(cin,toDoList.name);

    }while(toDoList.name.empty()==true);

    cout<<"Enter Description Name: "<<endl;
    getline(cin,toDoList.description);

}

void addList(Project &toDoList){
    List nuevaLista;
    
    cout<<"Enter List Name: "<<endl;
    getline(cin,nuevaLista.name);

    do{
      
      error(ERR_EMPTY);
      
      cout<<"\nEnter a Correct List Name: "<<endl;
      getline(cin,nuevaLista.name);
      
    }while(nuevaLista.name.empty());
    
    toDoList.lists.push_back(nuevaLista);
    //no se comprobar si la lista ya está existente o no.
}

void deleteList(Project &toDoList){
    List nuevaLista;

    cout<<"Enter List Name: "<<endl;
    getline(cin,nuevaLista.name);

    do{
      
      error(ERR_EMPTY);
      
      cout<<"\nEnter a Correct List Name: "<<endl;
      getline(cin,nuevaLista.name);
      
    }while(nuevaLista.name.empty());
    //no se como comprobar si la lista está o no.
}

void addTask(Project &toDoList){
  List nuevaLista;
  Task nuevoTask;

  cout<<"Enter List Name: "<<endl;
  getline(cin,nuevaLista.name);

  do{
    
    error(ERR_EMPTY);
    
    cout<<"\nEnter a Correct List Name: "<<endl;
    getline(cin,nuevaLista.name);
    
  }while(nuevaLista.name.empty());
  //no se comprobar si hay una lista con el mismo nombre.

  cout<<"Enter New Task: "<<endl;
  getline(cin,nuevoTask.name);

  cout<<"Enter deadline: (d/m/aaaa)"<<endl;
  
}

void deleteTask(Project &toDoList){
  List nuevaLista;
  cout<<"Enter List Name: "<<endl;
  getline(cin,nuevaLista.name);
  
  do{
    
    error(ERR_EMPTY);
    
    cout<<"\nEnter a Correct List Name: "<<endl;
    getline(cin,nuevaLista.name);
    
  }while(nuevaLista.name.empty());

  
}

void toggleTask(Project &toDoList){
    
}

void report(const Project &toDoList){
    
}

int main(){
  Project toDoList;
  toDoList.id=1;
  char option;
  
  do{
    showMainMenu();
    cin >> option;
    cin.get();
    
    switch(option){
      case '1': editProject(toDoList);
                break;
      case '2': addList(toDoList);
                break;
      case '3': deleteList(toDoList);
                break;
      case '4': addTask(toDoList);
                break;
      case '5': deleteTask(toDoList);
                break;
      case '6': toggleTask(toDoList);
                break;
      case '7': report(toDoList);
                break;
      case 'q': break;
      default: error(ERR_OPTION);
    }
  }while(option!='q');
  
  return 0;    
}
