#pragma once
#include <iostream>
#include <string>
#include "KS.h"
#include "Pipe.h"
#include <vector>
#include <fstream>

template<typename T>
T GetCorrectNumber(std::string text, T min, T max) {
    T n;
    std::cout << text << ":  ";
    while ((std::cin >> n).fail() || n<min || n>max  ) {
        cin.clear();
        cin.ignore(10000, '\n');
        std::cout << "Введите значение (" << min << "-" << max << "):";
    }
    return n;
}


template<typename T1,typename T2>
using Filter = bool(*)(const T1& p, T2 parametr);

template<typename T1, typename T2>
vector<int> UsingFilter(const vector<T1>& pipeline, Filter<T1,T2> f, T2 parametr) {
    int i = 0;
    vector<int>index;
    for (auto& p : pipeline) {
        if (f(p, parametr))
            index.push_back(i);
        i++;
    }
    return index;
}

template<typename T>
int GetID(vector<T>& t) {
    int i = 0;
    while (1){
        int id = GetCorrectNumber("Введите id", 0, 10000);
        for (auto& tt : t) {
            if (tt.id == id)
                return i;
            i++;
        }
        cout << "Такого id не существует" << endl;
        i = 0;
    }
}