import random

def game():
    word_list = ["python", "programming", "language", "computer", "science"]
    secret_word = random.choice(word_list)
    correct_guesses = []
    wrong_guesses = []
    print("Welcome to the hangman game!")
    print("Guess the secret word:")
    print("_ " * len(secret_word))
    while len(wrong_guesses) < 6:
        guess = input("Guess a letter: ").lower()
        if guess in secret_word:
            correct_guesses.append(guess)
            print("Correct!")
            print(" ".join([letter if letter in correct_guesses else "_" for letter in secret_word]))
        else:
            wrong_guesses.append(guess)
            print("Incorrect. You have", 6 - len(wrong_guesses), "guesses left.")
    if len(wrong_guesses) == 6:
        print("You lose! The secret word was", secret_word + ".")
    else:
        print("You win! The secret word was", secret_word + ".")
        
game()
