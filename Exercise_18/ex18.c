#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/** Our old friend die from ex17. */
void die(const char *message)
{
    if (errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

// a typedef creates a fake type, in this
// case for a function pointer
typedef int (*compare_cb) (int a, int b);
typedef int *(*sort_algo) (int *numbers, int count, compare_cb cmp);

/**
 * A classic bubble sort function that uses the
 * compare_cb to do the sorting.
 */
int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
    int temp = 0;
    int i = 0;
    int j = 0;
    int swapped;
    int *target = malloc(count * sizeof(int));

    if (!target)
        die("Memory error.");
    
    memcpy(target, numbers, count * sizeof(int));

    for (i = 0; i < count; i++) {
        swapped = 0;
        for (j = 0; j < count - i - 1; j++) {
            if (cmp(target[j], target[j + 1]) > 0) {
                temp = target[j + 1];
                target[j + 1] = target[j];
                target[j] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }

    return target;
}

int *selection_sort(int *numbers, int count, compare_cb cmp)
{
    int temp = 0;
    int index_of_min_element;
    int *target = malloc(count * sizeof(int));

    if (!target)
        die("Memory error.");
    
    memcpy(target, numbers, count * sizeof(int));

    for (int i = 0; i < count - 1; i++) {
        index_of_min_element = i;
        for (int j = i + 1; j < count; j++) {
            if (cmp(target[index_of_min_element], target[j]) > 0) {
                index_of_min_element = j;
            }
        }
        temp = target[index_of_min_element];
        target[index_of_min_element] = target[i];
        target[i] = temp;
    }

    return target;
}

int *insertion_sort(int *numbers, int count, compare_cb cmp)
{
    int j, key;
    int *target = malloc(count * sizeof(int));

    if (!target)
        die("Memory error.");
    
    memcpy(target, numbers, count * sizeof(int));

    for (int i = 1; i < count; i++) {
        key = target[i];
        j = i - 1;
        while (cmp(target[j], key) > 0 && j >= 0) {
            target[j + 1] = target[j];
            --j;
        }
        target[j + 1] = key;
    }

    return target;
}

int sorted_order(int a, int b)
{
    return a - b;
}

int reverse_order(int a, int b)
{
    return b - a;
}

int strange_order(int a, int b)
{
    if (a == 0 || b == 0) {
        return 0;
    } else {
        return a % b;
    }
}

/**
 * Used to test that we are sorting things correctly
 * by doing the sort and printing it out.
 */
void test_sorting(sort_algo algo, int *numbers, int count, compare_cb cmp)
{
    int i = 0;
    int *sorted = algo(numbers, count, cmp);

    if (!sorted)
        die("Failed to sort as requested.");

    for (i = 0; i < count; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");

    free(sorted);
}

void destroy(compare_cb cmp)
{
    int i = 0;

    // convert your function to string!
    unsigned char *data = (unsigned char *)cmp;

    for (i = 0; i < 1; i++) {
        data[i] = i;
    }

    printf("\n");
}

void dump(compare_cb cmp)
{
    int i = 0;

    unsigned char *data = (unsigned char *)cmp;

    for (i = 0; i < 30; i++) {
        printf("%02x:", data[i]);
    }

    printf("\n");
}

int main(int argc, char *argv[])
{
    if (argc < 2) die("USAGE: ex18 4 3 1 5 6");

    int count = argc - 1;
    int i = 0;
    char **inputs = argv + 1;

    int *numbers = malloc(count * sizeof(int));
    if (!numbers) die("Memory error.");

    for (i = 0; i < count; i++) {
        numbers[i] = atoi(inputs[i]);
    }

    printf("bubble_sort:\n");
    test_sorting(bubble_sort, numbers, count, sorted_order);
    test_sorting(bubble_sort, numbers, count, reverse_order);
    test_sorting(bubble_sort, numbers, count, strange_order);

    printf("\nselection_sort:\n");
    test_sorting(selection_sort, numbers, count, sorted_order);
    test_sorting(selection_sort, numbers, count, reverse_order);
    test_sorting(selection_sort, numbers, count, strange_order);

    printf("\ninsertion_sort:\n");
    test_sorting(insertion_sort, numbers, count, sorted_order);
    test_sorting(insertion_sort, numbers, count, reverse_order);
    test_sorting(insertion_sort, numbers, count, strange_order);

    free(numbers);

    printf("SORTED: ");
    dump(sorted_order);

    printf("SORTED: ");
    dump(reverse_order);

    printf("SORTED: ");
    dump(strange_order);

    // destroy(sorted_order);

    // printf("SORTED: ");
    // dump(sorted_order);

    return 0;
}
