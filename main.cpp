#include <iostream>
#include <string>
using namespace std;

void UnCrypt(string wordUser, int key) {
    string alphabetLower = "abcdefghijklmnopqrstuvwxyz";
    string alphabetUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string numbers = "0123456789";
    string word = wordUser;
    int newIndex;

    for (char c : word) {
        if (isalpha(c)) { // Process letters
            string alphabet = islower(c) ? alphabetLower : alphabetUpper;
            for (int j = 0; j < alphabet.length(); j++) {
                if (c == alphabet[j]) {
                    newIndex = (j - key + 26) % 26;
                    cout << alphabet[newIndex];
                    break;
                }
            }
        } else if (isdigit(c)) { // Process numbers
            for (int j = 0; j < numbers.length(); j++) {
                if (c == numbers[j]) {
                    newIndex = (j - key + 10) % 10;
                    cout << numbers[newIndex];
                    break;
                }
            }
        } else {
            cout << c; // Keep punctuation & spaces unchanged
        }
    }
    cout << endl;
}

void Crypt(string wordUser, int key) {
    string alphabetLower = "abcdefghijklmnopqrstuvwxyz";
    string alphabetUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string numbers = "0123456789";
    string word = wordUser;
    int newIndex;

    for (char c : word) {
        if (isalpha(c)) { // Process letters
            string alphabet = islower(c) ? alphabetLower : alphabetUpper;
            for (int j = 0; j < alphabet.length(); j++) {
                if (c == alphabet[j]) {
                    newIndex = (j + key) % 26;
                    cout << alphabet[newIndex];
                    break;
                }
            }
        } else if (isdigit(c)) { // Process numbers
            for (int j = 0; j < numbers.length(); j++) {
                if (c == numbers[j]) {
                    newIndex = (j + key) % 10;
                    cout << numbers[newIndex];
                    break;
                }
            }
        } else {
            cout << c; // Keep punctuation & spaces unchanged
        }
    }
    cout << endl;
}

bool isValidInput(const string& input) {
    for (char c : input) {
        if (isdigit(c)) return false;  // If there's a digit, it's invalid
    }
    return true;
}

int SwitchKey(string cryptWord, string unCryptWord) {
    string alphabetLower = "abcdefghijklmnopqrstuvwxyz";
    string alphabetUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string numbers = "0123456789";

    if (cryptWord.length() != unCryptWord.length()) {
        cout << "NOT VALID: Lengths of the words don't match!" << endl;
        return -1;
    }

    for (int i = 0; i < cryptWord.length(); i++) {
        if (isalpha(cryptWord[i]) && isalpha(unCryptWord[i])) {
            string alphabet = islower(cryptWord[i]) ? alphabetLower : alphabetUpper;
            int indexCrypt = alphabet.find(cryptWord[i]);
            int indexUnCrypt = alphabet.find(unCryptWord[i]);

            if (indexCrypt == string::npos || indexUnCrypt == string::npos) {
                cout << "NOT VALID: Invalid characters found!" << endl;
                return -1;
            }

            int key = (indexCrypt - indexUnCrypt + 26) % 26;
            return key;
        }
        else if (isdigit(cryptWord[i]) && isdigit(unCryptWord[i])) {
            int indexCrypt = numbers.find(cryptWord[i]);
            int indexUnCrypt = numbers.find(unCryptWord[i]);

            if (indexCrypt == string::npos || indexUnCrypt == string::npos) {
                cout << "NOT VALID: Invalid characters found!" << endl;
                return -1;
            }

            int key = (indexCrypt - indexUnCrypt + 10) % 10;
            return key;
        }
        else if (cryptWord[i] != unCryptWord[i]) {
            cout << "NOT VALID: Mismatch between letters and numbers!" << endl;
            return -1;
        }
    }

    return 0; // Return a valid key if everything is correct
}

int main() {
    int Skey;
    string operation, text, cryptText, unCryptText;

    while (true) {
        cout << "Do you want to Crypt(1), Uncrypt(2), get the Switch Key(3), or Uncrypt without key(4)?\n";
        cin >> operation;
        cin.ignore();

        // Check if the operation input is valid
        if (operation != "1" && operation != "2" && operation != "3" && operation != "4") {
            cout << "Error: Invalid choice! Please enter 1, 2, 3, or 4.\n";
            continue;
        }

        if (operation == "1" || operation == "2") {
            while (true) {
                cout << "Enter Switch Key (an integer):\n";
                cin >> Skey;
                cin.ignore();

                if (Skey < 0) {
                    cout << "Error: Invalid Switch Key! Please enter a valid positive key.\n";
                    continue;
                }
                break; // Exit loop when valid key is entered
            }

            cout << "Please enter text:\n";
            getline(cin, text);

            if (operation == "1") {
                Crypt(text, Skey);
            } else {
                UnCrypt(text, Skey);
            }
        }
        else if (operation == "3") {
            while (true) {
                cout << "Please enter Crypt Text:\n";
                getline(cin, cryptText);
                cout << "Please enter UnCrypt Text:\n";
                getline(cin, unCryptText);

                int resultKey = SwitchKey(cryptText, unCryptText);
                if (resultKey != -1) {
                    cout << "Switch Key: " << resultKey << endl;
                    break;
                } else {
                    cout << "Error: Invalid input! Please check your crypt and uncrypt texts.\n";
                }
            }
        }
        else if (operation == "4") {
            cout << "Please enter text to Uncrypt without a key:\n";
            getline(cin, text);
            // Try all possible key values to find the correct one
            for (int key = 1; key < 26; key++) {
                cout << "Trying key " << key << ": ";
                UnCrypt(text, key);
            }
        }
        else {
            cout << "Error: Invalid choice! Please enter 1, 2, 3, or 4.\n";
        }

        string repeat;
        cout << "Do you want to try again? (Y/N): ";
        cin >> repeat;

        if (repeat != "Y" && repeat != "y" && repeat != "yes" && repeat != "YES" ) {
            cout << "Thank you for using the program.\n";
            break; // Exit the loop
        }
    }

    return 0;
}
