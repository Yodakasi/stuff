#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 62

void replace(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void randomize(int *tab, int n) {
    for(int i=0; i<n; i++) {
        tab[i] = rand() % 100;
    }
}

void show(int *tab, int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", tab[i]);
    }
    puts("");
}

void copyLists(int *tab1, int *tab2, int n) {
    for(int i=0; i<n; i++) {
        tab2[i] = tab1[i];
    }
}

void bubbleSort(int *tab, int n) {
    for(int i=0; i<n - 1; i++) {
        for(int j=0; j<n-i-1; j++){
            if(tab[j] > tab[j + 1]) {
                replace(&tab[j], &tab[j + 1]);
            }
        }
    }
}

void insertSort(int *tab, int n) {
    for(int i=1; i<n; i++) {
        int j = i;
        while((tab[j] < tab[j - 1]) && (j > 0)) {
            replace(&tab[j], &tab[j - 1]);
            j--;
        }
    }
}

void selectSort(int *tab, int n) {
    for(int i=0; i<n - 1; i++) {
        int min = i;
        for(int j=i; j<n; j++){
            if(tab[j] < tab[min]) {
                min = j;
            }
        }
        replace(&tab[min], &tab[i]);
    }
}

void shellSort(int *tab, int n) {
    int h = n/2;
    int tab2[n];
    while(h > 1) {
        for(int k=0; k<h; k++) {
            int j = 0;
            for(int i=k; i<n; i+=h) {
                tab2[j] = tab[i];
                j++;
            }
            insertSort(tab2, j);
            j = 0;
            for(int i=k; i<n; i+=h) {
                tab[i] = tab2[j];
                j++;
            }
        }
        h /= 2;
        
    }
    selectSort(tab, n);
}

void quickSort(int *tab, int p, int k) {
    int i = p;
    int j = k;
    int pivot = tab[(i+j)/2];
    do {
        while(tab[i] < pivot)
            i++;
        while(tab[j] > pivot)
            j--;
        if(i <= j) {
            replace(&tab[i], &tab[j]);
            i++;
            j--;
        }
    } while(i <= j);
    if(j > p)
        quickSort(tab, p, j);
    if(i < k)
        quickSort(tab, i, k);
}


int main(int argc, char const *argv[]) {
    srand(time(0));
    clock_t t;
    int orgTab[N];
    int tab[N];
    randomize(orgTab, N);
    puts("Bubble sort:");
    copyLists(orgTab, tab, N);
    show(tab, N);
    t = clock();
    bubbleSort(tab, N);
    t = clock() - t; 
    show(tab, N);
    printf("It took %f\n", ((double)t)/CLOCKS_PER_SEC);
    puts("");
    puts("Insert sort:");
    copyLists(orgTab, tab, N);
    show(tab, N);
    t = clock();
    insertSort(tab, N);
    t = clock() - t;
    show(tab, N);
    printf("It took %f\n", ((double)t)/CLOCKS_PER_SEC);
    puts("");
    puts("Select sort:");
    copyLists(orgTab, tab, N);
    show(tab, N);
    t = clock();
    selectSort(tab, N);
    t = clock() - t;
    show(tab, N);
    printf("It took %f\n", ((double)t)/CLOCKS_PER_SEC);
    puts("");
    puts("Shell sort:");
    copyLists(orgTab, tab, N);
    show(tab, N);
    t = clock();
    shellSort(tab, N);
    t = clock() - t;
    show(tab, N);
    printf("It took %f\n", ((double)t)/CLOCKS_PER_SEC);
    puts("");
    puts("Quick sort:");
    copyLists(orgTab, tab, N);
    show(tab, N);
    t = clock();
    quickSort(tab, 0, N-1);
    t = clock() - t;
    show(tab, N);
    printf("It took %f\n", ((double)t)/CLOCKS_PER_SEC);
    
    return 0;
}
