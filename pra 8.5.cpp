#include <iostream>
#include <string>

using namespace std;

struct FileNode {
    string fileName;
    FileNode* next;
};

struct FolderNode {
    string folderName;
    FileNode* files;
    FolderNode* next;
};

class DirectoryManager {
private:
    FolderNode* folderHead;

    FolderNode* findFolder(const string& name) {
        FolderNode* curr = folderHead;
        while (curr) {
            if (curr->folderName == name) return curr;
            curr = curr->next;
        }
        return nullptr;
    }

    void insertFolder(FolderNode* newFolder) {
        if (!folderHead || newFolder->folderName < folderHead->folderName) {
            newFolder->next = folderHead;
            folderHead = newFolder;
            return;
        }
        FolderNode* curr = folderHead;
        while (curr->next && curr->next->folderName < newFolder->folderName) {
            curr = curr->next;
        }
        newFolder->next = curr->next;
        curr->next = newFolder;
    }

    void insertFile(FileNode*& head, const string& fileName) {
        FileNode* newFile = new FileNode{fileName, nullptr};
        if (!head || fileName < head->fileName) {
            newFile->next = head;
            head = newFile;
            return;
        }
        FileNode* curr = head;
        while (curr->next && curr->next->fileName < fileName) {
            curr = curr->next;
        }
        newFile->next = curr->next;
        curr->next = newFile;
    }

public:
    DirectoryManager() : folderHead(nullptr) {}

    void addFolder(const string& name) {
        if (!findFolder(name)) {
            FolderNode* newFolder = new FolderNode{name, nullptr, nullptr};
            insertFolder(newFolder);
        }
    }

    void addFile(const string& folderName, const string& fileName) {
        FolderNode* folder = findFolder(folderName);
        if (!folder) {
            addFolder(folderName);
            folder = findFolder(folderName);
        }
        insertFile(folder->files, fileName);
    }

    void displayDirectory() const {
        for (FolderNode* f = folderHead; f; f = f->next) {
            cout << "Folder: " << f->folderName << endl;
            for (FileNode* file = f->files; file; file = file->next) {
                cout << "  - " << file->fileName << endl;
            }
        }
    }

    ~DirectoryManager() {
        while (folderHead) {
            FolderNode* tempF = folderHead;
            folderHead = folderHead->next;
            while (tempF->files) {
                FileNode* tempFile = tempF->files;
                tempF->files = tempFile->next;
                delete tempFile;
            }
            delete tempF;
        }
    }
};

int main() {
    DirectoryManager dm;
    int choice;

    do {
        cout << "\n1. Add Folder\n2. Add File\n3. Display Directory\n4. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // To clear input buffer

        if (choice == 1) {
            cout << "Enter Folder name: ";
            string folderName;
            getline(cin, folderName);
            dm.addFolder(folderName);
        } 
        else if (choice == 2) {
            cout << "Enter Folder name: ";
            string folderName;
            getline(cin, folderName);
            cout << "Enter File name: ";
            string fileName;
            getline(cin, fileName);
            dm.addFile(folderName, fileName);
        } 
        else if (choice == 3) {
            dm.displayDirectory();
        } 
        else if (choice != 4) {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    cout << "Exiting.\n";
    return 0;
}