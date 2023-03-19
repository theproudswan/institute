#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void printAuthor() {

    cout << " ______        ___    _   _     ____   _    ____ _  _______ ____  \n";
    cout << "/ ___\\ \\      / / \\  | \\ | |   |  _ \\ / \\  / ___| |/ / ____|  _ \\ \n";
    cout << "\\___ \\\\ \\ /\\ / / _ \\ |  \\| |   | |_) / _ \\| |   | ' /|  _| | |_) |\n";
    cout << " ___) |\\ V  V / ___ \\| |\\  |   |  __/ ___ \\ |___| . \\| |___|  _ < \n";
    cout << "|____/  \\_/\\_/ \\___/ \\_| \\_|   |_| /_/   \\_\\____|_|\\_\\_____|_| \\_\\\n";

    cout << "Created by Ivan Lebedev.\n";

}

void packFiles(vector<string> fileNames, string packName) {
    // Open the output file
    ofstream packFile(packName, ios::binary);

    if (!packFile.is_open()) {
        cerr << "Error: Could not open " << packName << " for writing" << endl;
        exit(1);
    }

    // Write the number of files to the output file
    int numFiles = fileNames.size();
    packFile.write((char*)&numFiles, sizeof(int));

    // Pack each file into the output file
    for (string fileName : fileNames) {
        // Open the input file
        ifstream inputFile(fileName, ios::binary);

        if (!inputFile.is_open()) {
            cerr << "Error: Could not open " << fileName << " for reading" << endl;
            exit(2);
        }

        // Get the size of the input file
        inputFile.seekg(0, ios::end);
        int fileSize = inputFile.tellg();
        inputFile.seekg(0, ios::beg);

        // Write the size of the file to the output file
        packFile.write((char*)&fileSize, sizeof(int));

        // Write the file name to the output file
        int nameLen = fileName.length();
        packFile.write((char*)&nameLen, sizeof(int));
        packFile.write(fileName.c_str(), nameLen);

        // Write the contents of the file to the output file
        char buffer[1024];
        while (fileSize > 0) {
            int readSize = min(fileSize, 1024);
            inputFile.read(buffer, readSize);
            packFile.write(buffer, readSize);
            fileSize -= readSize;
        }

        // Close the input file
        inputFile.close();
    }

    // Close the output file
    packFile.close();
}

void unpackFiles(string packName) {
    // Open the input file
    ifstream packFile(packName, ios::binary);

    if (!packFile.is_open()) {
        cerr << "Error: Could not open " << packName << " for reading" << endl;
        exit(1);
    }

    // Read the number of files from the input file
    int numFiles;
    packFile.read((char*)&numFiles, sizeof(int));

    // Unpack each file from the input file
    for (int i = 0; i < numFiles; i++) {
        // Get the size of the file
        int fileSize;
        packFile.read((char*)&fileSize, sizeof(int));

        // Get the length of the file name
        int nameLen;
        packFile.read((char*)&nameLen, sizeof(int));

        // Read the file name
        char nameBuffer[256];
        packFile.read(nameBuffer, nameLen);
        string fileName(nameBuffer, nameLen);

        // Create the output file
        ofstream outputFile(fileName, ios::binary);

        if (!outputFile .is_open()) {
            cerr << "Error: Could not open " << fileName << " for writing" << endl;
            exit(2);
        }

        // Read the contents of the file
        char buffer[1024];
        while (fileSize > 0) {
            int readSize = min(fileSize, 1024);
            packFile.read(buffer, readSize);
            outputFile.write(buffer, readSize);
            fileSize -= readSize;
        }

        // Close the output file
        outputFile.close();
    }

    // Close the input file
    packFile.close();
}

int main(int argc, char* argv[]) {

    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " [-c|-s] <output_file> <input_file1> [<input_file2> ...]" << std::endl;
        return 1;
    }

    printAuthor();

    string packedFileName = argv[2];

    if (string(argv[1]) == "-c") {  // Concatenate files

        // Pack some files into a single file
        vector<string> fileNames;

        for (int i = 3; i < argc; ++i) {
            fileNames.push_back(argv[i]);
        }

        packFiles(fileNames, packedFileName);

        cout << "Files ";
        for (auto file : fileNames) {
            cout << file << " ";
        }
        cout << "were packed into " << packedFileName << endl;

    } else if (string(argv[1]) == "-s") {  // Split files
        // Unpack the files from the single file
        unpackFiles(packedFileName);
        cout << "File " << packedFileName << " was unpacked" << endl;
    } else {
        cerr << "Error: undefined command " << argv[1] << endl
             << "Use only -s or -c" << endl; 
    }

    return 0;
}
