
//FT_PRINTF MAIN TEST FROM TESTER//

int main(void)
{
	int	bytes;
	
	bytes = 0;
	ft_printf("Simple test\n");
	ft_printf("");
	ft_printf("\n");
	ft_printf("---F---\n");
	ft_printf("%d\n", 0);
	ft_printf("%d\n", 42);
	ft_printf("%d\n", 1);
	ft_printf("%d\n", (int)2147483647);
	ft_printf("%d\n", (int)2147483648);
	ft_printf("%d\n", (int)-2147483648);
	ft_printf("%d\n", (int)-2147483649);
	ft_printf("\n");
	ft_printf("%x\n", 0);
	ft_printf("%x\n", 42);
	ft_printf("%x\n", 1);
	ft_printf("%x\n", 5454);
	ft_printf("%x\n", (int)2147483647);
	ft_printf("%x\n", (int)2147483648);
	ft_printf("%x\n", (int)-2147483648);
	ft_printf("%x\n", (int)-2147483649);
	ft_printf("%x\n", (int)0xFFFFFFFF);
	ft_printf("%s\n", "");
	ft_printf("%s\n", "Hello");
	ft_printf("%s\n", "wereqewele");
	ft_printf("%s\n", NULL);
	ft_printf("-%s-%s-%s-%s-\n", "", "hello", "wereqewelemikeleachiwo", NULL);
	ft_printf("\n--Mixed---\n");
	ft_printf("%d%x%d%x%d%x%d%x\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
	ft_printf("-%d-%x-%d-%x-%d-%x-%d-%x-\n", 0, 0, 42, 42, 2147483647, 2147483647, (int)-2147483648, (int)-2147483648);
	ft_printf("\n");
	ft_printf("%s%s%s%s\n", "", "hello", "wereqewelemikeleachi", NULL);
	ft_printf("-%s-%s-%s-%s-\n", "", "hello", "wereqewelemikeleachi", NULL);
	printf("written: %d\n", bytes);
}
