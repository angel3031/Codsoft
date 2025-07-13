#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct Task {
    string description;
    bool isCompleted;

    Task(string desc) {
        description = desc;
        isCompleted = false;
    }
};


void showMenu() {
    cout << "\n============================\n";
    cout << "       TO-DO LIST      \n";
    cout << "============================\n";
    cout << " 1 Add a new task\n";
    cout << " 2 View all tasks\n";
    cout << " 3 Mark a task as completed\n";
    cout << " 4 Remove a task\n";
    cout << " 5 Exit the program\n";
    cout << "Please choose an option (1–5): ";
}


void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\n📭 Your to-do list is empty. Time to get productive!\n";
        return;
    }

    cout << "\n📝 Here are your tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". [" << (tasks[i].isCompleted ? "✔" : "✘") << "] " << tasks[i].description << endl;
    }
}


void addTask(vector<Task>& tasks) {
    cin.ignore(); 
    string newTask;
    cout << "\nWhat task would you like to add?  ";
    getline(cin, newTask);
    tasks.push_back(Task(newTask));
    cout << "Task added to your list!\n";
}


void completeTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\n No tasks to complete yet. Add some first!\n";
        return;
    }

    viewTasks(tasks);
    cout << "\nEnter the task number you completed: ";
    int taskNum;
    cin >> taskNum;

    if (taskNum < 1 || taskNum > tasks.size()) {
        cout << " Oops! That's not a valid task number.\n";
    } else {
        tasks[taskNum - 1].isCompleted = true;
        cout << " Great job! Task marked as completed.\n";
    }
}


void removeTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\n Your list is already empty.\n";
        return;
    }

    viewTasks(tasks);
    cout << "\nEnter the task number you want to remove: ";
    int taskNum;
    cin >> taskNum;

    if (taskNum < 1 || taskNum > tasks.size()) {
        cout << "Invalid task number. Please try again.\n";
    } else {
        tasks.erase(tasks.begin() + taskNum - 1);
        cout << " Task removed from your list.\n";
    }
}


int main() {
    vector<Task> taskList;
    int choice;

    cout << " Welcome to your personal To-Do List Manager!\n";

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(taskList);
                break;
            case 2:
                viewTasks(taskList);
                break;
            case 3:
                completeTask(taskList);
                break;
            case 4:
                removeTask(taskList);
                break;
            case 5:
                cout << "\n Goodbye! Stay productive and take care.\n";
                break;
            default:
                cout << " Invalid option. Please enter a number between 1 and 5.\n";
        }

    } while (choice != 5);

    return 0;
}
