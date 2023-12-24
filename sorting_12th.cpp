#include <iostream>

/*
                Sorting -
                            1. Selection sort
                            2. Bubble sort
                            3. Insertion sort


                1. Selection Sort -  select the minimum from the array and swap it.
                                    exa- arr - {13, 46, 24, 52, 20, 9}
                                        step1- {9, 46, 24, 52, 20, 13}
                                        step2- {9, 13, 24, 52, 20, 46}
                                        step3- {9, 13, 20, 52, 24, 46}
                                        step4- {9, 13, 20, 24, 52, 46}
                                        step5- {9, 13, 20, 24, 46, 52}

                        TC - O(N^2)     // <- is the best, avg and worst

        pseudo code
    we can say that
     in step1 - swap at index 0 and min index n => [0 -> n - 1]
        step2 - swap at index 1 and min index n => [1 -> n - 1]
        step3 - swap at index 2 and min index n => [2 -> n - 1]

        by above example we can say that swapping is happened till 'n-2'(we start at 0)
        so

        steplast - swap at index 'n - 2' and min index n => [n - 2 -> n - 1]


for(int i = 0; i <= n - 2; i++)         // for swapping of nmbr
{
    min = i                 // <- assuming
    for(int j = 0; j < n - 1; j++)      // to find min index, once this loop completed it will give minm and store in 'min i'
    {
        if(arr[j] < arr[min i])
        min i = j
    }
    swap(arr[min j], arr[i])            // or use basic swap- temp = a, a = b, b = temp
}


        Actual Code

void selection_sort(int arr[], int n)
{
    for(int i = 0; i < n - 2; i++)
    {
        int mini = i;
        for(int j = 1; j < n - 1; j++)
        {
            if(arr[j] < arr[mini])
            {
                mini = j;
            }
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    selection_sort(arr, n);
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
*/



/*
                        2. Bubble sort -  push the maximum to the last by adjacent swaps

                                    exa- lets take an array, arr- {13, 46, 24, 52, 20, 9}
                                                                  {13, 46, 24, 52, 20, 9}
                                                                  {13, 24, 46, 52, 20, 9}
                                                                  {13, 24, 46, 20, 52, 9}
                                                                  {13, 24, 46, 20, 9, 52}
                                                                  {13, 24, 20, 46, 9, 52}
                                                                  {13, 24, 20, 9, 46, 52}
                                                                  {13, 20, 24, 9, 46, 52}
                                                                  {13, 20, 9, 24, 46, 52}
                                                                  {13, 9, 20, 24, 46, 52}
                                                                  {9, 13, 20, 24, 46, 52}

                                TC - O(N^2)         // <- worst/avg
                                     O(N)           // <- best, when the array is in correct order

        pseudo code
        we went from 0 to n - 1
        then went from 0 to n - 2       // bcz maximum gets to the last, so we exclude it
        then went from 0 to n - 3
        then went from 0 to n - 4
        ...
        ...
        last went from 0 to 1

    for(int i = n - 1; i >= 1; i--)         // 'i' is for "n - 1" to "1"
    {
        for(int j = 0; j <= i - 1; i++)     // for i = n-1, j goes from 0 to n-2,  for i = n-2, j goes from 0 to n-3,  and similarly
        {                                   // we are taking j = i - 1 bcz we can't compare the last element with with element o/s the array
            if(arr[j] > arr[j + 1])
                swap
        }
    }


    Actual Code
void bubble_sort(int arr[], int n)
{
    for(int i = n - 1; i >= 1; i--)
    {
        for(int j = 0; j <= i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bubble_sort(arr, n);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
*/



/*
                        3. Insertion Sort -  takes an element and place it in its correct position

                lets take an array, arr- {14, 9, 15, 12, 6, 8, 13}
                first it will check first position & sort- {14, 9, 15, 12, 6, 8, 13}     // <-first place is 0 index, and 14 is in correct position
                then it will check second position & sort- {9, 14, 15, 12, 6, 8, 13}
                then 3rd position & sort-                  {9, 14, 15, 12, 6, 8, 13}
                then                    - {9, 14, 12, 15, 6, 8, 13} -> {9, 12, 14, 15, 6, 8, 13}
                then                    - {9, 12, 14, 6, 15, 8, 13} -> {9, 12, 6, 14, 15, 8, 13} -> {9, 6, 12, 14, 15, 8, 13} > {6, 9, 12, 14, 15, 8, 13}
                similarly               - all the steps then {6, 8, 9, 12, 14, 15, 13}
                at last                 - all the steps then {6, 8, 9, 12, 13, 14, 15}

        TC -  n × (n+1)/2  or O(n^2),           // worst, avg -> O(n^2)
                                                // best -> O(n),  while array is in already sorted order

        pseudo code
for(i = 0; i < n - 1; i++)          // we are running from 0 to n-1
{
    j = i
    while(j > 0 && a[j - 1] > a[j])     // if i=2(15 in our array), then arr[j-1] > a[j] will become arr[1]>arr[2]
    {
        swap(a[j-1], a[j])
        j--
    }
}


        Actual Code
insertion_sort(int arr[], int n)
{
    for(int i = 0; i < n -1; i++)
    {
        int j = i;
        while(j > 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;

            j--;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin << arr[i];
    }

    insertion_sort(arr, n);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
*/

int main()
{
    std::cout << "Hello World!\n";
}