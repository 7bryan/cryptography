#include <iostream>
#include <cmath>
#include <cctype>
// sorry for the messy code lmao

bool string_handle(const std::string& s){
    // handle if the s contain any integer
    for (char c : s){
        if (!std::isalpha(c) && c != ' '){
            return false; // return false if there's integer
        }
    }
    return true; // return true for all string
}

void encryption(){
    std::string code = "abcdefghijklmnopqrstuvwxyz";
    std::string s;
    std::cout << "Enter a string to encrypt: ";
    std::cin.ignore();
    std::getline(std::cin, s); // getline for storing the input with the space
    int count;
    std::cout << "Enter the number of characters to encrypt: ";
    std::cin >> count; // input for number of character move
    std::cout << "===========================================\n";
    
    if (string_handle(s)){
        std::string ans; //decryption string (answer)
            for (int i = 0; i < s.length(); ++i){ // loop through the s string
                if (s[i] == ' '){ // handle the space on string
                    ans += ' ';
                    continue;
                }
                int temp;
                for (int j = 0; j < code.length(); ++j){ // loop through the alphabet
                    if (s[i] == code[j]){ // if the s string at index i is the same with code index j:
                        temp = j + count; // temp var will store the the j + (count as the number for moving index)
                    }
                }
                if (temp + 1 > code.length()) temp = (temp % code.length()); // temp + 1 for avoiding skip the first alphabet (which is at index 0)
                ans += code[temp];
            }
        std::cout << ans;
        return;
    }
    else{ // respond if there's any integer on the string
        std::cout << "please only enter a string chiper";
        return;
    }
}

void decryption(){
    std::string code = "abcdefghijklmnopqrstuvwxyz";
    std::string s;
    std::cout << "Enter a string to decrypt: ";
    std::cin.ignore();
    std::getline(std::cin, s); // getline for storing the input with the space
    int count;
    std::cout << "Enter the number of characters to decrypt: ";
    std::cin >> count; // input for number of character move
    std::cout << "===========================================\n";
    count = std::abs(count - 26); // the logic is making the count to negative aka moving the character to the left

    if (string_handle(s)){
        std::string ans; //decryption string (answer)
            for (int i = 0; i < s.length(); ++i){ // loop through the s string
                if (s[i] == ' '){ // handle the space on string
                    ans += ' ';
                    continue;
                }
                int temp;
                for (int j = 0; j < code.length(); ++j){ // loop through the alphabet
                    if (s[i] == code[j]){ // if the s string at index i is the same with code index j:
                        temp = j + count; // temp var will store the the j + (count as the number for moving index)
                    }
                }
                if (temp + 1 > code.length()) temp = (temp % code.length()); // temp + 1 for avoiding skip the first alphabet (which is at index 0)
                ans += code[temp];
            }
        std::cout << ans;
        return;
    }
    else{ // the respond if there's any integer on the string
        std::cout << "please only enter a string chiper"; 
        return;
    }
}

void brute_solve(){
    int count = 1; // number of move
    std::string s;
    std::cout << "this menu will solve the encrypted string by moving each character through all possible combination of decryption\n";
    std::cout << "enter the string to solved : ";
    std::cin.ignore();
    std::getline(std::cin, s); // getline for storing the input with the space
    std::cout << "===========================================\n";
    std::string code = "abcdefghijklmnopqrstuvwxyz";

    if (string_handle(s)){
        for (int a = 0; a < code.length(); ++a){ // loop through all possible chatracter move/alphabet
            std::string ans; //decryption string (answer)
            for (int i = 0; i < s.length(); ++i){ // loop through the s string
                if (s[i] == ' '){ // handle the space on string
                    ans += ' '; // add the space back to the answer string
                    continue;
                }
                int temp; // var for the number of move + j (j as the string[j] position)
                for (int j = 0; j < code.length(); ++j){ // loop through the alphabet
                    if (s[i] == code[j]){ // if the s string at index i is the same with code index j:
                        temp = j + count; // temp var will store the the j + (count as the number for moving index)
                    }
                }
                if (temp + 1 > code.length()) temp = (temp % code.length()); // temp + 1 for avoiding skip the first alphabet (which is at index 0)
                ans += code[temp]; // adding the moved character to the answer
            }

            std::cout << "move by " << count << " or " << (-26 + count) << " = " << ans << '\n'; // "(-26 + count) as the backward move"
            std::cout << '\n';
            ++count; //moving the counter of move
        }
        return;
    }
    else{ // the respond if there's any integer on the string
        std::cout << "please only enter a string chiper";
        return;
    }
}

void menu(){
    int choice;
    std::cout << "welcome to the string cipher\n";
    std::cout << "===========================================\n";
    std::cout << "choice : \n";
    std::cout << "1. Encrypt\n2. Decrypt\n3. solve using brute force\n4. Exit\n";
    std::cout << "enter your choice : ";
    std::cin >> choice;
    std::cout << "===========================================\n";

    if (choice == 1){
        encryption();
        return;
    }
    if (choice == 2){
        decryption();
        return;
    }
    if (choice == 3){
        brute_solve();
        return;
    }
    if (choice == 4){
        std::cout << "bye bye";
        return;
    }
    else{ // error respond for invalid choice
        std::cout << "error\nenter a valid choice";
        return;
    }
}

int main(){
    menu();
    // i hate c++
    return 0;
}