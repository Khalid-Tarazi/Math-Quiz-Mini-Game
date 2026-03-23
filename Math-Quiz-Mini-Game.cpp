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
    switch (opType)
    {
    case enOperationType::Add:
        return "+";
    case enOperationType::Sub:
        return "-";
    case enOperationType::Mul:
        return "x";
    case enOperationType::Div:
        return "/";
    default:
        return "MixOp";
    }
}

string getQuestionLevelText(enQuestionsLevel questionLevel) {
    string arrQuestionLevelText[4] = { "Easy", "Medium", "Hard", "Mix"};
    return arrQuestionLevelText[questionLevel - 1];
}

int randomNumb(int from, int to) {
    return rand() % (to - from + 1) + from;
}

void setScreenColor(bool right) {
    if (right)
        system("color 2F"); // Green for correct answers.
    else
    {
        system("color 4F"); // Red for incorrect answers.
        cout << "\a"; // Plays an alert sound.
    }

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
    int answer = 0;
    cin >> answer;
    return answer;
}

void printTheQuestion(stQuizz& quizz, short questionNumber) {
    cout << "\n";
    cout << "Question [" << questionNumber + 1 << "/" << quizz.numberOfQuestions << "] \n\n";
    cout << quizz.questionList[questionNumber].number1 << endl;
    cout << quizz.questionList[questionNumber].number2 << " ";
    cout << getOpTypeSymbol(quizz.questionList[questionNumber].opeartionType);
    cout << "\n_______" << endl;
}

void correctTheQuestionAnswer(stQuizz& quizz, short questionNumber) {
    if (quizz.questionList[questionNumber].playerAnswer != quizz.questionList[questionNumber].correctAnswer) {
        quizz.questionList[questionNumber].answerResult = false;
        quizz.NumberOfWrongAnswers++;
        
        cout << "Wrong Answer :( \n";
        cout << "The right answer is: ";
        cout << quizz.questionList[questionNumber].correctAnswer;
        cout << "\n";
    }
    else {
        quizz.questionList[questionNumber].answerResult = true;
        quizz.NumberOfCorrectAnswers++;

        cout << "Right answer ! \n";
    }

    cout << endl;

    setScreenColor(quizz.questionList[questionNumber].answerResult);
}

void askAndCorrectQuestionListAnswers(stQuizz& quizz) {
    
    for (short questionNumber = 0; questionNumber < quizz.numberOfQuestions; questionNumber++) {
        printTheQuestion(quizz, questionNumber);
        quizz.questionList[questionNumber].playerAnswer = readQuestionAnswer();
        correctTheQuestionAnswer(quizz, questionNumber);
    }

    quizz.isPass = (quizz.NumberOfCorrectAnswers >= quizz.NumberOfWrongAnswers);
}

string getFinalResultsText(bool pass) {
    if (pass)
        return "PASS :) ";
    else
        return "FAIL :( ";
}

void printQuizzResult(stQuizz quizz) {
    cout << "\n";
    cout << "_______________________\n\n";
    cout << "Final result is " << getFinalResultsText(quizz.isPass);
    cout << "\n______________________\n\n";

    cout << "Number of questions: " << quizz.numberOfQuestions << endl;
    cout << "Questions level    : " << getQuestionLevelText(quizz.questionLevel) << endl;
    cout << "Op Type            :" << getOpTypeSymbol(quizz.opType) << endl;
    cout << "Number of right answers: " << quizz.NumberOfCorrectAnswers << endl;
    cout << "Number of wrong answers: " << quizz.NumberOfWrongAnswers << endl;
    cout << "__________________________\n";
}

void playMathGame() {
    stQuizz quizz;
    quizz.numberOfQuestions = readHowManyQuestions();
    quizz.questionLevel = readQuestionLevelType();
    quizz.opType = readOpType();
    
    generateQuizzQuestions(quizz);
    askAndCorrectQuestionListAnswers(quizz);
    printQuizzResult(quizz);
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

