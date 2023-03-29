#include "BMW.h"

const char* BMW::Name() const {
	return "BMW";
}

unsigned int BMW::FuelCapacity() const {
	return m_fuelCapacity;
}

double BMW::FuelConsumption() const {
	return m_fuelConsumption;
}

unsigned int BMW::Speed(Weather weather) const {
	switch (weather) {
	case Weather::Sunny:
		return m_maxSpeed;
		break;
	case Weather::Rain:
		return 85 * m_maxSpeed / 100;
		break;
	case Weather::Snow:
		return 57 * m_maxSpeed / 100;
		break;
	default:
		return m_maxSpeed;
	}
}