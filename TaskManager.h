#pragma once

#include<iostream>
#include<vector>
#include<functional>
#include"Task.cpp"

using namespace std;

class TaskManager {
    private:
        vector<Task> tasks;
    public:
        TaskManager(){
            tasks = vector<Task>();
        }

        int indexOfTask(Task& task) const;
        bool addTask(Task& task);
        bool removeTask(Task& task);
        bool removeTask(string title);

        optional<Task> searchTask(string title) const;
        vector<Task> searchTasks(string title) const;

        void markAsCompleted(string title);
        void markAsUncompleted(string task);

        auto begin() const { return tasks.begin(); }
        auto end() const { return tasks.end(); }

        auto begin() { return tasks.begin(); }
        auto end() { return tasks.end(); }

        bool empty() const {return tasks.size() == 0;}

        friend ostream& operator << (ostream& out, const TaskManager& taskManager);

};