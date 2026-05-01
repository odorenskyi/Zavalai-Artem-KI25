#ifndef VIRCHENKO_H
#define VIRCHENKO_H

#include <iostream>
#include <fstream>
#include <cstring>
#include "struct_type_project_3.h"

using namespace std;

//Пошук
void searchRecord(PostNode* head) {
    if (head == nullptr) {
        cout << "\nДовiдник порожнiй.\n";
        return;
    }
    char query[50];
    cout << "\nВведiть iндекс або назву для пошуку: ";
    cin >> query;

    bool found = false;
    PostNode* current = head;
    while (current != nullptr) {
        if (strstr(current->data.index, query) != nullptr ||
            strstr(current->data.settlement, query) != nullptr) {
            cout << "Знайдено: " << current->data.index << " - "
                 << current->data.settlement << " (" << current->data.branch << ")\n";
            found = true;
        }
        current = current->next;
    }
    if (!found) cout << "Збiгiв не знайдено.\n";
}

//Видалення
void deleteRecord(PostNode*& head) {
    if (head == nullptr) return;
    char query[10];
    cout << "\nВведiть iндекс для видалення: ";
    cin >> query;

    PostNode* current = head;
    PostNode* prev = nullptr;

    while (current != nullptr) {
        if (strcmp(current->data.index, query) == 0) {
            if (prev == nullptr) {
                head = current->next;
                delete current;
                current = head;
            } else {
                prev->next = current->next;
                delete current;
                current = prev->next;
            }
            cout << "Запис видалено.\n";
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "Запис не знайдено.\n";
}

//Завантаження з файлу
void loadFromBinary(PostNode*& head, const char* filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) return;

    PostData tempData;
    PostNode* tail = nullptr;

    while (inFile.read(reinterpret_cast<char*>(&tempData), sizeof(PostData))) {
        PostNode* newNode = new PostNode;
        newNode->data = tempData;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    inFile.close();
}

//Очищення пам'яті
void freeMemory(PostNode*& head) {
    PostNode* current = head;
    while (current != nullptr) {
        PostNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}

#endif
