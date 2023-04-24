#pragma once

#include "Car.h"
#include "Weather.h"
#include "Volvo.h"
#include "BMW.h"
#include "Seat.h"
#include "RangeRover.h"
#include "Fiat.h"

#include <iostream>

class Circuit {
private:
	bool m_hasRaced; //if ShowFinalRanks and ShowNotFinish are called before race it's gonna say "Race hasn't started yet!"
	unsigned int m_length;
	Weather m_weather;
	Car* m_cars[64]; //presupunem si noi ca nu se pot inscrie un numar prea mare de masini intr-o cursa
	double m_results[64];
	size_t m_carsCount;

	size_t m_finishedCars[64]; //indexele masinilor cu rezultate ok
	size_t m_finishedCount; //count of above ^

	size_t m_nonFinishedCars[64]; //indexele masinilor care n au terminat
	size_t m_nonFinishedCount; //count of above ^

	void sortFinishedCars();
public:
	Circuit();
	void SetLength(unsigned int length);
	void SetWeather(Weather weather);
	void AddCar(Car* car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};