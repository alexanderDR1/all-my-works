#include <iostream>

int main() {
    std::string str;
    int arr[26] = { 0 };

    std::cout << "Enter string: ";
    getline(std::cin, str);

    for(int i = 0; i < str.size(); i++) {
        int val = static_cast<int>(str[i]); // Decimal value of the character
        if(val - 65 < 26 && val - 65 >= 0) arr[val - 65]++;
        else if(val - 97 < 26 && val - 97 >= 0) arr[val - 97]++;
    }

    for(int i = 0; i < 26; i++) {
        std::cout << static_cast<char>(i + 65) << ": " << arr[i] << std::endl;
    }

    return 0;
}
