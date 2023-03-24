#include "Circuit.h"

Circuit::Circuit() :
	m_hasRaced(false),
	m_length(0),
	m_weather(Weather::Sunny),
	m_cars{ nullptr },
	m_carsCount(0),
	m_finishedCount(0),
	m_nonFinishedCount(0),
	m_finishedCars{ 0 },
	m_nonFinishedCars{ 0 }
{}

void Circuit::SetLength(unsigned int length) {
	m_length = length;
}


void Circuit::SetWeather(Weather weather) {
	m_weather = weather;
}

void Circuit::AddCar(Car* car) {
	m_cars[m_carsCount++] = car;
}

void Circuit::Race() {
	for (int i = 0; i < m_carsCount; ++i) {
		//calculam m_results[i]
		if (m_cars[i]->FuelConsumption() * m_length < m_cars[i]->FuelConsumption()) {
			m_results[i] = -1;
			m_nonFinishedCars[m_nonFinishedCount++] = i;
		}
		else {
			if (m_cars[i]->Speed(m_weather) == 0) {
				throw std::exception();
			}
			double result = (double)m_length / m_cars[i]->Speed(m_weather);
			m_results[i] = result;
			m_finishedCars[m_finishedCount++] = i;
		}
	}

	//sortFinishedCars();
}

void Circuit::ShowFinalRanks() {
	for (int i = 0; i < m_finishedCount; ++i) {
		std::cout << m_cars[m_finishedCars[i]]->Name() << " " << m_results[m_finishedCars[i]] << "\n";
	}
}

void Circuit::ShowWhoDidNotFinish() {
	for (int i = 0; i < m_nonFinishedCount; ++i) {
		std::cout << m_cars[m_nonFinishedCars[i]]->Name() << " " << m_results[m_nonFinishedCars[i]] << "\n";
	}
}
