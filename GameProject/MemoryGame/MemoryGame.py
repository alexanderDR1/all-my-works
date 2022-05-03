
import random
import  time
import collections
import os


def memorygame():
    #generate list of random numbers
     difficulty = int(input("Enter length of list that show amount numbers: "))
     generate_sequence = [random.randint(1, 101) for i in range(difficulty)]  
      
     print (generate_sequence)

     time.sleep(0.7)
     os.system("cls")
     
     print("we continue!")
     
     #get numbers from user
     get_list_from_user = []
     for i in range(0,difficulty):
        print("enter a number that you remember: ")
        element = int(input())
        get_list_from_user.append(element)
     print(get_list_from_user)

     is_list_equal(generate_sequence,get_list_from_user)
     

def is_list_equal(a,b):

   play = True
   if collections.Counter(a) == collections.Counter(b):
       print ("goood job :) you remember all numbers and its correct")
       print(play)

   else:
       print ("unfortunately its wrong . you can try agian ")
       print(not play)


