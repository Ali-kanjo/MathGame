# 🧮 Math Quiz Game in C++

A simple console-based math quiz game written in C++. The game challenges the user with a series of randomly generated math questions based on the selected difficulty and operation type.

## 🎮 Game Features

- Choose number of questions
- Select difficulty: Easy, Mid, Hard, or Mixed
- Select operation type: Add, Multiply, Subtract, Divide, or Mixed
- Get instant feedback (Right/Wrong)
- Summary report with final result (Pass/Fail)
- Console color changes based on answer/result

## 🧠 Difficulty Levels

| Level | Description     |
|-------|-----------------|
| 1     | Easy (1–9)       |
| 2     | Mid (10–50)      |
| 3     | Hard (50–100)    |
| 4     | Mixed Levels     |

## ➕ Operation Types

| Type | Operation        |
|------|------------------|
| 1    | Addition (+)      |
| 2    | Multiplication (*)|
| 3    | Subtraction (-)   |
| 4    | Division (/)      |
| 5    | Mixed             |

## 🖥️ How to Run

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/math-quiz-game.git
````

2. Compile the project:

   ```bash
   g++ -o MathGame MathGame.cpp
   ```

3. Run the executable:

   ```bash
   ./MathGame
   ```

## 📸 Example Output

```
Enter How many Question you want ? 2
Enter Question level : [1]Easy , [2]Mid , [3]Hard , [4]Mix ? 1
Enter Operation Type : [1] Add , [2] Mul , [3] Sub  , [4] Div , [5] Mix ? 1


Question [1/2] :

3
5 + 
_____________
8
Right Answer :-)

Question [2/2] :

2
7 + 
_____________
10
Wrong Answer :-(
Right Answer is : 9


________________________________________

 Final Result is  Pass :-) 
________________________________________

Number of Questions : 2
Questions level     : Easy
OpType              :  + 
Number of right answer : 1
Number of wrong answer : 1

________________________________________

Do you want to play again : n
```

## 📁 Files Structure

```
math-quiz-game/
│
├── MathGame.cpp       # Main source code
├── README.md          # Project documentation
```

## 🧑‍💻 Author

* Developed by [Your Name](https://github.com/yourusername)

## 📄 License

This project is licensed under the MIT License.

```

---
