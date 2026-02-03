#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

// --------------------------------------------
// STRUCT FOR MCQs
// --------------------------------------------
struct MCQ {
    string q, a, b, c, correct;
};

// --------------------------------------------
// LOADING EFFECT
// --------------------------------------------
void waitDots() {
    for (int i = 0; i < 3; i++) {
        cout << ".";
        for (int j = 0; j < 100000000; j++); 
    }
    cout << "\n";
}

// --------------------------------------------
// DELAY FOR NOTES
// --------------------------------------------
void slowPrint(string line) {
    cout << line << endl;

    // simple delay loop
    for (long i = 0; i < 100000000; i++);  //
}

// --------------------------------------------
// SHOW NOTES 
// --------------------------------------------
void showNotes(string topic) {

    string fileName;

    if (topic == "Variables") fileName = "variables.txt";
    else if (topic == "If Else Statements") fileName = "ifelse.txt";
    else if (topic == "Loops") fileName = "loops.txt";
    else if (topic == "Arrays") fileName = "arrays.txt";
    else if (topic == "Functions") fileName = "functions.txt";

    ifstream file(fileName);
    if (!file) {
        cout << "Error: Could not open " << fileName << endl;
        return;
    }

    cout << "\n------ Notes on " << topic << " ------\n";

    string line;
    while (getline(file, line)) {
        slowPrint(line);  
    }

    file.close();
}

// --------------------------------------------
// SAVE RESULT INTO A FILE
// --------------------------------------------
void saveResult(string name, string topic, int score) {
    ofstream fout("results.txt", ios::app);

    time_t now = time(0);
    string dt = ctime(&now);
     

    fout << name << "|" << topic << "|" << score << "|" << dt << "\n";
    fout.close();
}

// --------------------------------------------
// READ PREVIOUS RESULT IF EXISTS
// --------------------------------------------
string getPreviousResult(string name) {
    ifstream fin("results.txt");
    if (!fin) return "";

    string line;
    string last = "";

    while (getline(fin, line)) {
        if (line.find(name + "|") == 0) {
            last = line;
        }
    }

    fin.close();
    return last;
}

// --------------------------------------------
// FILE-BASED QUIZ FUNCTION
// --------------------------------------------
int takeQuiz(string topic) {
    srand(time(0));
    vector<MCQ> questions;
    string fileName;

    if (topic == "Variables") fileName = "D:\\Project\\project_folder\\Quiz txt files\\variablequiz.txt";
    else if (topic == "If Else Statements") fileName = "D:\\Project\\project_folder\\Quiz txt files\\ifelsequiz.txt";
    else if (topic == "Loops") fileName = "D:\\Project\\project_folder\\Quiz txt files\\loopsquiz.txt";
    else if (topic == "Arrays") fileName = "D:\\Project\\project_folder\\Quiz txt files\\arraysquiz.txt";
    else if (topic == "Functions") fileName = "D:\\Project\\project_folder\\Quiz txt files\\functionsquiz.txt";

    ifstream file(fileName);
    if (!file) {
        cout << "Error: Could not open " << fileName << endl;
        return 0;
    }

    cout << "\nStarting quiz on " << topic << " ";
    waitDots();

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string q, a, b, c, correct;

        getline(ss, q, '|');
        getline(ss, a, '|');
        getline(ss, b, '|');
        getline(ss, c, '|');
        getline(ss, correct, '|');

        questions.push_back({q, a, b, c, correct});
    }

    file.close();
    random_shuffle(questions.begin(), questions.end());

    int score = 0;
    string ans;

    int total = min(5, (int)questions.size());

    for (int i = 0; i < total; i++) {
        cout << "\nQ" << i + 1 << ": " << questions[i].q << endl;
        cout << "A) " << questions[i].a << endl;
        cout << "B) " << questions[i].b << endl;
        cout << "C) " << questions[i].c << endl;

        cout << "> ";
        cin >> ans;

        if (ans == "a") ans = "A";
        if (ans == "b") ans = "B";
        if (ans == "c") ans = "C";

        if (ans == questions[i].correct)
            score++;
    }

    cout << "\n----------------------------------------\n";
    cout << "You scored " << score << " out of " << total << " in " << topic << "!\n";
    cout << "----------------------------------------\n";

    return score;
}

// --------------------------------------------
// SHOW RESULT SUMMARY
// --------------------------------------------
void showResult(string name, int totalScore) {
    cout << "\n========================================\n";
    cout << "              RESULT SUMMARY             \n";
    cout << "========================================\n";
    cout << "Student Name : " << name << endl;
    cout << "Total Score  : " << totalScore << endl;
    cout << "========================================\n";
}
// --------------------------------------------
// MAIN PROGRAM
// --------------------------------------------
int main() {
    string name, topic, choice;
    int totalScore = 0;
    char takeQuizChoice;
    bool running = true;

    cout << "========================================\n";
    cout << "         VIRTUAL TEACHER BOT            \n";
    cout << "========================================\n\n";

    cout << "Enter your name: ";
    getline(cin, name);
    // CHECK PREVIOUS RECORD
    string last = getPreviousResult(name);
    if (last != "") {
        stringstream ss(last);
        string n, t, s, d;

        getline(ss, n, '|');
        getline(ss, t, '|');
        getline(ss, s, '|');
        getline(ss, d, '|');

        cout << "\nWelcome back " << name << "!\n";
        cout << "Your previous quiz was on '" << t << "' and you scored " << s << "/5 on " << d << "\n";
    }
    while (running) {
        cout << "\nHello " << name << "! What would you like to learn today?\n";
        cout << "1. Variables\n2. If Else Statements\n3. Loops\n4. Arrays\n5. Functions\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        if (choice == "1") topic = "Variables";
        else if (choice == "2") topic = "If Else Statements";
        else if (choice == "3") topic = "Loops";
        else if (choice == "4") topic = "Arrays";
        else if (choice == "5") topic = "Functions";
        else { cout << "Invalid choice!\n"; continue; }

        showNotes(topic);

        cout << "\nDo you want to take a quiz on this topic? (Y/N): ";
        cin >> takeQuizChoice;

        if (takeQuizChoice == 'Y' || takeQuizChoice == 'y') {
            int quizScore = takeQuiz(topic);
            totalScore += quizScore;

            saveResult(name, topic, quizScore);  // SAVE RESULT
        }
        bool subMenu = true;
        while (subMenu) {
            cout << "\n----------------------------------------\n";
            cout << "1. Return to Topics\n";
            cout << "2. Show My Result\n";
            cout << "3. Exit\n";
            cout << "----------------------------------------\n";
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == "1") subMenu = false;
            else if (choice == "2") showResult(name, totalScore);
            else if (choice == "3") {
                cout << "\nGoodbye, " << name << "! Keep learning :) \n";
                running = false;
                subMenu = false;
            }
            else cout << "Invalid option. Try again!\n";
        }
    }
    return 0;
}

