#ifndef STRUCT_TYPE_PROJECT_3_H
#define STRUCT_TYPE_PROJECT_3_H

struct PostData {
    char index[10];
    char region[50];
    char district[50];
    char settlement[50];
    char branch[100];
};

struct PostNode {
    PostData data;
    PostNode* next;
};

#endif
