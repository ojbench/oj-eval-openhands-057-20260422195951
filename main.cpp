#include <bits/stdc++.h>
using namespace std;

struct Student {
    string id;
    string name;
    int score;
    int idx;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Student> students;
    students.reserve(10000);
    unordered_map<string, int> id_pos;
    id_pos.reserve(16384);
    unordered_map<string, int> name_pos;
    name_pos.reserve(16384);

    int cmd;
    while (cin >> cmd) {
        if (cmd == 1) {
            string id, name; int s;
            if (!(cin >> id >> name >> s)) return 0;
            if (id_pos.find(id) != id_pos.end()) {
                cout << "FAILED\n";
            } else {
                int idx = (int)students.size();
                students.push_back({id, name, s, idx});
                id_pos[id] = idx;
                name_pos[name] = idx;
                cout << "SUCCESS\n";
            }
        } else if (cmd == 2) {
            if (!students.empty()) {
                for (const auto &st : students) {
                    cout << st.id << ' ' << st.name << ' ' << st.score << '\n';
                }
            }
        } else if (cmd == 3) {
            string id; cin >> id;
            auto it = id_pos.find(id);
            if (it != id_pos.end()) {
                const auto &st = students[it->second];
                cout << st.id << ' ' << st.name << ' ' << st.score << '\n';
            }
        } else if (cmd == 4) {
            string name; cin >> name;
            auto it = name_pos.find(name);
            if (it != name_pos.end()) {
                const auto &st = students[it->second];
                cout << st.id << ' ' << st.name << ' ' << st.score << '\n';
            }
        } else if (cmd == 5) {
            if (!students.empty()) {
                vector<Student> tmp = students;
                stable_sort(tmp.begin(), tmp.end(), [](const Student &a, const Student &b) {
                    return a.id < b.id; // 9-digit numeric strings
                });
                for (const auto &st : tmp) {
                    cout << st.id << ' ' << st.name << ' ' << st.score << '\n';
                }
            }
        } else if (cmd == 6) {
            if (!students.empty()) {
                vector<Student> tmp = students;
                stable_sort(tmp.begin(), tmp.end(), [](const Student &a, const Student &b) {
                    if (a.score != b.score) return a.score > b.score; // desc
                    return false; // keep insertion order
                });
                for (const auto &st : tmp) {
                    cout << st.id << ' ' << st.name << ' ' << st.score << '\n';
                }
            }
        } else if (cmd == 7) {
            cout << "END\n";
            break;
        } else {
            string rest; getline(cin, rest);
        }
    }
    return 0;
}
