# CS120 Game Prototype 2

## Introduction

This assignment will be in sync with your GAM100 prototype 2 assignment. In this assignment you will use C++ and the `doodle` framework to create a game prototype.

GAM100 will grade based off of the game design and game production. CS120 will grade based off of your use of C++.

## Submission

Your project will be hosted on GitHub via GitHub classroom assignment. This will also be your submission location.

# Create a ReadMe


Create a **`CS120ReadMe.md`** markdown file that defines the following.

1. Your names, assignment name/number, course name, term
2. Section describing anything incomplete about the assignment
3. Section describing something you're proud of about the assignment
4. Section that lists the File Name and Line Number for all code requirements
    - one example is enough if there are multiple instances

## Grading Rubric

- [x] [**core**] Used C++ and `doodle` framework to make a game prototype
- [x] [**core**] Code is reasonably organized across multiple files, so that there are no big monolithic source code files.
- [x] [**core**] Made good use of exceptions - main.cpp, line 78
- [x] [**core**] All functions, member functions and constructors validate their parameters - game.cpp, line 69
- [x] [**core**] Made good use of File IO with the `ifstream` and `ofstream` types main.cpp, line 93, line 96
- [x] [**core**] Made good use of `std::map` and/or `std::unordered_map` main_header.h, line 54
- [x] Uses the most appropriate loop statements for the kind loop that is done
- [x] Make good use of functions - main.cpp, line 90
- [x] Make good use of `class`/`struct` - pos.h, line 7
- [x] Make good use of References - arts.cpp, line 22
- [x] Print only debug info via `cout`
- [x] All variables are initialized when **defined** - main_header.h, line 56
- [x] If using shared global variables then they are defined in a header file with the `inline` keyword. - main_header.h, line 57
- [x] Constants are defined as `constexpr` whenever possible - main_header.h, line 55
- [x] Make good use of `using` statements - main_header.h, line 16
- [x] Collection of variables are put into a struct or class object - game.h, line 12
- [x] If using fixed size arrays then they are defined with `std::array`
- [x] Created and used your own `namespace` -main_header.h, line 19
- [x] All long functions are broken down into helper functions - game.cpp, line 143
- [x] Uses default arguments rather than function overloads
- [x] Made one more `constexpr` functions - main.cpp, line 84
- [x] If functions are defined in header files then they are marked as `inline` or `constexpr` - main_header.h, line 20
- [x] Window title contains team name - main.cpp, line 14
- [x] All source files compile without warnings and without errors.
- [x] Warning level 4 is set and treat warnings as errors is set.
- [x] Correct files submitted. No unnecessary files submitted.
- [x] **All** Source Code has a proper header comment: Name, Assignment Name, Course Number, Term & Year.
- [x] Followed the appropriate Code Quality Guidelines and Code Style Guidelines.
- [x] Created a properly filled out `CS120ReadMe.md` file
- [x] All requirements that are completed are checked off here by replacing the `[ ]` with `[x]`

Scores for Exercises will be given as the following:

Score        | Assessment
------------ | ----------
Zero         | Nothing turned in at all
Failing      | Close to meeting core requirements
Rudimentary  | Meets all of the core requirements
Satisfactory | Close to meeting all requirements
Good         | Clearly meets all requirements 
Excellent    | High quality, well beyond the requirements

## Unnecessary Files

Your repo must **NOT** contain

User-specific files

    *.suo
    *.user

Build results

    [Dd]ebug/
    [Rr]elease/
    x64/

Visual Studio Cache Files/Directories

    .vs/
