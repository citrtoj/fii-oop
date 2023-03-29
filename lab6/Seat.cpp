#include "Seat.h"

const char* Seat::Name() const {
	return "Seat";
}

unsigned int Seat::FuelCapacity() const {
	return m_fuelCapacity;
}

double Seat::FuelConsumption() const {
	return m_fuelConsumption;
}

unsigned int Seat::Speed(Weather weather) const {
	switch (weather) {
	case Weather::Sunny:
		return m_maxSpeed;
		break;
	case Weather::Rain:
		return 89 * m_maxSpeed / 100;
		break;
	case Weather::Snow:
		return 74 * m_maxSpeed / 100;
		break;
	default:
		return m_maxSpeed;
	}
}