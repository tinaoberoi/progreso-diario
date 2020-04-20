a = ["", "", ""]
b = ["", "", ""]
c = ["", "", ""]

def check():
	if(a[0] == a[1] == a[2] == 'X' or b[0]==b[1]==b[2] == 'X' or c[0]==c[1]==c[2] == 'X' or a[0]==b[1]==c[2] == 'X' or a[2]==b[1]==c[0] == 'X' or a[0]==b[0]==c[0] == 'X' or a[1]==b[1]==c[1] == 'X' or a[2]==b[2]==c[2] == 'X' or a[0] == a[1] == a[2] == 'O' or b[0]==b[1]==b[2] == 'O' or c[0]==c[1]==c[2] == 'O' or a[0]==b[1]==c[2] == 'O' or a[2]==b[1]==c[0] == 'O' or a[0]==b[0]==c[0] == 'O' or a[1]==b[1]==c[1] == 'O' or a[2]==b[2]==c[2] == 'O'):
		return True
	return False
def check_filled():
	if(a[0] != [""] and a[1] != [""] and a[2] != [""] and b[0] != [""] and b[1] != [""] and b[2] != [""] and c[0] != [""] and c[1] != [""] and c[2] != [""]):
		return True
	return False

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

def fill(pos, sign):
	if(pos == 1):
		if(a[0] == ''):
			a[0] = sign
		else:
			print("Not allowed")
	if(pos == 2):
		if(a[1] == ''):
			a[1] = sign
		else:
			print("Not allowed")
	if(pos == 3):
		if(a[2] == ''):
			a[2] = sign
		else:
			print("Not allowed")
	if(pos == 4):
		if(b[0] == ''):
			b[0] = sign
		else:
			print("Not allowed")
	if(pos == 5):
		if(b[1] == ''):
			b[1] = sign
		else:
			print("Not allowed")
	if(pos == 6 ):
		if(b[2] == ''):
			b[2] = sign
		else:
			print("Not allowed")
	if(pos == 7 ):
		if(c[0] == ''):
			c[0] = sign
		else:
			print("Not allowed")
	if(pos == 8 ):
		if(c[1] == ''):
			c[1] = sign
		else:
			print("Not allowed")
	if(pos == 9 ):
		if(c[2] == ''):
			c[2] = sign
		else:
			print("Not allowed")



def main_func():
	print("Welcome to Tic Tac Toe!")
	player1 = input("Player 1: Do you wnat to be X or O?  ")
	player2 = ''
	if(player1 == 'X'):
		player2 = 'O'
	else:
		player2 = 'X'

	
	print("Player1 will go first")
	#turn = 0= player1, turn = 1 = player2
	turn = 0
	
	start = input("Are you ready to play? Enter Yes or No  ")
	
	while(start_game(start)):
		display_board()
		if(turn == 0):
			print("your turn player1")
		else:
			print("your turn player2")
		pos = int(input("Choose your position: (1-9)  "))
		if(turn == 0):
			fill(pos, player1)
		else:
			fill(pos, player2)
		#display_board()
		if(check()):
			if(turn == 0):
				print("Player1 won!")
			if (turn == 1):
				print("Player2 won!")
			break
		else:
			if(check_filled()):
				print("Nobody Won")
				break
		turn = not turn


main_func()