void evaluateExpression(const std::string& expression, MyLinkedStack& stack) {
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token) {
        if (token[0] == '#') {
            int number = std::stoi(token.substr(1));
            stack.push(number);
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (stack.getNodeCnt() < 2) {
                std::cout << "Too many operands" << std::endl;
                return;
            }
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            int result;
            if (token == "+") result = a + b;
            else if (token == "-") result = a - b;
            else if (token == "*") result = a * b;
            else if (token == "/") {
                if (b == 0) {
                    std::cout << "Division by 0" << std::endl;
                    return;
                }
                result = a / b;
            }
            stack.push(result);
        } else if (token == "=") {
            if (stack.getNodeCnt() == 1) {
                std::cout << stack.top() << std::endl;
                stack.pop();
            } else {
                std::cout << "Too many operands" << std::endl;
            }
            return;
        } else {
            std::cout << "Expression error" << std::endl;
            return;
        }
    }
}
