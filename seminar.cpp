// seminar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct truba {
    string id; // ������������� �����
    int dlina; // ����� 
    int diametr; // �������
    bool remont; // ������� "� �������"
};

struct KS {
    string id; // ������������� ��
    string name; // ���
    int vol; // ���������� �����
    int workvol; // ���������� ������� �����
    int effect; // ������������ 
};

truba createpipe () {
    truba pipe;
    bool k;
    cout << "���������� ������ �����" << endl << endl;
    do {
        cout << "������� �������\n";
        cin >> pipe.diametr;
        cout << "������� �����\n";
        cin >> pipe.dlina;
        k = true;
        if (pipe.diametr < 0 || pipe.dlina < 0) {
            k = false;
            cin.clear();
            cin.ignore(100, '\n');
        }

    } while (cin.fail() || k==false);
    pipe.id = "";
    pipe.remont = false;
    return pipe;
}

void editpipe(truba&edit) { 
    edit.remont = !edit.remont;
}



void increatepipe(truba in) {
    cout << "��������� �� ����� ������ �����:\n";
    ifstream piperesults ("D:\piperesults.txt");
    if (piperesults.is_open())
    {
        piperesults >> in.diametr >> in.dlina;
        cout << in.diametr << endl << in.dlina << endl;
        piperesults.close();
    }
}

void outcreatepipe(truba out) {
    cout << "��������� ������ �����:\n";
    cout << "�������: "<< out.diametr << endl <<"�����: "<< out.dlina << endl << out.remont<< endl;
}

void savecreatefile(truba save ) {
    cout << "������ ��������� � ����\n";
    ofstream outpiperesults("D:\piperesults.txt");
    if (outpiperesults.is_open()) {
        outpiperesults << save.diametr << endl << save.dlina << endl;
        outpiperesults.close();
    }
}

bool CorrectTypeKS(int a, int b) { // ������� �������� �� ������������ �����
    return a and b >= 0;
}

KS createKS() {
    KS ks;
    cout << "���������� ������ ��\n\n" ;
    cout << "������� ��������\n";
    cin >> ks.name;
    do
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "������� ���������� �����\n";
        cin >> ks.vol;
        cout << "������� ���������� ������� �����\n";
        cin >> ks.workvol;
    } while (cin.fail() || !CorrectTypeKS(ks.vol,ks.workvol));
    ks.id = "";
    ks.effect = 1;
    ofstream piperesults;
    piperesults.open("D:\piperesults.txt");
    piperesults << ks.vol << endl << ks.workvol << endl << ks.name << endl;
    piperesults.close();
    return ks;
}

void outcreateKS(KS out) {
    cout << "��������� ������ ��:\n";
    cout << "���������� �����: "<<out.vol <<endl<<"���������� ������� �����: "<< out.workvol <<endl<<"��������: "<< out.name << endl ;
}

void increateKS(KS in) {
    cout << "��������� �� ����� ������ ��:\n";
    ifstream KSresults("D:\piperesults.txt");
    if (KSresults.is_open()) {
        KSresults >> in.vol >> in.workvol >> in.name;
        cout << in.vol << endl << in.workvol << endl << in.name << endl;
    }
}


void savecreateKS(KS save) {
    cout << "������ ��������� � ����\n";
    ofstream KSresults("D:\piperesults.txt");
    if (KSresults.is_open()) {
        KSresults << save.vol << endl << save.workvol << endl << save.name;
        KSresults.close();
    }
}

void editworkvol(KS& k) {
    cout << "������� ����� ���������� ������� �����: \n";
    cin >> k.workvol;
}

int main(){
    setlocale(LC_ALL, "rus");
    truba crpipe;
    crpipe = createpipe(); // ������ ������ ����� � �������� �� � ���������� crpipe
    editpipe(crpipe); // �������������� �������� "� �������"
    outcreatepipe(crpipe); // ����� ������ ����� �� �������
    savecreatefile(crpipe); // ���������� ������ ����� � ���� piperesults.txt
    increatepipe(crpipe); // ���������� ������ �� ����� � ����� �� �� ������� 
    /*KS crKS;
    crKS = createKS();
    editworkvol(crKS);
    outcreateKS(crKS);
    savecreateKS(crKS);
    increateKS(crKS);*/
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
