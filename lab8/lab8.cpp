#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <map>

class CompareModule {
public:
    bool operator()(std::pair<std::string, int>& p1, std::pair<std::string, int>& p2) {
        if (p1.second < p2.second) {
            return true;
        }
        else if (p1.second == p2.second) {
            if (p1.first > p2.first) {
                return true;
            }
        }
        return false;
    }
};

std::map<std::string, int> tokenize(std::string str) {
    std::map<std::string, int> map;
    std::string separators = " .,?!";
    size_t found = str.find_first_of(separators);
    while (found != std::string::npos) {
        if (found > 0) {
            map[str.substr(0, found)]++;
        }
        str = str.substr(found + 1);
        found = str.find_first_of(separators);
    }
    return map;
}

void lowerize(std::string& str) {
    for (auto& x : str) {
        if (x >= 'A' && x <= 'Z') {
            x += 32;
        }
    }
}

int main()
{
    std::ifstream fin("input.txt");
    std::string string;
    std::getline(fin, string);
    lowerize(string);
    std::map<std::string, int> map = tokenize(string);
    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, CompareModule> queue;
    for (auto pair : map) {
        queue.push(pair);
    }
    while (!queue.empty()) {
        const std::pair<std::string, int>& pair = queue.top();
        std::cout << pair.first << " => " << pair.second << "\n";
        queue.pop();
    }
}
