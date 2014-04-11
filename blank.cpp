#include <algorithm>
#include <iostream>
#include <string>
#include <iterator>

struct AreBothSpaces {
    bool operator()(char x, char y) const {
        return x == ' ' && y == ' ';
    }
};

void removeContinousSpaces(std::string& str) {
    std::string::iterator last = std::unique(str.begin(), str.end(), AreBothSpaces());
    str.erase(last, str.end());
}

int main() {
    std::string str = "aaa   bb   c d   e";
    removeContinousSpaces(str);
    std::cout << str << std::endl;
}
