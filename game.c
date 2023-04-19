#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int score = 0;
    int correct_answers = 0;
    int max_questions = 10; //oyunun bitiş sayısı
    int question_count = 1; //sorulan soru sayısı
    int answer;
    int num1, num2, operator_choice;

    srand(time(NULL));

    while (question_count <= max_questions) {
        // Two random integers are initialized
        num1 = rand() % 10;
        num2 = rand() % 10;

        // Two random operator is selected (+, -, *)
        operator_choice = rand() % 3;

        // Operations is made by selected operations and answer is identified.
        if (operator_choice == 0) {
            printf("Question %d: %d + %d = ", question_count, num1, num2);
            answer = num1 + num2;
        }
        else if (operator_choice == 1) {
            printf("Question %d: %d - %d = ", question_count, num1, num2);
            answer = num1 - num2;
        }
        else {
            printf("Question %d: %d * %d = ", question_count, num1, num2);
            answer = num1 * num2;
        }

        // Answer scanned and controlled
        int player_answer;
        scanf("%d", &player_answer);

        if (player_answer == answer) {
            printf("Correct!\n");
            score += 10;
            correct_answers++;
        }
        else {
            printf("Wrong answer, Correct answer is : %d\n", answer);
            score = 0;
        }

        question_count++;

        // Player reaches the score, then finish the game
        if (correct_answers == max_questions) {
            printf("Congratulations. You won the game!\n");
            break;
        }
    }

    printf("Your Score: %d", score);

    return 0;
}
