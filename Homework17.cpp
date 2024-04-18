#include <iostream>
#include <string>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"

struct info_sir 
{
	size_t l_index{};
	size_t r_index{};
	bool is_palindrom;
};

//Functia ce verifica daca un sir de caractere este un palindrom
void is_palindrom(const std::string& input, info_sir& informatie)
{
	for (size_t i{}; i < input.size() / 2; i++)
	{
		//Daca intalnim caractere ce se afla pe pozitii simetrice si sunt diferite
		//atunci intoarcem false
		if (input.at(i) != input.at(input.size() - i - 1))
		{
			//Pastram indicii caracterelor ce difera
			informatie.l_index = i,
			informatie.r_index = input.size() - i - 1,
			informatie.is_palindrom = false;
			return;
		}
	}
	//Daca nu a fost returnat false, inseamna ca sirul este palindrom
	informatie.is_palindrom = true; 
}

int main()
{
	std::string input{}; 
	std::cout << "\tIntroduce sirul pe care doresti sa il verifici: "; 
	std::getline(std::cin, input); 
	std::cout << std::endl;

	info_sir info;
	is_palindrom(input, info); 

	if (info.is_palindrom) 
	{
		std::cout << YELLOW << "\tSirul este un palindrom!" << RESET << std::endl;
	}
	else
	{
		std::cout << RED << "\tSirul nu este un palindrom!" << RESET << std::endl;
		std::cout << "\t";

		//Afisarea sirului care a fost introdus
		//Caracterele pe pozitii simetrice care difera sunt afisate cu rosu
		for (size_t i{}; i < input.size(); i++)
		{
			if (i != info.r_index && i != info.l_index)
			{
				std::cout << YELLOW << input.at(i) << RESET;
			}
			else 
			{
				std::cout << RED << input.at(i) << RESET;
			}
		}
	}
	std::cout << std::endl;
	return 0;
}

