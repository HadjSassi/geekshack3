#include <iostream>
#include <string>
#include <stack>
#include <unordered_set>

int main() {
    std::string s;
    std::cin >> s;
    
    std::unordered_set<std::string> possibilities;
    std::stack<std::string> stack;
    stack.push(s);
    
    while (!stack.empty()) {
        std::cout << "before: ";
        for (const auto& str : stack) {
            std::cout << str << " ";
        }
        std::cout << possibilities.size() << std::endl;
        
        std::string current = stack.top();
        stack.pop();
        
        if (possibilities.count(current) > 0) {
            continue;
        } else {
            possibilities.insert(current);
        }
        
        if (current.size() > 1) {
            for (int i = 0; i < current.size() - 1; i++) {
                if (current[i] == current[i+1]) {
                    if (current[i] == 't') {
                        std::string s1 = current.substr(0, i) + 'v' + current.substr(i+2);
                        stack.push(s1);
                    } else {
                        std::string s1 = current.substr(0, i) + 't' + current.substr(i+2);
                        stack.push(s1);
                    }
                }
            }
        }
        
        std::cout << "after: ";
        for (const auto& str : stack) {
            std::cout << str << " ";
        }
        std::cout << possibilities.size() << std::endl;
    }
    
    return 0;
}
 