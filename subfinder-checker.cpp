#include <iostream>
#include <fstream>

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */

int timeout_define(char *argv[])
{
	int i = 0;
	int count = 0;
	while (argv[i])
	{
		std::string argvi = argv[i];
		if (argvi == "-t" && argv[i + 1])
			return (std::atoi(argv[i + 1]));
		i++;	
	}
	return 5;
}

std::string domain_define(char *argv[])
{
	int i = 0;
	while (argv[i])
	{
		std::string argvi = argv[i];
		if (argvi == "-d" && argv[i + 1])
			return (argv[i + 1]);
		i++;	
	}
	return "NULL";
}

void help_command(char *argv[])
{
	int i = 0;
	while (argv[i])
	{
		std::string argvi = argv[i];
		if (argvi == "-h")
		{
			std::cout << "Usage of subfinder-checker : " << std::endl << std::endl;
			std::cout << "	-d domain :" << std::endl;
			std::cout << "		Domain to find subdomains for" << std::endl;
			std::cout << "	-t time :" << std::endl;
			std::cout << "		Specify a timeout for the checks in seconds" << std::endl;
			std::cout << "	-h:" << std::endl;
			std::cout << "		Display this help message" << std::endl << std::endl;
			exit(0);
		}
		i++;	
	}
}

void header(void)
{
	std::cout << YELLOW << " ___  __  __  ____      ____  ____  _  _  ____  ____  ____     ___  _   _  ____  ___  _  _  ____  ____ " << std::endl;
	std::cout << YELLOW <<  "/ __)(  )(  )(  _ \\ ___( ___)(_  _)( \\( )(  _ \\( ___)(  _ \\   / __)( )_( )( ___)/ __)( )/ )( ___)(  _ \\" << std::endl;
	std::cout << YELLOW << "\\__ \\ )(__)(  ) _ <(___))__)  _)(_  )  (  )(_) ))__)  )   /  ( (__  ) _ (  )__)( (__  )  (  )__)  )   /" << std::endl;
	std::cout << YELLOW << "(___/(______)(____/    (__)  (____)(_)\\_)(____/(____)(_)\\_)   \\___)(_) (_)(____)\\___)(_)\\_)(____)(_)\\_)" << std::endl;
	std::cout << std::endl << BLUE << "-   Made by Ophen :D    <|>   use -h to display the Help Message" << std::endl << std::endl << RESET;
}
int main(int argc, char *argv[])
{
	header();
	help_command(argv);
	std::fstream file;
	if (argc >= 2)
	{
		int timeout_time = timeout_define(argv);
		std::string domain = domain_define(argv);
		if (domain == "NULL" || domain.find(".") == std::string::npos)
		{	
			std::cout << RED << "Error: NO DOMAIN" << std::endl;
			return 1;
		}
		system(("subfinder -silent -d " + domain +  " > .tmp_domains").c_str());
		file.open(".tmp_domains", std::ios::in);
		if (file.is_open())
		{
			std::string subdomain;
			std::ofstream writeFile;
			writeFile.open("domains_result.txt", std::ios::out | std::ios::trunc);
			while(std::getline(file, subdomain))
			{
				int sys_ret = system(("ping -w" + std::to_string(timeout_time) +" -c1 -s1 " + subdomain + "  > /dev/null 2>&1").c_str());
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
		    return(std::cout << RED << "Error while opening file" << std::endl,1);
		}
	else 
	    return(std::cout << RED << "Error :: Arguments" << std::endl,1);
	return 0;
}
