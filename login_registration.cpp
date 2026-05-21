#include <iostream>
#include <fstream>
using namespace std;

void registerUser() {
    string username, password;

    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    ofstream file((username + ".txt").c_str());
    file << username << endl << password;
    file.close();

    cout << "Registration Successful!\n";
}

void loginUser() {
    string username, password;
    string storedUser, storedPass;

    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    ifstream file((username + ".txt").c_str());

    if (!file) {
        cout << "User not found!\n";
        return;
    }

    getline(file, storedUser);
    getline(file, storedPass);
    file.close();

    if (username == storedUser && password == storedPass)
        cout << "Login Successful!\n";
    else
        cout << "Incorrect Password!\n";
}

int main() {
    int choice;

    do {
        cout << "\n1. Register\n2. Login\n3. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: registerUser(); break;
            case 2: loginUser(); break;
            case 3: cout << "Goodbye!\n"; break;
            default: cout << "Invalid Choice!\n";
        }
    } while (choice != 3);

    return 0;
}