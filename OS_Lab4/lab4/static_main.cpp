#include "lib.h"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

class MainRoutine {
private:
    static void InvalidArgs() { std::cout << "Invalid arguments\n"; }

    static void MissingArgs() { std::cout << "Missing arguments\n"; }

    static void Function1(float a, float b, float c) {
        float result = SinIntegral(a, b, c);

        std::cout << result << '\n';
    }

    static void Function2(long x) {
        char *str = Translation(x);

        std::cout << str << '\n';
        std::free(str);
    }

    static void Help() {
        std::cout << "  1. help - for help\n";
        std::cout << "  2. exit - exits program\n";
        std::cout << "  3. 1 <A> <B> <e> - find Integral\n";
        std::cout << "  4. 2 <x> - translate x to binary number system\n";
    }

    static std::vector<std::string> Tokenize(const std::string &line) {
        std::vector<std::string> result;
        std::stringstream ss(line);
        while (ss) {
            std::string token;
            ss >> token;
            if (!token.empty()) {
                result.push_back(token);
            }
        }
        return result;
    }

    static bool ProceedLine(const std::string &line) {
        std::vector<std::string> tokens = Tokenize(line);
        if (tokens[0] == "help") {
            Help();
        } else if(tokens[0] == "exit") {
            return false;
        } else if(tokens[0] == "1") {
            if (tokens.size() != 3) {
                MissingArgs();
                return true;
            }
            try {
                int a = std::stoi(tokens[1]);
                int b = std::stoi(tokens[2]);
                int c = std::stoi(tokens[3]);
                Function1(a, b, c);
            } catch (std::invalid_argument &) {
                InvalidArgs();
            }
        } else if (tokens[0] == "2") {
            if (tokens.size() != 2) {
                MissingArgs();
                return true;
            }
            try {
                long x = std::stol(tokens[1]);
                Function2(x);
            } catch(std::invalid_argument &) {
                InvalidArgs();
            }
        } else {
            InvalidArgs();
        }
        return true;
    }

public:
    static void Start() {
        std::string line;
        std::cout << "> ";

        while (std::getline(std::cin, line)) {
            if (!ProceedLine(line)) {
                break;
            }
            std::cout << "> ";
        }
    }
};

int main() { MainRoutine::Start(); }