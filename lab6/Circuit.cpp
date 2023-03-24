#include "Circuit.h"

void Circuit::sortFinishedCars() {
	//for-in-for sorting. Does the job. Might replace in the future
	for (int i = 0; i < m_finishedCount - 1; ++i) {
		for (int j = i; j < m_finishedCount; ++j) {
			if (m_results[m_finishedCars[i]] > m_results[m_finishedCars[j]]) {
				size_t tmp = m_finishedCars[i];
				m_finishedCars[i] = m_finishedCars[j];
				m_finishedCars[j] = tmp;
			}
		}
	}
}

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
		if (m_cars[i]->FuelConsumption() * m_length / 100 > m_cars[i]->FuelCapacity()) {
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
	m_hasRaced = true;
	sortFinishedCars();
}

void Circuit::ShowFinalRanks() {
	if (!m_hasRaced) {
		std::cout << "No race has been initiated yet!\n";
		return;
	}
	std::cout << "\nLeaderboard:\n";
	for (int i = 0; i < m_finishedCount; ++i) {
		std::cout << m_cars[m_finishedCars[i]]->Name() << ": " << m_results[m_finishedCars[i]] << " hours, or " << m_results[m_finishedCars[i]] * 60 << " minutes\n";
	}
}

void Circuit::ShowWhoDidNotFinish() {
	if (!m_hasRaced) {
		std::cout << "No race has been initiated yet!\n";
		return;
	}
	std::cout << "\nCars that did not finish:\n";
	for (int i = 0; i < m_nonFinishedCount; ++i) {
		std::cout << m_cars[m_nonFinishedCars[i]]->Name() << "\n";
	}
}
