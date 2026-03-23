#include <iostream>
#include <cstdlib>
#include <ctime> 

using namespace std;

enum enQuestionsLevel {Easy = 1, Medium = 2, Hard = 3, Mix = 4};
enum enOperationType {Add = 1, Sub = 2, Mul = 3, Div = 4, MixOp = 5};

struct stQuestion {


};

struct stQuizz {


};

string getOpTypeSymbol(enOperationType opType) {


}

string getQuestionLevelText(enQuestionsLevel questionLevel) {

}

int randomNumb(int from, int to) {

}

void setScreenColor(bool right) {

}

short readHowManyQuestions() {

}

enQuestionsLevel readQuestionLevelType() {

}

enOperationType readOpType() {

}

int simpleCalculator(int number1, int number2, enOperationType opType) {

}

enOperationType getRandomOperationType() {

}

stQuestion generateQuestion(enQuestionsLevel questionLevel, enOperationType opType) {

}

void generateQuizzQuestions(stQuizz& quizz) {

}

int readQuestionAnswer() {

}

void printTheQuestion(stQuizz& quizz, short questionNumber) {

}

void correctTheQuestionAnswer(stQuizz& quizz, short questionNumber) {

}

void askAndCorrectQuestionListAnswers(stQuizz& quizz) {

}

string getFinalResultsText(bool pass) {

}

void printQuizzResult(stQuizz& quizz) {

}

void playMathGame() {
    


}

void resetScreen() {
    system("cls");
    system("color 0F");
}

void startGame() {
    char playAgain =  'Y';

    do {
        resetScreen();
        playMathGame();

        cout << endl << "Do you want to play again? Y/N? ";
        cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');
}

int main() {

    srand((unsigned)time(NULL));
    startGame();
    return 0;
}

