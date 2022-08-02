#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Node{
    int value;
    Node* next;
    Node(int x): value(x),next(nullptr){}
};

int main(){
    Node *root= new Node(5);

    return 0;
}