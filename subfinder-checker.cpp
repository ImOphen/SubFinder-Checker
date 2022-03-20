#include <iostream>
#include <fstream>
#include <thread>

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */

int timeout_define(char *argv[])
{
	int i = 0;
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
		if ((argvi == "-d" || argvi == "-dl") && argv[i + 1])
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
			std::cout << "	-dl file :" << std::endl;
			std::cout << "		File containing list of domains to enumerate and check" << std::endl;
			std::cout << "	-t seconds :" << std::endl;
			std::cout << "		Specify a timeout for the checks | Default : 5" << std::endl;
			std::cout << "	-o output :" << std::endl;
			std::cout << "		Specify in which file the program will output" << std::endl;
			std::cout << "		default : domains_result.txt" << std::endl;
			std::cout << "	-h:" << std::endl;
			std::cout << "		Display this help message" << std::endl;
			std::cout << "	-s:" << std::endl;
			std::cout << "		Silent : doesn't display the header message" << std::endl;
			std::cout << "	-ss:" << std::endl;
			std::cout << "		Super Silent : doesn't display the header message" << std::endl;
			std::cout << "		and the output" << std::endl << std::endl;
			exit(0);
		}
		i++;	
	}
}

void header(char *argv[])
{
	int i = 0;
	while (argv[i])
	{
		std::string argvi = argv[i];
		if (argvi == "-s" || argvi == "-ss")
			return;
		i++;
	}
	std::cout << YELLOW << " ___  __  __  ____      ____  ____  _  _  ____  ____  ____     ___  _   _  ____  ___  _  _  ____  ____ " << std::endl;
	std::cout << YELLOW <<  "/ __)(  )(  )(  _ \\ ___( ___)(_  _)( \\( )(  _ \\( ___)(  _ \\   / __)( )_( )( ___)/ __)( )/ )( ___)(  _ \\" << std::endl;
	std::cout << YELLOW << "\\__ \\ )(__)(  ) _ <(___))__)  _)(_  )  (  )(_) ))__)  )   /  ( (__  ) _ (  )__)( (__  )  (  )__)  )   /" << std::endl;
	std::cout << YELLOW << "(___/(______)(____/    (__)  (____)(_)\\_)(____/(____)(_)\\_)   \\___)(_) (_)(____)\\___)(_)\\_)(____)(_)\\_)" << std::endl;
	std::cout << std::endl << BLUE << "-   Made by Ophen :D    <|>   use -h to display the Help Message" << std::endl << std::endl << RESET;
}

std::string RandomString(std::size_t len)
{
	srand(time(0));
	std::string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	std::string newstr;
	int pos;
	while(newstr.size() != len)
	{
		pos = ((rand() % (str.size() - 1)));
		newstr += str.substr(pos,1);
	}
	return newstr;
}

int supersilent(char *argv[])
{
	int i = 0;
	while (argv[i])
	{
		std::string argvi = argv[i];
		if (argvi == "-ss")
			return 1;
		i++;
	}
	return 0;
}

std::string outputfile_finder(char *argv[])
{
	int i = 0;
	while (argv[i])
	{
		std::string argvi = argv[i];
		if (argvi == "-o" && argv[i + 1])
			return (argv[i + 1]);
		i++;	
	}
	return "domains_result.txt";
}

int dl(char *argv[])
{
	int i = 0;
	while (argv[i])
	{
		std::string argvi = argv[i];
		if (argvi == "-dl" && argv[i + 1])
			return 1;
		i++;	
	}
	return 0;
}

void run_checks(int &timeout_time, std::string &subdomain, std::ofstream &writeFile, int &super_silent)
{
	int sys_ret = system(("ping -w" + std::to_string(timeout_time) +" -c1 -s1 " + subdomain + "  > /dev/null 2>&1").c_str());
	if (sys_ret == 0)
	{    
		writeFile << subdomain << std::endl;
		if (!super_silent)
			std::cout << GREEN << subdomain << std::endl;
	}
	else
		if (!super_silent)
			std::cout << RED << subdomain << std::endl;
}

int main(int argc, char *argv[])
{
	header(argv);
	help_command(argv);
	std::fstream file;
	int super_silent = supersilent(argv);
	std::string outputfile = outputfile_finder(argv);
	if (argc >= 2)
	{
		int timeout_time = timeout_define(argv);
		if (!timeout_time)
			return(std::cout << RED << "Error: Invalid timeout value" << std::endl, 1);
		std::string domain = domain_define(argv);
		std::string tmpfile = "." + RandomString(10);
		if (domain == "NULL")	
			return(std::cout << RED << "Error: NO DOMAIN" << std::endl, 1);
		if ((dl(argv) && system(("subfinder -silent -dL " + domain +  " > " + tmpfile).c_str()))
			|| (!dl(argv) && system(("subfinder -silent -d " + domain +  " > " + tmpfile).c_str())))
			return (system(("rm -rf " + tmpfile).c_str()), 1);
		file.open(tmpfile, std::ios::in);
		if (file.is_open())
		{
			std::string subdomain;
			std::ofstream writeFile;
			writeFile.open(outputfile, std::ios::out | std::ios::trunc);
			if (writeFile.is_open())
			{
				while(std::getline(file, subdomain))
					run_checks(timeout_time, subdomain, writeFile, super_silent);
				std::cout << RESET;
				system(("rm -rf " + tmpfile).c_str());
			}
			else
		    	return(std::cout << RED << "Error while opening file" << std::endl,1);
		}
		else
		    return(std::cout << RED << "Error while opening file" << std::endl,1);
		}
	else 
	    return(std::cout << RED << "Error : Arguments" << std::endl,1);
	return 0;
}
