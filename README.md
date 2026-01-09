# Mini Uber App – C++ OOP Project

A console-based application written in **C++**, inspired by the basic logic of ride-sharing platforms such as Uber.  
The project focuses on **Object-Oriented Programming**, **STL usage**, **lambda expressions**, and clean architecture.

---

##  Features

- Manage **Users**
- Manage **Drivers** (each driver owns a Car)
- Display **available drivers**
- Create and store **Rides**
- Preview **drivers ordered by distance** from a given location
- Menu-driven console interface
- Input validation and exception handling

---

##  Project Structure (example)

The project is organized using a clear separation between header files and
implementation files, following common C++ best practices.
---

## ⚙️ Technologies Used

- C++17 / C++20
- STL (`vector`, `shared_ptr`, `algorithm`)
- Lambda expressions
- CMake
- GitHub Actions 

---

## 🖥️ Menu Options

The application provides a console-based menu that allows the user to interact
with the system through numeric commands.

Each option is described below:

### 1. Show all users
Displays all registered users in the system.  
Each user is printed with an index and basic information such as name and location.

### 2. Show all drivers
Displays all drivers currently stored in the system.  
Driver information includes availability status, current location, and assigned car.

### 3. Show available drivers
Displays only drivers that are currently marked as available for accepting a ride.  
This option helps quickly identify drivers that can be selected.

### 4. Show all rides
Displays all rides that have been created during the application runtime.  
Each ride includes information about the user, driver, destination, and price.

### 5. Add user
Allows the creation of a new user by reading user details from standard input.  
The newly created user is added to the system.

### 6. Add driver
Allows the creation of a new driver.  
The driver is initialized with a location, availability status, and an assigned car.

### 7. Request ride
Creates a new ride using the following steps:
- A user is selected from the list of registered users
- A destination location is entered from the keyboard
- The closest available driver is selected
- A new ride is created and stored

### 8. Show drivers ordered by distance
Displays all drivers ordered by their distance from a given location entered
from the keyboard.

This option:
- Uses STL `std::sort`
- Uses a lambda expression as a comparator
- Sorts a copy of the drivers list (non-destructive)
- Displays the exact distance for each driver

This functionality allows previewing driver proximity without creating a ride.

### 0. Exit
Terminates the application and exits the menu.




---

##  Show Drivers Ordered by Distance (Lambda Sorting)

This option allows the user to preview the order of drivers based on their distance  
from a given location, without creating a ride.

The user can:

1. Introduce a location from the keyboard (X, Y coordinates)
2. View all drivers sorted by distance from that location
3. See the exact distance for each driver

The sorting logic:

- Uses `std::sort` from the STL
- Uses a lambda expression as a comparator
- Is applied on a copy of the drivers vector, so the original order is not modified
- Prioritizes available drivers before unavailable ones

This feature demonstrates the use of STL algorithms, lambda expressions,  
and non-destructive operations on containers.



---

##  Request Ride

The **Request Ride** option creates a new ride by connecting a selected user with an available driver.

### Flow

1. The user selects **Request Ride** from the menu.
2. The application displays the list of registered users.
3. A user is selected by index.
4. The destination coordinates (**X**, **Y**) are read from the keyboard.
5. Drivers are processed to choose a suitable driver (typically the closest available one,
   depending on the current selection logic in `RideManager`).
6. If a driver is found:
    - A `Ride` object is created
    - The ride details are printed
    - The ride is stored in the rides list
7. If no driver is available, an exception is thrown and handled gracefully.

### Notes

- Input is validated (invalid indices or invalid numeric input are rejected).
- The ride creation logic is delegated to `RideManager`, keeping UI logic inside `Menu`
  and business logic inside the manager.



---

##  Design Notes (OOP & Architecture)

The project is organized to keep responsibilities separated and the codebase easy to extend.

### App (Application Layer)
- Owns the application state: users, drivers, and rides
- Controls the application lifecycle (startup and execution)
- Creates the `Menu` and passes references to the stored data

### Menu (UI Layer)
- Handles all console input/output
- Validates user input (menu options, indices, numeric values)
- Orchestrates actions by calling the appropriate logic (e.g., `RideManager`)
- Does not own data; it operates on references to the data owned by `App`

### RideManager (Business Logic Layer)
- Encapsulates ride creation logic
- Selects a suitable driver from the available drivers list (e.g., closest driver)
- Keeps business rules separate from UI code
- Can be extended later with more complex selection strategies and pricing rules

### Data Model
- `User`, `Driver`, `Ride`, `Location`, and `Car` represent the core entities
- Users and drivers are stored as `std::shared_ptr` to simplify lifetime management
- Rides are stored as value objects (`std::vector<Ride>`) to keep ride history simple

---

##  OOP and SOLID Principles

### Encapsulation
Class internals are hidden and accessed through public methods (getters/setters, actions).
This prevents accidental misuse of internal state and makes refactoring easier.

### Abstraction
Common behaviors are modeled through interfaces / base classes (e.g., `Car`), allowing
higher-level code to work with general concepts rather than concrete implementations.

### Polymorphism
Cars can be handled through a base `Car` type, enabling multiple car implementations
(e.g., `StandardCar`, future `ComfortCar`, `ElectricCar`) without changing the client code.

### Single Responsibility Principle (SRP)
Each class has a well-defined responsibility:
- `Menu` → UI interaction
- `RideManager` → business logic for ride creation
- `App` → state ownership and lifecycle
- Entity classes → model data and behaviors for the domain

---

## 🔍 Code Quality

### Static Analysis (cppcheck)
The project can be checked with **cppcheck** (often via GitHub Actions) to detect:
- style issues
- potential bugs
- suspicious code patterns

Warnings such as `unusedFunction` are style warnings. They can be handled by:
- using the functions in application logic or tests
- marking them with `[[maybe_unused]]`
- adding suppressions in cppcheck configuration if needed

### Clean Code Practices
- Clear separation between headers (`include/`) and sources (`src/`)
- Input validation in the menu to avoid invalid states
- Exceptions are handled gracefully during ride creation






