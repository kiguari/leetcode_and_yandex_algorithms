// В офисе, где работает программист Петр, установили кондиционер нового типа. Этот кондиционер отличается особой простотой в управлении. У кондиционера есть всего лишь два управляемых параметра: желаемая температура и режим работы.
// Кондиционер может работать в следующих четырех режимах:
// «freeze» — охлаждение. В этом режиме кондиционер может только уменьшать температуру. Если температура в комнате и так не больше желаемой, то он выключается.
// «heat» — нагрев. В этом режиме кондиционер может только увеличивать температуру. Если температура в комнате и так не меньше желаемой, то он выключается.
// «auto» — автоматический режим. В этом режиме кондиционер может как увеличивать, так и уменьшать температуру в комнате до желаемой.
// «fan» — вентиляция. В этом режиме кондиционер осуществляет только вентиляцию воздуха и не изменяет температуру в комнате.
// Кондиционер достаточно мощный, поэтому при настройке на правильный режим работы он за час доводит температуру в комнате до желаемой.
// Требуется написать программу, которая по заданной температуре в комнате troom, установленным на кондиционере желаемой температуре tcond и режиму работы определяет температуру, которая установится в комнате через час.
// Формат ввода
// Первая строка входного файла содержит два целых числа troom, и tcond, разделенных ровно одним пробелом (–50 ≤ troom ≤ 50, –50 ≤ tcond ≤ 50).
// Вторая строка содержит одно слово, записанное строчными буквами латинского алфавита — режим работы кондиционера.
// Формат вывода
// Выходной файл должен содержать одно целое число — температуру, которая установится в комнате через час.
// Пример 1
// Ввод
// 10 20
// heat
// Вывод
// 20
// Пример 2
// Ввод
// 10 20
// freeze
// Вывод
// 10
// Примечания
// В первом примере кондиционер находится в режиме нагрева. Через час он нагреет комнату до желаемой температуры в 20 градусов.
// Во втором примере кондиционер находится в режиме охлаждения. Поскольку температура в комнате ниже, чем желаемая, кондиционер самостоятельно выключается и температура в комнате не поменяется.

#include <stdio.h>
#include <unistd.h>

size_t		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	j;

	j = 0;
	if (n == 0)
		return (0);
	while (j <= n - 1)
	{
		if (((unsigned char*)s1)[j] == ((unsigned char*)s2)[j])
			j++;
		else
			return (((unsigned char*)s1)[j] - ((unsigned char*)s2)[j]);
	}
	return (0);
}

int ft_pars(int a, int d, char *str)
{
    int flag = 0;
    int size_line = 0;
    if(ft_memcmp(str, "freeze", 6) && ft_memcmp(str, "heat", 4) && ft_memcmp(str, "fan", 3) && ft_memcmp(str, "auto", 4))
        return(-100);
    if (a < -50 || a > 50 || d < -50 || d > 50)
        return(-100);
    size_line = ft_strlen(str);
    if(d >= a && !ft_memcmp(str, "heat", 4) && size_line == 4)
    {
        printf("%d", d);
        return(1);
    }
    if(a >= d && !ft_memcmp(str, "heat", 4) && size_line == 4)
    {
        printf("%d", a);
        return(1);
    }
    if(d >= a && !ft_memcmp(str, "freeze", 6) && size_line == 6)
    {
        printf("%d", a);
        return(1);
    }
    if(a >= d && !ft_memcmp(str, "freeze", 6) && size_line == 6)
    {
       printf("%d", d);
       return(1);
    }
    if(!ft_memcmp(str, "fan", 3) && size_line == 3)
    {
       printf("%d", a);
       return(1);
    }
    if(!ft_memcmp(str, "auto", 4) && size_line == 4)
    {
       printf("%d", d);
       return(1);
    }
    return(-100);
}

int main()
{
    int a = -100;
    int d = -100;
    char str[10];
    int flag = -100;
    scanf("%d %d %s", &a, &d, str);
    flag = ft_pars(a, d, str);
    if(a == -100 || d == -100 || str[0] == '\0' || flag == -100)
    {
        // printf("error");
        return(0);
    }
    return(0);
}