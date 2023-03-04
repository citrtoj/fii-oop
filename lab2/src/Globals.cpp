#include "Globals.h"
#include <cstring>

int CompareName(const Student& lhs, const Student& rhs) {
    return strcmp(lhs.Name(), rhs.Name());
}

int CompareMath(const Student& lhs, const Student& rhs) {
    if (lhs.GradeMath() < rhs.GradeMath()) {
        return -1;
    }
    else {
        if (lhs.GradeMath() > rhs.GradeMath()) {
            return 1;
        }
        else return 0;
    }
}

int CompareEng(const Student& lhs, const Student& rhs) {
    if (lhs.GradeEng() < rhs.GradeEng()) {
        return -1;
    }
    else {
        if (lhs.GradeEng() > rhs.GradeEng()) {
            return 1;
        }
        else return 0;
    }
}

int CompareHistory(const Student& lhs, const Student& rhs) {
    if (lhs.GradeHistory() < rhs.GradeHistory()) {
        return -1;
    }
    else {
        if (lhs.GradeHistory() > rhs.GradeHistory()) {
            return 1;
        }
        else return 0;
    }
}

int CompareAverage(const Student& lhs, const Student& rhs) {
    if (lhs.AverageGrade() < rhs.AverageGrade()) {
        return -1;
    }
    else {
        if (lhs.AverageGrade() > rhs.AverageGrade()) {
            return 1;
        }
        else return 0;
    }
}
