#include "Sort.h"
#pragma warning(disable:4996)

Sort::Sort(int count, int min, int max) : m_count(count) {
    m_arr = new int[count];
    for (size_t i = 0; i < count; ++i) {
        m_arr[i] = min + (rand() % (max - min + 1)); //rand with numbers from [min, max] inclusive
    }
}

Sort::Sort(std::initializer_list<int> init_list) {
    m_arr = new int[init_list.size()];
    m_count = init_list.size();
    for (auto i = init_list.begin(); i != init_list.end(); ++i) {
        m_arr[i - init_list.begin()] = *i;
    }
}

Sort::Sort(int vector[], int count) : m_count(count) {
    m_arr = new int[count];
    for (size_t i = 0; i < m_count; ++i) {
        m_arr[i] = vector[i];
    }
}

int Sort::MyAtoi(const char* text) {
    int s = 0;
    bool neg = false;
    size_t i = 0;
    if (text[i] == '-') {
        neg = true;
        ++i;
    }
    while (text[i] != '\0') {
        if (text[i] >= '0' && text[i] <= '9') {
            s = s * 10 + (text[i] - '0');
        }
        ++i;
    }
    return neg ? -s : s;
}

Sort::Sort(const char* text) : m_count(0), m_arr(0) {
    int* temp_arr = new int[(strlen(text) + 1) / 2]; //maximu
    int i = 0;
    int current_nr = 0;
    while (i < strlen(text)) {
        if (text[i] == ',') {
            temp_arr[m_count] = current_nr;
            m_count++;
            current_nr = 0;
            ++i;
        }
        current_nr = current_nr * 10 + text[i] - '0';
        ++i;
    }
    temp_arr[m_count] = current_nr;
    m_count++;
    m_arr = new int[m_count];
    for (int i = 0; i < m_count; ++i) {
        m_arr[i] = temp_arr[i];
    }
    delete[] temp_arr;
}

Sort::Sort(...) : m_count(0), m_arr(0) {}

void Sort::InsertSort(bool ascendent) {
    for (size_t i = 1; i < m_count; ++i) {
        size_t j = i - 1;
        int element = m_arr[i];
        while ( ( (m_arr[j] > element) == !ascendent) && j >= 0) {
            m_arr[j + 1] = m_arr[j];
            --j;
        }
        m_arr[j + 1] = element;
        
    }
}

void Sort::BubbleSort(bool ascendent) {
    for (size_t i = 0; i < m_count - 1; ++i) {
        for (int j = 0; j < m_count - i - 1; ++j) {
            if ( (m_arr[j] > m_arr[j + 1] ) == !ascendent) {
                std::swap(m_arr[j], m_arr[j + 1]);
            }
        }
    }
}

int Sort::Partition(int low, int high, bool ascendent) {
    const int pivotIndex = rand() % (high - low + 1) + low;
    std::swap(m_arr[pivotIndex], m_arr[high]);
    const auto pivot = m_arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if ((m_arr[j] <= pivot) == !ascendent) {
            i++;
            std::swap(m_arr[i], m_arr[j]);
        }
    }
    std::swap(m_arr[i + 1], m_arr[high]);
    return i + 1;
}

void Sort::QuickSortUtil(int low, int high, bool ascendent) {
    if (low < high) {
        const auto pivot = Partition(low, high, ascendent);
        QuickSortUtil(low, pivot - 1, ascendent);
        QuickSortUtil(pivot + 1, high, ascendent);
    }
}

void Sort::QuickSort(bool ascendent) {
    QuickSortUtil(0, (int)m_count - 1, ascendent);
}

void Sort::Print() {
    for (size_t i = 0; i < m_count; ++i) {
        std::cout << m_arr[i] << " ";
    }
    std::cout << "\n";
}

int Sort::operator[](size_t index) const {
    if (index < 0 || index >= m_count) {
        throw std::out_of_range("Invalid index");
    }
    return m_arr[index];
}

int Sort::GetElementsCount() {
    return (int)m_count;
}

int Sort::GetElementFromIndex(int index) const {
    return (*this)[index];
}