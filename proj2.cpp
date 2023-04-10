#include<iostream>
#include<fstream>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<string>
#include<utility>

using std::string;
using std::cin; using std::cout; using std::endl;

std::unordered_map<char, char> ReadEncodingPairs(std::unordered_map<char, char> encoding_pairs) {
    string encoding;  
    std::set<char> S;
    while (cin >> encoding) {
        if (static_cast<int>(encoding.size()) != 2)
            std::exit(EXIT_FAILURE);
        encoding_pairs.insert({encoding[0], encoding[1]}); 
        if (S.find(encoding[0]) != S.end()) {
            cout << error_msg << endl;
            std::exit(EXIT_FAILURE);
    }
        S.insert(encoding[0]);
    }
    return encoding_pairs;
}

string ApplyEncoding(string line, std::unordered_map<char, char> encoding_pairs) {
    string output;
    for (char c: line) {
        int TorF = 0;
        for (auto [left, right]: encoding_pairs) {
            if (c == left) { 
                output += right;
                TorF += 1;
            }
        }
        if (TorF == 0)
          output += c;
    }
    return output;
}

string ProcessFile(std::ifstream& input, std::unordered_map<char, char> encoding_map) {
    string line;
    string encoded_line;
    string new_file;
    std::set<string> lines;
    while (std::getline(input, line)) {
        encoded_line = ApplyEncoding( line, encoding_map); 
        if (lines.find(encoded_line) != lines.end() )
          continue;
        lines.insert(encoded_line);
        new_file += encoded_line + "\n";
    }
    return new_file;
}

int main(){
    string error_msg = "XD";
    string file_name;
    cin >> file_name;
    std::ifstream input(file_name);
    if (!(input.is_open())) {
        cout << error_msg << endl;
        return 1;
    }
    std::unordered_map<char, char> encoding_pairs;   
    std::unordered_map<char, char> map = ReadEncodingPairs(encoding_pairs);
    string output = ProcessFile(input, map);
    cout << output << endl;
    return 0;
}