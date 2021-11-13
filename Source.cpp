#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include<unordered_map>
#include<regex>
#define MAX 0;


int CounterLines(std::string path)//counter lines
{
	int count = 0;//counter
	std::string line;//
	std::ifstream file(path);//open a file stream

	if (file.is_open())//check if open is Succeeded
	{
		while (!file.eof())//while dond came to end of file
		{
			getline(file, line);//the next line
			count++;
		}
		file.close();
		return count;
	}

	else {
		std::cout << "the text file is didnt open" << std::endl;
		return -1;
	}
}
int CounterWords(std::string path)//counter number of words in a file
{
	std::ifstream file(path); //opening text file
	int word = 1; //will not count first word so initial value is 1
	char ch;
	//fin.seekg(0, std::ios::beg); //bring position of file pointer to begining of file
	if (file.is_open())//check if open is Succeeded
	{
		while (file)
		{
			file.get(ch);
			if (ch == ' ' || ch == '\n')
				word++;
		}
		file.close(); //closing file
		return word;
	}
	else {
		std::cout << "the text file is didnt open" << std::endl;
		return -1;
	}

}
int CounterUniquedWords(std::string path)// Prints unique words in a file
{
	int count = 0;
	std::ifstream fs(path);// Open a file stream
	std::map<std::string, int> mp;// Create a map to store count of all words
	std::string word;// Keep reading words while there are words to read
	if (fs.is_open())//check if file is open
	{
		while (fs >> word)
		{
			// If this is first occurrence of word
			if (!mp.count(word))
				mp.insert(make_pair(word, 1));
			else
				mp[word]++;
		}

		fs.close();

		// Traverse map and print all words whose count
		//is 1
		for (std::map<std::string, int> ::iterator p = mp.begin();
			p != mp.end(); p++)
		{
			if (p->second == 1)
				count++;
		}
		return count;
	}
	else {
		std::cout << "the text file is didnt open" << std::endl;
		return -1;
	}
}
int AverageSentenceLong(std::string path)
{
	int countNumberRow = 0, sumLength = 0;
	std::string line;
	std::ifstream file(path);//open the file

	if (file.is_open())//check if file is open
	{
		while (!file.eof())//while dont come to the end of the file
		{
			getline(file, line);//the next line
			sumLength += line.length();//sum all the lines length
			countNumberRow++;//count to the number of the rows
		}
		file.close();//close the file
		return sumLength / countNumberRow;

	}
	else {
		std::cout << "the text file is didnt open" << std::endl;
		return -1;
	}
}
int MaxSentence(std::string path)
{
	int  MaxLength = MAX;
	std::string line;
	std::ifstream file(path);//open a file stream

	if (file.is_open())//check if open
	{
		while (!file.eof())
		{
			getline(file, line);//the next line
			MaxLength = line.length() > MaxLength ? line.length() : MaxLength;//change to the true max length
		}
		file.close();
		return MaxLength;
	}
	else {
		std::cout << "the text file is didnt open" << std::endl;
		return -1;
	}


}
std::string PopularWord(std::string path)
{
	bool first = true;
	std::unordered_map<std::string, int> mp;//hash table to the words
	std::ifstream file(path);//opening text file
	std::string word;
	int maxValue = 0;
	std::string maxKey;

	if (file.is_open())
	{
		auto it = mp.find("");//declare of it

		while (file >> word)// extracting words from the file
		{

			it = mp.find(word);//find the word

			if (it != mp.end()) //if is dont end of the file
			{
				if (first)//if is the first word that is Was already in the hash
				{
					maxKey = it->first;//change the nax word
					maxValue = it->second;// change the max value
					first = false;
				}
				it->second++;//Change the number of phams that the word appears on
				if (it->second > maxValue)//change to the relevant maxValue
				{
					maxValue = it->second;
					maxKey = word;
				}

			}
			else
			{

				mp.insert({ word,1 });

			}
		}
		return maxKey;
	}
	else
	{
		return "the text file is didnt open";
	}




}
std::string PopularWordNotSyntacic(std::string path)
{
	bool first = true;
	std::unordered_map<std::string, int> mp;//hash table to the words
	std::ifstream file(path);//opening text file
	std::string word;
	int maxValue = 0;
	std::string maxKey;
	auto it = mp.find("");//declare of it
	if (file.is_open())
	{

		
		while (file >> word)// extracting words from the file
		{
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		if (word == "am" || word == "is" || word == "are" || word == "do" || word == "doesn't" ||
			word == "don't" || word == "the" || word == "that" || word == "does" || word == "and" || word == "or"
			|| word == "of" || word == "to" || word == "a" || word == "as" || word == "in" || word == "his" || word == "he" || word == "she" || word == "it"
			|| word == "i"||word=="was"||word=="with"||word=="have"||word=="had"||word=="you"||word=="they"||word=="at"
			||word=="for"||word=="on"||word=="her"||word=="be")
				continue;
			it = mp.find(word);//find the word

			if (it != mp.end()) //if is dont end of the file
			{
				if (first)//if is the first word that is Was already in the hash
				{
					maxKey = it->first;//change the nax word
					maxValue = it->second;// change the max value
					first = false;
				}
				it->second++;//Change the number of phams that the word appears on
				if (it->second > maxValue)//change to the relevant maxValue
				{
					maxValue = it->second;
					maxKey = word;
				}

			}
			else
			{

				mp.insert({ word,1 });

			}
		}
		return maxKey;
	}
	else
	{
		return "the text file is didnt open";
	}





}
std::string FindMaxLengthWithoutK(std::string path)
{
	int count = 0, maxLength = 0;//count the long
	std::ifstream fs(path);// Open a file stream	
	std::string word, temp, StrMaxLength;// Keep reading words while there are words to read
	
	if (fs.is_open())
	{
		while (fs >> word)
		{

			if (word.find("k") != std::string::npos)//check if k is in the word
			{
				if (count > maxLength)//change to the relevante MaxLength
				{
					maxLength = count;
					StrMaxLength = temp;

				}
				count = 0;
				temp = "";
			}
			else//if is not have a k in the word
			{
				temp.append(word);//add to the string
				temp.append(" ");
				count++;
			}
		}
		return StrMaxLength;
	}
	else
	{
		return "the text file is didnt open";
	}
}

int main() {


	std::cout << "Number of lines in text file: " << CounterLines("textfile.txt") << std::endl;
	std::cout << "Number of words in text file: " << CounterWords("textfile.txt") << std::endl;
	std::cout << "Number of UniqueWords in text file: " << CounterUniquedWords("textfile.txt") << std::endl;
	std::cout << "The average length of a sentence in a text file: " << AverageSentenceLong("textfile.txt") << std::endl;
	std::cout << "The maximum length of a sentence in a text file: " << MaxSentence("textfile.txt") << std::endl;
	std::cout << "The popular word in a text file: " << PopularWord("textfile.txt") << std::endl;
	std::cout << "The popular word in a text file without Syntactic words: " << PopularWordNotSyntacic("textfile.txt") << std::endl;
	std::cout << "The longest word sequence in a text that does not contain the letter k: " << FindMaxLengthWithoutK("textfile.txt") << std::endl;

	return 0;

}

