//使用环境windoes

#include <stdio.h>

#include <stdlib.h>

#include <string.h>





#define MAXLEN 100





typedef struct string

{

	char ch[MAXLEN];

	int len;

}SString,*PSString;





void StrReplace(PSString ps,SString t,SString v);

int StrLength(SString n);

int Index(PSString s,SString t,int pos) ;



int main(void) {

	PSString ps;

	SString s,t,v;

	int flag;

	ps = &s;

	fflush(stdin);

	printf("please input String:");

	gets(s.ch);

	fflush(stdin);

	printf("please input will be replaced String:");

	gets(t.ch);//需要判断一下这一段字符串是否在原字符串中存在

	flag = Index(ps,t,0);

	/*if(flag == -1) {

		printf("你所输入的字符串不在主串中,请重输\n");

		goto loop;

	}else

	//	printf("输入正确!!!");*/

	fflush(stdin);

	printf("please input replace String:");

	gets(v.ch);

	s.len = StrLength(s);

    t.len = StrLength(t);

    v.len = StrLength(v);

	StrReplace(ps,t,v);

	printf("len=%d\t%d\t%d\n",s.len,t.len,v.len);

	puts(ps->ch);

	return 0;



}



void StrReplace(PSString ps,SString t,SString v) {

	int i,pos;

	pos = 0;

	if(t.len == v.len) {

		while(1) {

       pos = Index(ps,t,pos);

	   printf("pos = %d\n",pos);

	   if(pos == -1 ) {

		   break;

	   }

	   for(i = 0;i < v.len;i++) {

            ps->ch[pos+i] = v.ch[i];

	   }

	   pos += v.len;

	}



	}

		if(t.len > v.len) {

			while(1) {

				pos = Index(ps,t,pos);

				printf("pos = %d\n",pos);

				if(pos == -1) {

					break;

				}

				for(i = 0;i < v.len;i++) {

					ps->ch[pos+i] = v.ch[i];

				}

				for(i = 0; i < ps->len;i++) {

					ps->ch[pos+v.len+i] = ps->ch[pos+t.len+i];

				}

				pos += v.len;

				ps->len = ps->len+v.len-t.len;

				printf("len = %d\n",ps->len);

			}

		}

		if(t.len < v.len)

			{

				while(1) {

				pos = Index(ps,t,pos);

				printf("pos = %d\n",pos);

				if(pos == -1 ) {

	 			   break;

				}

				ps->len =ps->len+v.len-t.len;

				for(i = ps->len;i != pos ;i--) {

					if(i+v.len-t.len < 100)

						ps->ch[i+v.len-t.len] = ps->ch[i];

					else break;

				}

				for(i = 0;i < v.len;i++) {

					ps->ch[pos+i] = v.ch[i];

				}

				pos += v.len;

				}



			}







}

int Index(PSString s,SString t,int pos) {

	int i = pos,j = 0;

	while(i < s->len&&j < t.len) {

		if(s->ch[i] == t.ch[j]) {

			i++;

			j++;

		}else {

			i = i - j + 1;

			j = 0;

		}

	}

	if(j > t.len-1){

		return i - t.len;

	}

	else

		return -1;

}



int StrLength(SString ps) {

	int len;

	len = 0;

	while(ps.ch[len] != '\0') {

		len++;

	}

	return len;

}


