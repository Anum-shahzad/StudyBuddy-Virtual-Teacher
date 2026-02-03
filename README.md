StudyBuddy – Virtual C++ Teacher & Quiz System

StudyBuddy is a console-based C++ application created as a first-year project to practice core programming concepts such as file handling, functions, and structured program flow.The project focuses on learning through interactive notes and topic-based quizzes.
This repository is maintained as a personal progress tracker, representing my early-stage C++ development skills.
---

Project Overview

StudyBuddy allows users to:
- Read topic notes loaded from text files
- Take multiple-choice quizzes for each topic
- Save quiz results for future reference
- View previous scores when returning to the program
---

Topics Included

- Variables 
- If Else Statements 
- Loops 
- Arrays 
- Functions
Each topic has:
- A notes file (theory)
- A quiz file (questions and options)
---

File Structure

```
StudyBuddy/
│
├── StudyBuddy.pdf
├── README.md
│
├── Notes_and_Source_Code/
│   │
│   ├── array_notes.txt
│   ├── functions_notes.txt
│   ├── if_else_notes.txt
│   ├── loops_notes.txt
│   ├── variables_notes.txt
│   ├── results.txt
│   │
│   └── StudyBuddy.cpp
│
└── Quiz_Files/
    │
    ├── array_quiz.txt
    ├── functions_quiz.txt
    ├── if_else_quiz.txt
    ├── loops_quiz.txt
    └── variables_quiz.txt
```

---

Notes System

- Notes are stored in plain text files
- Files are read line by line using getline()
- Each line is displayed with a small delay using a custom slowPrint() function
- This avoids dumping all content at once and improves readability
---

Quiz File Format

Quiz questions are stored using a pipe (|) separated format.

Structure

```
Question | Option A | Option B | Option C | CorrectOption

```

Example

```
Which loop always runs at least once? | for | while | do-while | c
Which keyword stops a loop? | break | stop | exit | a
What does ++ mean? | decrease | increment | skip | b

```

Why This Format Is Used

- Keeps quiz data structured and readable
- Allows easy splitting using stringstream
- Makes quizzes editable without changing the C++ code
---

Core Functions

Function
Purpose
waitDots()
Displays a simple loading effect
slowPrint()
Prints text with delay
showNotes()
Displays topic notes
takeQuiz()
Loads and runs quizzes
saveResult()
Saves results to file
getPreviousResult()
Retrieves past scores
showResult()
Displays result summary
main()
Controls program flow

---

Program Flow

1. User enters name
2. Previous results are checked
3. Topic menu is shown
4. Notes are displayed
5. User chooses to take quiz
6. Quiz score is calculated
7. Result is saved
8. User can continue or exit
---

Concepts Demonstrated

- Functions and modular design
- Loops and conditionals
- File handling (ifstream, ofstream)
- String handling
- Console-based user interaction
---

Project Explanation Video

A complete walkthrough of the project is available here: https://youtu.be/_0Kh_S2AY4Q
🔗 Watch Project Explanation Video
---

Developed By

Anum Shahzad
First Year C++ Project StudyBuddy – Virtual Teacher System
---

 
