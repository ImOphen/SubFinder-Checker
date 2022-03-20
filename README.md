# Subdomain-Finder-Checker


### Prerequisites
  subfinder -> you can install it on Kali linux with : 
  ```
    sudo apt update
    sudo apt install subfinder
   ```
  
------------------

This is a tool i made using C++, for learning purposes only, it relies on the **subfinder** tool to get a list of subdomains, and tries to ping them one by one, you will find the working subdomains in a file named **domains_result.txt**
use -h to display the help message

``compilation :``
```git clone https://github.com/ImOphen/Subdomain-Finder-Checker
c++ subfinder-checker.cpp -o subfinder-checker 
```
Help Message :
![image](https://user-images.githubusercontent.com/43254081/159156936-e44f031b-5ea8-4ef1-adf7-b890e7be2faa.png)
Command Example :
![image](https://user-images.githubusercontent.com/43254081/159156351-08320016-dd66-4c1c-89dd-cebe2f966861.png)
Command Example with silent mode and using the default timeout:
![image](https://user-images.githubusercontent.com/43254081/159156986-7b427f1a-4823-4edd-97c0-86ce0ec3e4dc.png)
domains_result.txt file:
![image](https://user-images.githubusercontent.com/43254081/159156458-486ed425-7504-4ec3-88bd-def511513457.png)
