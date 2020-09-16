// seminar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

struct truba {
    string id;
    int dlina;
    int diametr;
    bool remont;
};

struct KS {
    string id;
    string name;
    int vol;
    int workvol;
    int effect;
};

truba createpipe () {
    truba pipe;
    cout << "¬ведите диаметр\n";
    cin >>  pipe.diametr;
    cout << "¬ведите длину\n";
    cin >> pipe.dlina;
    pipe.id = "";
    pipe.remont = false;
    return pipe;
}

KS createKS(){
    KS ks;
    cout << "¬ведите количество цехов\n ";
    cin >> ks.vol;
    cout << "¬ведите количество рабочих цехов\n";
    cin >> ks.workvol;
    cout << "¬ведите им€\n";
    cin >> ks.name;
    ks.id = "";

    return ks;

}

int main(){
    setlocale(LC_ALL, "rus");
    createpipe();
    createKS();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
