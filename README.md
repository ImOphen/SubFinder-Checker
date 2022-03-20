# Subdomain-Finder-Checker


### Prerequisites
  subfinder -> you can install it on Kali linux with : 
  ```
    sudo apt update
    sudo apt install subfinder
   ```
  
------------------

This is a tool i made using C++, for learning purposes only, it relies on the **subfinder** tool to get a list of subdomains, and tries to ping them one by one, you will find the working subdomains in a file named **domains_result**

``usage :``
```git clone https://github.com/ImOphen/Subdomain-Finder-Checker
c++ subfinder-checker.cpp -o subfinder-checker 
./subfinder-checker -d DOMAIN.EXAMPLE -t TIME_OUT
```
![image](https://user-images.githubusercontent.com/43254081/159135493-0a73e5ba-4ec2-4484-a495-d1a1241b8191.png)
![image](https://user-images.githubusercontent.com/43254081/159135504-12331574-dc41-4a39-b337-bc27da60199b.png)
