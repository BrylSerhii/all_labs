#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
/*
Програма автодоповнення: реалізуйте програму, яка надає пропозиції автодоповнення тексту для заданої вхідної фрази
за допомогою моделі ланцюга Маркова. Програма має використовувати масив для зберігання вхідних текстових
даних і інший масив для зберігання моделі ланцюга Маркова. Програма повинна запропонувати користувачеві ввести фразу та
порядок моделі ланцюга Маркова.
*/

using namespace std;

vector<string> fruits = {
        "apple", "apricot", "banana", "blueberry", "cherry", "coconut", "grapefruit",
        "grapes", "kiwi", "lemon", "lime", "mango", "orange", "peach", "pear",
        "pineapple", "plum", "raspberry", "strawberry", "watermelon"
};

string autocomplete(const string& partialWord) {
    vector<string> candidates;

    for (const string& fruit : fruits) {
        if (fruit.find(partialWord) == 0) {
            candidates.push_back(fruit);
        }
    }

    if (candidates.empty()) {
        return "No suggestions found.";
    } else {
        srand(static_cast<unsigned int>(time(nullptr)));
        int index = rand() % candidates.size();
        return candidates[index];
    }
}

int main() {
    string partialWord;

    cout << "Enter a partial word: ";
    cin >> partialWord;

    string suggestion = autocomplete(partialWord);

    cout << "Autocomplete suggestion: " << suggestion << endl;

    return 0;
}
