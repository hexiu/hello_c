 #include<stdio.h>

char Data[] = {0x36,0x29,0x6D,0x68,0x6E,0x69,0x66,0x69,0x73,0x29,0x74,0x6E,0x69,0x66,0x66,0x77,0x77,0x29,0x64,0x68,0x6A};

void main()
{
    int i;
	printf("Please Internet the web:\n");

	for(i=0;i<sizeof(Data);i++)
		printf("%c",Data[i]^7);
}



