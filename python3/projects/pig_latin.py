
vowel = ['a', 'e', 'i', 'o', 'u']

def pig_latin(word):
	start = word[0]
	for v in vowel:
		if(word[0] == v):
			flag = True

	if(flag == False):
		new_word=word+"ay"
		return new_word

	if(flag):
		new_word=word[1:]+start+"ay"
		return new_word

word = input('Enter a word: ')
print(pig_latin(word))
