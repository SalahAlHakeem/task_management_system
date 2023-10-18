#include"Task.h"

Date::Date() {
    auto currentTime = std::chrono::system_clock::now();
    std::time_t currentTime_t = std::chrono::system_clock::to_time_t(currentTime);
    std::tm* currentTime_tm = std::localtime(&currentTime_t);
        
    day = currentTime_tm->tm_mday;
    month = currentTime_tm->tm_mon + 1;
    year = currentTime_tm->tm_year + 1900;
}

Date::Date(int day, int month, int year) {
    if (day > 31 || day <= 0) day = 31;
    if (month > 12 || month <= 0) month = 12;
    if (year < 1970) year= 1970;

    this->day = day;
    this->month = month;
    this->year = year;
}

ostream& operator<< (ostream& out, const Date& date) {
    out << "Date(" << to_string(date.day) << "-" << to_string(date.month) << "-" << to_string(date.year) << ")";
    return out;
}

istream& operator>> (istream& in, Date& date) {
    cout << "Do not use leading nulls for dates and months! (not `01` but `1`)\n";
    cout << "Enter a day: ";
    in >> date.day;
    cout << "Enter a month: ";
    in >> date.month;
    cout << "Enter a year: ";
    in >> date.year; 

    return in;
}


bool operator< (const Date& left, const Date& right) {
    if (left.year < right.year) {
        return true;
    } else if (left.year == right.year) {
        if (left.month < right.month) {
            return true;
        } else if (left.month == right.month) {
            return left.day < right.day;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool operator> (const Date& left, const Date& right) {
    if (left.year > right.year) {
        return true;
    } else if (left.year == right.year) {
        if (left.month > right.month) {
            return true;
        } else if (left.month == right.month) {
            return left.day > right.day;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool operator== (const Date& left, const Date& right) {
    return (left.year == right.year) &&  (left.month == right.month) && (left.day == right.day);
}

string Task::statusDescription() const {
    string resultDescription {};
    if (finished) {
        resultDescription = "completed";
    } else {
        if (isOverdued()) {
            resultDescription = "overdued";
        } else {
            resultDescription = "pending";
        }
    }
    return resultDescription;
}

bool Task::isOverdued() const {
    Date currentDate {};
    if (currentDate == dueDate) return false;
    return currentDate > dueDate;
}


ostream& operator<< (ostream& out, const Task& task) {
    string status = task.statusDescription();
    string matchingColor {};
    if (status == "pending") {
        matchingColor =  "\033[33m";
    } else if (status == "overdued") {
        matchingColor = "\033[31m";
    } else if (status == "completed") {
        matchingColor = "\033[32m";
    }

    out <<
        "Task(title=\"" << task.title  <<
        "\", description=\"" << task.description << 
        "\", status=" << matchingColor <<  status <<  "\033[0m" << ")";
    return out;
};

istream& operator>> (istream& in, Task& task) {
    cout << "\n**Creating a new task**" << '\n';
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Enter a title of task: ";
    getline(in, task.title);
    cout << "Enter a description of task: ";
    getline(in, task.description);
    cout << "Enter a due date of task:\n";
    in >> task.dueDate;
    return in;
}

bool operator== (const Task& left, const Task& right) {
    return 
        (left.title == right.title) && (left.description == right.description) &&
        (left.dueDate == right.dueDate) && (left.finished == right.finished);  
}


