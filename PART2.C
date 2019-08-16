//read/write pointerless program: part2.c

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
int i;
int q;  //length of user name
int s; //counter for spaces in sentence
int length1;  //length of user's sentence
int length2;  //length of selected word



strcpy(my_sentence[0], "We all hate the cafeteria food.\n");
strcpy(my_sentence[1], "That is a beautiful picture.\n");
strcpy(my_sentence[2], "I couldn't believe your great speech!\n");
strcpy(my_sentence[3], "Inside the icebox, there was a funny, green mold.\n");
strcpy(my_sentence[4], "The hamster likes to stay inside its cage.\n");
strcpy(my_sentence[5], "Some people love to eat snails.\n");
strcpy(my_sentence[6], "John opened his notebook and found a picture.\n");
strcpy(my_sentence[7], "I'm getting tired writing these sentences.\n");
strcpy(my_sentence[8], "The mother of Sally really likes to eat fruit.\n");
strcpy(my_sentence[9], "After I landed the skateboard, I had a small problem.\n");
strcpy(my_sentence[10], "The food fight spread all the way into the hallway.\n");
strcpy(my_sentence[11], "I received the nicest book from Santa.\n");
strcpy(my_sentence[12], "He knows how many eggs are there in one dozen.\n");
strcpy(my_sentence[13], "On the dog's nose are three warts.\n");
strcpy(my_sentence[14], "You won't believe what I saw when I looked in the room.\n");
strcpy(my_sentence[15], "At night, I dream about eating cereal.\n");
strcpy(my_sentence[16], "In my bathtub, I found three fish!\n");
strcpy(my_sentence[17], "The cake had a wonderful, thick frosting.\n");
strcpy(my_sentence[18], "When I look in the mirror, I like to look at my teeth.\n");
strcpy(my_sentence[19], "I'll tell you what I thought of the dance.\n");

strcpy(my_word[0], "food");
strcpy(my_word[1], "picture");
strcpy(my_word[2], "speech");
strcpy(my_word[3], "mold");
strcpy(my_word[4], "cage");
strcpy(my_word[5], "snails");
strcpy(my_word[6], "picture");
strcpy(my_word[7], "sentences");
strcpy(my_word[8], "fruit");
strcpy(my_word[9], "problem");
strcpy(my_word[10], "hallway");
strcpy(my_word[11], "Santa");
strcpy(my_word[12], "dozen");
strcpy(my_word[13], "warts");
strcpy(my_word[14], "room");
strcpy(my_word[15], "cereal");
strcpy(my_word[16], "fish");
strcpy(my_word[17], "frosting");
strcpy(my_word[18], "teeth");
strcpy(my_word[19], "dance");






textbackground(GREEN);
textcolor(BLUE);

{

clrscr();

gotoxy(1,2);
printf("Welcome to Level A, Part 2!  What was your first name again?\n\n");
printf("Just type it at the cursor and press the 'enter' key.  ");
fgets(name, 15, stdin); //gets name of user
q = strlen(name);
name[q - 1] = 0;    //eliminates "\n" after name
studentfile = fopen("a:\\student.txt", "a");

if (!studentfile)
	{puts("I can't open a file for you! Sorry!");
	exit(1);}

fputs(name, studentfile);
fputs("\n\nLevel A, Part 2\n\n", studentfile);

for (z = 0; z < 20; z++)


do
{
clrscr();
y = 0;
s = 0;
gotoxy(0,2);
printf("%s, you can do this just like the last part: type one sentence that \n\n", name);
printf(" could follow the one below.  Here's the word you'll want to put\n\n");
printf("near the beginning of your sentence: %s.", my_word[z]);


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
		printf("\Give me a break,n%s! You can write more than that!\n\nYour sentence was too short!\n", name);
		}

		{
		//#2Too short and has word in wrong spot
		if ((y - 1) == (length2 - 1) && (x >= length1/2) && (length1 < 25))
		printf("\n%s, let's see a longer sentence. Try again!\n", name);
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
		printf("\nI don't see \"%s\" anywhere in your sentence.  Try again!\n\nPress any key to try another one.\n", my_word[z]);
		}

		{
		//#6Long enough, and word is in right spot, but no spacing.
		if ((y - 1) == (length2 - 1) && (x < length1/2) && (length1 >= 25) && (s < 3))
		printf("Please type a longer sentence.\n");
		}

		{
		//#7Long enough, and word is in right spot
		if ((y - 1) == (length2 - 1) && (x < length1/2) && (length1 >= 25) && (s >= 3))
		printf("\nI hear applause from the studio audience, %s!", name);
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
	    fclose(studentfile);

gotoxy(1,18);
printf("\n\nCongratulations, you finished Part 2! Press ANY KEY to return to main menu.");

	       c = getche();
	       if (c == 'm')

	       {exit(1);}
}

return(0);
}




























