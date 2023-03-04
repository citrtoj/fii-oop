#ifndef STUDENT_H
#define STUDENT_H

class Student {

public:
    Student();

    void SetName(const char* x);
    void SetGradeMath(float x);
    void SetGradeEng(float x);
    void SetGradeHistory(float x);

    const char* Name() const;
    float GradeMath() const;
    float GradeEng() const;
    float GradeHistory() const;
    float AverageGrade() const;

private:
    char m_name[128];
    float m_gradeMath, m_gradeEng, m_gradeHistory;
};

#endif // STUDENT_H
