//뉴에이지 기술을 이용해서 온도를 예측하고, 목성에서 화성 사이의 거리를 기반으로 날씨를
//예측한다. 심지어 그러한 값이 제공되지 않아도 날씨를 예측할 수 있다.
//단, 그 경우에는 정확도가 99%밖에 안 된다.
#pragma once

class WeatherPrediction
{
public:
	WeatherPrediction() = default;
	//버추얼 소멸자
	virtual ~WeatherPrediction();
	//현재 온도를 화씨 단위로 세팅한다.
	virtual void setCurrentTempFahrenheit(int inTemp);
	//목성과 화성의 사이의 거리를 세팅한다.
	virtual void setPositionOfJupiter(int inDistanceFromMars);
	//내일의 온도 예측 결과를 리턴한다.
	virtual int getTomorrowTempFahrenheit() const;
	//내일 비가 올 확률을 얻는다. 리턴값 1은 내일 반드시 비가 온다는 의미고,
	//리턴값 0은 비가 오지 않는다는 의미다.
	virtual double getChanceOfRain() const;
	//아래 포맷으로 날씨 예측 결과를 출력한다.
	//Result: x.xx chance. Temp. xx
	virtual void showResult() const;
	//온도 예측 결과를 문자열로 리턴한다.
	virtual std::string getTemperature() const;
private:
	int mCurrentTempFahrenheit;
	int mDistanceFromMars;
};

