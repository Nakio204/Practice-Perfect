#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// Dem so luong tu trong xau
/*
int main() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    string word;
    int cnt = 0;
    while (ss >> word) {
        ++cnt;
    }
    cout << cnt << endl;

    return 0;
}
*/

// Xoa 1 tu trong xau
/*
int main() {
    string s;
    getline(cin, s);
    string word; cin >> word;
    stringstream ss(s);
    string token;
    vector<string> v;
    while (ss >> token) {
        if (token != word) {
            v.push_back(token);
        }
    }
    for(int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i != v.size() - 1) cout << " ";
    }

    return 0;
}
*/

// Tao email tu ten nguoi dung
int main() {
    int t;
    cout << "Nhap so luong email: ";
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        for (int i = 0; i < s.length(); i++) s[i] = tolower(s[i]);
        vector<string> v;
        stringstream ss(s);
        string tmp;
        while (ss >> tmp) {
            v.push_back(tmp);
        }
        cout << v.back();
        for(int i = 0; i < v.size() - 1; i++) {
            cout << v[i][0];
        }
        cout << "@icloud.com" << endl;
    }
    

    return 0;
}
