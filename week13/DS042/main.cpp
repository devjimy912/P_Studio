int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open file" << std::endl;
        return 1;
    }

    MyLinkedStack stack;
    std::string line;

    while (std::getline(inputFile, line)) {
        evaluateExpression(line, stack);
    }

    inputFile.close();
    return 0;
}
