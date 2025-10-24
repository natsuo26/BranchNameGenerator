# BranchNameGenerator
A command line tool to speed up the process of creating branch name and copy to clipboard based on JIRA/any issue item's name
## How to build?
This code should be build with MSVC++ v14 standard so preferably use Visual Studio to make a release build the project in solution once you have the .exe file you can choose to rename it to any name you are comfortable to type in your console when you want to use it e.g BNG.exe or branch.exe or you can leave it as it is and change the name later if want to
## How to Run?
To run follow the below steps after once the build is a success and you have the executable:
- So you need to move this file to any folder where you don't make many changes
- For example : C:\SystemVariables\BranchNameGenerator.exe (here a new folder SystemVariables is created by me to put all my executables there).
- Open System Properties by searching for "environment variables"  from global search in start
- Click on environment variables and then in the section (in bottom section) of system variables select on Variable with name Path and click on edit
- Click on "New" and add the path to your folder where your exe is located so in this example it will be "C:\SystemVariables\" or you can also browse it and then "OK" and "OK" and then once everything is saved 
- Now open a terminal and type the name of your .exe name and so the command will be  like: `<your exe name> <prefix> <JIRA issue name>` so it will be 
- e.g: ```BranchNameGenerator defect ISSUE-1453 this is a defect```
- expected o/p: defect/ISSUE-1453_this_is_a_defect 
- the output will be copied to your clipboard so you can close the terminal and directly go and paste it wherever you want to

