#include <iostream>
#include <cstdlib>
#include <ctime> 

using namespace std;

enum enQuestionsLevel {Easy = 1, Medium = 2, Hard = 3, Mix = 4};
enum enOperationType {Add = 1, Sub = 2, Mul = 3, Div = 4, MixOp = 5};

struct stQuestion {
    int number1 = 0;
    int number2 = 0;
    enOperationType opeartionType;
    enQuestionsLevel questionLevel;
    int correctAnswer = 0;
    int playerAnswer = 0;
    bool answerResult = false;
};

struct stQuizz {
    stQuestion questionList[100];
    short numberOfQuestions;
    enQuestionsLevel questionLevel;
    enOperationType opType;
    short NumberOfWrongAnswers = 0;
    short NumberOfCorrectAnswers = 0;
    bool isPass = false;
};

string getOpTypeSymbol(enOperationType opType) {


}

string getQuestionLevelText(enQuestionsLevel questionLevel) {

}

int randomNumb(int from, int to) {
    return rand() % (To - From + 1) + From;
}

void setScreenColor(bool right) {

}

short readHowManyQuestions() {
    short numberOfQuestions;

    do {
        cout << "How many questions do you want to answer? ";
        cin >> numberOfQuestions;
    } while (numberOfQuestions < 1 || numberOfQuestions > 10);
    return numberOfQuestions;
}

enQuestionsLevel readQuestionLevelType() {
    short questionLevel = 0;

    do {
        cout << "Enter question level: [1]Easy, [2] Medium, [3]Hard, [4]Mix ? ";
        cin >> questionLevel;
    } while (questionLevel < 1 || questionLevel > 4);
    
    return (enQuestionsLevel)questionLevel;
}

enOperationType readOpType() {
    short opType;

    do {
        cout << "Enter Opearation type: [1]add, [2]sub, [3]mul, [4]div, [5]mixOp ? ";
        cin >> opType;
    } while (opType < 1 || opType > 5);

    return (enOperationType)opType;
}

int simpleCalculator(int number1, int number2, enOperationType opType) {
    switch (opType) {
    case enOperationType::Add:
        return number1 + number2;
    case enOperationType::Sub:
        return number1 - number2;
    case enOperationType::Mul:
        return number1 * number2;
    case enOperationType::Div:
        return number1 / number2;
    default:
        return number1 + number2;
    }
}

enOperationType getRandomOperationType() {
    int op = randomNumb(1, 4);
    return (enOperationType)op;
}

stQuestion generateQuestion(enQuestionsLevel questionLevel, enOperationType opType) {
    stQuestion question;

    if (questionLevel == enQuestionsLevel::Mix) {
        questionLevel = (enQuestionsLevel)randomNumb(1, 3);
    }

    if (opType == enOperationType::MixOp) {
        opType = getRandomOperationType();
    }

    question.opeartionType = opType;

    switch (questionLevel) {
    
    case enQuestionsLevel::Easy:
        question.number1 = randomNumb(1, 10);
        question.number2 = randomNumb(1, 10);

        question.correctAnswer = simpleCalculator(question.number1, question.number2, question.opeartionType);
        question.questionLevel = questionLevel;
        return question;

    case enQuestionsLevel::Medium:
        question.number1 = randomNumb(10, 50);
        question.number2 = randomNumb(10, 50);

        question.correctAnswer = simpleCalculator(question.number1, question.number2, question.opeartionType);
        question.questionLevel = questionLevel;
        return question;

    case enQuestionsLevel::Hard:
        question.number1 = randomNumb(50, 100);
        question.number2 = randomNumb(50, 100);

        question.correctAnswer = simpleCalculator(question.number1, question.number2, question.opeartionType);
        question.questionLevel = questionLevel;
        return question;
    }
}

void generateQuizzQuestions(stQuizz& quizz) {
    for (short question = 0; question < quizz.numberOfQuestions; question++) {
        quizz.questionList[question] = generateQuestion(quizz.questionLevel, quizz.opType);
    }
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
    stQuizz quizz;
    quizz.numberOfQuestions = readHowManyQuestions();
    quizz.questionLevel = readQuestionLevelType();
    quizz.opType = readOpType();
    
    generateQuizzQuestions(quizz);


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

