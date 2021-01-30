#include <iostream>
using namespace std;
#define WORDS_AMOUNT 3
#define WORDS_STEP 1
#define N 256

bool isOriginalLine(char fragment[], char base[]);
bool isSeparator(char c);
void changeInput(char *inputText);
int strLength(char line[]);
int firstWordLength(char textFragment[]);


int main () {
	char textBase[] = "hello my dear hello world ";
	char textInput[] = "My,,      dEaR ... heLlo couNTry curRENt dear hello world faIl";
	char textFragment[N] = "";
	int attempts = 0;
	int subCarriage = 0;
	int wordsCounter = 0;
	bool attemptsFlag = false;
	int originalCounter = 0;
	int inputLength = strLength(textInput);

	changeInput(textInput);
	cout << "Input text: " <<textInput << endl;
	cout << "Text base:  " <<textBase << endl << endl;
	

	for (int i = 0; textInput[i] != '\0'; i++) {
		textFragment[subCarriage] = textInput[i];
		subCarriage++;
		if(isSeparator(textInput[i]))
			wordsCounter++;
		if (wordsCounter == WORDS_AMOUNT) {
			for (int j = strLength(textFragment) - 1; j > subCarriage - 1; j--) {
				textFragment[j] = 0;
			}
			if (isOriginalLine(textFragment, textBase)) {
				originalCounter++;
			}
			cout << textFragment << "<-- Text to compare" << endl;
			cout << textBase << "<-- To compare with" << endl;
			cout << isOriginalLine(textFragment, textBase) << endl;
			attempts++;
			wordsCounter = 0;
			i = i - subCarriage + firstWordLength(textFragment) + 1;
			subCarriage = 0;
		}
	}
	
	cout << attempts << endl;
	cout << originalCounter << endl;

	return 0;
}

bool isOriginalLine(char fragment[], char base[])
{
	for (int i = 0; base[i] != '\0'; i++) {
		if (base[i] == fragment[0] and (isSeparator(base[i-1]) or i == 0)) {
			for (int j = 0; fragment[j] != '\0'; j++) {
				if (fragment[j] == base[i]) {
					i++;
				} else
					break;
				if (fragment[j+1] == '\0' and isSeparator(base[i]))
					return false;
			}
		}
	}
	return true;
}

bool isSeparator(char c)
{
	char separatorList[] = " ,.!?<>/\"-'\\:;";
	for (int i = 0; separatorList[i] != '\0'; i++)
		if (separatorList[i] == c or c == '\0') 
			return true;
	return false;
}

void changeInput(char *inputText)
{
	int tempIndex = 0;
	int inputLength = strLength(inputText);
	
	for (int i = 0; inputText[i] != '\0'; i++) {
		if (!isSeparator(inputText[i])) {
			if (inputText[i] >= 'A' and inputText[i] <= 'Z') {
				inputText[tempIndex] = (char)((int)inputText[i] + 32);
				tempIndex++;
			} else {
				inputText[tempIndex] = inputText[i];
				tempIndex++;
			}
		} else if (!isSeparator(inputText[tempIndex - 1])){
			inputText[tempIndex] = ' ';
			tempIndex++;
		}
	}
	
	for (inputLength; inputLength >= tempIndex; inputLength--){
		inputText[inputLength] = 0;
	}
}

int strLength(char line[])
{
	int i;
	
	for (i = 0; line[i] != '\0'; i++)
	{
	}
	
	return i + 1;
}

int firstWordLength(char textFragment[])
{
	for (int i = 0; textFragment[i] != '\0'; i++)
		if (isSeparator(textFragment[i]))
			return i;
}
