import requests
import json
from datetime import date
import urllib.request
import random

def currencyroulettegame(diffuculty):
      
     #while True:
        #print ("choose difficulty from 1 - 5: ")
        #difficulty = int(input())
        #if (difficulty > 5 or difficulty < 1):
            #print("iligal command. try again ")
            #continue
        #else:
            #break
    
     d = difficulty
    
    #generate numbers from 1-100
     rand = (random.randint(1,100))

    #varible t mean total money . its mean current USD convert to ILS and multiply in random number
     url = 'https://v6.exchangerate-api.com/v6/a7dba39e16dcd2a6e9c844af/pair/USD/ILS/'
     api_key = 'a7dba39e16dcd2a6e9c844af'
     response = requests.get(url).json()
     res = urllib.request.urlopen(url)
     r = json.loads(res.read())
     rate = r.get("conversion_rate")
     t = rand * rate  #total money in ILS
     print("its corrent rate from USD to ILS" ,rate)

    #asking from user what the value he think will be in ILS
     print("hey user what you think will be result in USD?: ")
     get_guess_from_user = float(input())
     get_guess_from_user = get_guess_from_user * rate 
    #get money interval
     get_money_interval_min = t - ( 5 - d)
     get_money_interval_max = t + ( 5 - d)
     play = True
    #check if the value stay in generate interval 
     if( get_guess_from_user >= get_money_interval_min and  get_guess_from_user <= get_money_interval_max):
          print ("WOW its correct :) ")
          print(play)
     elif( get_guess_from_user < get_money_interval_min or  get_guess_from_user > get_money_interval_max):
          print("its not correct. try again")
          print(not play)
    
    







