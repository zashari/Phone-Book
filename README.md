# First Semester Project: Phone Book System

### Introduction

This C program is a digital phone book application developed as one of my assignments during my first year of college. It showcases my understanding and application of basic C programming concepts, including structures, file handling, sorting algorithms, and a simple text-based user interface.

### Program Overview

1. **Data Structure**:
   - A `data` structure (renamed to `Book` for clarity) is defined to store a phone book entry, consisting of a name and a phone number.

2. **Global Variables and Functions**:
   - `book[SIZE]`: An array of `Book` structures to store the phone book entries.
   - `last`: A global variable to keep track of the last index in the `book` array.
   - Functions for different operations: `sort`, `swap`, `select`, `read`, `write`, `add`, `display`, and `search`.

3. **Functionality**:
   - `read()`: Reads the phone book data from a file into the `book` array.
   - `write()`: Writes the phone book data from the `book` array to a file.
   - `add()`: Adds a new phone book entry.
   - `display()`: Displays all phone book entries.
   - `search()`: Searches for a phone number by name.

4. **Sorting and Searching**:
   - `sort()`: Sorts the phone book entries by name using a simple selection sort algorithm.
   - `select()`: Implements a binary search to find a phone book entry.

### Key Functionalities and Analysis

1. **Reading and Writing to File**:
   - `read()` and `write()` handle file I/O to persist the phone book data between runs.

2. **Adding Entries (`add`)**:
   - Allows adding new phone book entries, ensuring the array does not exceed its defined size.

3. **Displaying Entries (`display`)**:
   - Sorts the phone book entries before displaying them, making it easier to find entries.

4. **Searching for Entries (`search`)**:
   - Uses binary search to efficiently find an entry, demonstrating an understanding of more complex algorithms.

5. **Sorting Entries (`sort` and `swap`)**:
   - Implements a basic selection sort algorithm to order the entries alphabetically.

### Improvements

1. **Dynamic Memory Allocation**: To handle an unlimited number of entries, dynamically allocate memory instead of using a fixed-size array.
2. **Input Validation**: Add checks to validate user inputs (e.g., name and number formats).
3. **Error Handling**: Implement better error handling, especially for file operations.
4. **User Interface**: Enhance the user interface for better user experience.
5. **Modularity**: Refactor code into smaller, more focused functions for readability and maintainability.

### Conclusion

This phone book application reflects my foundational skills in C programming from my first year in college. It incorporates essential programming concepts and demonstrates my ability to develop a functional, albeit basic, application. With further development and refinement, it could be evolved into a more sophisticated and user-friendly digital phone book system.
