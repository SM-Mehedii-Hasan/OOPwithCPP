File handling in C++ is one of the most essential concepts for developing practical,
 real-world applications because it allows programs to store, retrieve,
  and manipulate data permanently — something not possible with simple variables or arrays that vanish when the program ends.
  
🔹 1. What is File Handling?
When your C++ program runs, it uses RAM (temporary memory). 
Any data you create—like user input, arrays, or objects—is erased once the program stops.
File handling allows your program to store data permanently in a file on disk (HDD/SSD). 
These files might be in text format (.txt) or binary format (.bin), and you can read, write, update, or delete data from them.

C++ provides a rich library for this through the <fstream> header, which defines three key classes:
ofstream – Output file stream (for writing)
ifstream – Input file stream (for reading)
fstream – General-purpose stream (for both reading and writing)



🔹 2. Opening Files
Before you can work with a file, you must open it. 
Opening a file means creating a connection between the program and the physical file on disk.
Syntax:
fstream file("filename.txt", mode);
filename.txt – The name of the file you want to open or create.
mode – Tells C++ how to open the file (read, write, append, etc.).
Example:
fstream file("data.txt", ios::out);
This opens (or creates) a file named data.txt for writing.

🔹 3. File Opening Modes and Their Meanings
| Mode          | Description                                                                   |
| ------------- | ----------------------------------------------------------------------------- |
| `ios::in`     | Open file for reading. Fails if the file doesn’t exist.                       |
| `ios::out`    | Open file for writing. Creates new file if none exists, erases existing data. |
| `ios::app`    | Append mode. All output is added to the end of the file.                      |
| `ios::ate`    | Move write position to the end, but allows seeking to earlier positions.      |
| `ios::binary` | Opens file in binary mode instead of text mode.                               |
| `ios::trunc`  | Truncate file (erase existing content) when opened.                           |


You can combine multiple modes using the bitwise OR operator (|), e.g.:
fstream file("data.txt", ios::in | ios::out);

🔹 4. Writing Data to a File
When you open a file in write mode (ios::out), you can use the insertion operator (<<), just like cout.
Example:
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ofstream file("GFG.txt"); // Open for writing
    file << "Welcome to GeeksforGeeks.";
    file << "Welcome to GeeksforGeeks.\n";
    for(int i=0;i<5;i++) file << "Welcome to GeeksforGeeks.\n";
    file.close();
    cout << "Data written successfully.";
    return 0;
}
👉 This creates a file named GFG.txt and writes the text into it.
Always close your file using file.close() — it ensures all buffered data is properly written to disk.

🔹 5. Reading Data from a File
To read, open the file using ifstream or fstream in read mode (ios::in).
Basic Example:
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream file("GFG.txt");
    string word;
    file >> word; // reads only until first space
    cout << "Read String: " << word;
    file.close();
    return 0;
}
Because >> stops reading at the first whitespace,
 we can use getline() to read entire lines
Example using getline():
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream file("GFG.txt");
    string line;
    getline(file, line);
    cout << "Read String: " << line;
    file.close();
    return 0;
}





Read line by line in a loop (most common way)
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream file("GFG.txt");
    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl;   // Print each line
    }

    file.close();
    return 0;
}


// 🟢 Explanation:
// while (getline(file, line)) keeps reading until the end of file (EOF).
// This way, all lines are read and printed one by one.


🔹 6. Checking for Errors
✅ File Not Opening:

Sometimes the file might not open due to permissions or missing files. Always check:

fstream file("nonexistent.txt", ios::in);
if (!file.is_open()) {
    cerr << "Error: Unable to open file!" << endl;
}

✅ Reading Errors:

If getline() or >> fails:

if (!getline(file, line))
    cerr << "Error reading data!";

✅ End-of-File (EOF) Check:

When reading until the end of a file:

string line;
while (getline(file, line)) {
    cout << line << endl;
}
if (file.eof())
    cout << "Reached end of file.";

🔹 7. Working with Binary Files

Binary files store data in raw bytes, not human-readable text. This is useful for storing objects, images, or structured data.

Writing Binary Data:
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    string str = "Welcome to GeeksForGeeks";
    ofstream file("fileBin.bin", ios::binary);
    size_t length = str.length();
    file.write(reinterpret_cast<const char*>(&length), sizeof(length));
    file.write(str.c_str(), length);
    file.close();
}

Reading Binary Data:
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    fstream file("fileBin.bin", ios::in | ios::binary);
    size_t length;
    file.read(reinterpret_cast<char*>(&length), sizeof(length));
    char* buffer = new char[length + 1];
    file.read(buffer, length);
    buffer[length] = '\0';
    cout << "File Data: " << buffer;
    delete[] buffer;
    file.close();
}

🔹 8. Additional File Operations
🗑 Delete a File:
if (remove("GFG.txt") == 0)
    cout << "File deleted successfully.";
else
    cerr << "Error deleting file!";

🧩 Append Data:
ofstream file("GFG.txt", ios::app);
file << "\nThis line was appended!";
file.close();

📄 Copy File:
ifstream source("GFG.txt");
ofstream dest("copy.txt");
string line;
while (getline(source, line))
    dest << line << endl;
source.close();
dest.close();


_________________________________________________________________________________________________________
#include<iostream>
#include<fstream>
using namespace std ;
int main(){
    ofstream fout;
    fout.open("zoom.txt");
    fout<<"Hello Mehedi";
    fout.close();
}
_____________________________________
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("zoom.txt");
    if (!fin) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    char c;
    while (fin.get(c)) {  // ✅ safer: reads until EOF automatically
        cout << c;
    }

    fin.close();
    return 0;
}

_______________________________________________________
#include <iostream>
#include<vector>
#include<algorithm>
#include <fstream>
using namespace std;

int main() {
    vector<int>arr;
    cout<<"enter:";
    for(int i=0;i<5;i++) {
       int x; cin>>x;
       arr.push_back(x);
       
    }
    ofstream fout;
    fout.open("zero.txt");
    fout<<"Original data:\n";
    for(int i=0;i<5;i++){
        fout<<arr[i]<<" ";
    }
    sort(arr.begin(),arr.end());
    fout<<"\nAfter sorted:\n";
    for(int i=0;i<5;i++){
        fout<<arr[i]<<" ";
    }
    fout.close();
  
}
______________________________________________________________
🔹 Slightly improved version

Here’s a cleaner version that:

Uses constructor form for file stream

Checks if file opened successfully

Uses a range-based for loop for simplicity

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main() {
    vector<int> arr;
    cout << "Enter 5 integers: ";
    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    ofstream fout("zero.txt"); // directly open in constructor
    if (!fout) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    fout << "Original data:\n";
    for (int num : arr)
        fout << num << " ";

    sort(arr.begin(), arr.end());

    fout << "\nAfter sorted:\n";
    for (int num : arr)
        fout << num << " ";

    fout.close();

    cout << "Data written successfully to zero.txt ✅" << endl;
    return 0;
}

🔹 Bonus: To read back and show file contents

If you want to read from the file again after writing:

ifstream fin("zero.txt");
string line;
cout << "\nFile content:\n";
while (getline(fin, line)) {
    cout << line << endl;
}
fin.close();
