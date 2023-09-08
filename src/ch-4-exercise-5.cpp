#include <iostream>

using namespace std;

string getExt(string &fileName);
string getRoot(string &fileName);

int main() {
    string fileName;
    fileName = "ILikeDoggies.text";
    getExt(fileName);
    getRoot(fileName);
    return 0;
}

string getExt(string &fileName) {
    string ext;
    ext = "File extension not found :(";
    for(int i = fileName.length() - 1; i >= 0; i--) {
        if(fileName[i] == '.') {
            ext = fileName.substr(i);
            return ext;
        }
    }
    return ext;
}

string getRoot(string &fileName) {
    string root;
    root = "File name was not found :(";
    for(int i = fileName.length() - 1; i >= 0; i--) {
        if(fileName[i] == '.') {
            root = fileName.substr(0, i);
            return root;
        }
    }
    return root;
}


/*
 * we want two functions: getRoot and getExt
 * getRoot should return the filename w/o the
 * extension.
 *
 * getExt should just return the extension.
 *
 * I think getExt is the easier of the two.
 * Just start at the end of the filename, and
 * count backwards until we reach a '.'
 *
 * Of course there a bunch of edge cases that can
 * and will screw this way of detecting an extension.
 * But...it's enough to get us off the ground for now.
 *
 *
 */
