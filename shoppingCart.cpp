
// Programmer: Aditya Shukla
// Project: Simple Shopping Cart System in C++
// Description: Console-based store interface with item selection and cart tracking

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

// Store board with item details: ID, Name, Price
string board[5][3] = {
    {"ID", "ITEMS", "PRICE"},
    {"1", "FLOUR", "200RS"},
    {"2", "RICE", "250RS"},
    {"3", "SUGAR", "100RS"},
    {"4", "SALT", "150RS"}
};

// Cart to hold selected items
vector<string> cart;
int choice;
int amount = 0;
bool endSession = false;

// Adds selected item to cart and updates total amount
void addCart(int choice) {
    switch(choice) {
        case 1: cart.push_back("FLOUR"); amount += 200; break;
        case 2: cart.push_back("RICE");  amount += 250; break;
        case 3: cart.push_back("SUGAR"); amount += 100; break;
        case 4: cart.push_back("SALT");  amount += 150; break;
        default: cout << "Invalid choice!" << endl;
    }
}

// Displays current cart contents and total amount
void showCart() {
    cout << "\nYour cart:" << endl;
    if(cart.empty()) {
        cout << "empty" << endl;
    } else {
        for(size_t i = 0; i < cart.size(); i++) {
            cout << (i+1) << ") " << cart[i] << endl;
        }
    }
    cout << "Total amount = " << amount << " RS" << endl;
}

int main() {
    // Main shopping loop
    while(endSession == false) {
        system("cls"); // Clears screen for fresh display

        // Welcome banner
        cout << " _______________________ " << endl;
        cout << "| WELCOME TO MY STORE  |" << endl;
        cout << " _______________________ " << endl;

        // Display item board
        for (int i = 0; i < 5; i++) {
            cout << setw(5) << board[i][0]
                 << setw(10) << board[i][1]
                 << setw(8) << board[i][2] << endl;
        }
        cout << " _______________________" << endl;

        // Show current cart
        showCart();

        // Prompt user for input
        cout << "\nEnter zero(0) to end the session" << endl;
        cout << "Enter the ID of the product you want to buy: ";
        cin >> choice;

        // Check for session end
        if(choice == 0) {
            endSession = true;
        } else {
            addCart(choice); // Add item to cart
        }
    }

    // Final cart summary
    system("cls");
    cout << "\nFinal cart:" << endl;
    for(size_t i = 0; i < cart.size(); i++) {
        cout << (i+1) << ") " << cart[i] << endl;
    }
    cout << "Final total = " << amount << " RS" << endl;
    cout << "Thank you for shopping!" << endl;

    return 0;
}
