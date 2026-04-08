#include <iostream>
#include <string>

using namespace std;

// the class that stores one username and one password together
class PasswordEntry
{
private:

    string username;
    string password;

public:

    // the constructor (so it runs automatically when object is made)
    PasswordEntry()
    {
        username = "";
        password = "";
    }

    // getter for username
    string getUsername()
    {
        return username;
    }

    // getter for password
    string getPassword()
    {
        return password;
    }

    // setter for username
    void setUsername(string newUsername)
    {
        username = newUsername;
    }

    // setter for password
    void setPassword(string newPassword)
    {
        password = newPassword;
    }
};

// function prototypes
int showMenu();
void addEntry(PasswordEntry entries[], int &entryCount);
void listEntries(PasswordEntry entries[], int entryCount);
void searchEntry(PasswordEntry entries[], int entryCount);
void updatePassword(PasswordEntry entries[], int entryCount);

int main()
{
    // array that stores 5 PasswordEntry objects
    // (the project explicitly asks for array with 5 entries)
    PasswordEntry entries[5];

    int entryCount = 0;
    int choice;

    bool programIsRunning = true;

    // main loop
    while (programIsRunning == true)
    {

        choice = showMenu();

        // menu choices
        if (choice == 1)
        {
            addEntry(entries, entryCount);
        }
        else if (choice == 2)
        {
            listEntries(entries, entryCount);
        }
        else if (choice == 3)
        {
            searchEntry(entries, entryCount);
        }
        else if (choice == 4)
        {
            updatePassword(entries, entryCount);
        }
        else if (choice == 5)
        {
            cout << "Exiting program..." << endl;
            programIsRunning = false;
        }

        cout << endl;
    }

    return 0;
}

int showMenu()
{
    string menuInput;

    // main menu loop
    while (true)
    {
        cout << "===== Password Manager =====" << endl;
        cout << "1. Add Entry" << endl;
        cout << "2. List Entries" << endl;
        cout << "3. Search" << endl;
        cout << "4. Update Password" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";

        // invalid input --> return 5
        if (!(cin >> menuInput))
        {
            return 5;
        }

        if (menuInput == "1")
        {
            return 1;
        }
        else if (menuInput == "2")
        {
            return 2;
        }
        else if (menuInput == "3")
        {
            return 3;
        }
        else if (menuInput == "4")
        {
            return 4;
        }
        else if (menuInput == "5")
        {
            return 5;
        }
        else
        {
            cout << "Invalid choice. Please enter a number from 1 to 5." << endl;
            cout << endl;
        }
    }
}

void addEntry(PasswordEntry entries[], int &entryCount)
{
    // check if array is full or not
    if (entryCount >= 5)
    {
        cout << "Password manager is full. You can only store 5 entries." << endl;
        return;
    }

    string newUsername;
    string newPassword;

    cout << "Enter username: ";
    cin >> newUsername;

    cout << "Enter password: ";
    cin >> newPassword;

    // store new username and password in next open slot
    entries[entryCount].setUsername(newUsername);
    entries[entryCount].setPassword(newPassword);

    entryCount = entryCount + 1;

    cout << "Entry added successfully." << endl;
}

void listEntries(PasswordEntry entries[], int entryCount)
{
    if (entryCount == 0)
    {
        cout << "No entries stored yet." << endl;
        return;
    }

    cout << "Stored entries:" << endl;

    for (int i = 0; i < entryCount; i++)
    {
        cout << "Entry " << i + 1 << ":" << endl;
        cout << "Username: " << entries[i].getUsername() << endl;
        cout << "Password: " << entries[i].getPassword() << endl;
        cout << endl;
    }
}

void searchEntry(PasswordEntry entries[], int entryCount)
{
    if (entryCount == 0)
    {
        cout << "No entries stored yet." << endl;
        return;
    }

    string usernameToFind;

    cout << "Enter username to search for: ";
    cin >> usernameToFind;

    // check each stored entry
    for (int i = 0; i < entryCount; i++)
    {
        if (entries[i].getUsername() == usernameToFind)
        {
            cout << "Entry found." << endl;
            cout << "Username: " << entries[i].getUsername() << endl;
            cout << "Password: " << entries[i].getPassword() << endl;
            return;
        }
    }

    // if no matches found
    cout << "Entry not found." << endl;
}

void updatePassword(PasswordEntry entries[], int entryCount)
{
    if (entryCount == 0)
    {
        cout << "No entries stored yet." << endl;
        return;
    }

    string usernameToUpdate;
    string newPassword;

    cout << "Enter username to update: ";
    cin >> usernameToUpdate;

    // search for the username.
    // if found, ask for a new password and replace the old one
    for (int i = 0; i < entryCount; i++)
    {
        if (entries[i].getUsername() == usernameToUpdate)
        {
            cout << "Enter new password: ";
            cin >> newPassword;

            entries[i].setPassword(newPassword);

            cout << "Password updated successfully." << endl;
            return;
        }
    }

    cout << "Entry not found." << endl;
}
