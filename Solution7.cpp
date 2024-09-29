#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct dates {
    int day, month, year;
};

struct times {
    int h;
    int m;
};

struct flights {
    string flight_code;
    dates date;
    times time;
    string depart;
    string arrive;
};

// Function to compare two flight times for sorting
bool compareFlights(const flights &f1, const flights &f2) {
    if (f1.date.year != f2.date.year)
        return f1.date.year < f2.date.year;
    if (f1.date.month != f2.date.month)
        return f1.date.month < f2.date.month;
    if (f1.date.day != f2.date.day)
        return f1.date.day < f2.date.day;
    if (f1.time.h != f2.time.h)
        return f1.time.h < f2.time.h;
    return f1.time.m < f2.time.m;
}

bool isValidFlightCode(const string &code) {
    if (code.size() > 5) return false;
    for (char c : code) {
        if (!isalnum(c)) return false;  // Check if each character is alphanumeric
    }
    return true;
}

bool isValidDate(const dates &d) {
    if (d.year < 1) return false;
    if (d.month < 1 || d.month > 12) return false;
    if (d.day < 1) return false;

    // Check days in month
    if (d.month == 2) {
        if ((d.year % 4 == 0 && d.year % 100 != 0) || (d.year % 400 == 0)) { // Leap year
            return d.day <= 29;
        }
        return d.day <= 28;
    } else if (d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11) {
        return d.day <= 30;
    } else {
        return d.day <= 31;
    }
}

bool isValidTime(const times &t) {
    return (t.h >= 0 && t.h < 24) && (t.m >= 0 && t.m < 60);
}

bool isValidLocation(const string &location) {
    return all_of(location.begin(), location.end(), [](char c) {
        return isalpha(c);  // Check if all characters are alphabetic
    });
}

void nhap(flights &fi) {
    cout << "Nhap ma bay: ";
    cin >> fi.flight_code;

    if (!isValidFlightCode(fi.flight_code)) {
        cout << "Ma bay khong hop le!" << endl;
        fi.flight_code = "";
    }

    cout << "Nhap ngay bay (dd mm yyyy): ";
    cin >> fi.date.day >> fi.date.month >> fi.date.year;

    if (!isValidDate(fi.date)) {
        cout << "Ngay khong hop le!" << endl;
        return;  // Exit if date is invalid
    } else {
        cout << "Ngay hop le" << endl;
    }

    cout << "Nhap gio bay (hh mm): ";
    cin >> fi.time.h >> fi.time.m;

    if (!isValidTime(fi.time)) {
        cout << "Gio khong hop le!" << endl;
        return;  // Exit if time is invalid
    } else {
        cout << "Gio hop le!" << endl;
    }

    cout << "Nhap noi di: ";
    cin >> fi.arrive;
    if (!isValidLocation(fi.arrive)) {
        cout << "Noi di khong hop le!" << endl;
        return;  // Exit if departure location is invalid
    } else {
        cout << "Noi di hop le!" << endl;
    }

    cout << "Nhap noi den: ";
    cin >> fi.depart;
    if (!isValidLocation(fi.depart)) {
        cout << "Noi den khong hop le!" << endl;
        return;  // Exit if arrival location is invalid
    } else {
        cout << "Noi den hop le!" << endl;
    }
}

void xuat(const flights &fi) {
    cout << "Flight Code: " << fi.flight_code << endl;
    cout << "Date: " << fi.date.day << "/" << fi.date.month << "/" << fi.date.year << endl;
    cout << "Time: " << fi.time.h << ":" << (fi.time.m < 10 ? "0" : "") << fi.time.m << endl;
    cout << "Departure: " << fi.arrive << endl;
    cout << "Arrival: " << fi.depart << endl;
}

void searchFlight(const vector<flights> &flightList) {
    string query;
    cout << "Nhap ma chuyen bay, noi di, hoac noi den de tim: ";
    cin >> query;

    bool found = false;
    for (const auto &flight : flightList) {
        if (flight.flight_code == query || flight.arrive == query || flight.depart == query) {
            xuat(flight);
            found = true;
        }
    }
    if (!found) {
        cout << "Khong tim thay chuyen bay!" << endl;
    }
}

void displayFlightsFromDate(const vector<flights> &flightList, const string &fromLocation, const dates &specificDate) {
    cout << "Chuyen bay khoi hanh tu " << fromLocation << " vao ngay " << specificDate.day << "/" << specificDate.month << "/" << specificDate.year << ":" << endl;
    
    bool found = false;
    for (const auto &flight : flightList) {
        if (flight.arrive == fromLocation && flight.date.day == specificDate.day && flight.date.month == specificDate.month && flight.date.year == specificDate.year) {
            xuat(flight);
            found = true;
        }
    }
    if (!found) {
        cout << "Khong co chuyen bay nao!" << endl;
    }
}

int countFlightsFromTo(const vector<flights> &flightList, const string &fromLocation, const string &toLocation) {
    int count = 0;
    for (const auto &flight : flightList) {
        if (flight.arrive == fromLocation && flight.depart == toLocation) {
            count++;
        }
    }
    return count;
}

void sortFlights(vector<flights> &flightList) {
    sort(flightList.begin(), flightList.end(), compareFlights);
    cout << "Danh sach chuyen bay da duoc sap xep!" << endl;
}

int main() {
    vector<flights> flightList;
    char choice;

    // Input flights
    do {
        flights fi;
        nhap(fi);
        flightList.push_back(fi);

        cout << "Ban co muon nhap chuyen bay khac? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    // Sort and display flights
    sortFlights(flightList);
    cout << "Danh sach chuyen bay sau khi sap xep:" << endl;
    for (const auto &flight : flightList) {
        xuat(flight);
    }

    // Search for a specific flight
    searchFlight(flightList);

    // Display flights from a specific location on a specific date
    string fromLocation;
    dates specificDate;
    cout << "Nhap noi khoi hanh: ";
    cin >> fromLocation;
    cout << "Nhap ngay (dd mm yyyy): ";
    cin >> specificDate.day >> specificDate.month >> specificDate.year;
    displayFlightsFromDate(flightList, fromLocation, specificDate);

    // Count flights from one location to another
    string toLocation;
    cout << "Nhap noi den: ";
    cin >> toLocation;
    int count = countFlightsFromTo(flightList, fromLocation, toLocation);
    cout << "So luong chuyen bay tu " << fromLocation << " den " << toLocation << " la: " << count << endl;

    return 0;
}