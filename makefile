driver: driver.o Queue/QueueArray.o Simulation/BankCalculator.o Simulation/Customer.o
	g++ -std=c++11 driver.o Queue/QueueArray.o Simulation/BankCalculator.o Simulation/Customer.o -o driver

driver.o: driver.cpp
	g++ -std=c++11 driver.cpp -c

QueueArray.o: Queue/QueueArray.h Queue/QueueArray.cpp Queue/QueueInterface.h
	g++ -std=c++11 Queue/QueueArray.cpp -c

BankCalculator.o: Simulation/BankCalculator.h Simulation/BankCalculator.cpp
	g++ -std=c++11 Simulation/BankCalculator.cpp -c

Customer.o: Simulation/Customer.h Simulation/Customer.cpp
	g++ -std=c++11 Simulation/Customer.cpp -c

clean:
	rm driver

	rm driver.o
	rm Queue/QueueArray.o
	rm Simulation/BankCalculator.o
	rm Simulation/Customer.o