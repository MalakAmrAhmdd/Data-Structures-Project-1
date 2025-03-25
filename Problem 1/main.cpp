#include <iostream>
#include "IftarManager.h"
#include "Guest.h"
#include <cstdlib>

using namespace std;

int main() {
// Create Iftar Manager
    IftarManager manager = IftarManager();
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
    Guest guest4 = Guest("Abdelrahman", "abdelrahmanyr05@gmail.com", "2024-03-25");
    manager.add_guest(guest4);
// Display updated guest lis
    cout << endl;
    manager.display_all_guests();
// Send reminders
    cout << "Reminders: " << endl;
    manager.send_reminder("2024-03-25");

}