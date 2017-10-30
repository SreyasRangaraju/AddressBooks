#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
#include<string>
using namespace std;

//Phonebook Structure
class Phonebook{
       private:
       char* firstName;
       char* lastName;
       char* homePhone;
       char* cellPhone;
       
       public:
       //Member Methods
       void setLastName(Phonebook*, char*, int);
       char* getLastName(Phonebook*, int);
       void setFirstName(Phonebook*, char*, int);
       char* getFirstName(Phonebook*, int);
       void setHomePhone(Phonebook*, char*, int);
       char* getHomePhone(Phonebook*, int);
       void setCellPhone(Phonebook*, char*, int);
       char* getCellPhone(Phonebook*, int);
       
       //Constructor
       Phonebook();
       
       //Destructor
       ~Phonebook();
       };
       
//Structure Methods
       int searchFriend(Phonebook*, char*, int);
       void searchFriends(Phonebook*, char*, int, int*);
       void addFriend(Phonebook*, int);
       void delFriend(Phonebook*, int, int);
       void showFriend(Phonebook*, int);
       void showBook(Phonebook*, int);
       
//Constructor
Phonebook::Phonebook()
{      
}

//Destructor
Phonebook::~Phonebook()
{
                       delete[] firstName;
                       delete[] lastName;
                       delete[] homePhone;
                       delete[] cellPhone;
}

       
//Set the Last Name
void Phonebook::setLastName(Phonebook* fr, char* name, int i)
{
     fr[i].lastName = (char*) calloc(strlen(name), sizeof(char));
     if (fr[i].lastName == NULL)
     {
                     printf("Out of memory");
     }
     else
     {   
                    strcpy(fr[i].lastName, name); 
     }
}
     
//Get Last Name
char* Phonebook::getLastName(Phonebook* fr, int i)
{
      return fr[i].lastName;
}
      
// Set First Name
void Phonebook::setFirstName(Phonebook* fr, char* name, int i)
{
     fr[i].firstName = (char*) calloc(strlen(name), sizeof(char));
     if (fr[i].firstName == NULL)
     {
                     printf("Out of memory");
     }
     else
     {  
                    strcpy(fr[i].firstName, name); 
     }
}
     
//Get First Name     
char* Phonebook::getFirstName(Phonebook* fr, int i)
{
      return fr[i].firstName;
}

//Set Home Phone Number
void Phonebook::setHomePhone(Phonebook* fr, char* name, int i)
{
     fr[i].homePhone = (char*) calloc(strlen(name), sizeof(char));
     if (fr[i].homePhone == NULL)
     {
                     printf("Out of memory");
     }
     else
     {     
                    strcpy(fr[i].homePhone, name); 
     }
}

//Get Home Phone Number
char* Phonebook::getHomePhone(Phonebook* fr, int i)
{
      return fr[i].homePhone;
}

//Set Cell Phone Number
void Phonebook::setCellPhone(Phonebook* fr, char* name, int i)
{
     fr[i].cellPhone = (char*) calloc(strlen(name), sizeof(char));
     if (fr[i].cellPhone == NULL)
     {
                     printf("Out of memory");
     }
     else
     {     
                    strcpy(fr[i].cellPhone, name); 
     }
}

//Get Cell Phone Number
char* Phonebook::getCellPhone(Phonebook* fr, int i)
{
      return fr[i].cellPhone;
}

//Structure Functions

//Search Friend
int searchFriend(Phonebook* fr, char* name, int arrayLength)
{
    int i;
    for (i = 0; i < arrayLength;i++)
    {
        if (strcmp(fr[i].getLastName(fr, i),name) == 0)
        {
           return i;
        }
    }
    return -1;
}

//Search Friends
void searchFriends(Phonebook* fr, char* name, int arrayLength, int* indices)
{
    int i, j = 0;
    for (i = 0; i < arrayLength; i++)
    {
        if (strcmp(fr[i].getLastName(fr, i),name) == 0)
        {
           indices[j] = i;
           j++;
        }
    }
}

//Add Friend
void addFriend(Phonebook* fr, int i)
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
                 fr[i].setFirstName(fr, buffer, i);
                 
                 //Last Name
                 printf("\nLast Name: ");
                 scanf("%s", buffer);
                 fr[i].setLastName(fr, buffer, i);
                 
                 //Home Phone
                 printf("\nHome Phone: ");
                 scanf("%s", buffer);
                 fr[i].setHomePhone(fr, buffer, i);   
                 
                 //Cell Phone
                 printf("\nCell Phone: ");
                 scanf("%s", buffer);
                 fr[i].setCellPhone(fr, buffer, i);
              }
}

//Delete Friend
void delFriend(Phonebook* fr, int i, int arrayLength)
{
     int j;
     for (j = i; j < arrayLength;j++)
     {
        fr[j].setFirstName(fr, fr[j+1].getFirstName(fr, j+1), j);
        fr[j].setLastName(fr, fr[j+1].getLastName(fr, j+1), j);
        fr[j].setHomePhone(fr, fr[j+1].getHomePhone(fr, j+1), j);
        fr[j].setCellPhone(fr, fr[j+1].getCellPhone(fr, j+1), j);
     }
}

//Show Friend
void showFriend(Phonebook* fr, int i)
{
     printf("\n%s %s \nHome# %s Cell# %s", fr[i].getFirstName(fr, i), fr[i].getLastName(fr, i), fr[i].getHomePhone(fr, i), fr[i].getCellPhone(fr, i));
}

//Show Phone Book
void showBook(Phonebook* fr, int arrayLength)
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
     Phonebook* fr = (Phonebook*) calloc(0, sizeof(Phonebook));
     char name[25];
     char fileName[20];
     char hPhone[10];
     char fName[10];
     char lName[10];
     char cPhone[10];
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
                         fscanf(read, "%s %s %s %s", fName, lName, hPhone, cPhone);
                         fr = (Phonebook*) realloc(fr, (arrayLength+1) * sizeof(Phonebook));
                         if (fr == NULL)
                         {
                                printf("Out of memory ");
                         }
                         else
                         {     
                               fr[arrayLength].setFirstName(fr, fName, arrayLength);
                               fr[arrayLength].setLastName(fr, lName, arrayLength);
                               fr[arrayLength].setHomePhone(fr, hPhone, arrayLength);
                               fr[arrayLength].setCellPhone(fr, cPhone, arrayLength);
                               arrayLength++;  
                         }
                         }                   
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
              fr = (Phonebook*) realloc(fr, (arrayLength+1) * sizeof(Phonebook));
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
                                    fprintf(write, "%s %s %s %s ", fr[count].getFirstName(fr, count), fr[count].getLastName(fr, count), fr[count].getHomePhone(fr, count), fr[count].getCellPhone(fr, count));
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
