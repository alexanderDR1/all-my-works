from GameProject import  MemoryGame , GuessGame , CurrencyRoulleteGame

def welcome(name):
    print(f"Hello {name} welcome to the World Of Games (Wog)\n Here you can find many cool games to play ;)")



def load_game():
    print ("Please choose a game to play: ")
    print("1. Memory Game - a sequence of numbers will appear for 1 second and you have toguess it back ")
    print ("2. Guess Game - guess a number and see if you chose like the computer")
    print ("3. Currency Roulette - try and guess the value of a random amount of USD in ILS")
    while True:
        choose_1 = int(input())
        if (choose_1 > 3 or  choose_1 < 1):
            print("iligal command. try again ")
            continue
        else:
            break


    while True:
        print ("Now choose difficulty from 1 - 5: ")
        difficulty = int(input())
        if (difficulty > 5 or difficulty < 1):
            print("iligal command. try again ")
            continue
        else:
            break
   
   if(choose_1 == 1):
      memorygame()
   elif(choose_1 == 2):
       guessgame()
   elif(choose_1 == 3):
       currencyroulettegame(difficulty)