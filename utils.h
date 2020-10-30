#pragma once
#include <iostream>
#include <string>
#include "KS.h"
#include "Pipe.h"
#include <vector>


template<typename T>
T GetCorrectNumber(std::string text, T min, T max) {
    T n;
    std::cout << text << ":  ";
    while ((std::cin >> n).fail() || n<min || n>max) {
        cin.clear();
        cin.ignore(10000, '\n');
        std::cout << "¬ведите значение (" << min << "-" << max << "):";
    }
    return n;
}

template<typename T>
T& SelectId(vector<T>& id) {
    size_t i = 1;
    size_t index = GetCorrectNumber("¬ведите номер", i, id.size());
    return id[index - 1];
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