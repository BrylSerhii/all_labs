#include <iostream>
#include <vector>
#include <algorithm>

/*Реалізуйте програму для сортування алгоритмом radix sort,
щоб відсортувати велику базу даних імен на основі їхніх прізвищ (алфавітний порядок).
Приклад рядку (ідентифікатор,імʼя,прізвище,по-батькові): "123,John,Doe,Ivanovich"*/

using namespace std;

int getMax(vector<string>& arr) {
    int max = arr[0].substr(arr[0].find(',') + 1, arr[0].find_last_of(',') - arr[0].find(',') - 1).length();
    for (int i = 1; i < arr.size(); i++) {
        int length = arr[i].substr(arr[i].find(',') + 1, arr[i].find_last_of(',') - arr[i].find(',') - 1).length();
        if (length > max) {
            max = length;
        }
    }
    return max;
}

void radixSort(vector<string>& arr) {
    int max = getMax(arr);

    for (int digit = max - 1; digit >= 0; digit--) {
        vector<string> output(arr.size());
        int count[256] = { 0 };

        for (int i = 0; i < arr.size(); i++) {
            string lastName = arr[i].substr(arr[i].find(',') + 1, arr[i].find_last_of(',') - arr[i].find(',') - 1);
            if (digit < lastName.length()) {
                count[static_cast<unsigned char>(lastName[digit])]++;
            }
            else {
                count[0]++;
            }
        }

        for (int i = 1; i < 256; i++) {
            count[i] += count[i - 1];
        }

        for (int i = arr.size() - 1; i >= 0; i--) {
            string lastName = arr[i].substr(arr[i].find(',') + 1, arr[i].find_last_of(',') - arr[i].find(',') - 1);
            if (digit < lastName.length()) {
                output[count[static_cast<unsigned char>(lastName[digit])] - 1] = arr[i];
                count[static_cast<unsigned char>(lastName[digit])]--;
            }
            else {
                output[count[0] - 1] = arr[i];
                count[0]--;
            }
        }

        arr = output;
    }
}

int main() {
    vector<string> names = {
            "John,Doe,Ivanovich",
            "Mary,Smith,Anne",
            "David,Johnson,Andrew",
            "Sarah,Williams,Jane",
            "Michael,Brown,Thomas"
    };

    radixSort(names);

    for (const auto& name : names) {
        cout << name << endl;
    }

    return 0;
}
