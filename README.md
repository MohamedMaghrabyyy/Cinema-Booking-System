# Cinema Management System

## Overview

The Cinema Management System is a C++ application designed to manage cinema operations, including movie scheduling, seat reservations, and user account management. This system allows users to view movies, book tickets, and manage their accounts.

## Features

- **User Account Management**: Create accounts, log in, and manage user profiles.
- **Movie Management**: View a list of movies available in the cinema.
- **Showtime Management**: View and book showtimes for movies.
- **Seat Reservation**: View and reserve seats for selected showtimes.
- **Payment Processing**: Handle payments using different methods (credit, debit, PayPal).

## Project Structure

- `App.cpp`: Main application logic for handling user interaction and system operations.
- `Seats.cpp` / `Seats.h`: Manages seat reservations and displays seat availability.
- `UserC.cpp` / `UserC.h`: Handles user account information and interactions.
- `Ticket.cpp` / `Ticket.h`: Manages ticket details and reservations.
- `Payment.cpp` / `Payment.h`: Handles different payment methods.
- `ShowTime.cpp` / `ShowTime.h`: Manages movie showtimes and associated seats.
- `CinemaC.cpp` / `CinemaC.h`: Manages the overall cinema operations, including movies, halls, and showtimes.

## Getting Started

### Prerequisites

- C++ compiler (e.g., g++, clang++)
- C++ Standard Library

### Building the Project

1. Clone the repository:

    ```bash
    git clone https://github.com/MohamedMaghrabyyy/Cinema-Managment-System.git
    ```

2. Navigate to the project directory:

    ```bash
    cd Cinema-Managment-System
    ```

3. Compile the project using a C++ compiler:

    ```bash
    g++ -o cinema_management_system *.cpp
    ```

### Running the Application

After compiling, run the application:

```bash
./cinema_management_system
