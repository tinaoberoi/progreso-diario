a = ["", "", ""]
b = ["", "", ""]
c = ["", "", ""]

def display_board():
	print("     |     |     ")
	print(" {0}    | {1}    | {2}  ".format(a[0], a[1], a[2]))
	print("     |     |     ")
	print("-----------------")
	print("     |     |     ")
	print(" {0}    | {1}    | {2}  ".format(b[0], b[1], b[2]))
	print("     |     |     ")
	print("-----------------")
	print("     |     |     ")
	print(" {0}    | {1}    | {2} ".format(c[0], c[1], c[2]))
	print("     |     |     ")


def start_game(start):
	flag = False
	if(start == 'Yes' or start == 'yes'):
		flag = True
	else:
		flag = False
	return flag

def main_func():
	print("Welcome to Tic Tac Toe!")
	player1 = input("Player 1: Do you wnat to be X or O?  ")
	player2 = ''
	if(player1 == 'X'):
		player2 = 'O'
	else:
		player2 = 'X'

	print("Player1 will go first")
	start = input("Are you ready to play? Enter Yes or No  ")
	if(start_game(start)):
		display_board()


main_func()