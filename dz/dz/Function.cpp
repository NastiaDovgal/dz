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
    cout << "Ведіть ім'я файлу для пошуку: ";
    cin >> file2.name;
    cout << "Ведіть розмір файлу: ";
    cin >> file2.size;
    cout << "Ведіть атрибут файлу: ";
    cin >> file2.attrib;
    intptr_t ptr = _findfirst("c:\\Project_Menu\\*.*", &file1);
    cout << "У директорії Project_Menu за запитом знайдено: " << endl;
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
        cout << "Меню: " << endl;
        cout << "1 - Створення каталога" << endl;
        cout << "2 - Видалення каталога" << endl;
        cout << "3 – Пошук файлів по заданому критерію (назва, розмір, атрибут)" << endl;
        cout << "0 – Вихід" << endl;
        cout << "Ведіть пункт: ";
        cin >> var;
        system("CLS");
        switch (var)
        {
        case 0:
            cout << "Програма завершила роботу" << endl;
            exit(0);
        case 1:

            if (!CreatDirectory())
                cout << "Папку було успішно створено!" << endl;
            else
                cout << "Не вдалося створити папку:(" << endl;
            break;
        case 2:
            if (!DeleteDirectory())
                cout << "Папку було успішно видалено!" << endl;
            else
                cout << "Не вдалося видалити папку:(" << endl;
            break;
        case 3:
            FindFiles_PrintFiles();
            break;
        }
        system("pause");
    } while (var != 0);
}