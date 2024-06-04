#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int value;
} HashItem;

typedef struct {
    HashItem* items;
    int size;
    int capacity;
} HashTable;

unsigned int hash(int key, int capacity) {
    return abs(key) % capacity;
}

HashTable* createTable(int capacity) {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    table->size = 0;
    table->capacity = capacity;
    table->items = (HashItem*)calloc(capacity, sizeof(HashItem));
    return table;
}

void freeTable(HashTable* table) {
    free(table->items);
    free(table);
}

void insert(HashTable* table, int key, int value) {
    unsigned int index = hash(key, table->capacity);
    while (table->items[index].key != 0) {
        index = (index + 1) % table->capacity;
    }
    table->items[index].key = key;
    table->items[index].value = value;
    table->size++;
}

int search(HashTable* table, int key) {
    unsigned int index = hash(key, table->capacity);
    while (table->items[index].key != 0) {
        if (table->items[index].key == key) {
            return table->items[index].value;
        }
        index = (index + 1) % table->capacity;
    }
    return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    HashTable* table = createTable(numsSize);
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int complementIndex = search(table, complement);
        if (complementIndex != -1) {
            int* result = (int*)malloc(2 * sizeof(int));
            result[0] = complementIndex;
            result[1] = i;
            *returnSize = 2;
            freeTable(table);
            return result;
        }
        insert(table, nums[i], i);
    }
    *returnSize = 0;
    freeTable(table);
    return NULL;
}

int main() {
    int nums[] = {2, 9, 11, 7};
    int target = 9;
    int returnSize;
    int* result = twoSum(nums, 4, target, &returnSize);
    if (returnSize == 2) {
        printf("Indices: %d, %d\n", result[0], result[1]);
        free(result);
    } else {
        printf("No two sum solution found.\n");
    }
    return 0;
}
