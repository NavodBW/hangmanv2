## An improved version of my [original hangman game](https://github.com/NavodBW/hangman-cpp) 
  
**IMPROVEMENTS:**

 - Instead of asking the user for the secret word, the game randomly selects a word that is longer than 3 letters from a text file. (text
   file obtained from: https://github.com/dwyl/english-words)
   
  - Uses [mersenne_twister_engine](https://en.cppreference.com/w/cpp/numeric/random/mersenne_twister_engine) 
   to generate a random number and select a word from the text.
   
  - Implemented **input validation** where the game converts the input into lowercase, only allows single alphabetical characters.
   
 -  Ignores the words with numbers or special chars in the text file
   
  - The game now offers to **search google** for the meaning of each word after each game

