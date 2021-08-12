/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:35:54 by rbourgea          #+#    #+#             */
/*   Updated: 2021/08/12 13:36:31 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char *gnl_strjoin(char const *s1, char const *s2)
{
    char *tab;
    size_t len;
    size_t i;
    size_t j;

    if (!s1 && !s2)
        return (0);
    i = ft_strlen(s1);
    j = ft_strlen(s2);
    len = i + j + 1;
    tab = (char *)malloc(sizeof(char) * len);
    if (!tab)
        return (NULL);
    i = 0;
    j = 0;
    while (s1 && i < len && s1[i])
    {
        tab[i] = s1[i];
        i++;
    }
    while (s2 && i < len && s2[j])
    {
        tab[i++] = s2[j++];
    }
    tab[i] = '\0';
    free((char *)s1);
    return (tab);
}

static char *first_line(char *str)
{
    char *line;
    int i;

    i = 0;
    if (!str)
        return (0);
    while (str[i] && str[i] != '\n')
        i++;
    line = (char *)malloc(sizeof(char) * i + 1);
    if (!line)
        return (NULL);
    i = 0;
    while (str[i] && str[i] != '\n')
    {
        line[i] = str[i];
        i++;
    }
    line[i] = '\0';
    return (line);
}

static char *save_line(char *save)
{
    char *str;
    int i;
    int j;

    i = 0;
    j = 0;
    if (!save)
        return (0);
    while (save[i] && save[i] != '\n')
        i++;
    if (!save[i])
    {
        free(save);
        return (0);
    }
    str = (char *)malloc(sizeof(char) * ft_strlen(save) - i + 1);
    if (!str)
        return (NULL);
    i++;
    while (save[i])
        str[j++] = save[i++];
    //free(save);
    str[j] = '\0';
    return (str);
}

static int ft_newline(char *save)
{
    int i;

    i = 0;
    if (!save)
        return (0);
    while (save[i])
    {
        if (save[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

int get_next_line(int fd, char **line)
{
    char buf[BUFFER_SIZE + 1];
    int read_num;
    static char *save;

    read_num = 1;
    if (fd < 0 || !line || BUFFER_SIZE <= 0)
        return (-1);
    while (read_num != 0 && !ft_newline(save))
    {
        read_num = read(fd, buf, BUFFER_SIZE);
        if (read_num == -1)
            return (-1);
        buf[read_num] = '\0';
        save = gnl_strjoin(save, buf);
    }
    *line = first_line(save);
    save = save_line(save);
    if (read_num == 0)
        return (0);
    return (1);
}