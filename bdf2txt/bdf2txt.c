/*
Copyright (c) 2011 Nico Hoffmann <nico@warp7.de>

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

   1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required.

   2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.

   3. This notice may not be removed or altered from any source
   distribution.
*/

#include <stdio.h>
#include <string.h>

#define BSIZE 1024

int main()
{
	char buffer[BSIZE];
	char *b = buffer;
	int echo = 1;
	int lineno = 0;
	
	do
	{
		b = fgets(buffer,BSIZE,stdin);
		++lineno;
		if(b)
		{
			if( echo )
			{
				fputs(b, stdout);
				if( ! strncmp(b, "BITMAP", 6) ) echo = 0;
			}
			else
			{
				if( ! strncmp(b, "ENDCHAR", 7) )
				{
					fputs(b, stdout);
					echo = 1;
				}
				else
				{
					char *s = b;
					int i;
					while(*s)
					{
						i=0;
						switch(*s)
						{
							case 'A' ... 'F': i=*s-'A'; i+=10; break;
							case 'a' ... 'f': i=*s-'a'; i+=10; break;
							case '0' ... '9': i=*s-'0';break;
							case '\n': break;
							default: fprintf(stderr,"error at line %i (char %i)\n",lineno,*s); break;
						}
						printf("%c", (i&8) ? '#':'.');
						printf("%c", (i&4) ? '#':'.');
						printf("%c", (i&2) ? '#':'.');
						printf("%c", (i&1) ? '#':'.');
						++s;
					}
					printf("\n");
				}
			}
		}
	} while(b);
	return 0;
}
