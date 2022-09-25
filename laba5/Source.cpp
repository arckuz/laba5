#include "Header.h"

void create_plane(string s, map<string, vector<string>>& CREATE_PLANE) {
    bool first_space = true, second_space = true;
    string name, town;
    vector<string> towns;
    for (auto i : s) {
        if (i == ' ' && first_space) {
            first_space = false;
            continue;
        }
        if (!first_space && second_space && i != ' ') {
            name += i;
        }
        if (i == ' ' && second_space) {
            second_space = false;
            continue;
        }
        if (!first_space && !second_space) {
            town += i;
        }
        if (!first_space && !second_space && i == ' ') {
            towns.push_back(town);
            town = "";
        }
    }
    CREATE_PLANE.insert(make_pair(name, towns));
    /*for (auto i : CREATE_PLANE) {
        cout << i.first << ": ";
        for (auto j : i.second) {
            cout << j << " ";
        }
    }*/
}
void planes_for_town(string s, map<string, vector<string>>& CREATE_PLANE) {
    bool first_space = true;
    string town = "";
    for (auto i : s) {
        if (i == ' ' && first_space) {
            first_space = false;
            continue;
        }
        if (!first_space) {
            town += i;
        }
    }
    cout << "Planse with town " << town << ":";
    for (auto i : CREATE_PLANE) {
        bool right = false;
        for (auto j : i.second) {
            if (j == town) {
                right = true;
            }
        }
        if (right) {
            cout << i.first << " ";
        }
    }
    cout << endl;
}
void planes(string s, map<string, vector<string>>& CREATE_PLANE) {
    for (auto i : CREATE_PLANE) {
        cout << "Plane " << i.first << " witn towns: ";
        for (auto j : i.second) {
            cout << j << " ";
        }
        cout << endl;
    }
}
void towns_for_plane(string s, map<string, vector<string>>& CREATE_PLANE) {
    bool first_space = true;
    string name = "", town = "";
    for (auto i : s) {
        if (i == ' ' && first_space) {
            first_space = false;
            continue;
        }
        if (!first_space && i != ' ') {
            name += i;
        }
    }
    cout << "TOWNS FOR PLANE " << name << " is: ";
    string perechen = "PLANE_FOR_TOWN ";
    for (auto i : CREATE_PLANE) {
        if (i.first == name) {
            for (auto j : i.second) {
                cout << j << " ";
            }
        }
    }
    cout << endl;
    for (auto i : CREATE_PLANE) {
        if (i.first == name) {
            for (auto j : i.second) {
                string perechen = "PLANE_FOR_TOWN ";
                perechen += j;


                first_space = true;
                town = "";
                for (auto i : perechen) {
                    if (i == ' ' && first_space) {
                        first_space = false;
                        continue;
                    }
                    if (!first_space) {
                        town += i;
                    }
                }
                int cnt = 0;
                cout << "planse with town " << town << ":";
                for (auto i : CREATE_PLANE) {
                    if (i.first == name) {
                        continue;
                    }  
                    for (auto j : i.second) {
                        if (j == town) {
                            cout << i.first << " ";
                            cnt += 1;
                        }
                    }   
                }
                if (cnt == 0) {
                    cout << "0";
                }
                cout << endl;
            }
        }
    }
}
void zadanie1() {
    setlocale(LC_ALL, "Russian");
    map<string, vector<string>> CREATE_PLANE;
    bool first_space = true, second_space = true;
    string name, town;
    vector<string> towns;
    int numb_oper = 0;
    cout << "Введите количество операций, которые хотит выволнить: ";
    cin >> numb_oper;
    vector<string> comands;
    for (int i = 0; i < numb_oper + 1; i++) {
        string stroka = "";
        getline(cin, stroka);
        comands.push_back(stroka);
    }
    PLANES N=PLANES::CREATE_PLANE;
    for (auto i : comands) {
        string s, str;
        s = i;
        for (auto i : s) {
            if (i == ' ') {
                break;
            }
            str += i;
        }
        s += ' ';
        if (str == "CREATE_PLANE") {
            N = PLANES::CREATE_PLANE;
        }
        if (str == "PLANES_FOR_TOWN") {
            N = PLANES::PLANES_FOR_TOWN;
        }
        if (str == "TOWNS_FOR_PLANE") {
            N = PLANES::TOWNS_FOR_PLANE;
        }
        if (str == "PLANES") {
            N = PLANES::PLANES;
        }
        switch (N) {
        case (PLANES::CREATE_PLANE):
            create_plane(s, CREATE_PLANE);
            break;
        case(PLANES::PLANES_FOR_TOWN):
            planes_for_town(s, CREATE_PLANE);
            break;
        case(PLANES::TOWNS_FOR_PLANE):
            towns_for_plane(s, CREATE_PLANE);
            break;
        case(PLANES::PLANES):
            planes(s, CREATE_PLANE);
            break;
        }
    }
}
