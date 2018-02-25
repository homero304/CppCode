//
//  lista.cpp
//  Ejercicios
//
//  Created by Homero Marin on 2/24/18.
//  Copyright © 2018 Homero Marin. All rights reserved.
//

#include <iostream>

class Node {
public:
    std::string s;
    Node* next;
    Node() {
        s="";
        next = NULL;
    }
    Node(std::string ps) {
        s = ps;
        next = NULL;
    }
};

class List {
public:
    List() {
        head = NULL;
        length = 0;
    }
    List(Node* n) {
        head = n;
        length = 1;
    }
    bool isEmpty() {
        return head == NULL;
    }
    void add(std::string s) {
        if (isEmpty()) {
            head = new Node(s);
            head->next = NULL;
        }
        else {
            Node *curr = head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = new Node(s);
        }
        length++;
    }
    std::string get(int index) {
        if (index >= length || index < 0) return "";
        int i = 0;
        Node *curr = head;
        while (curr != NULL && i < index) {
            curr = curr->next;
            i++;
        }
        return curr->s;
    }
    void remove(int index) {
        if (index >= length || index < 0) return;
        Node *temp;
        if (index == 0) {
            temp = head;
            head = head->next;
            delete temp;
        }
        else {
            Node *prev = head;
            Node *curr = head->next;
            int i = 1;
            while (curr->next != NULL && i < index) {
                curr = curr->next;
                prev = prev->next;
                i++;
            }
            temp = curr;
            prev->next = curr->next;
            delete temp;
        }
        
    }
    
    int find(std::string s){
        int f = -1, i = 0;
        Node *curr = head;
        while (curr != NULL && f == -1) {
            if (s == curr->s)
                f = i;
            curr = curr->next;
            i++;
        }
        return f;
    }
    void print() {
        Node *curr = head;
        while (curr != NULL) {
            std::cout << curr->s << " ";
            curr = curr->next;
        }
    }
    int getLength() {
        return length;
    }
private:
    Node* head;
    int length;
};

