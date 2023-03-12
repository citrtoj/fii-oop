#pragma once

#include <iostream>

class Canvas
{
    char** m_matrix;
    int m_width, m_height;
    bool CheckPoint(int x, int y);
private:
    void PlotLineLow(int x0, int x1, int y0, int y1, char ch);
    void PlotLineHigh(int x0, int x1, int y0, int y1, char ch);
public:
    Canvas(int width, int height);
    void DrawCircle(int x, int y, int ray, char ch);
    void FillCircle(int x, int y, int ray, char ch);
    void DrawRect(int left, int top, int right, int bottom, char ch);
    void FillRect(int left, int top, int right, int bottom, char ch);
    void SetPoint(int x, int y, char ch);
    void DrawLine(int x1, int y1, int x2, int y2, char ch);
    void Print(); // shows what was printed
    void Clear(); // clears the canvas
};
