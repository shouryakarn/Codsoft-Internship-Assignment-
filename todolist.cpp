#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Task {
private:
    string name;
    string description;
    string dueDate;
    bool completed;

public:
    Task(string n, string d, string dd) {
        name = n;
        description = d;
        dueDate = dd;
        completed = false;
    }

    string getName() { return name; }
    string getDescription() { return description; }
    string getDueDate() { return dueDate; }
    bool isCompleted() { return completed; }

    void setName(string n) { name = n; }
    void setDescription(string d) { description = d; }
    void setDueDate(string dd) { dueDate = dd; }
    void markCompleted() { completed = true; }
    void displayTask() {
        cout << "Task: " << name << endl;
        cout << "Description: " << description << endl;
        cout << "Due Date: " << dueDate << endl;
        cout << "Status: " << (completed ? "Completed" : "Pending") << endl;
    }
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void displayMenu() {
        cout << "------ To-Do List Menu ------" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Delete Task" << endl;
        cout << "3. Display Tasks" << endl;
        cout << "4. Mark Task as Completed" << endl;
        cout << "5. Edit Task" << endl;
        cout << "6. Exit" << endl;
    }

    void addTask() {
        string name, description, dueDate;
        cout << "Enter task name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter task description: ";
        getline(cin, description);
        cout << "Enter task due date (YYYY-MM-DD): ";
        getline(cin, dueDate);

        Task t(name, description, dueDate);
        tasks.push_back(t);
        cout << "Task added!" << endl;
    }

    void deleteTask() {
        if (tasks.size() == 0) {
            cout << "No tasks to delete!" << endl;
            return;
        }
        displayTasks();
        int taskNumber;
        cout << "Enter the task number to delete: ";
        cin >> taskNumber;

        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks.erase(tasks.begin() + taskNumber - 1);
            cout << "Task deleted!" << endl;
        } else {
            cout << "Invalid task number!" << endl;
        }
    }

    void displayTasks() {
        if (tasks.size() == 0) {
            cout << "No tasks to display!" << endl;
            return;
        }
        cout << "Tasks List:" << endl;
        for (int i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". " << tasks[i].getName() << " - " << (tasks[i].isCompleted() ? "Completed" : "Pending") << endl;
        }
    }

    void markTaskCompleted() {
        if (tasks.size() == 0) {
            cout << "No tasks to mark as completed!" << endl;
            return;
        }
        displayTasks();
        int taskNumber;
        cout << "Enter the task number to mark as completed: ";
        cin >> taskNumber;

        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].markCompleted();
            cout << "Task marked as completed!" << endl;
        } else {
            cout << "Invalid task number!" << endl;
        }
    }

    void editTask() {
        if (tasks.size() == 0) {
            cout << "No tasks to edit!" << endl;
            return;
        }
        displayTasks();
        int taskNumber;
        cout << "Enter the task number to edit: ";
        cin >> taskNumber;

        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            string name, description, dueDate;
            cout << "Enter new task name (current: " << tasks[taskNumber - 1].getName() << "): ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter new task description (current: " << tasks[taskNumber - 1].getDescription() << "): ";
            getline(cin, description);
            cout << "Enter new task due date (current: " << tasks[taskNumber - 1].getDueDate() << "): ";
            getline(cin, dueDate);

            tasks[taskNumber - 1].setName(name);
            tasks[taskNumber - 1].setDescription(description);
            tasks[taskNumber - 1].setDueDate(dueDate);
            cout << "Task updated!" << endl;
        } else {
            cout << "Invalid task number!" << endl;
        }
    }

    void run() {
        int choice;
        do {
            displayMenu();
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addTask();
                    break;
                case 2:
                    deleteTask();
                    break;
                case 3:
                    displayTasks();
                    break;
                case 4:
                    markTaskCompleted();
                    break;
                case 5:
                    editTask();
                    break;
                case 6:
                    cout << "Exiting..." << endl;
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }
        } while (choice != 6);
    }
};

int main() {
    ToDoList toDoList;
    toDoList.run();
    return 0;
}
