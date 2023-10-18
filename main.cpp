#include<iostream>
#include"TaskManager.cpp"

/*
    WARNING: it is required to compile this program with 17+ version of compiler
    try the following command on macOS for compiling: `g++ -std=c++17 -w main.cpp -o main`
*/

using namespace std;

const std::string RESET_COLOR = "\033[0m";
const std::string RED_COLOR = "\033[31m";
const std::string GREEN_COLOR = "\033[32m";
const std::string YELLOW_COLOR = "\033[33m";
const std::string BLUE_COLOR = "\033[34m";

int optionRetriever() {
    int option;
    cout << "\n**Choose one of the following commands**" << endl;
    cout << "1\tAdd a new task" << endl;
    cout << "2\tMark task as completed" << endl;
    cout << "3\tMark task as uncompleted" << endl;
    cout << "4\tRemove task" << endl;
    cout << "5\tView tasks" << endl;
    cout << "6\tExit program\n" << endl;

    cin >> option;
    cout << "\n";
    return option;
}

void addTask(TaskManager& manager) {
    Task newTask;
    cin >> newTask;
    if (manager.addTask(newTask)) {
        cout << GREEN_COLOR << "New task added successfuly!" << RESET_COLOR << endl;
    } else {
        cout << YELLOW_COLOR <<"Task already exists!" << RESET_COLOR << endl;
    }
}

void removeTask(TaskManager& manager) {
    string removingTaskTitle;
    cout << "Enter a task title to remove: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, removingTaskTitle);

    if (manager.removeTask(removingTaskTitle)) {
        cout << GREEN_COLOR <<"Task has been deleted!" <<  RESET_COLOR << endl;
    } else {
        cout << RED_COLOR << "Unable to delete task with title `" << (removingTaskTitle + "`") << RESET_COLOR << endl;
    }
}

void markCompletedTask(TaskManager& manager) {
    string title;
    cout << "Enter a title of task to complete: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    getline(cin, title);

    if (manager.searchTask(title)) {
        manager.markAsCompleted(title);
        cout << GREEN_COLOR << "Task has marked as completed!" << RESET_COLOR <<endl;
    } else {
        cout << YELLOW_COLOR <<"Unable to find task with title `" << title << "`." << RESET_COLOR << endl;
    }
}

void markUncompletedTask(TaskManager& manager) {
    string title;
    cout << "Enter a title of task to reset progress: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    getline(cin, title);
    

    if (manager.searchTask(title)) {
        manager.markAsUncompleted(title);
        cout << GREEN_COLOR << "Task has marked as uncompleted!" << RESET_COLOR <<endl;
    } else {
        cout << YELLOW_COLOR <<"Unable to find task with title `" << title << "`." << RESET_COLOR <<endl;
    }
}

int runTaskManagementSystem() {
    try {
        TaskManager manager{};

        while (true) {
            int option = optionRetriever();
            if (option == 1) {
                addTask(manager);
            } else if (option == 2) {
                markCompletedTask(manager);
            } else if (option == 3) {
                markUncompletedTask(manager);
            } else if (option == 4) {
                removeTask(manager);
            } else if (option == 5) {
                if (manager.empty()) {
                    cout << YELLOW_COLOR <<  "there is no task in task manager" << RESET_COLOR <<  endl;
                } else {
                    cout << manager << endl;
                }
            } else if (option == 6) {
                return 1;
            } 
        }
    }catch(exception& exception) {
        cerr << exception.what() << endl;
        return 0;
    }
}

int main() {
    if(runTaskManagementSystem() == 1) {
        cout << GREEN_COLOR << "program finished successfully!" << RESET_COLOR << endl;
    } else {
        cout << RED_COLOR <<"program fatally finished!" << RESET_COLOR << endl;
    }
}

