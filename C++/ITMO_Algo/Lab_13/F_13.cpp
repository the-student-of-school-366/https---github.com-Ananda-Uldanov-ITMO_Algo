#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool isValidName(const string& name) {
    regex namePattern("^[A-Z][a-zA-Z]* [A-Z][a-zA-Z]* [A-Z][a-zA-Z]*$");
    return regex_match(name, namePattern);
}

bool isValidAge(const string& age) {
    regex agePattern("^\\d{2}$");
    return regex_match(age, agePattern);
}

bool isValidPhoneNumber(const string& phone) {
    regex phonePattern("^((\\+7|8)?(\\d{10}|\\d{3}-\\d{3}-\\d{2}-\\d{2}))$");
    return regex_match(phone, phonePattern);
}

bool isValidAddress(const string& address) {
    regex addressPattern("^[A-Z]{3}, ul\\.[A-Z][a-zA-Z]*, d\\.\\d+$");
    return regex_match(address, addressPattern);
}

int main() {
    int M;
    cin >> M;
    cin.ignore();  // Игнорируем символ новой строки после числа

    vector<string> results;
    for (int i = 0; i < M; ++i) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        string name, age, phone, addressPart;
        ss >> name;
        name += " ";
        ss >> addressPart;
        name += addressPart + " ";
        ss >> addressPart;
        name += addressPart;

        ss >> age >> phone;
        
        getline(ss, addressPart);
        string address = addressPart.substr(1);  // Удаляем начальный пробел

        bool valid = isValidName(name) && isValidAge(age) && isValidPhoneNumber(phone) && isValidAddress(address);
        results.push_back(valid ? "YES" : "NO");
    }

    for (const string& result : results) {
        cout << result << endl;
    }

    return 0;
}
