#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "BST.h"

using namespace std;

#ifdef _MSC_VER // emory leak check
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif


int main(int argc, char* argv[]) {
    VS_MEM_CHECK  //enable memory leak check

    // reading inputs / outputs
    if (argc < 3) {
        cerr << "Please provide name of input and output files";
        return 1;
    }
    ifstream in(argv[1]);  //input file
    if (!in) {
        cerr << "Unable to open " << argv[1] << " for input";
        return 2;
    } else {
        cout << argv[1] << " opened successfully.\n";
    }
    ofstream out(argv[2]);  //output file
    if (!out) {
        in.close();
        cerr << "Unable to open " << argv[2] << " for output";
        return 3;
    } else {
        cout << argv[2] << " opened successfully.\n";
    }

    string line;
    BST<int> bstInt;
    BST<int> bstIntCopy;
    BST<string> bstString;
    BST<string> bstStringCopy;
    enum TreeType { none, treeInt, treeString};
    int tree = none;

    while(getline(in, line)){
        string command, val;

        if(line.size() == 0){
            continue;  //continue if line is empty
        }
        out << line << " ";  //outs the input line
        istringstream iss(line);
        iss >> command >> val;  //breaks line into command and val

        try{
            if(command == "INT"){
                tree = treeInt;
                out << "OK";
            }
            else if(command == "STRING"){
                tree = treeString;
                out << "OK";
            }
            //int tree commands:
            else if(tree == treeInt){
                if(command == "add"){
                    if(bstInt.addNode(stoi(val))){
                        out << "OK";
                    }
                    else{
                        out << "Error";
                    }
                }
                else if(command == "remove"){
                    if(bstInt.removeNode(stoi(val))){
                        out << "OK";
                    }
                    else{
                        out << "Error";
                    }
                }
                else if(command == "clear"){
                    if(bstInt.clearTree()){
                        out << "OK";
                    }
                    else{
                        out << "Error";
                    }
                }
                else if(command == "size"){
                    out << bstInt.treeSize();
                }
                else if(command == "print"){
                    out << bstInt;
                }
                else if(command == "find"){
                    if(bstInt.findVal(stoi(val))){
                        out << "found";
                    }
                    else{
                        out << "not found";
                    }
                }
                else if(command == "copy"){
                    if(bstInt.treeSize() != 0){
                        bstIntCopy = bstInt; // Uses Deep Assignment Operator
                        out << "OK";
                    }
                    else{
                        out << "Error";
                    }
                }
                else if (command == "printcopy"){
                    out << bstIntCopy;
                }
                else{
                    throw string("Error");
                }
            }
            //string tree commands:
            else if(tree == treeString){
                if(command == "add"){
                    if(bstString.addNode(val)){
                        out << "OK";
                    }
                    else{
                        out << "Error";
                    }
                }
                else if(command == "remove"){
                    if(bstString.removeNode(val)){
                        out << "OK";
                    }
                    else{
                        out << "Error";
                    }
                }
                else if(command == "clear"){
                    if(bstString.clearTree()){
                        out << "OK";
                    }
                    else{
                        out << "Error";
                    }
                }
                else if(command == "size"){
                    out << bstString.treeSize();
                }
                else if(command == "print"){
                    out << bstString;
                }
                else if(command == "find"){
                    if(bstString.findVal(val)){
                        out << "found";
                    }
                    else{
                        out << "not found";
                    }
                }
                else if(command == "copy"){
                    if(bstString.treeSize() != 0){
                        bstStringCopy = bstString; // uses the deep assignment operator
                        out << "OK";
                    }
                    else{
                        out << "Error";
                    }
                }
                else if(command == "printcopy"){
                    out << bstStringCopy;
                }
                else{
                    throw string("Error");
                }
            }
            else{
                throw string("Error");
            }
        }
        catch(string& error){
            out << error;
        }
        out << endl;
    }

    return 0;
}
