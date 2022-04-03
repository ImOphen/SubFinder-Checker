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
<img width="885" alt="image" src="https://user-images.githubusercontent.com/43254081/161425513-cd0cd3ed-3f8a-46f1-8795-7da3b9196cc0.png">  
Command Example :  
<img width="883" alt="image" src="https://user-images.githubusercontent.com/43254081/161425485-96724a07-59e0-40c6-8280-71364cb9b9ae.png">  
domains_result.txt file:  
<img width="880" alt="image" src="https://user-images.githubusercontent.com/43254081/161425548-f8bf6258-77b6-4893-88ad-4a122ef38ea1.png">  

