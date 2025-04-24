/*******************************************************
********************************************************
************* Mohammed El-Khadragy *********************
************** Evram Fady Nashaat **********************
***************** Bavly Adel ***************************
********************************************************
********************************************************/


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>
#include<windows.h>
#include <thread>

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
char getch() {
    char ch;
    termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
#endif

using namespace std;
using namespace std::chrono;

void intro() {

   cout << R"(
                            ███████╗██╗     ███████╗██████╗ ██████╗  █████╗  ██████╗██╗   ██╗
                            ██╔════╝██║     ██╔════╝██╔══██╗██╔══██╗██╔══██╗██╔════╝╚██╗ ██╔╝
                            █████╗  ██║     ███████╗██║  ██║██████╔╝███████║██║  ███╗╚████╔╝
                            ██╔══╝  ██║     ╚════██║██║  ██║██╔══██╗██╔══██║██║   ██║ ╚██╔╝
                            ███████╗███████╗███████║██████╔╝██║  ██║██║  ██║╚██████╔╝  ██║
                            ╚══════╝╚══════╝╚══════╝╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝   ╚═╝

                                    ███████╗██╗   ██╗██████╗  █████╗ ███╗   ███╗
                                    ██╔════╝██║   ██║██╔══██╗██╔══██╗████╗ ████║
                                    █████╗  ██║   ██║██████╔╝███████║██╔████╔██║
                                    ██╔══╝  ╚██╗ ██╔╝██╔══██╗██╔══██║██║╚██╔╝██║
                                    ███████╗ ╚████╔╝ ██║  ██║██║  ██║██║ ╚═╝ ██║
                                    ╚══════╝  ╚═══╝  ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚═╝

                                        ██████╗  █████╗ ██╗   ██╗██╗  ██╗   ██╗
                                        ██╔══██╗██╔══██╗██║   ██║██║  ╚██╗ ██╔╝
                                        ██████╔╝███████║██║   ██║██║   ╚████╔╝
                                        ██╔══██╗██╔══██║╚██╗ ██╔╝██║    ╚██╔╝
                                        ██████╔╝██║  ██║ ╚████╔╝ ███████╗██║
                                        ╚═════╝ ╚═╝  ╚═╝  ╚═══╝  ╚══════╝╚═╝
                                   ______                                 _           __
                                  / ____/__    __     ____  _________    (_)__  _____/ /_
                                 / /  __/ /___/ /_   / __ \/ ___/ __ \  / / _ \/ ___/ __/
                                / /__/_  __/_  __/  / /_/ / /  / /_/ / / /  __/ /__/ /_
                                \____//_/   /_/    / .___/_/   \____/_/ /\___/\___/\__/
                                                  /_/              /___/

       )" << endl;
            			Sleep(3000);


}


void loading_bar (){

 for (int i=15;i<=100;i+=5)//increasing by  5 and start with 15
        {
        system("cls");
       // ccolor(14);
		cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t";
		cout<<i<<" %% Loading...\n\n\t\t";
		cout<<" ";
		for (int j=0; j<i;j+=2){
			cout<<" ";
		}
		Sleep(50);  //sleep for 50 mile second
		if(i==90 || i==50 || i==96 || i==83){
			Sleep(50);
		}
	}
	system("cls");// clear the terminal
}

void progress_Bar() {
    const int progressBarWidth = 50;
    cout << "\nLoading...\n";

    for (int i = 0; i <= 100; i += 5) {
        cout << "\r[";
        int pos = (i * progressBarWidth) / 100;
        for (int j = 0; j < progressBarWidth; ++j) {
            if (j < pos) cout << "=";
            else if (j == pos) cout << ">";
            else cout << " ";
        }
        cout << "] " << i << "%";
        cout.flush();

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    cout << "\nLoading Complete!\n";
}

// Constants
const int MAX_USERS = 10;
const int MAX_QUESTIONS = 200;
const int MAX_OPTIONS = 4;

// User Structure
struct User {
    string username;
    string password;
};

// Question Structure
struct Question {
    string text;
    string options[MAX_OPTIONS];
    int correctIndex;
};

// Hardcoded Users (from Excel)
User users[MAX_USERS] = {
    {"shooter", "kokowawa"},
    {"ali100", "aliwika123"},
    {"mona2000", "monaooa123"},
    {"m", "m"},
    { "Bavly","1234"}
};

// Login Functions
string inputPassword() {
    string password;
    char ch;
    cout << "\t\t\t\t\t\tPassword 🔑: ";
    while ((ch = getch()) != '\n') {
        if (ch == '\r') break;
        if (ch == 127 || ch == 8) {
            if (!password.empty()) {
                password.pop_back();
                cout << "\b \b";
            }
        } else {
            password += ch;
            cout << '*';
        }
    }
    cout << endl;
    return password;
}

bool login(string& username_out){

    cout << "\n\n\n\t\t\t\t\t\t=== Login 🤖 ===\n";

    for (int attempt = 0; attempt < 3; ++attempt) {
        string uname, pword;
        cout << "\t\t\t\t\t\tUsername 🦸🏻:";
        cin >> uname;
        pword = inputPassword();

        for (int i = 0; i < MAX_USERS; ++i) {
            if (users[i].username == uname && users[i].password == pword) {
                username_out = uname;
                cout << "\t\t\t\t\t\t✅ Welcome, " << uname << "!\n";
                return true;
            }
        }
        cout << "\t\t\t\t\t❌ Invalid credentials. Try again.\n";
    }
    cout << "\t\t\t\t\t🚫 Too many failed attempts 💀 .\n";
    return false;
}

void logout(const string& username) {
    cout << "\n🔒 User '" << username << "' logged out. Goodbye!\n";
    exit(0);
}

// Question Loader
int loadQuestions(const string& filename, Question questions[]) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "❌ Failed to open question file.\n";
        return 0;
    }

    int count = 0;
    string line;
    while (getline(file, line) && count < MAX_QUESTIONS) {
        if (line.empty()) continue;
        questions[count].text = line;

        for (int i = 0; i < MAX_OPTIONS; ++i) {
            getline(file, line);
            questions[count].options[i] = line;
        }
        getline(file, line);
        questions[count].correctIndex = stoi(line) - 1;
        getline(file, line); // Skip blank line

        count++;
    }
    file.close();
    return count;
}

// Shuffle questions
void shuffleQuestions(Question questions[], int total) {
    srand(time(0));
    for (int i = 0; i < total; ++i) {
        int j = rand() % total;
        swap(questions[i], questions[j]);
    }
}

// Save user responses incrementally
void savePartialResponse(const string& username, const string& examType, const Question& question, int questionIndex, const string& userAnswer, bool isCorrect, bool isFirstSave) {
    ofstream outFile("user_responses.txt", ios::app); // Append mode
    if (!outFile.is_open()) {
        cerr << "❌ Failed to open file for saving user responses!\n";
        return;
    }

    // Print username and exam type only once
    if (isFirstSave) {
        outFile << "Username: " << username << "\n";
        outFile << "Exam Type: " << examType << "\n";
    }

    outFile << "Question " << (questionIndex + 1) << ": " << question.text << "\n";
    outFile << "Your Answer: " << userAnswer << "\n";
    outFile << "Correct Answer: " << question.options[question.correctIndex] << "\n";
    outFile << "Result: " << (isCorrect ? "✅ Correct" : "❌ Incorrect") << "\n";
    outFile << "-------------------\n";

    outFile.close();
}

// Exam Simulation
void simulateExam(Question questions[], int total, int timeLimitSeconds, const string& username, const string& examType) {
    int score = 0;
    auto startTime = steady_clock::now();
    bool isFirstSave = true; // Flag to track if it's the first save

    for (int i = 0; i < total; ++i) {
        auto now = steady_clock::now();
        auto elapsed = duration_cast<seconds>(now - startTime).count();
        if (elapsed >= timeLimitSeconds) {
            cout << "\n⏰ Time's up!\n";
            break;
        }

        int timeLeft = timeLimitSeconds - static_cast<int>(elapsed);
        if (timeLeft < 0) timeLeft = 0;
        int minLeft = timeLeft / 60;
        int secLeft = timeLeft % 60;

        cout << "\nQ" << (i + 1) << "/" << total
             << " [Time left: " << minLeft << " min " << setw(2) << setfill('0') << secLeft << " sec]"
             << ": " << questions[i].text << "\n";

        for (int j = 0; j < MAX_OPTIONS; ++j) {
            cout << "  " << (j + 1) << ". " << questions[i].options[j] << "\n";
        }
        int answer;
        string input;
        while (true) {
            cout << "Your answer (1-4) (E for exit): ";
            cin >> input;

            if (input.length() == 1 && toupper(input[0]) == 'E') {
                logout(username);
            }

            // Check if input is a single digit
            if (input.length() == 1 && isdigit(input[0])) {
                answer = input[0] - '0';
                if (answer >= 1 && answer <= 4) {
                    cin.ignore(1000, '\n');
                    break;
                }
            }
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "❌ Invalid input. Please enter a number between 1 and 4.\n";
        }

        // Compare with correct answer (0-based index)
        bool isCorrect = (answer - 1 == questions[i].correctIndex);
        if (isCorrect) {
            cout << "✅ Correct!\n";
            score++;
        } else {
            cout << "❌ Incorrect. Correct: "
                 << questions[i].options[questions[i].correctIndex] << "\n";
        }

        // Save the response immediately
        savePartialResponse(username, examType, questions[i], i, questions[i].options[answer - 1], isCorrect, isFirstSave);
        isFirstSave = false; // Set to false after the first save
    }

    cout << "\n🎯 Score: " << score << "/" << total
         << " (" << (score * 100.0 / total) << "%)\n";
}

// Main Program
int main() {
    SetConsoleOutputCP(CP_UTF8);

    intro();
    loading_bar();

    string currentUser;
    if (!login(currentUser)) return 1;

    progress_Bar();

    bool exams[3] = {false, false, false}; // C, C++, HTML flags
    int examChoice = 0;

    while (true) {
        // Handle exam execution
        if ((examChoice >= 1 && examChoice <= 3) && !exams[examChoice-1]) {
            progress_Bar();

            Question questions[MAX_QUESTIONS];
            string examFiles[] = {"c_questions.txt", "cpp_questions.txt", "HTML&CSS_questions.txt"};
            string examNames[] = {"C Exam", "C++ Exam", "HTML & CSS Exam"};

            int totalQuestions = loadQuestions(examFiles[examChoice-1], questions);
            if (totalQuestions == 0) return 1;

            shuffleQuestions(questions, totalQuestions);
            cout << "\n🕒 Exam starting now. You have 5 minutes 🚀🚀🚀.\n";
            simulateExam(questions, totalQuestions, 300, currentUser, examNames[examChoice-1]);

            exams[examChoice-1] = true;
        }
        // Handle logout
        else if (examChoice == 4 || (exams[0] && exams[1] && exams[2])) {
            logout(currentUser);
            break;
        }
        // Handle invalid input
        else if (examChoice > 4 || examChoice < 0) {
            cout << "❌ Invalid choice. Please enter a valid option.\n";
            examChoice = 0;
        }

        // Display available exams menu
        cout << "\n📚 Select your exam:\n";
        if (!exams[0]) cout << "1. C Exam 🅲\n";
        if (!exams[1]) cout << "2. C++ Exam 🅲➕➕\n";
        if (!exams[2]) cout << "3. HTML 🌐 & CSS 🎨 Exam\n";
        cout << "4. Logout\n";

        // Show completed exams
        if (exams[0]) cout << "You have completed C Exam\n";
        if (exams[1]) cout << "You have completed C++ Exam\n";
        if (exams[2]) cout << "You have completed HTML & CSS Exam\n";

        cout << "Enter your choice: ";
        cin >> examChoice;
    }

    return 0;
}
