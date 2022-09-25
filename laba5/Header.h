#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cctype>
using namespace std;



void create_plane(string s, map<string, vector<string>>& CREATE_PLANE);
void planes_for_town(string s, map<string, vector<string>>& CREATE_PLANE);
void planes(string s, map<string, vector<string>>& CREATE_PLANE);
void towns_for_plane(string s, map<string, vector<string>>& CREATE_PLANE);
void zadanie1();

enum class PLANES {
    CREATE_PLANE = 1,
    PLANES_FOR_TOWN,
    TOWNS_FOR_PLANE,
    PLANES 
};


