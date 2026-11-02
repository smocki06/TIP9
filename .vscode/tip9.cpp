#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Открываем файл для чтения
    ifstream fin("input.txt");
    // Открываем файл для записи
    ofstream fout("output.txt");

    // Сюда будем собирать результат
    string result = "";

    // Читаем файл по одному символу
    char c;
    while (fin.get(c)) {
        // Переводим символ в нижний регистр для сравнения
        char lower = c;
        if (lower >= 'A' && lower <= 'Z') {
            lower = lower - 'A' + 'a';   // превращаем заглавную в строчную
        }

        // Проверяем: является ли буква "запрещённой"?
        // Запрещённые буквы: u s e r a g m n t
        bool banned = false;
        if (lower == 'u') banned = true;
        if (lower == 's') banned = true;
        if (lower == 'e') banned = true;
        if (lower == 'r') banned = true;
        if (lower == 'a') banned = true;
        if (lower == 'g') banned = true;
        if (lower == 'm') banned = true;
        if (lower == 'n') banned = true;
        if (lower == 't') banned = true;

        // Если буква НЕ запрещённая — добавляем её в результат
        if (!banned) {
            result = result + c;
        }
    }

// //1.2 
// #include <iostream>
// #include <fstream>
// #include <string>
// using namespace std;

// int main() {
//     // Открываем файл для чтения
//     ifstream fin("input.txt");
//     // Открываем файл для записи
//     ofstream fout("output.txt");

//     // Проверка: а вдруг файл не нашелся?
//     if (!fin.is_open()) {
//         cout << "Ошибка: файл input.txt не найден! Проверь папку." << endl;
//         return 1; // Завершаем программу с ошибкой
//     }

//     string s;
//     // Читаем ВСЮ строку целиком (второй способ чтения)
//     getline(fin, s); 

//     string result = "";

//     // Идем по строке по индексам
//     for (int i = 0; i < s.length(); i++) {
//         char c = s[i];
//         char lower = c;
        
//         // Переводим в нижний регистр
//         if (lower >= 'A' && lower <= 'Z') {
//             lower = lower - 'A' + 'a';
//         }

//         // Проверяем, запрещенная ли это буква
//         bool banned = false;
//         if (lower == 'u') banned = true;
//         if (lower == 's') banned = true;
//         if (lower == 'e') banned = true;
//         if (lower == 'r') banned = true;
//         if (lower == 'a') banned = true;
//         if (lower == 'g') banned = true;
//         if (lower == 'm') banned = true;
//         if (lower == 'n') banned = true;
//         if (lower == 't') banned = true;

//         // Если не запрещенная — добавляем
//         if (!banned) {
//             result = result + c;
//         }
//     }

//     // Записываем результат
//     fout << result;

//     fin.close();
//     fout.close();

//     cout << "Готово! Проверь файл output.txt" << endl;
//     return 0;
// }

//     // Записываем результат в файл
//     fout << result;

//     // Закрываем файлы (хорошая привычка)
//     fin.close();
//     fout.close();

//     return 0;
// }

// //2
// #include <iostream>
// #include <fstream>
// #include <string>
// using namespace std;

// int main() {
//     // Открываем файлы на чтение
//     ifstream fin1("input1.txt");
//     ifstream fin2("input2.txt");

//     string X, Y;
//     // Читаем строки целиком (одно слово без пробелов)
//     fin1 >> X;
//     fin2 >> Y;

//     // Ищем Y внутри X
//     // find возвращает позицию, где начинается Y, или string::npos, если не нашёл
//     size_t pos = X.find(Y);

//     // Открываем файл для вывода
//     ofstream fout("output.txt");

//     if (pos != string::npos) {
//         fout << "yes";
//     } else {
//         fout << "no";
//     }

//     fin1.close();
//     fin2.close();
//     fout.close();
//     return 0;
// }

// //3
// #include <iostream>
// #include <fstream>
// #include <string>
// using namespace std;

// // Функция: переводит число (в виде строки цифр) в двоичную строку
// string toBinary(string number) {
//     // Сначала превращаем строку цифр в обычное число
//     long long value = 0;
//     for (int i = 0; i < number.length(); i++) {
//         value = value * 10 + (number[i] - '0');
//     }

//     // Особый случай: число 0
//     if (value == 0) return "0";

//     // Переводим в двоичную систему делением на 2
//     string binary = "";
//     while (value > 0) {
//         int digit = value % 2;          // остаток от деления на 2 — это бит
//         binary = char('0' + digit) + binary;  // добавляем бит В НАЧАЛО
//         value = value / 2;              // делим на 2
//     }
//     return binary;
// }

// int main() {
//     ifstream fin("input.txt");
//     ofstream fout("output.txt");

//     string s;
//     getline(fin, s);   // читаем ВСЮ строку, включая возможные пробелы

//     string result = "";
//     int i = 0;
//     while (i < s.length()) {
//         // Если текущий символ — цифра, значит началось число
//         if (s[i] >= '0' && s[i] <= '9') {
//             // Собираем все подряд идущие цифры
//             string number = "";
//             while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
//                 number = number + s[i];
//                 i++;
//             }
//             // Заменяем число на его двоичный вид
//             result = result + toBinary(number);
//         } else {
//             // Обычный символ — просто копируем
//             result = result + s[i];
//             i++;
//         }
//     }

//     fout << result;

//     fin.close();
//     fout.close();
//     return 0;
// }