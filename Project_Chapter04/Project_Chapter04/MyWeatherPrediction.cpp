#include "pch.h"
#include "MyWeatherPrediction.h"

void MyWeatherPrediction::setCurrentTempCelsius(int inTemp)
{
	int fahrenheitTemp = convertCelsiusToFahrenheit(inTemp);
	setCurrentTempFahrenheit(fahrenheitTemp);
}

int MyWeatherPrediction::getTomorrowTempCelsius() const
{
	int fahrenheitTemp = getTomorrowTempFahrenheit();
	return convertFahrenheitToCelsius(fahrenheitTemp);
}

void MyWeatherPrediction::showResult() const
{
	cout << "Tomorrow's temperature will be " <<
		getTomorrowTempCelsius() << " degrees Celsuis (" <<
		getTomorrowTempFahrenheit() << " degrees Fahrenheit)" << endl;
	cout << "Chance of rain is " << (getChanceOfRain() * 100) << " percent"
		<< endl;

	if (getChanceOfRain() > 0.5)
		cout << "Bring an umbrella!" << endl;
}

std::string MyWeatherPrediction::getTemperature() const
{
	// \u00B0는 ISO/IEC 10646 표준에 따라 온도를 나타내는 기호를 의미
	return WeatherPrediction::getTemperature() + "\u00B0"; 
	//버그!
	/*C++에서는 먼저 현재의 스코프, 그다음으로 클래스 스코프에서
	메서드 이름을 찾기 때문에 결국 getTemperature()호출은 
	MyWeatherPrediction::getTemperature() 호출과 같다.
	의도대로 작동하는 코드를 만들려면 스코프 지정 연산자를 사용해야 한다.
	
	NOTE : 마이크로소프트 비주얼 C++에서는 __super 키워드를 제공하여 명시적으로 
	부모이름을 지정하지 않아도 간편하게 부모의 메서드를 호출 할 수 있게 해준다.
	return __super::getTemperature() + "\u00B0F";
	*/
}

int MyWeatherPrediction::convertCelsiusToFahrenheit(int inCelsius)
{
	return 0;
}

int MyWeatherPrediction::convertFahrenheitToCelsius(int inFahrenheit)
{
	return 0;
}
