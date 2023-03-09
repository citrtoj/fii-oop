#include "Canvas.h"

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
	if (CheckPoint(x, y)) {
		m_matrix[x][y] = ch;
	}
}

void Canvas::Clear() {
	for (int i = 0; i < m_height; ++i) {
		memset(m_matrix[i], ' ', m_width);
		m_matrix[i][m_width] = '\0';
	}
}

void Canvas::Print() {
	for (int i = 0; i < m_height; ++i) {
		std::cout << m_matrix[i];
		std::cout << '\n';
		//ne am asigurat ca niciodata n o sa fie
		//vreun null unde nu trebuie
		//prin SetPoint, initializare, si Clear
	}
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