#include <iostream>
#include <fstream>

using namespace std;
void QuickSort(int* tab, int left, int right, int &comparisons);
int* RandomTable(int length);
void Swap(int *tab, int i, int j);
double QuickSortStatistics(int length, int max);
void TestQuickSort();

void Swap(int *tab, int i, int j) {
    int temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;
}

int* RandomTable(int length) {
    int *tab = new int[length];

    for (int i = 0; i < length; i++) {
        tab[i] = rand() % 100;
    }

    return tab;
}

void QuickSort(int *tab, int left, int right, int &comparisons) {
    int pos = left;
    int i = left + 1;

        if (left < right) {
            while ( i <= right) {
                if (tab[i] < tab[left]) {
                    pos++;
                    Swap(tab, pos, i);
                }
                i++;
                comparisons++;
            }
            Swap(tab, pos, left);
            QuickSort(tab, left, pos - 1, comparisons);
            QuickSort(tab, pos + 1, right, comparisons);
        }
}

double QuickSortStatistics(int length, int max) {
    int comparisons = 0;
    for(int i = 0; i < max; i++) {
        int* tab = RandomTable(length);
        QuickSort(tab, 0, length - 1, comparisons);
        delete[] tab;

    }
    return (double)comparisons/max;
}

void TestQuickSort() {
    int finalLength = 1000;
    ofstream resultsQuickSort("/Users/janchmielewski/Desktop/Uni/Algorytmy I Struktury Danych/Sortowanie Szybkie/QuickSortStatistics");
    for(int length = 10; length <= finalLength; length += 10) {
        float average = QuickSortStatistics(length, 1000);
        resultsQuickSort << "\n" << length << "               " << average;
    }
    resultsQuickSort.close();
}

int main() {
    TestQuickSort();
    return 0;
}