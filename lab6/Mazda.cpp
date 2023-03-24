#include "Mazda.h"

const char* Mazda::Name() const {
	return "Mazda";
}

unsigned int Mazda::FuelCapacity() const {
	return m_fuelCapacity;
}

double Mazda::FuelConsumption() const {
	return m_fuelConsumption;
}

unsigned int Mazda::Speed(Weather weather) const {
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