#include "Canvas.h"
#include <math.h>

Canvas::Canvas(int width, int height) : m_matrix(nullptr), m_width(width), m_height(height) {
	m_matrix = new char* [height];
	for (int i = 0; i < height; ++i) {
		m_matrix[i] = new char[width + 1]; //width + null char
		memset(m_matrix[i], ' ', width);
		m_matrix[i][width] = '\0';
	}
}
bool Canvas::CheckPoint(int x, int y) {
	if (x < 0 || x > m_width) {
		return false;
	}
	if (y < 0 || y > m_height) {
		return false;
	}
	return true;
}
void Canvas::SetPoint(int x, int y, char ch) {
	if (ch == '\0') return;
	if (!CheckPoint(x, y)) {
		std::cout << "not suited";
		return;
	}
	m_matrix[y][x] = ch;
}

void Canvas::Clear() {
	for (int i = 0; i < m_height; ++i) {
		memset(m_matrix[i], ' ', m_width);
		m_matrix[i][m_width] = '\0';
	}
}

void Canvas::Print() {
	for (int i = 0; i < m_width + 2; ++i) {
		std::cout << "--";
	}
	std::cout << "\n";
	for (int i = 0; i < m_height; ++i) {
		std::cout << "| ";
		for (int j = 0; j < m_width; ++j) {
			std::cout << m_matrix[i][j] << " ";
		}
		std::cout << "|\n";
		//ne am asigurat ca niciodata n o sa fie
		//vreun null unde nu trebuie
		//prin SetPoint, initializare, si Clear
	}
	for (int i = 0; i < m_width + 2; ++i) {
		std::cout << "--";
	}
	std::cout << "\n";
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
	for (int i = left; i <= right; ++i) {
		for (int j = top; j <= bottom; ++j) {
			SetPoint(i, j, ch);
		}
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
	for (int i = left; i <= right; ++i) {
		SetPoint(i, top, ch);
		SetPoint(i, bottom, ch);
	}
	for (int i = top + 1; i < bottom; ++i) {
		SetPoint(left, i, ch);
		SetPoint(right, i, ch);
	}
}

void Canvas::PlotLineLow(int x0, int y0, int x1, int y1, char ch) {
	int dx = x1 - x0, dy = y1 - y0;
	int yi = 1;
	if (dy < 0) {
		yi = -1;
		dy = -dy;
	}
	int D = (2 * dy) - dx;
	int y = y0;

	for (int x = x0; x <= x1; ++x) {
		SetPoint(x, y, ch);
		if (D > 0) {
			++y;
			D = D - 2 * dx;
		}
		D = D + 2 * dy;
	}
}

void Canvas::PlotLineHigh(int x0, int y0, int x1, int y1, char ch) {
	int dx = x1 - x0;
    	int dy = y1 - y0;
   	int xi = 1;
    	if (dx < 0) {
		xi = -1;
		dx = -dx;
	}
    	int D = (2 * dx) - dy;
    	int x = x0;

    	for (int y = y0; y <= y1; ++y) {
		SetPoint(x, y, ch);
		if (D > 0) {
			x = x + xi;
			D = D + (2 * (dx - dy));
		}
		else {
			D = D + 2 * dx;
		}
	}
}



void Canvas::DrawLine(int x0, int y0, int x1, int y1, char ch) {
	if (!CheckPoint(x1, y1) && !CheckPoint(x0, y0)) {
		return;
	}
	if (abs(y1 - y0) < abs(x1 - x0)) {
		if (x0 > x1) {
			PlotLineLow(x1, y1, x0, y0, ch);
		}
		else {
			PlotLineLow(x0, y0, x1, y1, ch);
		}
	}
	else {
		if (y0 > y1) {
			PlotLineHigh(x1, y1, x0, y0, ch);
		}
		else {
			PlotLineHigh(x0, y0, x1, y1, ch);
		}
	}
}

void Canvas::DrawCircleUtil(int x0, int y0, int x, int y, char ch) {
	SetPoint(x0 + x, y0 + y, ch);
	SetPoint(x0 - x, y0 + y, ch);
	SetPoint(x0 + x, y0 - y, ch);
	SetPoint(x0 - x, y0 - y, ch);
	SetPoint(x0 + y, y0 + x, ch);
	SetPoint(x0 - y, y0 + x, ch);
	SetPoint(x0 + y, y0 - x, ch);
	SetPoint(x0 - y, y0 - x, ch);
}

void Canvas::DrawCircle(int x0, int y0, int r, char ch) {
	int x = 0;
	int y = r;
	int d = 3 - 2 * r;
	DrawCircleUtil(x0, y0, x, y, ch);
	while (y >= x) {
		x++;
		if (d > 0) {
			y--;
			d = d + 4 * (x - y) + 10;
		}
		else {
			d = d + 4 * x + 6;
		}
		DrawCircleUtil(x0, y0, x, y, ch);
	}
}

void Canvas::FillCircle(int x0, int y0, int r, char ch) {
	for (int x = -r; x < r; x++) {
		int height = (int)sqrt(r * r - x * x);
		for (int y = -height; y < height; y++)
			SetPoint(x0 + x, y0 + y, ch);
	}
}
