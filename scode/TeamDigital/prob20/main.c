#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

int escape_from_grid(int n, int m, int **grid) {
   
}

int main() {
    int grid_x;
    scanf("%d", &grid_x);
    int grid_y;
    scanf("%d", &grid_y);
    int i_grid, j_grid;
    int **grid = (int **) malloc(grid_x * sizeof(int *));
    for (i_grid = 0; i_grid < grid_x; i_grid++) {
        grid[i_grid] = (int *) malloc(grid_y * sizeof(int));
    }
    for (i_grid = 0; i_grid < grid_x; i_grid++) {
        for (j_grid = 0; j_grid < grid_y; j_grid++) {
            scanf("%d", &grid[i_grid][j_grid]);
        }
    }

    int out_ = escape_from_grid(grid_x, grid_y, grid);
    printf("%d", out_);
}