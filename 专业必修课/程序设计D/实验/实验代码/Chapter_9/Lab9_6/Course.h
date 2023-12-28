// Course.h
#include <iostream>
#include <string.h>
#ifndef COURSE_H
#define COURSE_H

class Course {
public:
    Course(const char *name = "", short score = 0) {
        strncpy(this->name, name, sizeof(this->name) - 1);
        this->name[sizeof(this->name) - 1] = '\0'; // Ensure null-termination
        this->score = score;
    }

    void displayCourse() const {
        std::cout << "Course Name: " << name << ", Score: " << score << std::endl;
    }

private:
    char name[21];
    short score;
};

#endif // COURSE_H
