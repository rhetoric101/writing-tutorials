//read/write pointerless program:  Part1.c

#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
FILE *studentfile;

main()
{

char name[15]; //Variable for the name of the user
char sentence[148]; //Variable for the sentence entered by user
char my_sentence[21][80];
char my_word[21][30];
char c; //Keypress variable to choose options
int p;
int z; //variable used to count through array members
int x; // variable used to count through length of user's sentence
int y = 0; //variable used to count through length of selected word
int q;  //length of user name
int s; //counter for spaces in sentence
int length1;  //length of user's sentence
int length2;  //length of selected word


strcpy(my_sentence[0], "The dog was chased by the cat.\n");
strcpy(my_sentence[1], "Jake only likes certain kinds of work.\n");
strcpy(my_sentence[2], "Jimmy likes to eat frogs.\n");
strcpy(my_sentence[3], "Sally tripped and fell on her face.\n");
strcpy(my_sentence[4], "Peter shot a spit wad over the teacher.\n");
strcpy(my_sentence[5], "Everyone loved the purple underwear that belonged to Bill.\n");
strcpy(my_sentence[6], "The puppy ran out from under the porch and chased the cat.\n");
strcpy(my_sentence[7], "The potato chips fell onto the floor and made a mess.\n");
strcpy(my_sentence[8], "The spider crawled into his ear and made a nest.\n");
strcpy(my_sentence[9], "All good seventh graders like the taste of broccoli.\n");
strcpy(my_sentence[10], "The car went off the road and off the cliff.\n");
strcpy(my_sentence[11], "Sally wanted me to go see her friend.\n");
strcpy(my_sentence[12], "Each of us threw a rock through the window.\n");
strcpy(my_sentence[13], "Candice helped the old man.\n");
strcpy(my_sentence[14], "I'm tired of eating popcorn.\n");
strcpy(my_sentence[15], "The nicest teacher is Mr. Priest.\n");
strcpy(my_sentence[16], "I know what happened when you yelled in class.\n");
strcpy(my_sentence[17], "I hate to take out the garbage.\n");
strcpy(my_sentence[18], "The most enjoyable thing to do in class is write notes.\n");
strcpy(my_sentence[19], "Special awards should be given to some teachers.\n");

strcpy(my_word[0], "cat");
strcpy(my_word[1], "work");
strcpy(my_word[2], "frogs");
strcpy(my_word[3], "face");
strcpy(my_word[4], "teacher");
strcpy(my_word[5], "Bill");
strcpy(my_word[6], "cat");
strcpy(my_word[7], "mess");
strcpy(my_word[8], "nest");
strcpy(my_word[9], "broccoli");
strcpy(my_word[10], "cliff");
strcpy(my_word[11], "friend");
strcpy(my_word[12], "window");
strcpy(my_word[13], "man");
strcpy(my_word[14], "popcorn");
strcpy(my_word[15], "Mr. Priest");
strcpy(my_word[16], "yelled");
strcpy(my_word[17], "garbage");
strcpy(my_word[18], "notes");
strcpy(my_word[19], "teachers");

textbackground(GREEN);
textcolor(BLUE);

{

clrscr();

gotoxy(1,2);
printf("O.K., before we get started I'd like you to type your first name\n");
printf("and press the 'enter' key.  ");
fgets(name, 15, stdin); //gets name of user
q = strlen(name);
name[q - 1] = 0;    //eliminates "\n" after name
studentfile = fopen("a:\\student.txt", "a");

if (!studentfile)
	{puts("I can't open a file for you! Sorry!");
	exit(1);}

fputs(name, studentfile);
fputs("\n\nLevel A, Part 1\n\n", studentfile);

for (z = 0; z < 19; z++)


do
{
clrscr();
y = 0;
s = 0;
gotoxy(0,2);
printf("%s, please type one sentence that", name);
printf(" could follow the one below,\n\n");

printf("putting the following word near the beginning of your sentence:  ");

printf("%s.", my_word[z]);

gotoxy(1,8);
printf("%s\n", my_sentence[z]);
gotoxy(1,10);


fgets(sentence, 148, stdin);  //asks user to write a sentence
fputs(my_sentence[z], studentfile);
fputs(sentence, studentfile);
length1 = strlen(sentence); //assign length of sentence to "length1"

length2 = strlen(my_word[z]); //assign length of "word" to "length2"
for (x = 0; x < length1; x++)
	{
	if (sentence[x] == ' ')
	{s++;}
	}
for (x = 0; x < length1; x++)

	{
	//beginning of parser
	if (sentence[0] != my_word[z][y])//solves upper case problem at beginning
	{sentence[0] = (sentence[0] + 32);}

	if ((sentence[x] != my_word[z][y])  && (y < length2))
	{y = 0;}

	if ((sentence[x] == my_word[z][y])  && (y < length2))
	{y = y + 1;}

	if ((sentence[x] != my_word[z][length2 - 1])  && (x > length2))
	{y = y;}

	if ((sentence[x] == my_word[z][length2 - 1]) && (y == length2 ))
		break;
		}
       gotoxy(1,12);
		{
		//#1Too short but has word  in correct spot
		if ((y - 1) == (length2 - 1) && (x < length1/2) && (length1 < 25))
		printf("\n%s, your sentence was too short!\n", name);
		}

		{
		//#2Too short and has word in wrong spot
		if ((y - 1) == (length2 - 1) && (x >= length1/2) && (length1 < 25))
		printf("\nCome on now, %s, you can write longer sentences than that!\n", name);
		}

		{
		//#3Too short and has no word
		if ((y - 1) != (length2 - 1) && (length1 < 25))
		printf("\nYou left out the word, %s, and your sentence was too short!\n", name);
		}


		{
		//#4Long enough, but word is in wrong spot
	       if ((y - 1) == (length2 - 1) && (x >= length1/2) && (length1 >= 25))
		printf("\nTry again, %s, but put \"%s\" closer to the front.\n", name, my_word[z]);
		 }


		{
		//#5Long enough, but word is missing
		if ((y - 1) != (length2 - 1) && (length1 >= 25))
		printf("\nWhere's the word, %s?\n\nPress any key to try another one.\n", name);
		}

		{
		//#6Long enough, and word is in right spot, but no spacing.
		if ((y - 1) == (length2 - 1) && (x < length1/2) && (length1 >= 25) && (s < 3))
		printf("Please type a longer sentence.\n");
		}

		{
		//#7Long enough, and word is in right spot
		if ((y - 1) == (length2 - 1) && (x < length1/2) && (length1 >= 25) && (s >= 3))
		printf("\nSuperb job, %s!", name);
		}
	       printf("\n\nPress \"enter\" to try another or \"m\" to return to main menu.\n");

  gotoxy(1,14);

	       c = getche();
	       if (c == 'm')


		{exit(1);}

}


  // End of do-while loop #5
  while ((y - 1) != (length2 - 1) || (x >= length1/2) || (length1 < 25) || (s < 3));

fflush(stdin);

}

{
gotoxy(1,18);
	    fclose(studentfile);

printf("\n\nCongratulations, you finished Part 1! Press ANY KEY to return to main menu.");

	       c = getche();
	       if (c == 'm')
	    {exit(1);}
}

return(0);
}







































