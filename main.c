/// QUTAIBA ALASHQAR, 20290036.
/// LAB_2, DATA STRUCURE,

#include <stdio.h>
#include <stdlib.h>
//int repet = 0;
//int bolbs = 0;
//int size_allready = 0;
//int allredy_in_row[size_allready];
//int allredy_in_col[size_allready];
//int repetation[repet];
int colll;
int size;
int find_bolbs(int arr[][colll], int roww, int coll, int array_roww[size], int array_coll[size], int real_sizee);
//int check(int star, int i, int j, int roww, int coll, int arr[][colll]);


int main()
{
    int row, col;
    scanf("%d", &row);
    scanf("%d", &col);
    int array[row][col];
    int size_guessed = row * col;
    int array_row[size_guessed];
    int array_col[size_guessed];
    int real_size = 0;
    int position = 0;
    int index_1;
    int index_2;
    colll = col;
    //
    for (int i = 0; i < size_guessed; i++){
        scanf("%d", &index_1);
        if (index_1 == -1){
            break;
        }
        else{
            array_row[position] = index_1;
            scanf("%d", &index_2);
            array_col[position] = index_2;
            position++;
            real_size++;
        }
    }
    size = real_size;
    //
    int status = 0;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            status = 0;
            for (int k = 0; k < real_size; k++){
                if (array_row[k] == i && array_col[k] == j){
                    array[i][j] = 1;
                    status = 1;
                    break;
                }
            }
            if (status == 0){
                array[i][j] = 0;
            }
            status = 0;
        }
    }
    //
    find_bolbs(array, row, col, array_row, array_col, real_size);
    //
    return 0;
}

int find_bolbs(int arr[][colll], int roww, int coll, int array_roww[size], int array_coll[size], int real_sizee){

    int star = 1;
    int repet = 0;
    int bolbs = 0;
    int size_bolbs = 100;
    int counter = 0;
    int counter_used = 0;
    int result[size_bolbs];
    int allready_used_i[size_bolbs];
    int allready_used_j[size_bolbs];
    int flag = 0;


    for (int i = 0; i < roww; i++){
        for (int j = 0; j < coll; j++){
            flag = 0;
            for (int w = 0; w < counter_used; w++){
                if ((i == allready_used_i[w]) && (allready_used_j[w] == j)){
                    flag = 1;
                }
            }

            if ((arr[i][j] == star) && (flag != 1)){
                allready_used_i[counter_used] = (i);
                allready_used_j[counter_used] = (j);
                counter_used++;
                bolbs++;
                repet++;
                bool flag_2 = true;
                int new_position = 1;
                while (flag_2 == true){
                    if (arr[i][j + new_position] == star){ // right
                        repet++;
                        allready_used_i[counter_used] = (i);
                        allready_used_j[counter_used] = (j + new_position);
                        counter_used++;
                    }
                    if (arr[i][j - new_position] == star){ // left
                        repet++;
                        allready_used_i[counter_used] = (i);
                        allready_used_j[counter_used] = (j - new_position);
                        counter_used++;
                    }
                    if (arr[i + new_position][j] == star){ // down
                        repet++;
                        allready_used_i[counter_used] = (i + new_position);
                        allready_used_j[counter_used] = (j);
                        counter_used++;
                    }
                    if (arr[i - new_position][j] == star){ // up
                        repet++;
                        allready_used_i[counter_used] = (i - new_position);
                        allready_used_j[counter_used] = (j);
                        counter_used++;
                    }
                    if (arr[i - new_position][j + new_position] == star){  // dino up right
                        repet++;
                        allready_used_i[counter_used] = (i - new_position);
                        allready_used_j[counter_used] = (j + new_position);
                        counter_used++;
                    }
                    if (arr[i + new_position][j + new_position] == star){  // dino down right
                        repet++;
                        allready_used_i[counter_used] = (i + new_position);
                        allready_used_j[counter_used] = (j + new_position);
                        counter_used++;
                    }
                    if (arr[i + new_position][j - new_position] == star){  // dino down left
                        repet++;
                        allready_used_i[counter_used] = (i + new_position);
                        allready_used_j[counter_used] = (j - new_position);
                        counter_used++;
                    }
                    if (arr[i - new_position][j - new_position] == star){  // dino up left
                        repet++;
                        allready_used_i[counter_used] = (i - new_position);
                        allready_used_j[counter_used] = (j - new_position);
                        counter_used++;
                    }

                }
                result[counter] = repet;
                counter++;
                repet = 0;
                //check(arr[i][j], i, j, roww, coll, arr);
            }
            else{
                allready_used_i[counter_used] = (i);
                allready_used_j[counter_used] = (j);
                counter_used++;
                continue;
            }
        }
    }

    printf("%d ", bolbs);
    for (int i = 0; i < counter; i++){
        printf("%d ", result[i]);
    }
}




/*
int check(int star, int i, int j, int roww, int coll, int arr[][colll]){

    allredy_in_row[size_allready] = i;
    allredy_in_row[size_allready] = j;
    size_allready++;
    flag = true;
    while (fage == true){
        if (arr[i][j + 1] == star){  // right
            allredy_in_row[size_allready] = i;
            allredy_in_row[size_allready] = j + 1;
            size_allready++;
            repet++;
        }
        if (arr[i][j - 1] == star){  // left
            allredy_in_row[size_allready] = i;
            allredy_in_row[size_allready] = j - 1;
            size_allready++;
        }
        if (arr[i + 1][j] == star){  // down
            allredy_in_row[size_allready] = i + 1;
            allredy_in_row[size_allready] = j;
            size_allready++;
        }
        if (arr[i - 1][j] == star){  // up
            allredy_in_row[size_allready] = i - 1;
            allredy_in_row[size_allready] = j;
            size_allready++;
        }
        if (arr[i - 1][j + 1] == star){  // dino up right
            allredy_in_row[size_allready] = i - 1;
            allredy_in_row[size_allready] = j + 1;
            size_allready++;
        }
        if (arr[i + 1][j + 1] == star){  // dino down right
            allredy_in_row[size_allready] = i + 1;
            allredy_in_row[size_allready] = j + 1;
            size_allready++;
        }
        if (arr[i + 1][j - 1] == star){  // dino down left
            allredy_in_row[size_allready] = i + 1;
            allredy_in_row[size_allready] = j - 1;
            size_allready++;
        }
        if (arr[i - 1][j - 1] == star){  // dino up left
            allredy_in_row[size_allready] = i - 1;
            allredy_in_row[size_allready] = j - 1;
            size_allready++;
        }
    }
}


*/
