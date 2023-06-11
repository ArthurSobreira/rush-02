/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:41:01 by arsobrei          #+#    #+#             */
/*   Updated: 2023/06/11 12:14:29 by arsobrei         ###   ########.fr       */                                                                       */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DICT_ENTRIES 32
#define MAX_WORD_LENGTH 20

typedef struct {
    int number;
    char word[MAX_WORD_LENGTH];
} DictionaryEntry;

int ft_load_dict(DictionaryEntry* dictionary) {
    FILE* file = fopen("dictionary.txt", "r"); 

    int count = 0;
    while ((count < MAX_DICT_ENTRIES) && (fscanf(file, "%d %s", &dictionary[count].number, dictionary[count].word) == 2)) 
	{
        count++;
    }
    fclose(file);
    return (count);
}

void ft_convnert_number(int number, const DictionaryEntry* dictionary, int dictSize, char* result) 
{
    if (number == 0) 
	{
        return;
    }

    for (int i = dictSize - 1; i >= 0; i--) {
        if (dictionary[i].number <= number) {
            int quotient = number / dictionary[i].number;
            strcat(result, dictionary[i].word);

            if (quotient > 1) {
                strcat(result, " ");
                ft_convnert_number
			(quotient, dictionary, dictSize, result);
            }

            number %= dictionary[i].number;
            break;
        }
    }
}

void ft_print_number(const char* number, const DictionaryEntry* dictionary, int dictSize) {
    int num = atoi(number);
    char result[1000] = "";
    ft_convnert_number(num, dictionary, dictSize, result);
    printf("%s\n", result);
}

int main(void) 
{
    DictionaryEntry dictionary[MAX_DICT_ENTRIES];
    int dictSize = ft_load_dict
(dictionary);

    if (dictSize == 0) {
        return 1;
    }

    const char* inputNumber = "500";
    ft_print_number
(inputNumber, dictionary, dictSize);

    return (0);