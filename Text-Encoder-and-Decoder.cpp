#include <iostream>
#include <string>
#include <map>
#include <sstream> 
#include<limits>

using namespace std;

long long getValidInput()
{
    long long input;
    while (true)
    {
        cin >> input;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            cout << "Errorr\n";
            cout << "=======================\n";
            cout << "Conversion modes\n1) Letter (A) -> Symbol (#)\n2) Symbol (#) -> Letter (A)\nChoose conversion mode : ";
        }
        else
        {
            break;
        }
    }
    return input;
}

int main()
{
    int choose2;
    do
    {
        system("cls");
        int choose;

        cout << "Conversion modes\n1) Letter (A) -> Symbol (#)\n2) Symbol (#) -> Letter (A)\nChoose conversion mode : ";
        choose = getValidInput();

        while (!(choose == 1 || choose == 2))
        {
            system("cls");
            cout << "Errorr\n";
            cout << "=======================\n";
            cout << "Conversion modes\n1) Letter (A) -> Symbol (#)\n2) Symbol (#) -> Letter (A)\nChoose conversion mode : ";
            choose = getValidInput();
        }

        if (choose == 1)
        {
            cin.ignore();
            system("cls");
            map<char, string> charToSymbol = {
                {'a',"@#"},   {'b',"#@@@"}, {'c',"#@#@"}, {'d',"#@@"},  {'e',"@"},
                {'f',"@@#@"}, {'g',"##@"},  {'h',"@@@@"}, {'i',"@@"},   {'j',"@###"},
                {'k',"#@#"},  {'l',"@#@@"}, {'m',"##"},   {'n',"#@"},   {'o',"###"},
                {'p',"@##@"}, {'q',"##@#"}, {'r',"@#@"},  {'s',"@@@"},  {'t',"#"},
                {'u',"@@#"},  {'v',"@@@#"}, {'w',"@##"},  {'x',"#@@#"}, {'y',"#@##"},
                {'z',"##@@"} 
            };

            string text;
            cout << "Enter ur words : ";
            getline(cin, text);

            string SymbolResult;

            for (int i = 0; i < text.size(); i++) 
            {
                char c = text[i];
                if (c == ' ') {
                    SymbolResult += " _ ";
                }
                else if (charToSymbol.find(c) != charToSymbol.end()) {
                    SymbolResult += charToSymbol[c] + " ";
                }
            }

            cout << "Here we go : " << SymbolResult << endl;
        }
        else
        {
            cin.ignore();
            system("cls");
            map<string, char>
                SymbolToChar =
            {
                {"@#", 'a'},   {"#@@@", 'b'}, {"#@#@", 'c'}, {"#@@", 'd'},  {"@", 'e'},
                {"@@#@", 'f'}, {"##@", 'g'},  {"@@@@", 'h'}, {"@@", 'i'},   {"@###", 'j'},
                {"#@#", 'k'},  {"@#@@", 'l'}, {"##", 'm'},   {"#@", 'n'},   {"###", 'o'},
                {"@##@", 'p'}, {"##@#", 'q'}, {"@#@", 'r'},  {"@@@", 's'},  {"#", 't'},
                {"@@#", 'u'},  {"@@@#", 'v'}, {"@##", 'w'},  {"#@@#", 'x'}, {"#@##", 'y'},
                {"##@@", 'z'}, {"_", ' '}
            };

            string SymbolInput;
            cout << "Enter ur Symbols : ";
            getline(cin, SymbolInput);

            stringstream ss(SymbolInput);
            string code;
            string result;

            while (ss >> code)
            {
                if (SymbolToChar.find(code) != SymbolToChar.end())
                {
                    result += SymbolToChar[code];
                }
                else
                {
                    result += '?';
                }
            }

            cout << "Here we go : " << result << endl;
        }

        cout << "=================\nConvert antther one..?";
        cout << "\n1) yes\nany) no\n";
        cin >> choose2;

    } while (choose2 == 1);

    cout << "=====================================" << "\nDone...";

    return 0;
}