#from GameProject import Live , Score
import os
import time


SCORES_FILE_NAME = "Scores.txt"
BAD_RETURN_CODE = 0

def Score_cleaner():
    os.system('clr')





points_of_winning = (4 * 3) + 5


#what i need to do
#1 - build text file that save points of gamer 
#2 - you need add new points to old points every time that user win


score_file = open(SCORES_FILE_NAME, "w+")
score_file.write("the score is: ")
print(score_file.read(points_of_winning))
time.sleep(3)
score_file.close()



#def add_score(difficulty):
    #this function need read text file with info about score of gamer 
    #after that save it and open that or not
    #if file wiil close\fail that you need build new score and put him to score.txt    
