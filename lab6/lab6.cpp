#include "Circuit.h"

int main() {
	Circuit c;
	c.SetLength(600);
	c.SetWeather(Weather::Rain);
	c.AddCar(new Dacia());
	c.AddCar(new Ford());
	c.AddCar(new Mazda());
	c.AddCar(new Toyota());
	c.AddCar(new Mercedes());
	c.Race();
	c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
	c.ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit
	return 0;
}