#include<stdio.h>
#include<string.h>
char str[200000];
int main()
{
	int n = 0;
	int re[26] = { 0 }, ch[26] = {0};
	
	int len;
	scanf("%s",str);
	len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		re[str[i]-'a']++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (re[i] % 2 != 0)
		{
			ch[n++] = i;
		}
	}
	for (int i = 0, j = n-1; i < j; i++, j--)
	{
		re[ch[i]]++;
		re[ch[j]]--;
	}
	if (n % 2 != 0)
	{
		str[len / 2] = ch[n / 2] + 'a';
	}
	for (int i = 0, j = len-1,h=0; i <= j; i++, j--)
	{
		for (; h < 26; h++)
		{
			if (re[h] >= 2)
			{
				re[h] -= 2;
				str[i] = h+'a';
				str[j] = h+'a';
				break;
			}
		}
	}
	printf("%s", str);

	return 0;
}