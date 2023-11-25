#include <iostream>
#include <set>
#include <stack>

int main() {
    int sum=0;
    std::string s;
    std::cin >> s;

    std::set<std::string> possibilities;
    std::stack<std::string> stack;
    stack.push(s);

    while (!stack.empty()) {
        // std::cout << "before: " << stack.top() << " " << possibilities.size() << std::endl;

        s = stack.top();
        stack.pop();

        if (possibilities.find(s) != possibilities.end()) {
            continue;
        } else {
            possibilities.insert(s);
            sum++;
        }

        if (s.length() > 1) {
            for (int i = 0; i < s.length() - 1; ++i) {
                if (s[i] == s[i + 1]) {
                    if (s[i] == 't') {
                        std::string s1 = s.substr(0, i) + "v" + s.substr(i + 2);
                        stack.push(s1);
                    } else {
                        stack.push(s.substr(0, i) + "t" + s.substr(i + 2));
                    }
                }
            }
        }
        // std::cout << "after: " << stack.size() << " " << possibilities.size() << std::endl;
    }

    //std::cout << possibilities.size() << std::endl;
    std::cout << sum;
    return 0;
}