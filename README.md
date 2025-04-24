# Exam_Simulation_System
🚀 **Project Showcase: Exam Simulation System**  I’m excited to share a recent project I worked on developing a C++-based Exam Simulation System that allows users to securely log in, attempt multiple-choice exams (C, C++, HTML &amp; CSS), and track their progress in real-time.


# Elegant Eldorado Syllabus Day - Quiz System

## Overview
This is a C++ console-based Quiz System designed to conduct exams in C, C++, and HTML & CSS. The program provides a user-friendly interface with loading bars, a login system, and a timed exam environment. It saves user responses to a file for review.

## Features
- **Login System**: Secure login with predefined usernames and passwords.
- **Exams**: Supports three exams (C, C++, HTML & CSS) with a 5-minute time limit each.
- **Question Management**: Loads questions from text files, shuffles them, and displays them with options.
- **Progress Bars**: Visual loading bars for a better user experience.
- **Response Saving**: Saves user answers and results to `user_responses.txt`.

## Requirements
- **Operating System**: Windows (due to use of `windows.h` and `conio.h`).
- **Compiler**: Any C++ compiler supporting C++11 or later (e.g., g++, MSVC).
- **Files**: Question files (`c_questions.txt`, `cpp_questions.txt`, `HTML&CSS_questions.txt`) must be in the same directory as the executable.

## File Structure
- Each question file should have the following format:
  ```
  Question text
  Option 1
  Option 2
  Option 3
  Option 4
  Correct answer (1-4)
  [Blank line]
  ```

## Usage
1. Compile and run the program on a Windows machine.
2. The program displays an ASCII art intro and a loading bar.
3. Log in using one of the predefined credentials:
   - Example: Username: `shooter`, Password: `123456`
4. Select an exam (C, C++, or HTML & CSS) from the menu.
5. Answer the questions within 5 minutes. Enter `E` to exit during the exam.
6. View your score and results saved in `user_responses.txt`.
7. Choose another exam or logout.

## Notes
- The program is designed for Windows. For cross-platform support, modifications are needed.
- Ensure question files are correctly formatted to avoid runtime errors.
