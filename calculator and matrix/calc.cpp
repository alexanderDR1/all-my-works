#include <iostream>

int sum(int first,int second){
    return first + second;
}

int multiply(int first,int second){
    return first*second;
}

int divide(int first,int second){
    if(second==0)
    {
        std::cout <<"error: can't divide by zero"<<std::endl;
        return 0;
    }
    return first/second;
}

int main()
{
    int first_number;
    int second_number;
    int command;
    int result;

    while(true) {
        // Step 1: Get command from user
        std::cout <<"enter a command (0 - sum, 1 - mul, 2 - div, 3 - exit): ";
        std::cin >> command;

        if(command==3) return 0;
        if(command > 3)
        {
            std::cout << "Wrong Command" << std::endl;
            continue;
        }
        // Step 2: Request numbers from user
        std::cout << "enter first num: ";
        std::cin >> first_number;
        std::cout << "enter second num: ";
        std::cin >>second_number;

        // Step 3: calculate
        switch (command){
            case 0:
                result = sum(first_number,second_number);
                break;
            case 1:
                result = multiply(first_number,second_number);
                break;
            case 2:
                result = divide(first_number,second_number);
                break;
        }

        // Step 4: Show result
        std::cout << "Result: " << result << std::endl;
    }

    return 0;
}
