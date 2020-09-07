#include "get_next_line.h"


char    *get_buff(const int fd)
{
    size_t  size;
    char    buff[BUFFER_SIZE + 1];

    size = read(fd, buff, BUFFER_SIZE);
    buff[size] = '\0';
    char *output = ft_strdup(buff);
    return (output);
}

char    **get_line(const int fd, char *output)
{
    char **tab;

    if (!output)
        output = get_buff(fd);
    while (!checkRet(output))
    {
        output = ft_strjoin(output, get_buff(fd));
    }
    tab = ft_split(output, '\n');

    printf("real : %s\n", tab[0]);
    printf("res  : %s\n", tab[1]);
    return (tab);
}

int     checkRet(const char *str)
{
    size_t i;

    i = 0;
    if (str == NULL)
        return (0);
    while (str[i])
    {
        if (str[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

char    *get_endl(const int fd, const int i )
  {
    static char *res;
    char        **tab;

    tab = get_line(fd, res);
    if (!res)
    {
        res = tab[1];
        return (tab[0]);
    }
    else
    {
        tab[0] = ft_strjoin(res, tab[0]);
    }
    res = tab[1];
    
    return (tab[0]);
  }  

int     get_next_line(int fd, char **line)
{
    static int i;
    printf("output : %s\n", get_endl(fd, i));
    i++;
    return (i);
}






int main()
{
    char **ok;
    int fd = open("fichier", O_RDONLY);
    get_next_line(fd, ok);
    get_next_line(fd, ok);
    get_next_line(fd, ok);
    get_next_line(fd, ok);
    get_next_line(fd, ok);
    get_next_line(fd, ok);
    get_next_line(fd, ok);



}