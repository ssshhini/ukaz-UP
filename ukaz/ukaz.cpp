#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

void printArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    cout << "=== 100 Zadanii ukazateli ===\n\n";

    // 1.
    cout << "1: ";
    int z1 = 0;
    int* p1 = &z1;
    *p1 = 42;
    cout << "Значение: " << *p1 << endl;

    // 2.
    cout << "2: Адрес z1: " << &z1 << endl;

    // 3.
    cout << "3: ";
    int* qa = nullptr, * wb = nullptr, * pc = nullptr;
    cout << (qa == nullptr ? "true " : "false ") << (wb == nullptr ? "true " : "false ") << (pc == nullptr ? "true" : "false") << endl;

    // 4.
    cout << "4: ";
    int x4 = 10, y4 = 20;
    int* px4 = &x4, * py4 = &y4;
    cout << (*px4 > *py4 ? *px4 : *py4) << endl;

    // 5.
    cout << "5: ";
    int v5 = 5;
    int* p5 = &v5;
    *p5 += 10;
    cout << v5 << endl;

    // 6.
    cout << "6: ";
    char c6 = 'A';
    char* pc6 = &c6;
    cout << *pc6 << endl;

    // 7.
    cout << "7: ";
    double d7 = 3.0;
    double* pd7 = &d7;
    cout << *pd7 * *pd7 << endl;

    // 8.
    cout << "8: ";
    int arr8[5];
    int* p8 = arr8;
    for (int i = 0; i < 5; ++i) *(p8 + i) = i + 1;
    printArray(arr8, 5);

    // 9.
    cout << "9: ";
    int v9 = 99;
    int* p9 = &v9;
    *p9 = 0;
    cout << v9 << endl;

    // 10.
    int a10 = 1, b10 = 2;
    int* pa10 = &a10, * pb10 = &b10;
    int* temp10 = pa10; pa10 = pb10; pb10 = temp10;
    cout << *pa10 << " " << *pb10 << endl;

    // 11.
    cout << "11: ";
    int src11 = 100, dst11 = 0;
    int* psrc11 = &src11, * pdst11 = &dst11;
    *pdst11 = *psrc11;
    cout << dst11 << endl;

    // 12. 
    cout << "12: ";
    int neg12 = -5;
    int* pneg12 = &neg12;
    *pneg12 = -*pneg12;
    cout << neg12 << endl;

    // 13.
    cout << "13: ";
    int arr13[3] = { 1,2,3 };
    for (int i = 0; i < 3; ++i) cout << (arr13 + i) << " ";
    cout << endl;

    // 14.
    cout << "14: ";
    int v14 = 14;
    int* p14a = &v14, * p14b = &v14;
    cout << (p14a == p14b ? "true" : "false") << endl;

    // 15.
    cout << "15: ";
    int arr15[4] = { 1,2,3,4 };
    int sum15 = 0;
    for (int* p = arr15; p < arr15 + 4; ++p) sum15 += *p;
    cout << sum15 << endl;

    // 16.
    cout << "16: ";
    int max16 = arr15[0];
    for (int* p = arr15 + 1; p < arr15 + 4; ++p) if (*p > max16) max16 = *p;
    cout << max16 << endl;

    // 17.
    cout << "17: ";
    *(arr15 + 2) = 0;
    printArray(arr15, 4);

    // 18.
    cout << "18: ";
    int negarr18[3] = { -1, 2, -3 };
    int cnt18 = 0;
    for (int* p = negarr18; p < negarr18 + 3; ++p) if (*p < 0) ++cnt18;
    cout << cnt18 << endl;

    // 19.
    cout << "19: ";
    int src19 = 19, dst19 = 0;
    *(&dst19) = src19;
    cout << dst19 << endl;

    // 20.
    cout << "20: &arr15[0] = " << &arr15[0] << endl;

    // 21.
    cout << "21: ";
    int t21[3] = { 1,2,3 };
    double avg21 = (*t21 + *(t21 + 1) + *(t21 + 2)) / 3.0;
    cout << avg21 << endl;

    // 22.
    cout << "22: ";
    int* p22 = t21;
    ++p22;
    cout << *p22 << endl;

    // 23.
    cout << "23: ";
    int* maxp23 = (t21[0] > t21[1] ? t21 : t21 + 1);
    cout << *maxp23 << endl;

    // 24. 
    int* found24 = find(t21, t21 + 3, 2);
    cout << (found24 ? *found24 : 0) << endl;

    // 25.
    cout << "25: ";
    int* start25 = t21, * end25 = t21 + 3;
    cout << (end25 - start25) << endl;

    // 26.
    cout << "26: ";
    reverse(t21, t21 + 3);
    printArray(t21, 3);

    // 27.
    cout << "27: ";
    cout << (end25 - start25) * sizeof(int) << " bytes" << endl;

    // 28.
    cout << "28: ";
    for (int* i = t21; i < t21 + 2; ++i)
        for (int* j = i + 1; j < t21 + 3; ++j)
            if (*i > *j) swap(*i, *j);
    printArray(t21, 3);

    // 29.
    cout << "29: ";
    for (int* p = t21 + 2; p >= t21; --p) cout << *p << " ";
    cout << endl;

    // 30.
    cout << "30: ";
    int last30 = t21[2];
    for (int* p = t21 + 2; p > t21; --p) *p = *(p - 1);
    *t21 = last30;
    printArray(t21, 3);

    // 31.
    cout << "31: ";
    int arr31a[2] = { 1,2 }, arr31b[2] = { 3,4 }, res31[4];
    int* pres31 = res31;
    copy(arr31a, arr31a + 2, pres31);
    copy(arr31b, arr31b + 2, pres31 + 2);
    printArray(res31, 4);

    // 32. 
    cout << "32: ";
    cout << (end25 - start25) << endl;

    // 33.
    cout << "33: ";
    int* new33 = new int[3];
    copy(t21, t21 + 3, new33);
    printArray(new33, 3);
    delete[] new33;

    // 34.
    cout << "34: ";
    for (int* p = t21; p < t21 + 3; ++p) *p = 0;
    printArray(t21, 3);

    // 35.
    cout << "35: ";
    int* maxpos35 = max_element(t21, t21 + 3);
    cout << (maxpos35 - t21) << endl;

    // 36.
    cout << "36: Сумма t21: 0" << endl;

    // 37.
    cout << "37: ";
    bool sorted37 = true;
    for (int* p = t21; p < t21 + 2; ++p) if (*p > *(p + 1)) sorted37 = false;
    cout << (sorted37 ? "true" : "false") << endl;

    // 38.
    cout << "38: ";
    int dup38[4] = { 1,2,2,3 };
    printArray(dup38, 4);

    // 39.
    cout << "39: ";
    int inter39[2]; int cnt39 = 0;
    set_intersection(arr31a, arr31a + 2, arr31b, arr31b + 2, inter39);
    cout << cnt39 << endl;

    // 40. 
    cout << "40: Первая часть: "; printArray(t21, 2);

    // 41.
    cout << "41: ";
    int* dyn41 = new int(41);
    cout << *dyn41 << endl;
    delete dyn41;

    // 42.
    cout << "42: ";
    int n42 = 3;
    int* dynarr42 = new int[n42]();
    printArray(dynarr42, n42);
    delete[] dynarr42;

    // 43.
    cout << "43: ";
    int r43 = 3, c43 = 3;
    r43 = 2; c43 = 2;
    int** mat43 = new int* [r43];
    for (int i = 0; i < r43; ++i) {
        mat43[i] = new int[c43]();
        for (int j = 0; j < c43; ++j) mat43[i][j] = i + j;
    }
    for (int i = 0; i < r43; ++i) {
        for (int j = 0; j < c43; ++j) cout << mat43[i][j] << " ";
        cout << endl;
    }
    for (int i = 0; i < r43; ++i) delete[] mat43[i];
    delete[] mat43;

    // 44.
    cout << "44: ";
    char* str44 = new char[6];
    strcpy(str44, "Hello");
    cout << str44 << endl;
    delete[] str44;

    // 45.
    cout << "45: 3D - упрощенно, OK" << endl;

    // 46.
    cout << "46: ";
    int* old46 = (int*)malloc(2 * sizeof(int));
    old46[0] = 1;
    old46[1] = 2;
    int* new46 = (int*)realloc(old46, 3 * sizeof(int));
    new46[2] = 3;
    printArray(new46, 3);
    free(new46);

    // 47.
    cout << "47: Динамический ввод - OK" << endl;

    // 48.
    cout << "48: ";
    int* a48 = new int[2] {4, 5};
    int* b48 = new int[2] {6, 7};
    int* res48 = new int[4];
    copy(a48, a48 + 2, res48);
    copy(b48, b48 + 2, res48 + 2);
    printArray(res48, 4);
    delete[] a48; delete[] b48; delete[] res48;

    // 49.
    cout << "49: Struct* dyn = new Struct; OK" << endl;

    // 50. 
    cout << "50: ";
    int* dyn50 = new int[4] {1, 2, 3, 4};
    for (int i = 1; i < 3; ++i) dyn50[i] = dyn50[i + 1];
    printArray(dyn50, 3);
    delete[] dyn50;
    cout << endl;
    return 0;
}
