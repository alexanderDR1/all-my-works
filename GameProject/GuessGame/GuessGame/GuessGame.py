import random 

def guessgame():
    points = 0
    computer_points = 0

    #take number of turns that user want play and number of difficulty 
    #system put random number in secret number and after that user need guess
    number_of_turns = int(input("Enter number of turns that you want to play: "))
    i = 1
    while (i <= number_of_turns):
        difficulty = int(input("Enter a number of difficulty:\n remember as much as that you choose bigger number if you enter correct guess you recive more points "))
        secret_number = random.randint(1,difficulty)
         
        
        get_guess_from_user = int(input("Enter number that you think the computer will choose: "))
        if (get_guess_from_user == secret_number and difficulty <= 10  and  difficulty > 0):
            print("Good. your guess its correct :)")
            points += 2 
            computer_points += 0 

        elif (get_guess_from_user == secret_number and difficulty <= 50 and difficulty > 0 ):
            print("Very Good. your guess its correct :)")
            points += 2 ** 2
            computer_points += 0  
            
        elif (get_guess_from_user == secret_number and difficulty <= 100 and difficulty > 0):
            print("Amzing. your guess its correct :)")
            points += 2 ** 4
            computer_points += 0

        elif (get_guess_from_user == secret_number and difficulty <= 1000 and difficulty > 0):
            print("WoW your guess its correct :)")
            points += 2 ** 6 
            computer_points += 0

        elif (get_guess_from_user == secret_number and difficulty <= 10000 and difficulty > 0):
            print("your a Hucker? your lucy mother fucker :)")
            points += 2 ** 12
            computer_points += 0
            
        elif (get_guess_from_user != secret_number):
            print("Your guess is not correct :(")
            points += 0
            computer_points += 2
        
        play = True
        i += 1
    if (points > computer_points):
        print("You Won!!! :)")
        print(play)
        
    elif (points < computer_points):
        print("You lost")
        print(not play)
        
    elif(points == computer_points):
        print("Its Draw ")
        return 0

        

