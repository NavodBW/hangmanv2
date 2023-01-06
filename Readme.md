An improved version of my original hangman game (https://github.com/NavodBW/hangman-cpp); where instead of asking the user for the secret word, the game radomly selects a word that is longer than 3 letters from a text file. (text file obtained from: https://github.com/dwyl/english-words)
Uses mersenne_twister_engine (https://en.cppreference.com/w/cpp/numeric/random/mersenne_twister_engine) to genarate a random number and select a word from the text.

Todo:
-Ask the user whether they want to quit or try a new game