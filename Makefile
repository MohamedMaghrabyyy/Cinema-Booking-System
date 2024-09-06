exec: App.o Credit.o Movie.o NotARobot.o Debit.o Paypal.o SMS.o Seats.o Cinema.o Ticket.o main.o
	g++ App.o Credit.o Movie.o NotARobot.o Debit.o Paypal.o SMS.o Seats.o Cinema.o Ticket.o main.o -o exec

%.o: %.cpp
	g++ -c $<

clean:
	rm -f *.o exec
