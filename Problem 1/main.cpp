#include <iostream>
#include "IftarManager.h"
#include "Guest.h"
#include <cstdlib>

using namespace std;

int main() {
// Create Iftar Manager
    IftarManager manager = IftarManager();  // Default size is 10 but we can change it

// Add guests
    Guest guest1 = Guest("Aisha", "aisha@example.com", "2025-03-15");
    Guest guest2 = Guest("Omar", "omar@example.com", "2025-03-18");
    Guest guest3 = Guest("Zainab", "zainab@example.com", "2025-03-20");
    manager.add_guest(guest1);
    manager.add_guest(guest2);
    manager.add_guest(guest3);

// Display guest list
    manager.display_all_guests();

// Update invitation date for Omar
    manager.update_guest_invitation("Omar", "2025-03-15");


// Display updated guest list
    cout << endl;
    manager.display_all_guests();


// Send reminders
    cout << "\nReminders: " << endl;
    manager.send_reminder("2025-03-15");


// -- Test cases --
    cout << "\n -- Test Cases\n";
    // Actual mail for testing mails
    Guest guest4 = Guest("Abdelrahman", "20230220@stud.fci-cu.edu.eg", "2024-02-25");
    Guest guest5 = Guest("Maged", "maged@example.com", "2025-05-00");
    Guest guest6 = Guest("Sarah", "sarsor@example.com", "2025-01-12");
    Guest guest7 = Guest("Shady", "shadyy@example.com", "2022-02-17");
    Guest guest8 = Guest("Akram", "akrom@example.com", "2025-04-01");
    Guest guest9 = Guest("Lamis", "lam@mail.com", "2025-06-01");

    manager.add_guest(guest4);
    manager.add_guest(guest5);
    manager.add_guest(guest6);
    manager.add_guest(guest7);
    manager.add_guest(guest8);
    manager.add_guest(guest9);

    cout << "\nGuests (before removing):\n";
    manager.display_all_guests();

    manager.remove_guest("Sarah");
    manager.remove_guest("Shady");

    cout << "\nGuests (after removing):\n";
    manager.display_all_guests();

    cout << "\nGuests (unsorted):\n";
    manager.display_all_guests();

    manager.sort_guest_list();
    cout << "\nGuests (sorted):\n";
    manager.display_all_guests();

    cout << "\nMail Testing:\n";
    manager.send_reminder("2024-02-25");
}