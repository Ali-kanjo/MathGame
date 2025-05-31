#include<iostream>
using namespace std;

enum enQuestionLevel { EasyLevel = 1, MidLevel = 2, HardLevel = 3, Mix = 4 };
enum enOperationType { Add = 1, Mul = 2, Sub = 3, Div = 4, MixOp = 5 };

struct stQuestion {
	int Number1;
	int Number2;
	enQuestionLevel QuestionLevel;
	enOperationType OperationType;
	int PlayerAnswer;
	int RightAnswer;
	bool IsPass = false;
};

struct stQuiz {
	stQuestion Questions[100];
	int NumOfQuestions;
	enQuestionLevel QuestionsLevel;
	enOperationType OpType;
	int NumberOfRightAnswer = 0;
	int NumberOfWrongAnswers = 0;
	bool PassOrFail = false;
};

int ReadHowManyQuesiton() {

	int Num = 0;
	do {
		cout << "Enter How many Question you want ? ";
		cin >> Num;

		if (Num <= 0)

			cout << "Please enter a pozitive number\n";

	} while (Num <= 0);

	return Num;
}

enQuestionLevel ReadQuestionLevel() {
	int QuestionLevel;

	do {

		cout << "Enter Question level : [1]Easy , [2]Mid , [3]Hard , [4]Mix ? ";
		cin >> QuestionLevel;


	} while (QuestionLevel < 1 || QuestionLevel>4);


	return (enQuestionLevel)QuestionLevel;
}

enOperationType ReadOperationType() {
	int OpType;

	do {

		cout << "Enter Operation Type : [1] Add , [2] Mul , [3] Sub  , [4] Div , [5] Mix ? ";
		cin >> OpType;

	} while (OpType < 1 || OpType>5);

	
	return (enOperationType)OpType;
}

int RandomNum(int From, int To) {

	int RandNum = rand() % (To - From + 1) + From;

	return RandNum;
}

string GetOperationSymbol(enOperationType OpType) {
	
	switch (OpType) {

	case enOperationType::Add:
		return " + ";

	case enOperationType::Mul:
		return " * ";

	case enOperationType::Sub:
		return " - ";

	case enOperationType::Div:
		return " / ";

	case enOperationType::MixOp:
		return " Mix ";

	}
}

string GetQuestionLevelText(enQuestionLevel QuestionLevel) {
	string QuestionsLevelText[] = { "Easy","Mid","Hard","Mix" };

	return QuestionsLevelText[QuestionLevel - 1];
}

int CalculateNumbers(int Num1, int Num2, enOperationType OpType) {

	switch (OpType) {

	case enOperationType::Add:

		return Num1 + Num2;

	case enOperationType::Mul:

		return Num1 * Num2;

	case enOperationType::Sub:

		return Num1 - Num2;

	case enOperationType::Div:

		return (Num2 == 0) ? 0 : Num1 / Num2;

	}
}

void CheckPlayerAnswer(stQuiz& Quiz, int Question) {

	if (Quiz.Questions[Question].PlayerAnswer==Quiz.Questions[Question].RightAnswer)
	{
		cout << "Right Answer :-)\n";

		Quiz.NumberOfRightAnswer++;
		Quiz.Questions[Question].IsPass = true;
	}

	else
	{
		cout << "Wrong Answer :-(\n";
		cout << "Right Answer is : " << Quiz.Questions[Question].RightAnswer << endl;

		Quiz.NumberOfWrongAnswers++;
		Quiz.Questions[Question].IsPass = false;

	}
}

enOperationType GetOperationType() {

		return (enOperationType)RandomNum(1, 4);
}

void GetTheScreenColor(bool Answer) {

	if (Answer)
		system("color 2F");

	else
		system("color 4F");

}

string GetPassOrFail(bool Result) {

	if (Result)
		return " Pass :-) ";
	else
		return " Fail :-( ";
}

stQuestion GenerateQuesiton(enQuestionLevel QuestionLevel, enOperationType OpType) {
	stQuestion Question;

	if (QuestionLevel == enQuestionLevel::Mix) {

		QuestionLevel = (enQuestionLevel)RandomNum(1, 3);
	}

	if (OpType == enOperationType::MixOp) {
		OpType = GetOperationType();
	}


	Question.OperationType = OpType;


	switch (QuestionLevel) {

	case enQuestionLevel::EasyLevel:
		Question.Number1 = RandomNum(1, 9);
		Question.Number2 = RandomNum(1, 9);
		Question.RightAnswer = CalculateNumbers(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionLevel = QuestionLevel;
		break;
	case enQuestionLevel::MidLevel:
		Question.Number1 = RandomNum(10, 10);
		Question.Number2 = RandomNum(10, 50);
		Question.RightAnswer = CalculateNumbers(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionLevel = QuestionLevel;
		break;
	case enQuestionLevel::HardLevel:
		Question.Number1 = RandomNum(50, 100);
		Question.Number2 = RandomNum(50, 100);
		Question.RightAnswer = CalculateNumbers(Question.Number1, Question.Number2, Question.OperationType);
		Question.QuestionLevel = QuestionLevel;
		break;
	}

	return Question;
}

void GenerateQuestions(stQuiz& Quiz) {
	for (int Question = 0; Question < Quiz.NumOfQuestions; Question++) {
		Quiz.Questions[Question] = GenerateQuesiton(Quiz.QuestionsLevel, Quiz.OpType);
	}
}

void PrintQuestion(stQuiz Quiz, int Question) {

	cout << "\n\nQuestion [" << Question + 1 << "/" << Quiz.NumOfQuestions << "] : \n\n";
	cout << Quiz.Questions[Question].Number1 << endl;
	cout << Quiz.Questions[Question].Number2;
	cout << GetOperationSymbol(Quiz.Questions[Question].OperationType) << endl;
	cout << "_____________" << endl;

}

int GetPlayerAnswer() {
	int Answer = 0;

	cin >> Answer;

	return Answer;
}

void AskAndCorrectQuistionsAnswers(stQuiz& Quiz) {

	for (int Question = 0; Question < Quiz.NumOfQuestions; Question++) {

		PrintQuestion(Quiz, Question);
		Quiz.Questions[Question].PlayerAnswer = GetPlayerAnswer();
		CheckPlayerAnswer(Quiz, Question);
		GetTheScreenColor(Quiz.Questions[Question].IsPass);
		
	}

	Quiz.PassOrFail = (Quiz.NumberOfRightAnswer >= Quiz.NumberOfWrongAnswers);

}

void ShowResultsInTheScreen(stQuiz Quiz) {

	cout << "\n\n________________________________________\n\n";
	cout << " Final Result is " << GetPassOrFail(Quiz.PassOrFail) << "\n";
	cout << "________________________________________\n\n";
	cout << "Number of Questions : " << Quiz.NumOfQuestions<< endl;
	cout << "Questions level     : " << GetQuestionLevelText( Quiz.QuestionsLevel) << endl;
	cout << "OpType              : " << GetOperationSymbol(Quiz.OpType) << endl;
	cout << "Number of right answer : " << Quiz.NumberOfRightAnswer << endl;
	cout << "Number of wrong answer : " << Quiz.NumberOfWrongAnswers << endl;
	cout << "\n________________________________________\n\n";

	GetTheScreenColor(Quiz.PassOrFail);
}

void PlayMathGame() {
	stQuiz Quiz;

	Quiz.NumOfQuestions = ReadHowManyQuesiton();
	Quiz.QuestionsLevel = ReadQuestionLevel();
	Quiz.OpType = ReadOperationType();

	GenerateQuestions(Quiz);
	AskAndCorrectQuistionsAnswers(Quiz);
	ShowResultsInTheScreen(Quiz);

	

}

void ResetScreen() {

	system("cls");
	system("color 0F");
}

void StartGame() {
	char Answer='Y';

	do {

		ResetScreen();
		PlayMathGame();

		cout << "Do you want to play again : ";
		cin >> Answer;

	} while (Answer == 'Y' || Answer == 'y');
}

int main() {

	srand((unsigned)time(NULL));

	StartGame();

	return 0;

}

