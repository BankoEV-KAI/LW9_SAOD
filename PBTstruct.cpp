#include "PBTstruct.h"

#include <iostream>
#include <cstdlib>

Node* ExamplePBT;

Node* AddNodes(Node* pCurrent, int count) { 
    Node* pTemp;
    int countLeft, countRight;
    if (count == 0)  
        return nullptr; 
    else {
        countLeft = count / 2; 
        countRight = count - countLeft - 1; 
        pTemp = new Node; 
        pTemp->data = rand() % 100; 
        pTemp->left = AddNodes(pTemp->left, countLeft); 
        pTemp->right = AddNodes(pTemp->right, countRight);
        pCurrent = pTemp;
        
        return pTemp; 
    }
}

void printForward(Node* pCurrent, int levelPBT) { 
    if (pCurrent != NULL) {
        std::string str; 
        for (int i = 0; i < levelPBT; i++)
            str += "     ";
        std::cout << " " << str << pCurrent->data << "\n";

        printForward(pCurrent->left, levelPBT + 1); 
        printForward(pCurrent->right, levelPBT + 1); 
    }
}

void printSymmetrical(Node* pCurrent, int levelPBT) { 
    if (pCurrent != NULL) {
        printSymmetrical(pCurrent->left, levelPBT + 1); 

        std::string str; 
        for (int i = 0; i < levelPBT; i++)
            str += "     ";
        std::cout << " " << str << pCurrent->data << "\n";

        printSymmetrical(pCurrent->right, levelPBT + 1); 
    }
}

void printInverselySymmetrical(Node* pCurrent, int levelPBT) {
    if (pCurrent != NULL) {
        printInverselySymmetrical(pCurrent->right, levelPBT + 1); 

        std::string str; 
        for (int i = 0; i < levelPBT; i++)
            str += "     ";
        std::cout << " " << str << pCurrent->data << "\n";

        printInverselySymmetrical(pCurrent->left, levelPBT + 1); 
    }
}

void deletePBT(Node* pCurrent) {
    if (pCurrent != NULL) {
        deletePBT(pCurrent->left); 
        deletePBT(pCurrent->right); 
        delete pCurrent; 
    }
}

Stack* stack;

void initStack(Node* PBT) {
    stack = new Stack;
    stack->passedVertex = PBT;
    stack->levelPBT = -1;
    stack->next = nullptr;
}

bool isEmpty() {
    return stack->levelPBT < 0;
}

void printNonRecursiveSymmetrical() {
    initStack(ExamplePBT);
    Node* pCurrentTree = ExamplePBT; 
    bool Stop = false;
    int levelPBT = 0;

    while (!Stop) {
        while (pCurrentTree != NULL) {

            Stack* item = new Stack; 
            item->levelPBT = levelPBT;
            item->passedVertex = pCurrentTree;
            item->next = stack;
            stack = item;
            pCurrentTree = stack->passedVertex;
            pCurrentTree = pCurrentTree->left;
            levelPBT++;
        }
        if (isEmpty()) 
            Stop = true; 
        else { 
            levelPBT = stack->levelPBT;
            pCurrentTree = stack->passedVertex;
            std::string str = "";
            for (int i = 0; i < levelPBT; i++)
                str += "     ";
            std::cout << " " << str << (pCurrentTree->data) << "\n";
            Stack* current = stack;
            stack = stack->next;
            delete current;
            
            pCurrentTree = pCurrentTree->right;
            levelPBT++;
        }
    }
}