#include "IftarManager.h"
#include <iostream>
#include <curl/curl.h>


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


void IftarManager::send_email(string name, string contact, string date) {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
        struct curl_slist *recipients = NULL;
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.mailjet.com/v3.1/send");
        curl_easy_setopt(curl, CURLOPT_USERNAME, "9385dd8f2e046880bd11631303c00151");
        curl_easy_setopt(curl, CURLOPT_PASSWORD, "bfb13a2ecbb2434fbe296374fb43d42b");
        curl_easy_setopt(curl, CURLOPT_POST, 1L);

        string data_ = "{\"Messages\":[{\"From\":{\"Email\":\"fatimaiftards@gmail.com\",\"Name\":\"Fatima\"},\"To\":[{\"Email\":\"" + contact + "\",\"Name\":\"" + name + "\"}],\"Subject\":\"Reminder for your iftar at Fatima's.\",\"TextPart\":\"Iftar Gathering\",\"HTMLPart\":\"<h3>This is a reminder that your iftar is on " + date + "</h3><br />I hope you will be able to make it!\"}]}";
        const char* data = data_.c_str();

        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, recipients);

        // Capture the response
        std::string response_string;
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);

        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            // Print the response
            std::cout << "Response from Mailjet: " << response_string << std::endl;
        }
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

