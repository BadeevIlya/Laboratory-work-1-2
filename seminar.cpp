// seminar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Pipe.h"
#include "KS.h"
#include "utils.h"

using namespace std;

//truba createpipe () {
//    truba pipe;
//    cout << "Считывание данных трубы" << endl << endl;
//    while (1) {
//        cout << "Введите диаметр\n";
//        cin >> pipe.diametr;
//        cout << "Введите длину\n";
//        cin >> pipe.dlina;
//        if (cin.fail()) {
//            cin.clear();
//            cin.ignore(10000, '\n');
//        }
//        else if (pipe.diametr < 0 || pipe.dlina < 0) {
//            continue;
//        }
//        else break;
//    }
//    pipe.id = "";
//    pipe.remont = false;
//    return pipe;
//}

void ChangeStatusPipe(Pipe& p)
{
    p.remont = !p.remont;
}

void ChangeW_Count(KS& k)
{
    k.w_count = GetCorrectNumber("Введите новое количество рабочих цехов", 0, k.count);
}

Pipe LoadPipe(ifstream& fin) {
    Pipe p;
    fin >> p.id >> p.diametr >> p.dlina >>p.remont;
    return p;
}

KS LoadKS(ifstream& fin) {
    KS k;
    fin >> k.id >> k.name >> k.count >> k.w_count >> k.effect;
    return k;
}

void SavePipe(ofstream& fout, const Pipe&p) {
    fout << p.id << endl << p.diametr << endl << p.dlina << endl << p.remont<<endl;
}

void SaveKS(ofstream& fout, const KS&k) {
    fout << k.id << endl << k.name << endl << k.count << endl << k.w_count << endl << k.effect << endl;
}

void DeletePipe(vector<Pipe>& p) {
    vector<Pipe>::iterator itErase = p.begin();
    size_t i = 1;
    size_t index = GetCorrectNumber("Введите номер", i, p.size());
    advance(itErase, index - 1);
    p.erase(itErase);
}

void DeleteKS(vector<KS>& k) {
    vector<KS>::iterator itErase = k.begin();
    size_t i = 1;
    size_t index = GetCorrectNumber("Введите номер", i, k.size());
    advance(itErase, index - 1);
    k.erase(itErase);
}


bool CheckPipeId(const Pipe& p, int parametr) {
    return p.id == parametr;
}

bool CheckStatusRemont(const Pipe& p, bool parametr) {
    return p.remont == parametr;
}

bool CheckNameKS(const KS& k, string parametr) {
    return k.name == parametr;
}

bool CheckUnworkKS(const KS& k, int parametr) { 
    int i = 100 - ((k.w_count / 100) * k.count);
    return i == parametr;
}



void printMenu() {
    cout << "1. Создать трубу\n"
        << "2. Создать КС\n"
        << "3. Считать данные из файла\n"
        << "4. Импорт данных в файл\n"
        << "5. Отправить трубу на ремонт\n"
        << "6. Ввести новое количество рабочих цехов\n"
        << "7. Вывод данных трубы\n"
        << "8. Вывод данных КС\n"
        << "9. Удалить трубу\n"
        << "10. Удалить КС\n"
        << "11. Фильтр труб по id\n"
        << "0. Выход\n"
        << "Выбирите действие";
}

int main(){
    setlocale(LC_ALL, "rus");
    vector <Pipe> pipeline;
    vector <KS> ksgroup;
    while (1) {
        printMenu();
        switch (GetCorrectNumber("", 0,14)) {
            case 1:
            {
                Pipe p;
                cin >> p;
                pipeline.push_back(p);
                break;
            }
            case 2:
            {
                KS k;
                cin >> k;
                ksgroup.push_back(k);
                break;
            }
            case 3:
            {
                ifstream fin("D:\ results.txt");
                if (fin.is_open()) {
                    pipeline.clear();
                    ksgroup.clear();
                    int p_count, ks_count;
                    fin >> p_count >> ks_count;
                    while (p_count--)
                        pipeline.push_back(LoadPipe(fin));
                    while (ks_count--)
                        ksgroup.push_back(LoadKS(fin));
                    Pipe::MaxID = pipeline.size();
                    KS::MaxID = ksgroup.size();
                    fin.close();
                }
                break;
            }
            case 4:
            {
                ofstream fout;
                fout.open("D:\ results.txt");
                if (fout.is_open()) {
                    fout << pipeline.size() << endl <<  ksgroup.size() << endl;
                    for (Pipe t : pipeline)
                        SavePipe(fout,t);
                    for (KS kk : ksgroup)
                        SaveKS(fout,kk);
                    fout.close();
                    pipeline.clear();
                    ksgroup.clear();
                }
                break;
            }
            case 5:
            {
                if (!pipeline.empty()) {
                    ChangeStatusPipe(SelectId(pipeline));
                }
                else {
                    cout << "Значения трубы не заданы!\n";
                }
                break;
            }
            case 6:
            {
                if (!ksgroup.empty()) {
                    ChangeW_Count(SelectId(ksgroup));
                }
                else {
                    cout << "Значения КС не заданы!\n";
                }                
                break;
            }
            case 7:
            {
                if (!pipeline.empty()) {
                    for (auto& p : pipeline) 
                        cout << p; // Вывод данных труб на консоль 
                }
                else {
                    cout << "Значения трубы не заданы!\n";
                }
                break;
            }
            case 8:
            {
                if (!ksgroup.empty()) {
                    for (auto& k : ksgroup)
                        cout << k;// вывод данных КС на консоль
                }
                else {
                    cout << "Значения КС не заданы!\n";
                }
                break;
            }
            case 9:
            {
                if (!pipeline.empty()) {

                    DeletePipe(pipeline);
                }
                else {
                    cout << "Значения трубы не заданы!\n";
                }
                break;
            }
            case 10:
            {
                if (!ksgroup.empty()) {
                    DeleteKS(ksgroup);
                }
                else {
                    cout << "Значения КС не заданы!\n";
                }
                break;
            
            }
            case 11:
            {
                if (!pipeline.empty()) {
                    int i = GetCorrectNumber("Введите id трубы", 0, 1111);
                    for (int index: UsingFilter(pipeline, CheckPipeId, i))
                        cout << pipeline[index];
                }
                else {
                    cout << "Значения КС не заданы!\n";
                }
                break;
            }
            case 12:
            {
                if (!pipeline.empty()) {
                    for (int index : UsingFilter(pipeline, CheckStatusRemont, false))
                        cout << ksgroup[index];
                }
                else {
                    cout << "Значения КС не заданы!\n";
                }
                break;
            }
            case 13:
            {
                if (!ksgroup.empty()) {
                    string name;
                    cout << "Название КС:  ";
                    cin.get();
                    getline(cin, name);
                    for (int index : UsingFilter(ksgroup, CheckNameKS, name))
                        cout << ksgroup[index];
                }
                else {
                    cout << "Значения КС не заданы!\n";
                }
                break;
            }
            case 14:
            {
                if (!ksgroup.empty()) {
                    int i = GetCorrectNumber("Введите искомый процент", 0, 100);
                    for (int index : UsingFilter(ksgroup, CheckUnworkKS, i))
                        cout << pipeline[index];
                }
                else {
                    cout << "Значения КС не заданы!\n";
                }
                break;
            }
            case 0:
            {
                return 0;
            }
            default: {
                cout << "Ошибка ввода!\n";
            }
        }
    }
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
