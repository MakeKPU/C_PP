#pragma once

class EvenSequence
{
public:
	EvenSequence(initializer_list<double> args)
	{
		if (args.size() % 2 != 0)
		{
			throw invalid_argument("initialzer_list should "
				"contain even number of elements.");
		}
		mSequence.reserve(args.size());
		for (auto value : args)
		{
			mSequence.push_back(value);
		}
	}
	void dump() const
	{
		for (auto value : mSequence)
		{
			cout << value << ", ";
		}
		cout << endl;
	}
private:
	vector<double> mSequence;
	
};

