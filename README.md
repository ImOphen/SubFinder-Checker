# Subdomain-Finder-Checker


### Prerequisites
  subfinder -> you can install it on Kali linux with : 
  ```
    sudo apt update
    sudo apt install subfinder
   ```
  
------------------

This is a tool i made using C++, for learning purposes only, it relies on the **subfinder** tool to get a list of subdomains, and tries to ping them one by one, you will find the working subdomains in a file.
use -h to display the help message

``compilation :``
```git clone https://github.com/ImOphen/Subdomain-Finder-Checker
c++ subfinder-checker.cpp -o subfinder-checker 
```
``Usage :``  
Help Message :
![image](https://user-images.githubusercontent.com/43254081/159159793-eb903ddc-cef8-4404-8582-68507d9c804e.png)
Command Example :
![image](https://user-images.githubusercontent.com/43254081/159158959-4f83f665-83d2-4b2a-b95e-fe827ef01ab1.png)
Command Example with silent mode and using the default timeout:
![image](https://user-images.githubusercontent.com/43254081/159156986-7b427f1a-4823-4edd-97c0-86ce0ec3e4dc.png)
domains_result.txt file:
![image](https://user-images.githubusercontent.com/43254081/159156458-486ed425-7504-4ec3-88bd-def511513457.png)
