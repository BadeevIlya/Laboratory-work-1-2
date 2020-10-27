// seminar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Pipe.h"
#include "KS.h"





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

void editpipe(Pipe & edit) { // функция, которая отправляет на ремонт трубу
    edit.ChangeStatusPipe(); 
}


void edit_w_count(KS& k) {
    k.ChangeW_Count();
}

int GetCorrectNumber(int min, int max) {
    int n;
    while ((cin>>n).fail()|| n<min || n>max) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Введите значение (" << min << "-" << max << "):";        
    }
    return n;
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
        << "0. Выход\n"
        << "Выбирите действие: ";

}

Pipe loadpipe(ifstream& fin) {
    Pipe t;
    t.LoadPipe(fin);
    return t;
}

KS loadKS(ifstream& fin) {
    KS k;
    k.LoadKS(fin);
    return k;
}
Pipe& SelectPipe(vector<Pipe>& p) {
    cout << "Введите номер: " << endl;
    unsigned int index = GetCorrectNumber(1, p.size());
    return p[index - 1];
}

KS& SelectKS(vector<KS>& k) {
    cout << "Введите номер: " << endl;
    unsigned int index = GetCorrectNumber(1, k.size());
    return k[index - 1];
}

int main(){
    setlocale(LC_ALL, "rus");
    vector <Pipe> pipeline;
    vector <KS> ksgroup;
    int marker_p = 0;
    int marker_k = 0;
    while (1) {
        printMenu();
        switch (GetCorrectNumber(0,8)) {
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
                    Pipe p;
                    int p_count, ks_count;
                    fin >> p_count >> ks_count;
                    marker_p = p_count;
                    marker_k = ks_count;
                    while (p_count--)
                        pipeline.push_back(loadpipe(fin));
                    while (ks_count--)
                        ksgroup.push_back(loadKS(fin));
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
                        t.SavePipe(fout, t);
                    for (KS kk : ksgroup)
                        kk.SaveKS(fout, kk);
                    fout.close();
                }
                break;
            }
            case 5:
            {
                if (marker_p>0) {
                    editpipe(SelectPipe(pipeline)); // редактирование признака "в ремонте"
                }
                else {
                    cout << "Значения трубы не заданы!\n";
                }
                
                break;
            }
            case 6:
            {
                if (marker_k > 0) {
                    edit_w_count(SelectKS(ksgroup));
                }
                else {
                    cout << "Значения КС не заданы!\n";
                }                
                break;
            }
            case 7:
            {
                if (marker_p > 0) {

                    cout << SelectPipe(pipeline); // вывод данных трубы на консоль
                }
                else {
                    cout << "Значения трубы не заданы!\n";
                }
                break;
            }
            case 8:
            {
                if (marker_k > 0) {

                    cout << SelectKS(ksgroup); // вывод данных КС на консоль
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
