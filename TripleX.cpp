#include <iostream>
// cl triplex.cpp and triplex
void PrintIntroduction(int Difficulty)
{
    std::cout << "\n\nYou are a secret agent, your Level is: " << Difficulty;
    std::cout << "\nEnter the correct code to continue \n\n";
}


bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    const int CodeA = rand() % Difficulty+Difficulty;
    const int CodeB = rand() % Difficulty+Difficulty;
    const int CodeC = rand() % Difficulty+Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA*CodeB*CodeC;

    std::cout << std::endl;
    std::cout << "+ There are 3 numbers" << std::endl;
    std::cout << "+ The codes sum: " << CodeSum << std::endl;
    std::cout << "+ The multiply is: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum,GuessProduct;
    GuessSum = GuessA + GuessB + GuessC;
    GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "You Win!";
        return true;
    }
    else
    {
        std::cout << "You Lose!";
        return false;
    }

}

int main()
{
    int LevelDifficulty = 1;
    int const maxDifficulty = 5;
    while (LevelDifficulty <= maxDifficulty)    //ctrl c will close the program
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }
    
    std::cout << "Great, You reached Deep Web. Be Careful!";

    return 0;
} 