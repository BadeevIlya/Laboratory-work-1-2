#pragma once
#include <iostream>
#include <string>
#include "KS.h"
#include "Pipe.h"
#include <vector>
#include <fstream>
#include <map>


template<typename T>
T GetCorrectNumber(std::string text, T min, T max) {
    T n;
    std::cout << text << ":  ";
    while ((std::cin >> n).fail() || n<min || n>max || cin.peek() != '\n' ) {
        cin.clear();
        cin.ignore(10000, '\n');
        std::cout << "¬ведите значение (" << min << "-" << max << "):";
    }
    return n;
}


template<typename T>
using FilterPipe = bool(*)(const Pipe& p, T parametr);

template<typename T>
vector<int> UsingFilterForPipe(const map<int, Pipe>& pipeline, FilterPipe<T> f, T parametr) {
    int i = 1;
    vector<int>index;
    for (auto& p : pipeline) {
        if (f(p.second, parametr))
            index.push_back(i);
        i++;
    }
    return index;
}

template<typename T>
using FilterKS = bool(*)(const KS& k, T parametr);
template<typename T>
vector<int> UsingFilterForKS(const map<int, KS>& ksgroup, FilterKS<T> f, T parametr) {
    int i = 1;
    vector<int>index;
    for (auto& k : ksgroup) {
        if (f(k.second, parametr))
            index.push_back(i);
        i++;
    }
    return index;
}


