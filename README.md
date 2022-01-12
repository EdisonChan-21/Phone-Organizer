# Phone-Organizer
This assignment is about developing an application which can organize phone entries in a contact book which allow user to entry and store information of name, nickname, phone number, email address, last-call date and time. Moreover, users are allowed to store the entries under one of three groups specified by the user: Family, Friend or Junk. Also, the information of phone entries under a user-given group can be displayed or removed upon the user’s request. The application requires user login so that the contact book would not be allowed to use unless username with corresponding password is provided.

# Introduction
A phone organizer is an application that can organize phone entries in a contact book which help users to store the phone entries in a more systematic way. The contact book would consist of information of contacts that perform under groups, functions for entry and remove contacts and a login system.

Users could input and save Information consist of name, nickname, phone number, email address, last-call date and time. Information should be stored in the contact book after users input them. A class pEntry is required to realize for holding the information. 

The phone entries are stored under three groups: Family, Friend and Junk. The user can specify one of the three groups to store entries. A class pContactB is required to realize for holding a number of pEntry under three groups. The groups can be realized as an array of pEntry objects. And the size of each array is assigned to 100. 
Users can request the application to display the information of entries in one specified group. A function display() is used to display the contact information under one of the three groups specified by the user. Under display(), a for-loop is used to show all the phone entry. 

Users can request the application to display the number of valid elements in the array. A variable which store the number of valid elements of groups can is kept inside object pContactB. The size of each group is assigned to 100. If a contact is input by user, the number of valid elements should be minus one. 

Users can remove phone entries under specified group. User is required to input the phone number that is chosen to delete. After user have chosen, the memory of that corresponding phone number will be released. 

User need to login before start using the application. Username and password is required to type in before login. The program would read data from a file which is used to store username and password. If the username is new to the program, new password would be required to input and they would be saved in the file storing username and password. If the user input correct username but fails to provide the correct password in three consecutive trials, the application will end. 

The content of contact book should be saved into a file. The user should be able to read the content of current contact book from the file and store the information into three group arrays. Constructor is called by the program and read the content of the file and store the data into three groups.
