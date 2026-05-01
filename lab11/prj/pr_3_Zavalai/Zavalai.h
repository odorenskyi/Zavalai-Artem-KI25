#ifndef ZAVALAI_H
#define ZAVALAI_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include "struct_type_project_3.h"
#include <windows.h>

using namespace std;

//новий запис
void addRecord(PostNode*& head)
 {
    setlocale(LC_ALL, "Ukrainian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    PostNode* newNode = new PostNode;
    newNode->next = nullptr;

    cout << "\n--- Додавання нового запису ---\n";
    cin.ignore();
    cout << "Введiть iндекс: ";
    cin.getline(newNode->data.index, 10);
    cout << "Введiть область: ";
    cin.getline(newNode->data.region, 50);
    cout << "Введiть район (або '-'): ";
    cin.getline(newNode->data.district, 50);
    cout << "Введiть населений пункт: ";
    cin.getline(newNode->data.settlement, 50);
    cout << "Введiть ВПЗ: ";
    cin.getline(newNode->data.branch, 100);

    if (head == nullptr) {
        head = newNode;
    } else {
        PostNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    cout << "Запис успiшно додано!\n";
}

//вивести список
void printList(PostNode* head)
{
    setlocale(LC_ALL, "ukr");
    if (head == nullptr) {
        cout << "\nДовiдник порожнiй.\n";
        return;
    }
    cout << "\n----------------------------------------------------------------------------------------\n";
    cout << left << setw(8) << "Iндекс" << " | "
         << setw(15) << "Область" << " | "
         << setw(15) << "Район" << " | "
         << setw(15) << "Населений пункт" << " | "
         << "ВПЗ" << endl;
    cout << "----------------------------------------------------------------------------------------\n";

    PostNode* current = head;
    while (current != nullptr) {
        cout << left << setw(8) << current->data.index << " | "
             << setw(15) << current->data.region << " | "
             << setw(15) << current->data.district << " | "
             << setw(15) << current->data.settlement << " | "
             << current->data.branch << endl;
        current = current->next;
    }
}

//запис у файл
void saveToBinary(PostNode* head, const char* filename) {
    ofstream outFile(filename, ios::binary | ios::trunc);
    if (!outFile) return;

    PostNode* current = head;
    while (current != nullptr) {
        outFile.write(reinterpret_cast<const char*>(&current->data), sizeof(PostData));
        current = current->next;
    }
    outFile.close();
}

//експорт у txt
void exportToText(PostNode* head) {
    char filename[50];
    cout << "\nВведiть назву файлу (напр. export.txt): ";
    cin >> filename;
    ofstream txtFile(filename);
    if (!txtFile) return;

    PostNode* current = head;
    while (current != nullptr) {
        txtFile << current->data.index << " | " << current->data.settlement << "\n";
        current = current->next;
    }
    txtFile.close();
    cout << "Експортовано!\n";
}

#endif
