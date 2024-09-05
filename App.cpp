#include "App.h"

void App::run() {
    createInitialData();

    while (true) {
        UserC user("", "", "");
        bool validLogin = false;

        while (!validLogin) {
            int choice;
            cout << "1. Login\n"
                 << "2. Create an account\n"
                 << "3. Exit\n"
                 << "Choose an option: ";
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case 1:
                    validLogin = loginUser(user);
                    if (!validLogin) {
                        cout << "Invalid email. Please try again." << endl;
                    }
                    break;
                case 2:
                    createAccount(user);
                    validLogin = true; 
                    break;
                case 3:
                    cout << "Exiting application." << endl;
                    return;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        }

        while (true) {
            int action;
            cout << "1. View all movies\n"
                 << "2. View all showtimes\n"
                 << "3. Book a showtime\n"
                 << "4. Logout\n"
                 << "Choose an action: ";
            cin >> action;
            cin.ignore();

            switch (action) {
                case 1:
                    cout << cinema->viewMovies() << endl;
                    break;
                case 2:
                    cout << cinema->viewAllShowtimes() << endl;
                    break;
                case 3:
                    bookShowtime(user);
                    break;
                case 4:
                    cout << "Logging out..." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }

            if (action == 4) {
                break;
            }
        }
    }
}

bool App::loginUser(UserC& user) {
    string email;
    cout << "Enter your email: ";
    getline(cin, email);

    for (const auto& u : cinema->getUsers()) {
        if (u.getMail() == email) {
            user = u;
            cout << "Logged in successfully!" << endl;
            return true;
        }
    }
    return false;
}

void App::createAccount(UserC& user) {
    string name, phone, email;
    cout << "Enter your email: ";
    getline(cin, email); 

    cout << "Enter your name: ";
    getline(cin, name); 

    cout << "Enter your phone number: ";
    getline(cin, phone);

    user = UserC(name, email, phone);
    cinema->AddUser(user);
    cout << "Account created successfully!" << endl;
}

void App::bookShowtime(UserC& user) {
    string movieTitle;
    cout << "Enter the movie title you want to book: ";
    getline(cin, movieTitle);  

    vector<ShowTime> showtimes = cinema->viewShowtimes(movieTitle);
    if (showtimes.empty()) {
        cout << "No showtimes found for this movie." << endl;
        return;
    }

    cout << "Available showtimes:" << endl;
    for (size_t i = 0; i < showtimes.size(); ++i) {
        cout << i + 1 << ". Movie: " << showtimes[i].getMovie().GetTitle()
             << ", Day: " << static_cast<int>(showtimes[i].getDay())
             << ", Time: " << static_cast<int>(showtimes[i].getTime())
             << ", Hall: " << showtimes[i].getHall().getName() << endl;
    }

    int choice;
    cout << "Select a showtime by number: ";
    cin >> choice;
    cin.ignore(); 
    if (choice < 1 || choice > showtimes.size()) {
        cout << "Invalid choice." << endl;
        return;
    }

    ShowTime selectedShowtime = showtimes[choice - 1];
    
    int displayChoice;
    cout << "1. Display available seats\n"
         << "2. Proceed to reserve a seat\n"
         << "Choose an option: ";
    cin >> displayChoice;
    cin.ignore();  

    if (displayChoice == 1) {
        cout << "Displaying available seats:" << endl;
        selectedShowtime.getSeats().displaySeats();
    } else if (displayChoice != 2) {
        cout << "Invalid choice. Exiting seat reservation." << endl;
        return;
    }

    string seatLabel;
    cout << "Enter the seat you want to reserve: ";
    getline(cin, seatLabel); 

    if (!const_cast<Seats&>(selectedShowtime.getSeats()).reserveSeat(seatLabel)) {
        cout << "Failed to reserve seat." << endl;
        return;
    }

    string paymentMethod;
    cout << "Select payment method (stored/new): ";
    getline(cin, paymentMethod);

    Payment* payment = nullptr;
    if (paymentMethod == "stored") {
        payment = const_cast<Payment*>(user.getPaymentMethod());
    } else if (paymentMethod == "new") {
        string methodType;
        cout << "Enter payment method type (credit/debit/paypal): ";
        getline(cin, methodType); 

        if (methodType == "credit") {
            payment = new Credit("123456", new SMS("123-456-7890"));
        } else if (methodType == "debit") {
            payment = new Debit("654321", new SMS("987-654-3210"));
        } else if (methodType == "paypal") {
            payment = new Paypal("user@example.com", new NotRobot());
        } else {
            cout << "Invalid payment method." << endl;
            return;
        }
        user.setPaymentMethod(payment);
    } else {
        cout << "Invalid payment choice." << endl;
        return;
    }

    cout << payment->processPayment() << endl;

    Ticket ticket(user.getName(), user.getMail(), selectedShowtime);
    user.addTicket(ticket);
    cout << "Booking confirmed. Ticket details:\n" << ticket.formulateTicket() << endl;
}




void App::createInitialData() {
    // Example data for halls
    cinema->AddHall(Hall("Hall 1", HallE::PREMIUM));
    cinema->AddHall(Hall("Hall 2", HallE::STANDARD));

    // Example data for movies
    cinema->AddMovie(MovieC("Movie", { MovieGenreE::ACTION, MovieGenreE::COMEDY }, 8.5));
    cinema->AddMovie(MovieC("Movie B", { MovieGenreE::DRAMA, MovieGenreE::THRILLER }, 7.2));
    cinema->AddMovie(MovieC("Movie C", { MovieGenreE::HORROR, MovieGenreE::ROMANCE }, 9.1));

    // Example data for showtimes
    cinema->AddShowTime(ShowTime(cinema->getMovies()[0], DayE::MONDAY, TimeE::SIX_PM, cinema->getHalls()[0]));
    cinema->AddShowTime(ShowTime(cinema->getMovies()[1], DayE::TUESDAY, TimeE::TWELVE_AM, cinema->getHalls()[1]));
    cinema->AddShowTime(ShowTime(cinema->getMovies()[2], DayE::WEDNESDAY, TimeE::NINE_AM, cinema->getHalls()[0]));
}
