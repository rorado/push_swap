#include <stdio.h>
#include <stdlib.h>

int countWord(char *str)
{
    int i = 0;
    int word = 0;

    while (str[i])
    {
        if (str[i] != ' ')
        {
            while (str[i] != ' ' && str[i])  
                i++;
            word++;
        }
        else
            i++;
    }
    return word;
}

char *word_dup(char const *s, int start, int end)
{
    char *word;
    int i = 0;

    word = malloc(sizeof(char) * (end - start + 1));
    if (!word)
        return NULL;

    while (start < end)
        word[i++] = s[start++];

    word[i] = '\0';
    return word;
}

void free_all(char **res, int j)
{
    while (j > 0)
        free(res[--j]);
    free(res);
}

char **ft_split(const char *s, char c)
{
    int i = 0;
    int j = 0;
    int start;
    char **res;

    res = malloc((countWord((char *)s) + 1) * sizeof(char *));
    if (!res)
        return NULL;
    while (s[i])
    {
        while (s[i] == ' ' && s[i])
            i++;
        start = i;
        while (s[i] && s[i] != c)
            i++;
        if (start < i)
        {
            res[j] = word_dup(s, start, i); 
            if (!res[j])
                return (free_all(res, j), NULL);
            j++;
        }
    }
    res[j] = NULL;
    return res;
}
