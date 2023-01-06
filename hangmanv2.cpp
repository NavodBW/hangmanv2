#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>
#include <algorithm>
#include <cctype>

const int MAX_INCORRECT_GUESSES = 6; // maximum number of incorrect guesses allowed

int main(){
  while(true)
  {

  // Open the dictionary file
  std::ifstream dictionaryFile("dictionary.txt");

  // Check if the file was successfully opened
  if (!dictionaryFile.is_open())
  {
    std::cout << "Error: Could not open dictionary file." << std::endl;
    return 1;
  }

  // Read in the words from the dictionary file
  std::vector<std::string> words;
  std::string word;
  while (dictionaryFile >> word)
  {
    if (word.length() > 3 && std::all_of(word.begin(), word.end(), isalpha))

      {
        words.push_back(word);
      }
    }

  // Close the dictionary file
  dictionaryFile.close();

  // Select a random word from the words vector as the secret word
  std::random_device rd; // used to obtain a seed for the random number engine
  std::mt19937 generator(rd()); // standard mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<int> distribution(0, words.size() - 1);
  std::string secretWord = words[distribution(generator)];

  // Initialize the number of incorrect guesses to 0
  int numIncorrectGuesses = 0;

  // Create a vector to store the correct guesses
  std::vector<char> correctGuesses;

  // Create a vector to store the incorrect guesses
  std::vector<char> incorrectGuesses;

  // Keep looping until the player has won or lost
  while (numIncorrectGuesses < MAX_INCORRECT_GUESSES)
  {
    // Print the current state of the game
    std::cout << "Incorrect Guesses: ";
    for (char ch : incorrectGuesses)
    {
      std::cout << ch << " ";
    }
    std::cout << std::endl;

    std::cout << "Word: ";
    for (char ch : secretWord)
    {
      if (std::find(correctGuesses.begin(), correctGuesses.end(), ch) != correctGuesses.end())
      {
        std::cout << ch << " "; // print the letter if it has been guessed
      }
      else
      {
        std::cout << "_ "; // print a blank if the letter has not been guessed
      }
    }
    std::cout << std::endl;

    // Print the number of remaining incorrect guesses
    std::cout << "Remaining Incorrect Guesses: " << MAX_INCORRECT_GUESSES - numIncorrectGuesses << std::endl;
    // Prompt the player to enter a guess
    std::cout << "Enter a guess: ";
    char guess;
    std::cin >> guess;

    // Check if the guess is correct
    if (std::find(secretWord.begin(), secretWord.end(), guess) != secretWord.end())
    {
      // Add the guess to the correct guesses vector
      correctGuesses.push_back(guess);

      // Check if the player has won
      bool won = true;
      for (char ch : secretWord)
      {
        if (std::find(correctGuesses.begin(), correctGuesses.end(), ch) == correctGuesses.end())
        {
          won = false;
          break;
        }
      }

      if (won)
      {
        std::cout << "Congratulations, you won!" << std::endl;
        break;
      }
    }
    else
    {
      // Add the guess to the incorrect guesses vector
      incorrectGuesses.push_back(guess);
      numIncorrectGuesses++;
    }
  }

  if (numIncorrectGuesses == MAX_INCORRECT_GUESSES)
  {
    std::cout << "You lost :( The secret word was: " << secretWord << std::endl;
  }

  // Ask the player if they want to start a new game or quit
  std::cout << "Play again? (y/n) ";
  char playAgain;
  std::cin >> playAgain;
  if (playAgain == 'n')
  {
    break;
  }
  }

system("pause");
return 0;

}
