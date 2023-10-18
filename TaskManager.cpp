#include"TaskManager.h"

int TaskManager::indexOfTask(Task& task) const {
    for (int index = 0; index < tasks.size(); index++) {
        if (tasks[index] == task) {
            return index;
        }
    }
    return -1;
}

bool TaskManager::addTask(Task& task) {
    if (indexOfTask(task) == -1) {
        tasks.push_back(task);   
        return true;
    }
    return false;
}

bool TaskManager::removeTask(Task& task) {
    int deletingIndex(0);
    for (Task& currentTask :tasks) {
        if (currentTask == task) {
            tasks.erase(tasks.begin() + deletingIndex);
            return true;
        }
        deletingIndex++;
    }

    return false;
}

bool TaskManager::removeTask(string title) {
    int deletingIndex(0);

    for (Task& currentTask: tasks) {
        if (currentTask.title == title) {
            tasks.erase(tasks.begin() + deletingIndex);
            return true;
        }
        deletingIndex++;
    }

    return false;
}

vector<Task> TaskManager::searchTasks(string title) const {
    vector<Task> foundTasks {};

    for (Task currentTask: tasks) {
        if (currentTask.title == title) {
            foundTasks.push_back(currentTask);
        }
    }

    return foundTasks;
}

optional<Task> TaskManager::searchTask(string title) const {
    for (Task currentTask: tasks) {
        if (currentTask.title == title) {
            return currentTask;
        }
    }

    return {};
}

void TaskManager::markAsCompleted(string title) {
    /*
    for (int index = 0; index < tasks.size(); index++) {
        if (tasks[index].get().title == title) {
            tasks[index].get().finished = true;
        }
    }
    */

    for (int index = 0; index < tasks.size(); index++) {
        if (tasks[index].title == title) {
            tasks[index].finished = true;
        }
    }
}
void TaskManager::markAsUncompleted(string title) {
    /*
    for (int index = 0; index < tasks.size(); index++) {
        if (tasks[index].get().title == title) {
            tasks[index].get().finished = false;
        }
    }
    */

    for (int index = 0; index < tasks.size(); index++) {
        if (tasks[index].title == title) {
            tasks[index].finished = false;
        }
    }
}

ostream& operator << (ostream& out, const TaskManager& taskManager) {
    for (int index = 0; index < taskManager.tasks.size(); index++) {
        if (index != taskManager.tasks.size() - 1) {
            out << taskManager.tasks[index] << '\n';
        } else {
            out << taskManager.tasks[index] ;
        }
    }
    return out;
}
