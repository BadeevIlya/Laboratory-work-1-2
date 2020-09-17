// seminar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>

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
    cout << "Считывание данных трубы" << endl << endl;
    cout << "Введите диаметр\n";
    cin >>  pipe.diametr;
    cout << "Введите длину\n";
    cin >> pipe.dlina;
    pipe.id = "";
    pipe.remont = false;
    return pipe;
}

void increatepipe(truba in) {
    cout << "Считанные из файла данные трубы:\n";
    ifstream piperesults ("D:\piperesults.txt");
    piperesults >> in.diametr >> in.dlina;
    cout << in.diametr << endl << in.dlina << endl;
}

void outcreatepipe(truba out) {
    cout << "Введенные данные трубы:\n";
    cout << out.diametr << endl << out.dlina << endl;
}

void savecreatefile(truba save ) {
    cout << "Данные сохранены в файл\n";
    ofstream piperesults;
    piperesults.open("D:\piperesults.txt");
    piperesults << save.diametr << endl << save.dlina << endl;
    piperesults.close();
}

void outcreateKS(KS out) {
    cout << "Введенные данные КС:\n";
    cout << out.vol <<endl<< out.workvol <<endl<< out.name << endl;
}

void increateKS(KS in) {
    cout << "Считанные из файла данные КС:\n";
    ifstream piperesults("D:\piperesults.txt");
    piperesults >> in.vol >> in.workvol >>in.name;
    cout << in.vol <<endl<< in.workvol << endl<< in.name << endl;
}

void savecreateKS(KS save) {
    cout << "Данные сохранены в файл\n";
    ofstream piperesults("D:\piperesults.txt");
    piperesults << save.vol << endl << save.workvol << endl <<save.name;
    piperesults.close();
}



KS createKS() {
    KS ks;
    cout << "Считывание данных КС" << endl << endl;
    cout << "Введите количество цехов\n";
    cin >> ks.vol;
    cout << "Введите количество рабочих цехов\n";
    cin >> ks.workvol;
    cout << "Введите имя\n";
    cin >> ks.name;
    ks.id = "";
    ofstream piperesults;
    piperesults.open("D:\piperesults.txt");
    piperesults << ks.vol << endl << ks.workvol << endl << ks.name << endl;
    piperesults.close();
    return ks;
}

int main(){
    setlocale(LC_ALL, "rus");
    truba crpipe;
    crpipe = createpipe(); // запись данных трубы и передача их в переменную crpipe
    outcreatepipe(crpipe); // вывод данных трубы на консоль
    savecreatefile(crpipe); // сохранение данных трубы в файл piperesults.txt
    increatepipe(crpipe); // считывание данных из файла и вывод их на консоль 
    KS crKS;
    crKS = createKS();
    outcreateKS(crKS);
    savecreateKS(crKS);
    increateKS(crKS);
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
