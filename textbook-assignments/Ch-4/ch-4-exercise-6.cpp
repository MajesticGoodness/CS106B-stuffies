#include <iostream>

using namespace std;

string getExt(string &fileName);
string getRoot(string &fileName);
string defaultExt(string &fileName, string &ext);
bool hasExt(string &fileName);

int main() {
    string fileName;
    string ext;
    fileName = "ILikeDoggies";
    ext = ".dude";
    defaultExt(fileName, ext);
    return 0;
}

string getExt(string &fileName) {
    string ext;
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
    int fileNameLength = 0;
    int extLength = 0;
    int rootLength = 0;

    fileNameLength = fileName.length();
    extLength = getExt(fileName).length();
    rootLength = fileNameLength - extLength;

    root = fileName.substr(0, rootLength);
    return root;
}

string defaultExt(string &fileName, string &ext) {
    string result;
    result = fileName;

    if(ext[0] == '*' && hasExt(fileName)) {
        ext = getExt(ext);
        result = getRoot(fileName) + ext;
        return result;
    }
    if(hasExt(fileName)) {
        return result;
    }
    result = fileName + ext;
    return result;
}

bool hasExt(string &fileName) {
    if(getExt(fileName) != "") {
        return true;
    }
    return false;
}

/* If an ext has *, then I treat it as an override sort of behavior.
 * That is, defaultExt is designed to not change the extension of
 * a file if it already has one. However, the client can override
 * that behavior by including an * before the second argument.
 * defaultExt(coolguy.hate, .love) would not change the extension.
 * defaultExt(coolguy.hate, *.love) will however.
 *
 */
