#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    int type;
} Pair;

void find_combinations(Pair* nums, int size, int target, Pair* current_combination, int current_size, Pair** results, int* results_size) {
    if (target == 0) {
        Pair* result = malloc(current_size * sizeof(Pair));
        for (int i = 0; i < current_size; i++) {
            result[i] = current_combination[i];
        }
        *results_size += 1;
        *results = realloc(*results, *results_size * sizeof(Pair*));
        (*results)[*results_size - 1] = result;
        return;
    }
    if (target > 0 && size > 0) {
        find_combinations(nums + 1, size - 1, target - nums[0].num, current_combination, current_size, results, results_size);
        current_combination[current_size] = nums[0];
        find_combinations(nums + 1, size - 1, target, current_combination, current_size + 1, results, results_size);
    }
}

int main() {
    int n, z;
    scanf("%d %d", &n, &z);
    
    Pair* l = malloc(2 * n * sizeof(Pair));
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        l[2 * i].num = a;
        l[2 * i].type = 1;
        l[2 * i + 1].num = b;
        l[2 * i + 1].type = 2;
    }
    
    Pair* results = NULL;
    int results_size = 0;
    Pair* current_combination = malloc(n * sizeof(Pair));
    find_combinations(l, 2 * n, z, current_combination, 0, &results, &results_size);
    
    int* lista = malloc(results_size * sizeof(int));
    for (int i = 0; i < results_size; i++) {
        int score = 0;
        for (int j = 0; j < n; j++) {
            if (results[i][j].type == 1) {
                score += results[i][j].num;
            }
        }
        lista[i] = score;
    }
    
    int min_score = lista[0];
    int ind = 0;
    for (int i = 1; i < results_size; i++) {
        if (lista[i] < min_score) {
            min_score = lista[i];
            ind = i;
        }
    }
    
    printf("%d\n", min_score);
    
    free(l);
    free(current_combination);
    for (int i = 0; i < results_size; i++) {
        free(results[i]);
    }
    free(results);
    free(lista);
    
    return 0;
}

