#include <iostream>
using namespace std;
#define WORDS_AMOUNT 3
#define WORDS_STEP 1
#define N 256

bool isOriginalLine(char* w1, char* w2);
bool isSeparator(char c);
void changeInput(char *inputText);
int strLength(char line[]);
int firstWordLength(char textFragment[]);


int main () {
	char textBase[] = "hello my dear hello world ";
	char textInput[] = "My,,      dEaR ... heLlo couNTry curRENt dear hello faIl";
	char textFragment[N] = "";
	int attempts = 0;
	int subCarriage = 0;
	int wordsCounter = 0;
	int originalCounter = 0;
	char* base = textBase;
	char* fragment;
	int inputLength;
	
	changeInput(textInput);
	inputLength = strLength(textInput);

	for (int i = 0; i <= inputLength; i++) {
		textFragment[subCarriage] = textInput[i];
		subCarriage++;
		if(isSeparator(textInput[i]))
			wordsCounter++;
		if (wordsCounter == WORDS_AMOUNT) {
			for (int j = strLength(textFragment) - 1; j > subCarriage - 1; j--) {
				textFragment[j] = 0;
			}
			fragment = textFragment;
			if (isOriginalLine(base, fragment)) {
				originalCounter++;
			}
			attempts++;
			wordsCounter = 0;
			i = i - subCarriage + firstWordLength(textFragment) + 1;
			subCarriage = 0;
		}
	}

	cout << "Originality of entered text is: " << originalCounter * 100 / attempts << " %" << endl;
	
	return 0;
}

bool isOriginalLine(char *base, char *fragment)
{
	int i=0;
    int j=0;

    for(i;i < strLength(base); i++)
    {
        if(base[i] == fragment[j])
        {
            j++;
        }
    }

    if(strLength(fragment) == j)
        return false;
    else
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
