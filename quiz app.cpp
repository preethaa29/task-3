#include <iostream>
#include <vector>
#include <algorithm>

class Question {
public:
    std::string questionText;
    std::vector<std::string> options;
    int correctOption;

    Question(const std::string& text, const std::vector<std::string>& opts, int correct)
        : questionText(text), options(opts), correctOption(correct) {}
};

class Quiz {
private:
    std::vector<Question> questions;
    int score;

public:
    Quiz(const std::vector<Question>& quizQuestions) : questions(quizQuestions), score(0) {}

    void displayQuestion(int questionNumber) const {
        const Question& q = questions[questionNumber];
        std::cout << "Question " << (questionNumber + 1) << ": " << q.questionText << "\n";
        
        for (size_t i = 0; i < q.options.size(); ++i) {
            std::cout << i + 1 << ". " << q.options[i] << "\n";
        }
    }

    void takeQuiz() {
        for (size_t i = 0; i < questions.size(); ++i) {
            displayQuestion(i);
            int userChoice;
            std::cout << "Your answer: ";
            std::cin >> userChoice;

            if (userChoice > 0 && userChoice <= static_cast<int>(questions[i].options.size())) {
                if (userChoice == questions[i].correctOption) {
                    std::cout << "Correct!\n";
                    score++;
                } else {
                    std::cout << "Incorrect. The correct answer is: " << questions[i].correctOption << ". " << questions[i].options[questions[i].correctOption - 1] << "\n";
                }
            } else {
                std::cout << "Invalid choice. Skipping to the next question.\n";
            }

            std::cout << "\n";
        }
    }

    void displayResult() const {
        std::cout << "Quiz completed! Your score: " << score << " out of " << questions.size() << "\n";
    }
};

int main() {
    std::vector<Question> quizQuestions = {
        {"What is the capital of France?", {"Berlin", "Paris", "Madrid", "Rome"}, 2},
        {"Which planet is known as the Red Planet?", {"Mars", "Venus", "Jupiter", "Saturn"}, 1},
        {"What is the largest mammal in the world?", {"Elephant", "Blue Whale", "Giraffe", "Hippopotamus"}, 2},
        {"Who wrote 'Romeo and Juliet'?", {"William Shakespeare", "Jane Austen", "Charles Dickens", "Mark Twain"}, 1},
        {"What is the currency of Japan?", {"Won", "Yen", "Ringgit", "Baht"}, 2}
    };

    Quiz quiz(quizQuestions);

    std::cout << "Welcome to the Quiz App!\n\n";
    quiz.takeQuiz();
    quiz.displayResult();

    return 0;
}
