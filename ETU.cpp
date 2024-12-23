#include <iostream>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <chrono>
#include <ctime>

using namespace std;
using namespace chrono;

int x = 0, y = 0;

void clearConsole() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    DWORD charsWritten;
    DWORD consoleSize;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    consoleSize = consoleInfo.dwSize.X * consoleInfo.dwSize.Y;
    FillConsoleOutputCharacter(hConsole, ' ', consoleSize, { 0, 0 }, &charsWritten);

    FillConsoleOutputAttribute(hConsole, consoleInfo.wAttributes, consoleSize, { 0, 0 }, &charsWritten);

    SetConsoleCursorPosition(hConsole, { 0, 0 });
}

void FillArr(int arr[], int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		arr[i] = (rand() % 199) - 99; // Диапазон от -99 до 99
		cout << arr[i] << " ";
	}
	cout << endl;
}

// Вывод массива.
void PrintArr(int arr[], int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << " ";
	}
}
// Сортировка пузырьком.
void BubbleSort(int arr[], int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		for (int j = 0; j < arrSize - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
// Сортировка шейкером.
void ShakerSort(int arr[], int arrSize)
{
	bool swapped = true;
	int start = 0;
	int end = arrSize - 1;

	while (swapped) {
		swapped = false;

		for (int i = start; i < end; ++i) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}

		if (!swapped)
			break;

		swapped = false;
		--end;

		for (int i = end - 1; i >= start; --i) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}
		++start;
	}
}
// Соритровка расчёской.
void CombSort(int arr[], int arrSize) {
	float k = 1.247;
	float S = arrSize - 1;
	int swap;
	int count = 0;

	while (S >= 1)
	{
		for (int i = 0; i + S < arrSize; i++)
		{
			if (arr[i] > arr[int(i + S)])
			{
				swap = arr[int(i + S)];
				arr[int(i + S)] = arr[i];
				arr[i] = swap;
			}
		}
		S /= k;
	}

	while (true)
	{
		for (int i = 0; i < arrSize - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = swap;
			}
			else count++;
		}
		if (count == arrSize - 1)
			break;
		else
			count = 0;
	}

}
// Сортировка вставками
void InsertionSort(int arr[], int arrSize) {
	{
		for (int i = 1; i < arrSize; i++)
		{
			int j = i - 1;
			while (j >= 0 && arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				j--;
			}
		}
	}
}
// Быстрая сортировка.
void QuickSort(int arr[], int begin, int end) {
	int mid;
	int f = begin;
	int l = end;
	mid = arr[(f + l) / 2];
	while (f < l) {
		while (arr[f] < mid) f++;
		while (arr[l] > mid) l--;
		if (f <= l) {
			swap(arr[f], arr[l]);
			f++;
			l--;
		}
	}
	if (begin < l) QuickSort(arr, begin, l);
	if (f < end) QuickSort(arr, f, end);
}
// Сортировка Шелла.
void ShellSort(int arr[], int arrSize)
{
	int i, j, step;
	int tmp;
	for (step = arrSize / 2; step > 0; step /= 2)
		for (i = step; i < arrSize; i++)
		{
			tmp = arr[i];
			for (j = i; j >= step; j -= step)
			{
				if (tmp < arr[j - step])
					arr[j] = arr[j - step];
				else
					break;
			}
			arr[j] = tmp;
		}
}


// Структура минимального и максимального значений.
struct MinMax {
	int min;
	int max;
};

// Поиск минимальных и максимальных элементов.
MinMax MinAndMaxValue(int arr[], int arrSize, bool sorted) {
	MinMax result = { arr[0], arr[0] };
	if (sorted) {
		result.min = arr[0];
		result.max = arr[arrSize - 1];
	}
	else {
		for (int i = 1; i < arrSize; i++) {
			if (arr[i] < result.min) {
				result.min = arr[i];
			}
			if (arr[i] > result.max) {
				result.max = arr[i];
			}
		}
	}
	return result;
}
// Среднее значение минимального и максимального элементов
void AvgMinMax(int arr[], int arrSize, bool sorted) {
	MinMax resault = MinAndMaxValue(arr, arrSize, sorted);
	int avg = (float(resault.max + resault.min) / 2);
	int cnt = 0;
	cout << "Средний результат максимального и минимального элемента: " << avg << endl;
	cout << "Индексы элементов равные среднему значению: ";
	for (int i = 0; i < arrSize && (!sorted || arr[i] <= avg); i++) {
		if (arr[i] == avg) {
			cout << i << " ";
			++cnt;
		}

	}
	cout << "\nКол - во найденных : " << cnt << endl;


}


// Подсчёт количества элементов меньше заданного числа.
int CntLess(int arr[], int arrSize, int choice) {
	int cnt = 0;
	for (int i = 0; i < arrSize && arr[i] < choice; i++) {
		++cnt;
	}
	return cnt;
}

// Подсчёт количества элементов больше заданного числа.
int CntUp(int arr[], int arrSize, int choice) {
	int cnt = 0;

	for (int i = arrSize - 1; i >= 0 && arr[i] > choice; i--) {
		++cnt;
	}
	return cnt;
}
// Бинарный поиск.
bool BinarySearh(int arr[], int arrSize, int choice) {
	int low = 0;
	while (low <= arrSize) {
		int mid = low + (arrSize - low) / 2;

		if (arr[mid] == choice)
			return true;
		if (arr[mid] < choice)
			low = mid + 1;
		else
			arrSize = mid - 1;
	}
	return false;
}
// Обычный линейный поиск.
bool JustSearch(int arr[], int arrSize, int choice) {
	for (int i = 1; i < arrSize; i++) {
		if (arr[i] == choice) {
			return true;
		}
	}
	return false;
}

void setCursorPosition(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hConsole, position);
}
void printNewLine(int n) {
    y += n;
    x = 0;
    setCursorPosition(x, y);
}

void BubbleSort2(int* arr, int* end) {
    for (int* i = arr; i < end; i++) {
        for (int* j = arr; j < end - (i - arr); j++) {
            if (*j > *(j + 1)) {
                swap(*j, *(j + 1));
            }
        }
    }
}

void CombSort2(int* matrix, int* end) {
    float k = 1.247;
    int s = end - matrix;
    bool swapped = true;

    while (s > 1 || swapped) {
        s = (s > 1) ? int(s / k) : 1;
        swapped = false;

        for (int* i = matrix; i + s < end + 1; i++) {
            if (*i > *(i + s)) {
                swap(*i, *(i + s));
                swapped = true;
            }
        }
    }
}

void InsertionSort2(int* matrix, int* end) {
    {
        for (int* i = matrix; i < end + 1; i++)
        {
            int* j = i - 1;
            while (*j >= 0 && *j > *(j + 1))
            {
                swap(*j, *(j + 1));
                j--;
            }
        }
    }
}

void QuickSort2(int* matrix, int* begin, int* end) {
    int* f = begin;
    int* l = end;
    int mid = *(begin + (end - begin) / 2);

    while (f <= l) {
        while (*f < mid) f++;
        while (*l > mid) l--;

        if (f <= l) {
            swap(*f, *l);
            f++;
            l--;
        }
    }
    if (begin < l) QuickSort2(matrix, begin, l);
    if (f < end) QuickSort2(matrix, f, end);
}



void printMatrix(int* matrix, int n) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int* num = matrix + i * n + j;
            setCursorPosition(x + j * 5, y + i);
            cout << *num;
        }
    }
}

// Заполнение матрицы спиралькой
void fillMatrixSpiral(int* matrix, int n) {
    int num = 1;
    int top = 0, bottom = n - 1, left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            *(matrix + top * n + i) = rand() % 100 + 1;
            setCursorPosition(x + i * 5, y + top);
            cout << *(matrix + top * n + i);
            Sleep(50);
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            *(matrix + i * n + right) = rand() % 100 + 1;
            setCursorPosition(x + right * 5, y + i);
            cout << *(matrix + i * n + right);
            Sleep(50);
        }
        right--;

        for (int i = right; i >= left; i--) {
            *(matrix + bottom * n + i) = rand() % 100 + 1;
            setCursorPosition(x + i * 5, y + bottom);
            cout << *(matrix + bottom * n + i);
            Sleep(50);
        }
        bottom--;

        for (int i = bottom; i >= top; i--) {
            *(matrix + i * n + left) = rand() % 100 + 1;
            setCursorPosition(x + left * 5, y + i);
            cout << *(matrix + i * n + left);
            Sleep(50);
        }
        left++;
    }
    printNewLine(n);
}

// Заполнение матрицы змейкой
void fillMatrixSnake(int* matrix, int n) {
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int value = 1;
    while (top <= bottom && left <= right) {

        for (int i = bottom; i >= top; i--) {
            int* num = matrix + i * n + left;
            *num = rand() % 100 + 1;
            setCursorPosition(x + left * 5, y + i);
            cout << *num;
            Sleep(50);
        }
        left++;

        for (int i = top; i <= bottom; i++) {
            int* num = matrix + i * n + left;
            *num = rand() % 100 + 1;
            setCursorPosition(x + left * 5, y + i);
            cout << *num;
            Sleep(50);
        }
        left++;
    }
    printNewLine(n);
}
void swapBlocks(int* matrix, int n, int firstRowStart, int firstColStart,
    int secondRowStart, int secondColStart, int blockN) {
    for (int i = 0; i < blockN; i++) {
        for (int j = 0; j < blockN; j++) {
            int* elem1 = matrix + (firstRowStart + i) * n + (firstColStart + j);
            int* elem2 = matrix + (secondRowStart + i) * n + (secondColStart + j);
            swap(*elem1, *elem2);
        }
    }
}


void sumToElementsMatrix(int* matrix, int N) {
    int needNum;
    cout << "Введите число, которое нужно прибавить к каждому элементу";
    printNewLine(1);
    cin >> needNum;
    printNewLine(1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int* num = matrix + i * N + j;
            *num += needNum;
        }
    }
}

void delToElementsMatrix(int* matrix, int N) {
    int needNum;
    cout << "Введите число, которое нужно вычесть к каждому элементу";
    printNewLine(1);
    cin >> needNum;
    printNewLine(1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int* num = matrix + i * N + j;
            *num -= needNum;
        }
    }
}

void multToElementsMatrix(int* matrix, int N) {
    int needNum;
    cout << "Введите число, которое нужно умножить к каждому элементу";
    printNewLine(1);
    cin >> needNum;
    printNewLine(1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int* num = matrix + i * N + j;
            *num *= needNum;
        }
    }
}
void divToElementsMatrix(int* matrix, int N) {
    int needNum;
    cout << "Введите число, которое нужно поделить к каждому элементу";
    printNewLine(1);
    cin >> needNum;
    printNewLine(1);
    if (needNum != 0) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int* num = matrix + i * N + j;
                *num /= needNum;
            }
        }
    }
}

void PrintText(char* text, int* len) {
    unsigned int j = 0;
    for (unsigned int i = 0; i < *len; i++, j++) {
        cout << text[i];
    }
    text[j++] = '\0';
}

void InputFromFile(int N, char* text, char* FileName) {
    ifstream File;

    File.open(FileName);
    if (!File.is_open()) {
        cout << "Файл не удалось открыть." << endl;
    }

    File.getline(text, N, '.');
    File.close();
}

void TextLenght(char* text, int* len) {
    unsigned L = 0;

    while (text[L]) {
        ++L;
    }
    *len = L;
}

void FirstEdit(char* text, int* len) {
    unsigned int j = 0;
    int beginLen = *len;
    for (int i = 0; i < beginLen; i++) {
        if (text[i] == ' ' && text[i + 1] == ' ') { // Блок с проверкой на повторяющиеся пробелы.
            continue;
        }

        if (i == 0 || (text[j - 1] == ' ')) { // Блок с проверкой на регистр.
            text[j++] = toupper(text[i]); // Ставит букву заглавной в каждом слове. (под вопросом)
        }

        else {
            text[j++] = tolower(text[i]);
        }

        if (ispunct(text[i]) && (ispunct(text[i + 1]))) { // Блок с проверкой на повторяющиеся знаки препинания.
            int cnt = 1;
            while (i + cnt < beginLen && ispunct(text[i + cnt])) {
                cnt++;
            }
            i += cnt;
            text[j++] = text[i];
        }

    }
    *len = j;
    text[j] = '\0';

}

void PrintWordsWithoutDigits(char* text, int* len) {
    int start = 0;
    bool hasDigit = false;

    for (int i = 0; i <= *len; i++) {
        if (isspace(text[i]) || text[i] == '\0') {
            if (!hasDigit && start < i) {
                for (int j = start; j < i; j++) {
                    cout << text[j];
                }
                cout << " ";
            }
            hasDigit = false;
            start = i + 1;
        }

        else if (isdigit(text[i])) {
            hasDigit = true;
        }
    }

    cout << endl;
}

void PrintWordsLenght(char* text, int* len) {
    int start = 0;

    for (int i = 0; i <= *len; i++) {
        if (isspace(text[i]) || text[i] == '\0') {
            if (start < i) {
                int j = start;
                for (j; j < i; j++) {
                    cout << text[j];
                }
                cout << "(" << j - start << ") ";
            }
            start = i + 1;
        }
    }
    cout << endl;
}

void InputFromKeyboard(char* text, int N) {
    cin.ignore();
    cin.getline(text, N, '.');
    cin.sync();
}

int LinearSubText(char* text, char* subText, int* textLen) {
    int subLen = 0;
    while (subText[subLen] != '\0') {
        subLen++;
    }
    for (int i = 0; i < *textLen - subLen; i++) {
        int j;
        for (j = 0; j < subLen; j++) {
            if (text[i + j] != subText[j]) {
                break;
            }
        }
        if (j == subLen) {
            return i;
        }
    }

    return -1;
}


int BoyerMooreSearch(char* text, char* subText, int* textLen) {
    int subLen = 0;
    while (subText[subLen] != '\0') {
        subLen++;
    }

    int badChar[256];
    for (int i = 0; i < 256; i++) {
        badChar[i] = -1;
    }
    for (int i = 0; i < subLen; i++) {
        badChar[(unsigned char)subText[i]] = i;
    }

    int shift = 0;
    while (shift <= (*textLen - subLen)) {
        int j = subLen - 1;

        while (j >= 0 && subText[j] == text[shift + j]) {
            j--;
        }

        if (j < 0) {
            return shift;
        }
        else {
            shift += max(1, j - badChar[(unsigned char)text[shift + j]]);
        }
    }

    return -1;
}


void lab1(){
    cout << "Под int отводится " << sizeof(int) << " байта памяти" << endl; // 4
    cout << "Под short int отводится " << sizeof(short int) << " байта памяти" << endl; // 2
    cout << "Под long int отводится " << sizeof(long long) << " байта памяти" << endl; // 8 (???? От компилятора чтоль зависит) 
    cout << "Под float отводится " << sizeof(float) << " байта памяти" << endl; // 4
    cout << "Под double отводится " << sizeof(double) << " байт памяти" << endl; // 8
    cout << "Под long double отводится " << sizeof(long double) << " байтов памяти" << endl; // 16
    cout << "Под char отводится " << sizeof(char) << " байт памяти" << endl; // 1
    cout << "Под bool отводитья " << sizeof(bool) << " байт памяти\n" << endl; // 1

    cout << "Теперь нужно ввести целое число для вывода двоичного представления " << endl; // int

    unsigned int mask = 1 << 31;
    int number;
    cin >> number;


    for (int i = 0; i < 32; ++i) {
        cout << ((number & mask) ? 1 : 0);
        if (i % 8 == 0) {
            cout << " ";
        }
        mask = mask >> 1;

    }

    cout << "\nТеперь нужно ввести вещественное число для вывода двоичного представления" << endl; // float

    unsigned int mask2 = 1 << 31;
    union
    {
        float numberFloat;
        int numFloat;
    };
    cin >> numberFloat;
    cout << endl;

    for (int i = 0; i < 32; ++i) {
        cout << ((mask2 & numFloat) ? 1 : 0);
        if ((i == 0) || (i == 8)) {
            cout << " ";
        }
        mask2 = mask2 >> 1;
    }

    cout << "\nТеперь нужно ввести вещественное число (double) для вывода двоичного представления" << endl; // double

    unsigned long long mask3 = 1ULL << 63;
    union
    {
        double numberDouble;
        long long numDouble;
    };
    cin >> numberDouble;
    cout << endl;

    for (int i = 0; i < 64; ++i) {
        cout << ((mask3 & numDouble) ? 1 : 0);
        if ((i == 0) || (i == 8)) {
            cout << " ";
        }
        mask3 = mask3 >> 1;
    }
    cout << endl;
    /* ----------------------------------------------------------------------------------------------------------------------------------
       ---------------------------------------------------------------------------------------------------------------------------------- */

       // integer

       cout << "Реализация ИДЗ: инвертирование битов для int\n";

       bool mode = true;
       int numberIntIdz;
       while (mode) {
           bool whilemode = 1;
           cout << "Введи любое число типа integer (чтобы выйти, введи 0)\n";

           cin >> numberIntIdz;
           if (numberIntIdz == 0) {
               break;
           }
           cout << "Битовое представления числа: (чтобы продолжить - 1, выйти - 0)\n";
           while (whilemode) {
               bool cont = 1;

               unsigned int mask = 1 << 31;
               for (int i = 0; i < 32; ++i) {
                   cout << ((numberIntIdz & mask) ? 1 : 0);
                   if (i % 8 == 0) {
                       cout << " ";
                   }
                   mask = mask >> 1;

               }
               cout << endl;
               numberIntIdz = ~numberIntIdz;
               cin >> cont;

               if (cont == 0) {
                   cout << "Выход\n";
                   whilemode = 0;
               }

           }
       }

       // float

       cout << "Реализация ИДЗ: инвертирование битов для float\n";

       union
       {
           float numberFloatIdz;
           int numFloatIdz;
       };

       while (mode) {
           bool whilemode = 1;
           cout << "Введи любое число типа float (чтобы выйти, введи 0)\n";

           cin >> numberFloatIdz;
           if (numberFloatIdz == 0) {
               break;
           }
           cout << "Битовое представления числа: (чтобы продолжить - 1, выйти - 0)\n";
           while (whilemode) {
               bool cont = 1;

               unsigned int mask = 1 << 31;
               for (int i = 0; i < 32; ++i) {
                   cout << ((mask & numFloatIdz) ? 1 : 0);
                   if ((i == 0) || (i == 8)) {
                       cout << " ";
                       }
                   mask = mask >> 1;
       }
               cout << endl;
               numFloatIdz = ~numFloatIdz;
               cin >> cont;

               if (cont == 0) {
                   cout << "Выход\n";
                   whilemode = 0;
               }

           }
       }

       // double

       cout << "Реализация ИДЗ: инвертирование битов для double\n";

       union
       {
           double numberDoubleIdz;
           long long numDoubleIdz;
       };

       while (mode) {
           bool whilemode = 1;
           cout << "Введи любое число типа double (чтобы выйти, введи 0)\n";

           cin >> numberDoubleIdz;
           if (numberDoubleIdz == 0) {
               break;
           }
           cout << "Битовое представления числа: (чтобы продолжить - 1, выйти - 0)\n";
           while (whilemode) {
               bool cont = 1;

               unsigned long long mask = 1ULL << 63;
               for (int i = 0; i < 32; ++i) {
                   cout << ((mask & numDoubleIdz) ? 1 : 0);
                   if ((i == 0) || (i == 8)) {
                       cout << " ";
                       }
                   mask = mask >> 1;
       }
               cout << endl;
               numDoubleIdz = ~numDoubleIdz;
               cin >> cont;

               if (cont == 0) {
                   cout << "Выход\n";
                   whilemode = 0;
               }

           }
       }
}

void lab2() {
	srand(time(NULL));
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
	nanoseconds resultTime;
	nanoseconds resultSorted;

	const unsigned int N = 600; // Размерность массива
	int arr[N]; // Сам массив

	bool started = true;
	bool choiseStarted = true;

	while (started) {
		bool notSorted = false;
		int sortChoice;
		int operationChoice;
		cout << "Размерность массива - " << N << endl;
		cout << "Неотсортированный массив со случайными числами:" << endl;
		FillArr(arr, N);

		cout << "Предстоит выбрать метод сортировки:" << endl;
		cout << " 1 | Bubble Sort" << endl;
		cout << " 2 | Shaker Sort" << endl;
		cout << " 3 | Comb Sort" << endl;
		cout << " 4 | Insertion sort" << endl;
		cout << " 5 | Quick sort" << endl;
		cout << " 6 | ShellSort" << endl;
		cout << " 7 | Не сортировать массив" << endl;
		cout << " 0 | Выход из программы" << endl;

		cin >> sortChoice;
		if (sortChoice == 0) {
			started = false;
			break;
		}
		start = steady_clock::now();
		switch (sortChoice) {
		case 1: BubbleSort(arr, N); break;
		case 2: ShakerSort(arr, N); break;
		case 3: CombSort(arr, N); break;
		case 4: InsertionSort(arr, N); break;
		case 5: QuickSort(arr, 0, N - 1); break;
		case 6: ShellSort(arr, N); break;
		case 7: notSorted = true; break;
		default: cout << "Неверный выбор" << endl;
		}

		end = steady_clock::now();
		resultSorted = duration_cast<nanoseconds>(end - start);

		cout << "Полученный массив: " << endl;
		PrintArr(arr, N);
		cout << "\nВремя, потраченное на сортировку: " << resultSorted.count() << endl;

		cout << "Теперь предстоит выбрать методы для работы с массивом: " << endl;

		while (choiseStarted) {

			int choiceNumber;
			int cnt;


			cout << " 1 | Найти минимальный и максимальный элементы" << endl;
			cout << " 2 | Найти среднее значение минимального и максимального элементов" << endl;
			cout << " 3 | Подсчитать количество элементов меньше числа a (для отсортированного массива)" << endl;
			cout << " 4 | Подсчитать количество элементов больше числа b (для отсортированного массива)" << endl;
			cout << " 5 | Найти число с помощью бинарного поиска" << endl;
			cout << " 6 | Найти число с помощью обычного перебора" << endl;
			cout << " 0 | Вернуться в главное меню" << endl;

			cin >> operationChoice;

			if (operationChoice == 0) {
				break;
			}

			switch (operationChoice) {
			case 1: {
				start = steady_clock::now();
				MinMax result = MinAndMaxValue(arr, N, !notSorted);
				end = steady_clock::now();
				resultTime = duration_cast<nanoseconds>(end - start);
				cout << "Минимальный элемент: " << result.min << " Максимальный элемент: " << result.max << "\nЗатраченное время: " << resultTime.count() << endl;;
				break;
			}
			case 2: {
				start = steady_clock::now();
				AvgMinMax(arr, N, !notSorted);
				end = steady_clock::now();
				resultTime = duration_cast<nanoseconds>(end - start);
				break;
			}
			case 3: {

				if (notSorted) { cout << "Нужен именно отсортированный массив!!" << endl; break; }


				cout << "Введите число а: " << endl;
				cin >> choiceNumber;

				start = steady_clock::now();
				cnt = CntLess(arr, N, choiceNumber);
				end = steady_clock::now();
				resultTime = duration_cast<nanoseconds>(end - start);
				cout << "Кол-во элементов меньших числа а: " << cnt << "\nЗатраченное время: " << resultTime.count() << endl;
				break;
			}
			case 4: {

				if (notSorted) { cout << "Нужен именно отсортированный массив!!" << endl; break; }

				cout << "Введите число b: " << endl;
				cin >> choiceNumber;

				start = steady_clock::now();
				cnt = CntUp(arr, N, choiceNumber);
				end = steady_clock::now();
				resultTime = duration_cast<nanoseconds>(end - start);

				cout << "Кол-во элементов меньших числа b: " << cnt << "\nЗатраченное время: " << resultTime.count() << endl;
				break;
			}
			case 5: {

				if (notSorted) { cout << "Нужен именно отсортированный массив!!" << endl; break; }

				cout << "Введите число, чтобы узнать есть ли он в массиве или нет." << endl;
				cin >> choiceNumber;

				start = steady_clock::now();
				cout << (BinarySearh(arr, N, choiceNumber) ? "Найдено" : "Не найдено") << endl;
				end = steady_clock::now();
				resultTime = duration_cast<nanoseconds>(end - start);

				cout << "Затраченное время : " << resultTime.count() << endl;
				break;
			}
			case 6: {

				if (notSorted) { cout << "Нужен именно отсортированный массив!!" << endl; break; }

				cout << "Введите число, чтобы узнать есть ли он в массиве или нет." << endl;
				cin >> choiceNumber;

				start = steady_clock::now();
				cout << (JustSearch(arr, N, choiceNumber) ? "Найдено" : "Не найдено") << endl;
				end = steady_clock::now();
				resultTime = duration_cast<nanoseconds>(end - start);

				cout << "Затраченное время : " << resultTime.count() << endl;
				break;
			}
			case 7: {
				int i1, i2;
				cout << "Введите два индекса для обмена: ";
				cin >> i1 >> i2;

				if (i1 >= 0 && i1 < N && i2 >= 0 && i2 < N) {
					start = steady_clock::now();
					swap(arr[i1], arr[i2]);
					end = steady_clock::now();
					resultTime = duration_cast<nanoseconds>(end - start);
				}
				else { cout << "Неверные индексы!" << endl; }

				cout << "Изменённый массив: " << endl;
				PrintArr(arr, N);

				cout << "Затраченное время: " << resultTime.count() << endl;
				break;
			}
			default:
				cout << "Неверный выбор" << endl;
			}
		}
	}
}

void lab3() {
    clearConsole();
    const int N = 8;
    const int halfN = N / 2;

    srand((unsigned)time(0));
    int choice;
    bool started = true;
    int matrix[N][N];
    int* ptr = &matrix[0][0];
    int* end = &matrix[0][0] + N * N - 1;
    cout << "Предстоит выбрать как создать матрицу: \n 1 | Змейкой \n 2 | Спиралькой";
    printNewLine(3);

    cin >> choice;
    printNewLine(1);
    switch (choice) {
    case 1: fillMatrixSnake(ptr, N); break;
    case 2: fillMatrixSpiral(ptr, N); break;
    }
    printNewLine(2);

    cout << "Какую сортировку предпочитаете?\n 1 | Bubble\n 2 | Insertion\n 3 | Comb\n 4 | Quick\n 5 | Не сортировать.";
    printNewLine(6);
    cin >> choice;
    switch (choice) {
    case 1: BubbleSort2(ptr, end); break;
    case 2: InsertionSort2(ptr, end); break;
    case 3: CombSort2(ptr, end); break;
    case 4: QuickSort2(ptr, ptr, end); break;
    case 5: break;
    }
    printMatrix(ptr, N);
    printNewLine(N + 1);



    printNewLine(1);
    while (started) {
        cout << "Предстоит выбрать изменение блоков: \n 1 | По вертикали\n 2 | По горизонтале \n 3 | По диагонали \n 4 | По часово стрелке\n 5 | Выйти.";
        printNewLine(7);
        cin >> choice;
        switch (choice) {
        case 1: swapBlocks(ptr, N, 0, 0, halfN, 0, halfN);
            swapBlocks(ptr, N, 0, halfN, halfN, halfN, halfN);  break;
        case 2: swapBlocks(ptr, N, 0, 0, 0, halfN, halfN);
            swapBlocks(ptr, N, halfN, 0, halfN, halfN, halfN); break;
        case 3: swapBlocks(ptr, N, 0, 0, halfN, halfN, halfN);
            swapBlocks(ptr, N, halfN, 0, 0, halfN, halfN); break;
        case 4: swapBlocks(ptr, N, 0, 0, 0, halfN, halfN); swapBlocks(ptr, N, 0, 0, halfN, halfN, halfN);
            swapBlocks(ptr, N, 0, 0, halfN, 0, halfN); break;
        case 5: started = false; break;

        }
        printMatrix(ptr, N);
        printNewLine(N + 1);
    }
    printNewLine(1);

    started = true;


    while (started) {
        cout << "Теперь предстоит выбрать операцию над матрицами\n 1 | Сложить каждый элемент на число\n 2 | Вычесть каждый элемент на число\n 3 | Умножить каждый элемент на число\n 4 | Поделить каждый элемент на число\n 5 | Выйти.";
        printNewLine(6);
        cin >> choice;
        printNewLine(1);
        switch (choice) {
        case 1: sumToElementsMatrix(ptr, N); break;
        case 2: delToElementsMatrix(ptr, N); break;
        case 3: multToElementsMatrix(ptr, N); break;
        case 4: divToElementsMatrix(ptr, N); break;
        case 5: started = false; break;
        }
        printMatrix(ptr, N);
        printNewLine(N + 1);
    }
}

void lab4() {
    
    const int N = 650;

    int len = 0;

    
    bool started = true; // Для while
    int choice;
    char choiceFileName[50]; // char под название файла.
    char text[N]; // Сам текс.
    char subText[N]; // Подтекст для поиска.
    int* TextLen = &len; // Длина строки text через указатель (в начале len = 0)


    while (started) {
        started = true;
        cout << "Нужно выбрать откуда вводить текст: \n1 | С клавиатуры\n2 | Из файла\n3 | Выйти из программы" << endl;
        cin >> choice;

        switch (choice) {
        case 1: cout << "Введите текст: " << endl; InputFromKeyboard(text, N); break;
        case 2: cout << "Введите название файла: " << endl; cin >> choiceFileName;
            InputFromFile(N, text, choiceFileName); break;
        case 3: started = false; break;
        }
        TextLenght(text, TextLen);

        bool started2 = true;
        while (started && started2) {
            cout << "Теперь необходимо выбрать взаимодействие с текстом: \n1 | Редактировать текст (убрать лишние пробелы, знаки препинания, испр. регистра)\n2 | Вывести на экран слова последовательности, в которых не встречаются цифры\n3 | Вывести кол-во символов в каждом слове\n4 | Вывыести начальный индекс подстроки линейным поиском\n5 | Вывод начальный индекс подстроки алгоритмом Бойера-Мура\n6 | Выход из программы." << endl;
            cin >> choice;
            int result;

            switch (choice) {
            case 1: FirstEdit(text, TextLen); cout << "Отредактированный текст: " << text; break;
            case 2: PrintWordsWithoutDigits(text, TextLen); break;
            case 3: PrintWordsLenght(text, TextLen); break;
            case 4: cout << "Введите текс для поиска подстроки в тексте (должно заканчиваться на точку)" << endl; InputFromKeyboard(subText, N);
                result = LinearSubText(text, subText, TextLen); cout << (result >= 0 ? "Индекс найден: " + to_string(result) : "Индекс не найден"); break;
            case 5: cout << "Введите текс для поиска подстроки в тексте (должно заканчиваться на точку)" << endl; InputFromKeyboard(subText, N);
                result = BoyerMooreSearch(text, subText, TextLen); cout << (result >= 0 ? "Индекс найден: " + to_string(result) : "Индекс не найден"); break;
            case 6: started2 = false; break;
            }
            cout << endl;
        }

    }

}
int main() {
    setlocale(0, "");
    SetConsoleCP(1251);
    bool running = true;

    while (running) {
        cout << "Выберите лабораторную работу:\n" << "1 | Лабораторная работа 1\n" << "2 | Лабораторная работа 2\n3 | Лабораторная работа 3\n4 | Лабораторная работа 4\n5 | Выход\n";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            lab1(); break;
        case 2:
            lab2(); break;
        case 3:
            lab3(); break;
        case 4:
            lab4(); break;
        case 5: running = false; break;
        }
        cout << endl;
        
    }
    return 0;
}