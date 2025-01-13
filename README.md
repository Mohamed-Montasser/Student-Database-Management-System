# Student Database Management System

This is a **Student Database Management System** implemented in C. It allows users to store, manage, and manipulate student records, including adding, editing, deleting, and viewing student data. The program uses dynamic memory allocation to handle student records efficiently.

---

## Table of Contents
1. [Features](#features)
2. [How It Works](#how-it-works)
3. [Functions](#functions)
4. [Future Improvements](#future-improvements)
5. [Example Workflow](#example-workflow)


---

## Features
- **Dynamic Memory Allocation**: Uses `malloc` and `realloc` to manage student records dynamically.
- **Student Structure**: Each student record contains:
  - `name` (string, up to 25 characters)
  - `age` (unsigned integer, range 1-50)
  - `id` (unsigned integer, must be greater than 0).
- **Menu-Driven Interface**: Provides a user-friendly menu for:
  - Adding new students.
  - Editing existing student records.
  - Viewing all students.
  - Deleting a student.
  - Exiting the program.
- **Input Validation**: Ensures valid input for age (1-50) and ID (greater than 0).

---

## How It Works
1. The program starts by asking the user how many students they want to store initially.
2. It dynamically allocates memory for the student records and initializes them.
3. The user is presented with a menu to:
   - Add new students.
   - Edit existing student records.
   - View all students.
   - Delete a student.
   - Exit the program.
4. The program ensures data integrity by validating inputs and handling memory allocation dynamically.

---

## Functions
1. **`SetStud(student *ptr1, int *num)`**:
   - Initializes the database by taking input for a specified number of students.

2. **`GetStud(student *ptr1, int *num)`**:
   - Displays detailed information about all students.

3. **`AddStud(student *oldPtr, int *num)`**:
   - Adds a new student to the database and resizes the memory allocation.

4. **`CopyData(student *oldPtr, int *num, student *newPtr)`**:
   - Copies data from an old pointer to a new pointer (used for resizing memory).

5. **`ShiftUpData(student *oldPtr, int *num, int n)`**:
   - Shifts data up when a student is deleted to fill the gap.

6. **`DelData(student *Ptr, int *num)`**:
   - Deletes a student from the database and resizes the memory allocation.

7. **`GetStudOneLine(student *Ptr, int *num)`**:
   - Displays all students in a compact, tabular format.

8. **`EditStudent(student *Ptr, int *num)`**:
   - Allows the user to edit a specific student's name, age, or ID.

---

## Future Improvements
- **Save/Load Data**: Add functionality to save the database to a file and load it back when the program starts.
- **Search Functionality**: Implement a search feature to find students by name, ID, or age.
- **Error Handling**: Improve error handling for invalid inputs and memory allocation failures.
- **Degree Field**: Utilize the `degree` field in the student structure to store and display student grades.
- **User Interface**: Add a graphical user interface (GUI) for better user interaction.
- **Sorting**: Implement sorting functionality to display students by name, age, or ID.
- **Export Data**: Allow exporting student data to CSV or Excel for external use.
- **Data Validation**: Enhance input validation to handle edge cases and invalid data formats.
- **Performance Optimization**: Optimize memory usage and performance for large datasets.

---

## Example Workflow
1. **Add Students**:
   - The user inputs the number of students to add.
   - For each student, the user provides a name, age, and ID.

2. **Edit Students**:
   - The user selects a student by their number and chooses to edit their name, age, or ID.

3. **View Students**:
   - The program displays all students in a tabular format with their ID, age, and name.

4. **Delete Students**:
   - The user selects a student by their number, and the program removes them from the database.

5. **Exit**:
   - The program terminates, and all dynamically allocated memory is freed.

  ---
