#pragma once

#include <iostream>

class CustomException : public std::exception {
    public:

        CustomException(std::string message) {     // Constructor
            this->message = message;
        }

        std::string what () {
            return this->message;
        }

    private:
        std::string message;
};