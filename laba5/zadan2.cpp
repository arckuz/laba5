#include "Header.h"
void CLASS(string stroka, map<string, vector<string>>& LESSONS) {
    bool first_space = true, second_space = true, OK;
    string day = "", disciplina = "";
    for (auto i : stroka) {
        if (i == ' ' && first_space) {
            first_space = false;
            continue;
        }
        if (i != ' ' && !first_space && second_space) {
            day += i;
        }
        if (i == ' ' && !first_space) {
            second_space = false;
            continue;
        }
        if (i != ' ' && !second_space) {
            disciplina += i;
        }
        if (i == ' ' && !second_space) {
            break;
        }
    }
    OK = false;
    for (auto i : LESSONS) {
        if (i.first == day) {
            OK = true;
            vector<string> v;
            v = i.second;
            v.push_back(disciplina);
            LESSONS.erase(day);
            LESSONS.insert(make_pair(day, v));
            v.clear();
            break;
        }
    }
    if (!OK) {
        vector<string> v;
        v.push_back(disciplina);
        LESSONS.insert(make_pair(day, v));
        v.clear();
    }
}
void NEXT(int& n, map<int, int> ::iterator& it, map<string, vector<string>>& LESSONS) {
    n = it->second;
    it++;
    if (n - it->second > 0) {
        while (n - it->second != 0) {
            bool OK = false;
            for (auto i : LESSONS) {
                if (stoi(i.first) == n) {
                    vector<string> v1, empty;
                    v1 = i.second;
                    LESSONS.erase(i.first);
                    LESSONS.insert(make_pair(i.first, empty));
                    for (auto i : LESSONS) {
                        if (stoi(i.first) == it->second - 1) {
                            OK = true;
                            vector<string> v2;
                            v2 = i.second;
                            if (v1.size() > v2.size()) {
                                for (auto k : v2) {
                                    v1.push_back(k);
                                }
                            }
                            else {
                                for (auto k : v1) {
                                    v2.push_back(k);
                                }
                            }
                            LESSONS.erase(i.first);
                            if (v1.size() > v2.size()) {
                                LESSONS.insert(make_pair(i.first, v1));
                            }
                            else {
                                LESSONS.insert(make_pair(i.first, v2));
                            }
                            break;
                        }

                    }
                    if (!OK) {
                        LESSONS.insert(make_pair(to_string(it->second - 1), v1));
                    }
                    break;
                }
            }
            n--;
        }
    }
}
void VIEW(string stroka, map<string, vector<string>>& LESSONS) {
    bool first_space = true;
    string day;
    for (auto i : stroka) {
        if (i == ' ' && first_space) {
            first_space = false;
            continue;
        }
        if (i != ' ' && !first_space) {
            day += i;
        }
    }
    for (auto i : LESSONS) {
        if (i.first == day) {
            if (i.second.size() == 0) {
                cout << "In " << day << " day We are free!";
            }
            else {
                cout << "In " << day << " day " << i.second.size() << " classes in university : ";
                for (auto j : i.second) {
                    cout << j << " ";
                }
            }
        }
    }
    cout << endl;
}
void zadanie2() {
    setlocale(LC_ALL, "Russian");
    map<string, vector<string>> LESSONS;
    map<int, int> month = { {1,31},{2,28},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31} };
    int n = 1, numb_oper;
    map<int, int> ::iterator it = month.begin();
    cout << "Введите количество операций, которые хотит выволнить: ";
    cin >> numb_oper;
    vector<string> comands;
    for (int i = 0; i < numb_oper + 1; i++) {
        string s = "";
        getline(cin, s);
        comands.push_back(s);
    }
    for (auto i : comands) {
        string stroka, str = "";
        stroka = i;
        for (auto i : stroka) {
            if (i == ' ') {
                break;
            }
            str += i;
        }
        stroka += " ";
        if (str == "CLASS") {
            CLASS(stroka, LESSONS);
        }
        if (str == "NEXT") {
            NEXT(n, it, LESSONS);
        }
        if (str == "VIEW") {
            VIEW(stroka, LESSONS);
        }
    }
}