#pragma once

#include<iostream>
#include<string>
#include<chrono>
#include<ctime>

using namespace std;

class Date {
    int day;
    int month;
    int year;
    public:
        Date();

        Date(int day, int month, int year);

        friend ostream& operator<< (ostream& out, const Date& date);
        friend bool operator< (const Date& left, const Date& right);
        friend bool operator> (const Date& left, const Date& right);
        friend bool operator== (const Date& left, const Date& right);
        friend istream& operator>> (istream& in, Date& date);
};

class Task {
    public:
        string title;
        string description;
        Date dueDate;
        bool finished;
    public:
        Task(): title(""), description(""), dueDate(), finished(false) {}
        Task(string title, string description, Date date):
            title(title), description(description), dueDate(date), finished(false) {}

        bool isOverdued() const ;

        string statusDescription() const;
  
        friend ostream& operator<< (ostream& out, const Task& task);
        friend bool operator== (const Task& left, const Task& right);
        friend istream& operator>> (istream& in, Task& task);
};
