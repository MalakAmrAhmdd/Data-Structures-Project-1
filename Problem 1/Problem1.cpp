#include <iostream>
#include <curl/curl.h>

using namespace std;

class Guest {
private:
    string name;
    string contact;
    string iftar_date;

public:
    Guest();
    Guest(string name, string contact, string date);

    string getName () {
        return name;
    }
    string getContact () {
        return contact;
    }
    string getDate () {
        return iftar_date;
    }

    void display_guest();
    void update_invitation(string new_date);
};

Guest::Guest() : name(""), contact(""), iftar_date("") {}

Guest::Guest(string name, string contact, string date) {
    this->name = name;
    this->contact = contact;
    this->iftar_date = date;
}

void Guest::display_guest() {
    cout << "Guest: " << this->name <<
         ", Contact: " << this->contact <<
         ", Iftar Date: " << this->iftar_date << endl;
}

void Guest::update_invitation(string new_date) {
    this->iftar_date = new_date;
}


class List {
private:
    Guest* list = new Guest;
    int length = 0;
    int maxSize;

public:
    List();
    List(int size);
    ~List();

    Guest& operator= (Guest guest);
    Guest& operator[](int index);
    int size();
    void insert(Guest guest);
    void removeAt(int loc);
    int search(string name);
};

List::List() {
}

List::List(int len) {
    this->maxSize = len;
    list = new Guest[this->maxSize];
}

List::~List() {
    delete[] list;
}

Guest& List::operator=(Guest guest) {
    delete[] list;
    list = &guest;
    return *list;
}

Guest& List::operator[](int index) {
    if (index >= 0 && index < length) {
        return list[index];
    } else {
        throw out_of_range("- Index out of range");
    }
}

int List::size() {
    return length;
}

void List::insert(Guest guest)  {
    if (maxSize > length) {
        list[length] = guest;
        this->length++;
    }
    else {
        cerr << "- Guest list is currently full!";
    }
}

void List::removeAt(int loc) {
    for (int i = loc; i < size() - 1; i++) {
        list[i] = list[i+1];
    }
    length--;
}

int List::search(string name) {
    for (int i = 0; i < this->size(); i++) {
        if (name == list[i].getName()) {
            return i;
        }
    }
    return -1;
}


class IftarManager {
private:
    List guest_list;

public:
    IftarManager();
    IftarManager(int size);
    void add_guest(Guest guest);
    void remove_guest(string name);
    void display_all_guests();
    void update_guest_invitation(string name, string new_date);
    void send_reminder(string date);
    void send_email(string name, string contact, string date);
    void sort_guest_list();
};


using namespace std;
string API_KEY = "9385dd8f2e046880bd11631303c00151";
string API_SECRET = "bfb13a2ecbb2434fbe296374fb43d42b";

IftarManager::IftarManager() : guest_list(10) {
}

IftarManager::IftarManager(int size) : guest_list(size) {
}

void IftarManager::add_guest(Guest guest) {
    guest_list.insert(guest);
}

void IftarManager::remove_guest(string name) {
    int posOfGuest = guest_list.search(name);
    if (posOfGuest != -1) {
        guest_list.removeAt(posOfGuest);
    }
}

void IftarManager::display_all_guests() {
    int currSize = guest_list.size();
    for (int i = 0; i < currSize; i++) {
        cout << "Guest: " << guest_list[i].getName() <<
             ", Contact: " << guest_list[i].getContact() <<
             ", Iftar Date: " << guest_list[i].getDate() << endl;
    }
}

void IftarManager::update_guest_invitation(string name, string new_date) {
    int posOfGuest = guest_list.search(name);
    if (posOfGuest != -1) {
        guest_list[posOfGuest].update_invitation(new_date);
    }
}


// Callback function to capture the response
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* s) {
    size_t newLength = size * nmemb;
    try {
        s->append((char*)contents, newLength);
    } catch (std::bad_alloc& e) {
        return 0;
    }
    return newLength;
}

void IftarManager::send_email(string name, string contact, string date) {
    CURL *curl;
    CURLcode res;
    long http_code = 0;

    curl = curl_easy_init();
    if(curl) {
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");

        curl_easy_setopt(curl, CURLOPT_URL, "https://api.mailjet.com/v3.1/send");
        curl_easy_setopt(curl, CURLOPT_USERNAME, API_KEY.c_str());
        curl_easy_setopt(curl, CURLOPT_PASSWORD, API_SECRET.c_str());
        curl_easy_setopt(curl, CURLOPT_POST, 1L);

        string data_ = "{\"Messages\":[{\"From\":{\"Email\":\"fatimaiftards@gmail.com\",\"Name\":\"Fatima\"},\"To\":[{\"Email\":\"" + contact + "\",\"Name\":\"" + name + "\"}],\"Subject\":\"Reminder for your iftar at Fatima's.\",\"TextPart\":\"Iftar Gathering\",\"HTMLPart\":\"<h3>This is a reminder that your iftar is on " + date + "</h3><br />I hope you will be able to make it!\"}]}";
        const char* data = data_.c_str();

        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        string response_string;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);

        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
            if (http_code == 200) {
                cout << "Email sent successfully to: " << contact << std::endl;
            } else {
                cout << "Failed to send email. HTTP response code: " << http_code << std::endl;
                cout << "Response from Mailjet: " << response_string << std::endl;
            }
        }

        // Clean up
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }
}



void IftarManager::send_reminder(string date) {
    for (int i = 0; i < guest_list.size(); i++) {
        if (date == guest_list[i].getDate()) {
            guest_list[i].display_guest();
            send_email(guest_list[i].getName(), guest_list[i].getContact(), guest_list[i].getDate());
        }
    }
}

void IftarManager::sort_guest_list() {
    // Using insertion sort
    for (int i = 1; i < guest_list.size(); i++) {
        int j;
        Guest tmp = guest_list[i];
        for (j = i; j > 0 && tmp.getDate() < guest_list[j-1].getDate(); j--) {
            guest_list[j] = guest_list[j - 1];
        }
        guest_list[j] = tmp;
    }
}

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