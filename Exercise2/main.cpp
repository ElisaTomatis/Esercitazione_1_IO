#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>

// funzione mapping [1,5] -> [-1,2]
double mapValue(double x)
{
	return -1.0+(x-1.0)*(3.0/4.0);
}


int main()
{
	std::ifstream fstr;
	fstr.open("data.txt");
	
	if (fstr.fail())
	{
		std::cerr << "non è stato possibile aprire il file" << std::endl;
		return 1;
	}
	
	// output
	std::ofstream outputFile("result.txt");
	
	if (outputFile.fail())
	{
		std::cerr << "non è stato possibile creare il file result.txt" << std::endl;
		return 1;
	}
	
	// intestazione file 
	outputFile << "# N Mean \n";
	
	double value;
	double number;
	double sum = 0.0;
	unsigned int i = 1;
	
	while(fstr >> number)
	{
		value = mapValue(number);
		sum += value;
		double mean = sum/(i);
		
		outputFile << (i) << " " << std::scientific << std::setprecision(16) << mean << "\n";
        i += 1;		
		
	}
	
	fstr.close();
	outputFile.close();
	
    return 0;
}
