#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <direct.h>
#include <io.h>
#include <Windows.h>
using namespace std;

int CreatDirectory()
{
    int x = _mkdir("c:\\Project_Menu");
    return x;
}

int DeleteDirectory()
{
    int x = _rmdir("c:\\Project_Menu2");
    return x;
}


void FindFiles_PrintFiles()
{
    _finddata_t file1, file2;
    cout << "����� ��'� ����� ��� ������: ";
    cin >> file2.name;
    cout << "����� ����� �����: ";
    cin >> file2.size;
    cout << "����� ������� �����: ";
    cin >> file2.attrib;
    intptr_t ptr = _findfirst("c:\\Project_Menu\\*.*", &file1);
    cout << "� �������� Project_Menu �� ������� ��������: " << endl;
    int x;
    do
    {
        if (file1.name == file2.name && file1.size == file2.size && file1.attrib == file2.attrib)
        {
            cout << file1.name << ' ' << file1.size << ' ' << file1.attrib << endl;
        }
        x = _findnext(ptr, &file1);
    } while (x == 0);
}


void Menu()
{
    int var;
    do
    {
        cout << "����: " << endl;
        cout << "1 - ��������� ��������" << endl;
        cout << "2 - ��������� ��������" << endl;
        cout << "3 � ����� ����� �� �������� ������� (�����, �����, �������)" << endl;
        cout << "0 � �����" << endl;
        cout << "����� �����: ";
        cin >> var;
        system("CLS");
        switch (var)
        {
        case 0:
            cout << "�������� ��������� ������" << endl;
            exit(0);
        case 1:

            if (!CreatDirectory())
                cout << "����� ���� ������ ��������!" << endl;
            else
                cout << "�� ������� �������� �����:(" << endl;
            break;
        case 2:
            if (!DeleteDirectory())
                cout << "����� ���� ������ ��������!" << endl;
            else
                cout << "�� ������� �������� �����:(" << endl;
            break;
        case 3:
            FindFiles_PrintFiles();
            break;
        }
        system("pause");
    } while (var != 0);
}