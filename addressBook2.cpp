#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
#include<string>
using namespace std;

//Person Class
class Person{
      private:
      //Data
      char* firstName;
      char* lastName;
      
      public:
      //Member Methods
      void setLastName(char*);
      char* getLastName();
      void setFirstName(char*);
      char* getFirstName();
      //Constructor
      Person();
       
      //Destructor
      ~Person();
};

//Friend Class
class Friend : public Person{
       private:
       //Data
       char* homePhone;
       char* cellPhone;
       
       public:
       //Member Methods
       void setHomePhone(char*);
       char* getHomePhone();
       void setCellPhone(char*);
       char* getCellPhone();
       
       //Constructor
       Friend();
       
       //Destructor
       ~Friend();
};
  
//PersonalFriend Class       
class PersonalFriend : public Friend{
      private:
      //Data
      char* email;
      
      public:
      //Member Methods
      void setEmail(char*);
      char* getEmail();
      
      //Constructor
       PersonalFriend();
       
       //Destructor
       ~PersonalFriend();
};
       
//Structure Methods
       int searchFriend(PersonalFriend*, char*, int);
       void searchFriends(PersonalFriend*, char*, int, int*);
       void addFriend(PersonalFriend*, int);
       void delFriend(PersonalFriend*, int, int);
       void showFriend(PersonalFriend*, int);
       void showBook(PersonalFriend*, int);
       
//Person Constructor
Person::Person()
{      
}

//Person Destructor
Person::~Person()
{
                       delete[] firstName;
                       delete[] lastName;
}

//Friend Constructor
Friend::Friend()
{      
}

//Friend Destructor
Friend::~Friend()
{
                       delete[] homePhone;
                       delete[] cellPhone;
}

//PersonalFriend Constructor
PersonalFriend::PersonalFriend()
{      
}

//PersonalFriend Destructor
PersonalFriend::~PersonalFriend()
{
                       delete[] email;
}

       
//Set the Last Name
void Person::setLastName(char* name)
{
     lastName = (char*) calloc(strlen(name), sizeof(char));
     if (lastName == NULL)
     {
                     printf("Out of memory");
     }
     else
     {   
                    strcpy(lastName, name); 
     }
}
     
//Get Last Name
char* Person::getLastName()
{
      return lastName;
}
      
// Set First Name
void Person::setFirstName(char* name)
{
     firstName = (char*) calloc(strlen(name), sizeof(char));
     if (firstName == NULL)
     {
                     printf("Out of memory");
     }
     else
     {  
                    strcpy(firstName, name); 
     }
}
     
//Get First Name     
char* Person::getFirstName()
{
      return firstName;
}

//Set Home Phone Number
void Friend::setHomePhone(char* name)
{
     homePhone = (char*) calloc(strlen(name), sizeof(char));
     if (homePhone == NULL)
     {
                     printf("Out of memory");
     }
     else
     {     
                    strcpy(homePhone, name); 
     }
}

//Get Home Phone Number
char* Friend::getHomePhone()
{
      return homePhone;
}

//Set Cell Phone Number
void Friend::setCellPhone(char* name)
{
     cellPhone = (char*) calloc(strlen(name), sizeof(char));
     if (cellPhone == NULL)
     {
                     printf("Out of memory");
     }
     else
     {     
                    strcpy(cellPhone, name); 
     }
}

//Get Cell Phone Number
char* Friend::getCellPhone()
{
      return cellPhone;
}

//Set email
void PersonalFriend::setEmail(char* name)
{
     email = (char*) calloc(strlen(name), sizeof(char));
     if (email == NULL)
     {
                     printf("Out of memory");
     }
     else
     {     
                    strcpy(email, name); 
     }
}

//Get email
char* PersonalFriend::getEmail()
{
      return email;
}

//Structure Functions

//Search Friend
int searchFriend(PersonalFriend* fr, char* name, int arrayLength)
{
    int i;
    for (i = 0; i < arrayLength;i++)
    {
        if (strcmp(fr[i].getLastName(),name) == 0)
        {
           return i;
        }
    }
    return -1;
}

//Search Friends
void searchFriends(PersonalFriend* fr, char* name, int arrayLength, int* indices)
{
    int i, j = 0;
    for (i = 0; i < arrayLength; i++)
    {
        if (strcmp(fr[i].getLastName(),name) == 0)
        {
           indices[j] = i;
           j++;
        }
    }
}

//Add Friend
void addFriend(PersonalFriend* fr, int i)
{
     char* buffer;
     buffer = (char*) calloc(80, sizeof(char));
     
     if (buffer == NULL)
              {
                     printf("Out of memory");
              }
              else
              {                             
                 //First Name
                 printf("\nFirst Name: ");
                 scanf("%s", buffer);
                 fr[i].setFirstName(buffer);
                 
                 //Last Name
                 printf("\nLast Name: ");
                 scanf("%s", buffer);
                 fr[i].setLastName(buffer);
                 
                 //Home Phone
                 printf("\nHome Phone: ");
                 scanf("%s", buffer);
                 fr[i].setHomePhone(buffer);   
                 
                 //Cell Phone
                 printf("\nCell Phone: ");
                 scanf("%s", buffer);
                 fr[i].setCellPhone(buffer);
                 
                 //Email
                 printf("\nEmail: ");
                 scanf("%s", buffer);
                 fr[i].setEmail(buffer);
              }
}

//Delete Friend
void delFriend(PersonalFriend* fr, int i, int arrayLength)
{
     int j;
     for (j = i; j < arrayLength;j++)
     {
        fr[j].setFirstName(fr[j+1].getFirstName());
        fr[j].setLastName(fr[j+1].getLastName());
        fr[j].setHomePhone(fr[j+1].getHomePhone());
        fr[j].setCellPhone(fr[j+1].getCellPhone());
        fr[j].setEmail(fr[j+1].getEmail());
     }
}

//Show Friend
void showFriend(PersonalFriend* fr, int i)
{
     printf("\n\n%s %s \nHome# %s Cell# %s \nEmail %s", fr[i].getFirstName(), fr[i].getLastName(), fr[i].getHomePhone(), fr[i].getCellPhone(), fr[i].getEmail());
}

//Show Phone Book
void showBook(PersonalFriend* fr, int arrayLength)
{
     int i;
     for (i = 0; i < arrayLength; i++)
     {
        showFriend(fr, i);
     }
}
       
//Main Method
main()
{
    
     //Declaring variables
     int selection, i = -1, arrayLength = 0, choice = 0;
     int* indices = (int*) calloc(arrayLength, sizeof(int));
     PersonalFriend* fr = (PersonalFriend*) calloc(0, sizeof(PersonalFriend));
     char name[25];
     char fileName[20];
     char hPhone[10];
     char fName[10];
     char lName[10];
     char cPhone[10];
     char email[10];
     FILE* write;
     FILE* read;
     
     //Asking for File
     printf("Do you wish to load a file? Press 1 for yes, or any other digit for no: ");
     scanf("%d", &choice);
     
     if (choice == 1)
     {
                printf("Enter filename: ");
                scanf("%s", fileName);
                read = fopen(fileName, "r");
                
                if (read)
                {
                         while (!feof(read))
                         {
                         fscanf(read, "%s %s %s %s %s", fName, lName, hPhone, cPhone, email);
                         fr = (PersonalFriend*) realloc(fr, (arrayLength+1) * sizeof(PersonalFriend));
                         if (fr == NULL)
                         {
                                printf("Out of memory ");
                         }
                         else
                         {     
                               fr[arrayLength].setFirstName(fName);
                               fr[arrayLength].setLastName(lName);
                               fr[arrayLength].setHomePhone(hPhone);
                               fr[arrayLength].setCellPhone(cPhone);
                               fr[arrayLength].setEmail(email);
                               arrayLength++;  
                         }
                         }
                         arrayLength--;                   
                }
                else
                {
                    printf("File not found ");
                }               
     }
     
     while (selection != 6){
     
     selection = 0;
     
     //Menu Options
     printf("\n Phone Book Application");
     printf("\n 1) Add Friend");
     printf("\n 2) Delete Friend");
     printf("\n 3) Show a Friend");
     printf("\n 4) Search Friends");
     printf("\n 5) Show Phone book");
     printf("\n 6) Quit");
     printf("\n Please choose an option by pressing the corresponding number: ");
     scanf("%d", &selection);
     
     //Add Friend
     if (selection == 1)
     {   
              //Error-Checking Memory     
              fr = (PersonalFriend*) realloc(fr, (arrayLength+1) * sizeof(PersonalFriend));
              if (fr == NULL)
              {
                     printf("Out of memory");
              }
              else
              {     
                    addFriend(fr, arrayLength);
                    arrayLength++;  
              }   
     }       
            
     //Delete Friend
     else if (selection == 2)
     {
               printf("\nEnter the last name of the friend you wish to delete: ");
               scanf("%s", name);
               i = searchFriend(fr, name, arrayLength);
               
               if(i == -1)
               {
                    printf("The friend was not found");
               }
               else
               {
                   arrayLength--;
                   delFriend(fr, i, arrayLength);  
                   free(fr);
               }
     }  
            
     //Show Friend
     else if (selection == 3)
     {
               printf("\nEnter the last name of the friend you wish to show: ");
               scanf("%s", name);
               i = searchFriend(fr, name, arrayLength);
               
               if(i == -1)
               {
                    printf("The friend was not found");
               }
               else
               {
                   showFriend(fr, i);  
               }    
     }
     
     //Search Friends
     else if (selection == 4)
     {
               printf("\nEnter the last name of the friends you wish to show: ");
               scanf("%s", name);
               i = searchFriend(fr, name, arrayLength);
               
               if(i == -1)
               {
                    printf("The friend was not found");
               }
               else
               {
                   indices = (int*) realloc(indices, (arrayLength) * sizeof(int));
                   if (indices == NULL)
                   {
                               printf("Out of memory");
                   }
                   else
                   {
                       searchFriends(fr, name, arrayLength, indices);
                       int counter;
                       for (counter  = 0; counter < arrayLength, indices[counter] < arrayLength; counter++)
                       {
                           if(counter == 0 || indices[counter] != 0)
                           {
                                      showFriend(fr, indices[counter]);
                                      indices[counter] = 0;
                           }
                       }
                   } 
               }    
     }   
            
     //Show Phone Book
     else if (selection == 5)
     {
               showBook(fr, arrayLength);    
     }  
            
     //Quit
     else if (selection == 6)
     {
               printf("Do you wish to save contents in a file? Press 1 for yes or any other digit for no: ");
               scanf("%d", &choice);
               
               if (choice == 1)
               {
                          printf("Please enter a filename: ");
                          scanf("%s", fileName); 
                          write = fopen(fileName, "w");
                          if (write)
                          {
                                    int count;
                                    for (count = 0; count < arrayLength; count++)
                                    {                           
                                    fprintf(write, "%s %s %s %s %s ", fr[count].getFirstName(), fr[count].getLastName(), fr[count].getHomePhone(), fr[count].getCellPhone(), fr[count].getEmail());
                                    }
                                    
                          }
                          else
                          {
                              printf("File could not be opened, no data was saved ");
                          }                                    
               }   
     }  
            
     //Invalid Menu Value
     else
     {
               printf("Please choose valid menu option\n");
     }
     
     }
}  
