#include "Student.h"
#include <math.h>

Student::Student() : m_name(""), m_gradeEng(1.0), m_gradeHistory(1.0), m_gradeMath(1.0) {}

void Student::SetName(const char* x) {
    //caracter cu caracter, sa n avem treaba
    int i = 0;
    while (x[i] != '\0' && x[i] < 127) {
        m_name[i] = x[i];
        ++i;
    }
    m_name[i] = '\0';
}

void Student::SetGradeEng(float x) {
    if (x < 1.0 || x > 10.0) {
        return;
    }
    m_gradeEng = x;
}

void Student::SetGradeMath(float x) {
    if (x < 1.0 || x > 10.0) {
        return;
    }
    m_gradeMath = x;
}

void Student::SetGradeHistory(float x) {
    if (x < 1.0 || x > 10.0) {
        return;
    }
    m_gradeHistory = x;
}

const char* Student::Name() const {
    return m_name;
}

float Student::GradeEng() const {
    return m_gradeEng;
}

float Student::GradeMath() const {
    return m_gradeMath;
}

float Student::GradeHistory() const {
    return m_gradeHistory;
}

float Student::AverageGrade() const {
    return (m_gradeEng + m_gradeHistory + m_gradeMath) / 3;
}
