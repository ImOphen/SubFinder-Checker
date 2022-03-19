#include <iostream>
#include <fstream>

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */

int main(int argc, char *argv[])
{
	std::fstream file;
	if (argc == 2)
	{
		std::string domain = argv[1];
		if (domain.find(".") == std::string::npos)
		{	
			std::cout << "Error" << std::endl;
			return 1;
		}
		system(("subfinder -d " + domain +  " > .tmp_domains").c_str());
		file.open(".tmp_domains", std::ios::in);
		if (file.is_open())
		{
			std::string subdomain;
			std::ofstream writeFile;
			writeFile.open("domains_result", std::ios::out | std::ios::trunc);
			while(std::getline(file, subdomain))
			{
				int sys_ret = system(("ping -w3 -c1 -s1 " + subdomain + "  > /dev/null 2>&1").c_str());
				if (sys_ret == 0)
				{    
					writeFile << subdomain << std::endl;
					std::cout << GREEN << subdomain << std::endl;
				}
				else
					std::cout << RED << subdomain << std::endl;
			}
			std::cout << RESET;
			system("rm -rf .tmp_domains");
		}
		else
		    return(std::cout << "Error while opening file" << std::endl,1);
		}
	else 
	    return(std::cout << "Error :: Arguments" << std::endl,1);
	return 0;
}
