
int main()
{
	while(gets(str))
	{

			len=strlen(str);
			for(i=1;i<=len/2;i++)
			{
				if(len%i==0)
				{
					k=check(i);
				}
				else
					continue;
				if(k==1)
					break;
			}
			if(k==0)
				printf("1\n");
			else
				printf("%ld\n",len/i);
		}
}

long check(long n)
{
	for(i=0;i<n;i++)
	{
		for(j=i+n;j<len;j+=n)
		{
			if(str[j]!=str[i])
			{
				flag=0;
				break;
			}
		}
	}
	return flag;
}
