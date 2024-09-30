#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAX_FLIGHT_CODE_LEN = 5;

struct dates {
    int day, month, year;
};

struct times {
    int h, m;
};

struct flights {
    string flight_code;
    dates date;
    times time;
    string depart;
    string arrive;
};

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
    if (code.size() > MAX_FLIGHT_CODE_LEN) return false;
    return all_of(code.begin(), code.end(), ::isalnum);
}

bool isValidDate(const dates &d) {
    if (d.year < 1) return false;
    if (d.month < 1 || d.month > 12) return false;
    if (d.day < 1) return false;

    const vector<int> days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool isLeapYear = (d.year % 4 == 0 && d.year % 100 != 0) || (d.year % 400 == 0);
    if (d.month == 2 && isLeapYear) {
        return d.day <= 29;
    }
    return d.day <= days_in_month[d.month - 1];
}

bool isValidTime(const times &t) {
    return (t.h >= 0 && t.h < 24) && (t.m >= 0 && t.m < 60);
}

bool isValidLocation(const string &location) {
    return !location.empty() && all_of(location.begin(), location.end(), ::isalpha);
}

void inputFlight(flights &fi) {
    cout << "Nhập mã chuyến bay (tối đa 5 ký tự chữ và số): ";
    cin >> fi.flight_code;

    while (!isValidFlightCode(fi.flight_code)) {
        cout << "Mã chuyến bay không hợp lệ! Vui lòng nhập lại: ";
        cin >> fi.flight_code;
    }

    cout << "Nhập ngày bay (dd mm yyyy): ";
    cin >> fi.date.day >> fi.date.month >> fi.date.year;
    while (!isValidDate(fi.date)) {
        cout << "Ngày không hợp lệ! Vui lòng nhập lại (dd mm yyyy): ";
        cin >> fi.date.day >> fi.date.month >> fi.date.year;
    }

    cout << "Nhập giờ bay (hh mm): ";
    cin >> fi.time.h >> fi.time.m;
    while (!isValidTime(fi.time)) {
        cout << "Giờ không hợp lệ! Vui lòng nhập lại (hh mm): ";
        cin >> fi.time.h >> fi.time.m;
    }

    cout << "Nhập nơi khởi hành (chỉ ký tự chữ cái): ";
    cin >> fi.depart;
    while (!isValidLocation(fi.depart)) {
        cout << "Nơi khởi hành không hợp lệ! Vui lòng nhập lại: ";
        cin >> fi.depart;
    }

    cout << "Nhập nơi đến (chỉ ký tự chữ cái): ";
    cin >> fi.arrive;
    while (!isValidLocation(fi.arrive)) {
        cout << "Nơi đến không hợp lệ! Vui lòng nhập lại: ";
        cin >> fi.arrive;
    }
}

void outputFlight(const flights &fi) {
    cout << "Mã chuyến bay: " << fi.flight_code << endl;
    cout << "Ngày bay: " << fi.date.day << "/" << fi.date.month << "/" << fi.date.year << endl;
    cout << "Giờ bay: " << setw(2) << setfill('0') << fi.time.h << ":" << setw(2) << setfill('0') << fi.time.m << endl;
    cout << "Nơi khởi hành: " << fi.depart << endl;
    cout << "Nơi đến: " << fi.arrive << endl;
}

void searchFlight(const vector<flights> &flightList) {
    string query;
    cout << "Nhập mã chuyến bay, nơi khởi hành hoặc nơi đến để tìm: ";
    cin >> query;

    bool found = false;
    for (const auto &flight : flightList) {
        if (flight.flight_code == query || flight.depart == query || flight.arrive == query) {
            outputFlight(flight);
            found = true;
        }
    }

    if (!found) {
        cout << "Không tìm thấy chuyến bay nào!" << endl;
    }
}

void displayFlightsFromDate(const vector<flights> &flightList, const string &fromLocation, const dates &specificDate) {
    cout << "Chuyến bay khởi hành từ " << fromLocation << " vào ngày " << specificDate.day << "/" << specificDate.month << "/" << specificDate.year << ":" << endl;

    bool found = false;
    for (const auto &flight : flightList) {
        if (flight.depart == fromLocation && flight.date.day == specificDate.day &&
            flight.date.month == specificDate.month && flight.date.year == specificDate.year) {
            outputFlight(flight);
            found = true;
        }
    }

    if (!found) {
        cout << "Không có chuyến bay nào cho ngày và địa điểm này!" << endl;
    }
}

int countFlightsFromTo(const vector<flights> &flightList, const string &fromLocation, const string &toLocation) {
    return count_if(flightList.begin(), flightList.end(),
                    [&](const flights &f) { return f.depart == fromLocation && f.arrive == toLocation; });
}

void sortAndDisplayFlights(vector<flights> &flightList) {
    sort(flightList.begin(), flightList.end(), compareFlights);
    cout << "Danh sách chuyến bay đã sắp xếp theo ngày và giờ:\n";
    for (const auto &flight : flightList) {
        outputFlight(flight);
        cout << endl;
    }
}

int main() {
    vector<flights> flightList;
    char choice;

    do {
        flights fi;
        inputFlight(fi);
        flightList.push_back(fi);

        cout << "Bạn có muốn nhập chuyến bay khác không? (y/n): ";
        cin >> choice;
    } while (tolower(choice) == 'y');

    sortAndDisplayFlights(flightList);

    searchFlight(flightList);

    string fromLocation;
    dates specificDate;
    cout << "Nhập nơi khởi hành: ";
    cin >> fromLocation;
    cout << "Nhập ngày (dd mm yyyy): ";
    cin >> specificDate.day >> specificDate.month >> specificDate.year;
    displayFlightsFromDate(flightList, fromLocation, specificDate);

    string toLocation;
    cout << "Nhập nơi đến: ";
    cin >> toLocation;
    int count = countFlightsFromTo(flightList, fromLocation, toLocation);
    cout << "Số lượng chuyến bay từ " << fromLocation << " đến " << toLocation << " là: " << count << endl;

    return 0;
}
